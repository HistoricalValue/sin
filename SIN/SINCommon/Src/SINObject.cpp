
#include <algorithm>
#include <functional>


#include "SINAlloc.h"
#include "SINObject.h"
#include "SINAssert.h"
#include "SINMemoryCell.h"
#include "SINMemoryCellString.h"
#include "SINMemoryCellObject.h"
#include "SINFunction.h"

//#define TO_STRING_APPEND(TYPE)		str			<<									\
//									i->first	<<									\
//									":"			<<									\
//									static_cast<TYPE *>(i->second)->GetValue();		\
//									break
//
//#define TO_STRING_APPEND_OBJECT()	{const Object * obj = static_cast<MemoryCellObject *>(i->second)->GetValue();		\
//									if (parentsId.find(obj->ID()) !=  parentsId.end())						\
//										str << i->first << ":self-->Object(" << obj->ID() << ")<--";					\
//									else																				\
//										str << i->first << ":" << obj->ToString(parentsId);								\
//										break;}



///--------------------------------------------------
///	static functions and functors

//-----------------------------------------------------------------

struct TableKeyFunctor : public std::unary_function<const SIN::Types::Object::ObjectTableValue &, void> {
	SIN::Types::Object * keys;
	TableKeyFunctor(SIN::Types::Object * obj) : keys(obj){}
	void operator() (const SIN::Types::Object::ObjectTableValue & otv) 
		{ keys->SetValue( SINEW(SIN::MemoryCellString(otv.first))); }
};


//-----------------------------------------------------------------


struct ClearTableFunctor : public std::unary_function <const SIN::Types::Object::ObjectTableValue &, void> {

	void operator() (const SIN::Types::Object::ObjectTableValue & otv) {
		if (otv.second != static_cast<SIN::MemoryCell *>(0)) {
			if(otv.second->Type() == SIN::MemoryCell::OBJECT_MCT){
				SIN::MemoryCellObject* obj = &static_cast<SIN::MemoryCellObject &>(*otv.second);

				//An to exoume 3anadei simenei oti eixame kuklo kai to exoume idi kanei delete
				if ( !obj->GetValue()->IsMarckedForDeletion() ) {
					obj->GetValue()->MarkForDeletion();	
					SINDELETE(obj); 
				}
			}
			else
				SINDELETE(otv.second); 
		}
	}
};


//-----------------------------------------------------------------

struct CopyTableFunctor : public std::unary_function <const SIN::Types::Object::ObjectTableValue &, void> {
	SIN::Types::Object::ObjectTable & table;

	CopyTableFunctor(SIN::Types::Object::ObjectTable & ot) : table(ot){}

	void operator() (const SIN::Types::Object::ObjectTableValue& otv) const {
		std::pair<SIN::Types::Object::ObjectTable::iterator, bool> ins_pair = 
			table.insert(SIN::Types::Object::ObjectTableValue(otv.first, 0x00));
		SINASSERT(ins_pair.second);
		SIN::MemoryCell::Assign(ins_pair.first->second, otv.second->Clone());
	}
};




namespace SIN {
	
	namespace Types {

		///--------------------		Object		---------------------------///

		///--------------------------------------------------
		///	private methods
		
		Object::Object(const Object & obj)  : marckedForDeletion(false), rc(0), id(ObjectFactory::NextID()), index(0)  
			{ std::for_each(obj.table.begin(), obj.table.end(), CopyTableFunctor(this->table)); }
		
		
		
		//-----------------------------------------------------------------

		const String Object::ToString(std::set<unsigned> & parentsId) const {
			
			String str;
			str << "Object(" << id << ")[";
			parentsId.insert(id);
			
			for (ObjectTable::const_iterator i = table.begin(); i != table.end(); ++i) {
				str << i->first << ":";
				MemoryCell* element = i->second;
				if (element->Type() == MemoryCell::OBJECT_MCT) {
					Object* obj = static_cast<MemoryCellObject*>(element)->GetValue();
					unsigned int id = obj->ID();
					if (parentsId.find(id) == parentsId.end()) {
						str << obj->ToString(parentsId);
						parentsId.insert(id);
					}
					else
						str << "self (object(" << id << "))";
				}
				else
					str << element->ToString();
				str << ", ";
			}
			
			str << ']';
			return str;
		}


		///--------------------------------------------------
		///	public methods
		
		//-----------------------------------------------------------------
		//constructors
		Object::Object(void) : marckedForDeletion(false), rc(0), id(ObjectFactory::NextID()), index(0), table() {}

