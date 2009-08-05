
#include <algorithm>
#include <functional>


#include "SINAlloc.h"
#include "SINObject.h"
#include "SINAssert.h"
#include "SINMemoryCell.h"
#include "SINMemoryCellAST.h"
#include "SINMemoryCellBool.h"
#include "SINMemoryCellNumber.h"
#include "SINMemoryCellObject.h"
#include "SINMemoryCellString.h"
#include "SINMemoryCellFunction.h"


#define TO_STRING_APPEND(TYPE)		str			<<									\
									i->first	<<									\
									":"			<<									\
									static_cast<TYPE *>(i->second)->GetValue();		\
									break

#define TO_STRING_APPEND_OBJECT()	{const Object * obj = static_cast<MemoryCellObject *>(i->second)->GetValue();		\
									if (parentsId.find(obj->ID()) !=  parentsId.end())						\
										str << i->first << ":self-->Object(" << obj->ID() << ")<--";					\
									else																				\
										str << i->first << ":" << obj->ToString(parentsId);								\
										break;}



namespace SIN {
	
	namespace Types {

		///--------------------		Object		---------------------------///



		///--------------------------------------------------
		///	static functions and functors

		//-----------------------------------------------------------------
		
		struct TableKeyFunctor : public std::unary_function<const Object::ObjectTableValue &, void> {
			Object * keys;
			TableKeyFunctor(Object * obj) : keys(obj){}
			void operator() (const Object::ObjectTableValue & otv) 
				{ keys->SetValue( SINEW(MemoryCellString(otv.first))); }
		};


		struct CleanTableFunctor : public std::unary_function <const Object::ObjectTableValue &, void> {

			void operator() (const Object::ObjectTableValue & otv) {
				if (otv.second != static_cast<MemoryCell *>(0)) {
					if(otv.second->Type() == MemoryCell::OBJECT_MCT){
						MemoryCellObject * obj = static_cast<MemoryCellObject *>(otv.second);

						//An to exoume 3anadei simenei oti eixame kuklo kai to exoume idi kanei delete
						if ( !obj->GetValue()->IsMarckedForDeletion() ) {
							obj->GetValue()->MarckedForDeletion();	
							SINDELETE(otv.second); 
						}
					}
					else
						SINDELETE(otv.second); 
				}
			}
		};




		///--------------------------------------------------
		///	private methods
		
		//-----------------------------------------------------------------

		const String Object::ToString(std::set<unsigned> & parentsId) const {
			
			String str = String() << "Object(" << id << "){";
			parentsId.insert(id);
			
			for (ObjectTable::const_iterator i = table.begin(); i != table.end(); ++i) {
				switch(i->second->Type()) {
					case MemoryCell::BOOL_MCT		: TO_STRING_APPEND(MemoryCellBool);
					case MemoryCell::STRING_MCT		: TO_STRING_APPEND(MemoryCellString);
					case MemoryCell::NUMBER_MCT		: TO_STRING_APPEND(MemoryCellNumber);
					case MemoryCell::AST_MCT		: TO_STRING_APPEND(MemoryCellAST);
					case MemoryCell::OBJECT_MCT		: TO_STRING_APPEND_OBJECT();
					case MemoryCell::FUNCTION_MCT	: TO_STRING_APPEND(MemoryCellFunction);
					default: SINASSERT(0);
				}
				str << ", ";
			}
			
			str << "}";
			return String(str);	
		}


		///--------------------------------------------------
		///	public methods
		
		//-----------------------------------------------------------------
		//constructors
		Object::Object() : marckedForDeletion(false), rc(0), id(SinObjectFactory::NextID()), index(0) {}
		


		//-----------------------------------------------------------------
		//destructors
		Object::~Object() { 
			SINASSERT(rc == 0 && marckedForDeletion);
			for_each(table.begin(), table.end(), CleanTableFunctor());
			table.clear();
		}



		//-----------------------------------------------------------------

		unsigned Object::ID() const 
			{ return id; }



		//-----------------------------------------------------------------

		bool Object::IsUnreferenced (void) const 
			{ return rc == 0 ? true: false; }

		
		//-----------------------------------------------------------------

		unsigned Object::ReferenceCounter (void) const 
			{ return rc; }
		
		
		//-----------------------------------------------------------------

		void Object::IncrementReferenceCounter (void)
			{ ++rc;}
		

		//-----------------------------------------------------------------

		void Object::DecrementReferenceCounter (void) { 
			SINASSERT(rc > 0);
			--rc;
		}



		//-----------------------------------------------------------------
		
		void Object::SetValue(MemoryCell * value) { 
			String key = to_string(index++);

			while(table.find(key) != table.end())
				{ key = to_string(index++); }
			table[key] = value; 
		}


		//-----------------------------------------------------------------

		void Object::SetValue (const String & key, MemoryCell * value) 
			{ table[key] = value; }


		//-----------------------------------------------------------------

		void Object::SetValue (const ObjectTableValue & otv) 
			{ SetValue(otv.first, otv.second); }
		
		
		//-----------------------------------------------------------------
		
		void Object::MarckedForDeletion(void)
			{ marckedForDeletion = true;}



		//-----------------------------------------------------------------
		
		bool Object::IsMarckedForDeletion(void) const
			{ return marckedForDeletion; }


		//-----------------------------------------------------------------

		MemoryCell * Object::GetValue (const String & key) const {
			ObjectTable::const_iterator result = table.find(key);
			return result != table.end() ? result->second : static_cast<MemoryCell *>(0);
		}


		//-----------------------------------------------------------------
		Object *	 Object::ObjectKeys(void) const 
			{ return std::for_each(table.begin(), table.end(), TableKeyFunctor(SINEW(Object))).keys; }


		//-----------------------------------------------------------------
		unsigned Object::NumberOfElements (void) const  
			{ return table.size(); }


		//-----------------------------------------------------------------

		const String Object::ToString(void) const {
			std::set<unsigned> parents;
			return ToString(parents); //If we wont to eleminat the last ',' we must do this: Erase(1, str_size - 3);
		}


		//-----------------------------------------------------------------

		bool Object::operator== (const Nil_t & n) const 
			{ return false; }
		
		
		//-----------------------------------------------------------------

		bool Object::operator!= (const Nil_t & n) const 
			{ return true; }
		

		//-----------------------------------------------------------------

		bool Object::operator== (const String & str) const 
			{ return false; }


		//-----------------------------------------------------------------
		
		bool Object::operator!= (const String & str) const 
			{ return true; }
		

		//-----------------------------------------------------------------

		bool Object::operator== (const Number num) const 
			{ return false; }
		

		//-----------------------------------------------------------------

		bool Object::operator!= (const Number num) const 
			{ return true; }
		

		//-----------------------------------------------------------------
		
		bool Object::operator== (const Object & obj) const 
			{ return id == obj.ID(); }


		//-----------------------------------------------------------------
		
		bool Object::operator!= (const Object & obj) const 
			{ return id != obj.ID(); }



		///--------------------		SinObjectFactory	---------------------------///


		//---------------------------------------------------

		SinObjectFactory::SinObjectFactory(void): next_id(0) {}

		
		//---------------------------------------------------
		SinObjectFactory::~SinObjectFactory(void) {}
		
		
		//---------------------------------------------------
		// singleton related
		SinObjectFactory* SinObjectFactory::singleton = 0;
		
		
		//---------------------------------------------------
		
		bool SinObjectFactory::singleton_created = false;
		
		
		//---------------------------------------------------
		
		void SinObjectFactory::SingletonCreate(void) {
			SINASSERT(!singleton_created);
			if ((singleton = SINEW(SinObjectFactory)) != 0)
				singleton_created = true;
		}
		
		
		//---------------------------------------------------
		
		bool SinObjectFactory::SingletonCreated(void) {
			return singleton_created;
		}
		
		
		//---------------------------------------------------

		void SinObjectFactory::SingletonDestroy(void) {
			SINASSERT(singleton_created);
			SINDELETE(singleton);
			singleton_created = false;
		}
		
		
		//---------------------------------------------------

		SinObjectFactory& SinObjectFactory::SingletonInstance(void) {
			SINASSERT(singleton_created);
			return *(singleton_created ? singleton : 0);
		}
		
		
		//---------------------------------------------------
		// convenience methods	
		
		//---------------------------------------------------
		unsigned const SinObjectFactory::NextID(void) 
			{ return SingletonInstance().InstanceNextID(); }
		

		//---------------------------------------------------
		// instance factory methods

		//---------------------------------------------------
		unsigned const SinObjectFactory::InstanceNextID(void) 
			{ return next_id++; }
	}	//namespace Types


	//-----------------------------------------------------------------
	
	String const to_string(SIN::Types::Object const & val) 
		{ return val.ToString(); }
	

	//-----------------------------------------------------------------
	
	String const to_string(SIN::Types::Object const * val) 
		{ return val->ToString(); }

}	//namespace SIN