		//-----------------------------------------------------------------
		//destructors
		Object::~Object(void) {
			SINASSERT(rc == 0 && marckedForDeletion);
			for_each(table.begin(), table.end(), ClearTableFunctor());
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
		
		void Object::MarkForDeletion(void)
			{ marckedForDeletion = true;}



		//-----------------------------------------------------------------
		
		bool Object::IsMarckedForDeletion(void) const
			{ return marckedForDeletion; }


		//-----------------------------------------------------------------

		namespace {
			MemoryCell* const P_not_found_value = 0x00;
			static InstanceProxy<MemoryCell> P_not_found(P_not_found_value);
		}
		InstanceProxy<MemoryCell>& Object::GetValue (const String & key) {
			SINASSERT(static_cast<MemoryCell*>(P_not_found) == P_not_found_value);
			ObjectTable::iterator result = table.find(key);
			return result != table.end() ? result->second : P_not_found;
		}


		//-----------------------------------------------------------------
		Object * Object::ObjectKeys(void) const 
			{ return std::for_each(table.begin(), table.end(), TableKeyFunctor(SINEW(Object))).keys; }


		//-----------------------------------------------------------------

		Object * Object::Clone(void) const 
			{ return SINEWCLASS(Object, (*this)); }
		
		
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

		bool Object::operator== (const Boolean_t & n) const 
			{ return n; }

		//-----------------------------------------------------------------

		bool Object::operator== (const String_t & str) const 
			{ return false; }

		//-----------------------------------------------------------------

		bool Object::operator== (const Number_t num) const 
			{ return false; }

		//-----------------------------------------------------------------
		
		bool Object::operator== (const Object_t & obj) const 
			{ return id == obj->ID(); }

		//-----------------------------------------------------------------

		bool Object::operator== (const Function_t & n) const 
			{ return false; }

		//-----------------------------------------------------------------

		bool Object::operator== (const Metacode_t & n) const 
			{ return false; }

		//-----------------------------------------------------------------

		bool Object::operator== (const LibraryFunction_t & n) const 
			{ return false; }

		//-----------------------------------------------------------------

		bool Object::operator!= (const Nil_t & n) const 
			{ return false; }

		//-----------------------------------------------------------------

		bool Object::operator!= (const Boolean_t & n) const 
			{ return !n; }

		//-----------------------------------------------------------------

		bool Object::operator!= (const String_t & str) const 
			{ return false; }

		//-----------------------------------------------------------------

		bool Object::operator!= (const Number_t num) const 
			{ return false; }

		//-----------------------------------------------------------------
		
		bool Object::operator!= (const Object_t & obj) const 
			{ return id != obj->ID(); }

		//-----------------------------------------------------------------

		bool Object::operator!= (const Function_t & n) const 
			{ return false; }

		//-----------------------------------------------------------------

		bool Object::operator!= (const Metacode_t & n) const 
			{ return false; }

		//-----------------------------------------------------------------

		bool Object::operator!= (const LibraryFunction_t & n) const 
			{ return false; }




		///--------------------		ObjectFactory	---------------------------///


		//---------------------------------------------------

		ObjectFactory::ObjectFactory(void): next_id(0) {}

		
		//---------------------------------------------------
		ObjectFactory::~ObjectFactory(void) {}
		
		
		//---------------------------------------------------
		// singleton related
		ObjectFactory* ObjectFactory::singleton = 0;
		
		
		//---------------------------------------------------
		
		bool ObjectFactory::singleton_created = false;
		
		
		//---------------------------------------------------
		
		void ObjectFactory::SingletonCreate(void) {
			SINASSERT(!singleton_created);
			if ((singleton = SINEW(ObjectFactory)) != 0)
				singleton_created = true;
		}
		
		
		//---------------------------------------------------
		
		bool ObjectFactory::SingletonCreated(void) {
			return singleton_created;
		}
		
		
		//---------------------------------------------------

		void ObjectFactory::SingletonDestroy(void) {
			SINASSERT(singleton_created);
			SINDELETE(singleton);
			singleton_created = false;
		}
		
		
		//---------------------------------------------------

		ObjectFactory& ObjectFactory::SingletonInstance(void) {
			SINASSERT(singleton_created);
			return *(singleton_created ? singleton : 0);
		}
		
		
		//---------------------------------------------------
		// convenience methods	
		
		//---------------------------------------------------
		unsigned const ObjectFactory::NextID(void) 
			{ return SingletonInstance().InstanceNextID(); }
		

		//---------------------------------------------------
		// instance factory methods

		//---------------------------------------------------
		unsigned const ObjectFactory::InstanceNextID(void) 
			{ return next_id++; }
	}	//namespace Types


	//-----------------------------------------------------------------
	
	String const to_string(SIN::Types::Object const & val) 
		{ return val.ToString(); }
	

	//-----------------------------------------------------------------
	
	String const to_string(SIN::Types::Object const * val) 
		{ return val->ToString(); }

}	//namespace SIN
