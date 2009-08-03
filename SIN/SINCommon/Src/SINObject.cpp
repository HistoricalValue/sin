
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

#define TO_STRING_APPEND_OBJECT()	{const SINObject * obj = static_cast<MemoryCellObject *>(i->second)->GetValue();		\
									if (parentsId.find(obj->ID()) !=  parentsId.end())						\
										str << i->first << ":self-->Object(" << obj->ID() << ")<--";					\
									else																				\
										str << i->first << ":" << obj->ToString(parentsId);								\
										break;}



namespace SIN {
	


	///--------------------		SINObject		---------------------------///



	///--------------------------------------------------
	///	static functions and functors

	//-----------------------------------------------------------------
	
	struct TableKeyFunctor : public std::unary_function<const SINObject::ObjectTableValue &, void> {
		SINObject * keys;
		TableKeyFunctor(SINObject * obj) : keys(obj){}
		void operator() (const SINObject::ObjectTableValue & otv) 
			{ keys->SetValue( SINEW(MemoryCellString(otv.first))); }
	};


	struct CleanTableFunctor : public std::unary_function <const SINObject::ObjectTableValue &, void> {
		std::set<unsigned> objectsId;
		void operator() (const SINObject::ObjectTableValue & otv) {
			
			if (otv.second != static_cast<MemoryCell *>(0)) {
				if(otv.second->Type() == MemoryCell::OBJECT_MCT){
					MemoryCellObject * obj = static_cast<MemoryCellObject *>(otv.second);
					//An to exoume 3anadei simenei oti eixame kuklo kai to exoume idi kanei delete
					if (objectsId.find(obj->GetValue()->ID()) == objectsId.end()) {
						objectsId.insert(obj->GetValue()->ID());
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

	const String SINObject::ToString(std::set<unsigned> & parentsId) const {
		
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
	SINObject::SINObject() : id(SinObjectFactory::NextID()), index(0), rc(0) {}
	


	//-----------------------------------------------------------------
	//destructors
	SINObject::~SINObject() { 
		SINASSERT(rc == 0);
		for_each(table.begin(), table.end(), CleanTableFunctor());
		table.clear();
	}



	//-----------------------------------------------------------------

	unsigned SINObject::ID() const 
		{ return id; }



	//-----------------------------------------------------------------

	bool SINObject::IsUnreferenced (void) const 
		{ return rc == 0 ? true: false; }

	
	//-----------------------------------------------------------------

	unsigned SINObject::ReferenceCounter (void) const 
		{ return rc; }
	
	
	//-----------------------------------------------------------------

	void SINObject::IncrementReferenceCounter (void)
		{ ++rc;}
	

	//-----------------------------------------------------------------

	void SINObject::DecrementReferenceCounter (void) { 
		SINASSERT(rc > 0);
		--rc;
	}



	//-----------------------------------------------------------------
	
	void SINObject::SetValue(MemoryCell * value) { 
		String key = string_cast(index++);

		while(table.find(key) != table.end())
			{ key = string_cast(index++); }
		table[key] = value; 
	}


	//-----------------------------------------------------------------

	void SINObject::SetValue (const String & key, MemoryCell * value) 
		{ table[key] = value; }


	//-----------------------------------------------------------------

	void SINObject::SetValue (const ObjectTableValue & otv) 
		{ SetValue(otv.first, otv.second); }
	
	
	//-----------------------------------------------------------------

	MemoryCell * SINObject::GetValue (const String & key) const {
		ObjectTable::const_iterator result = table.find(key);
		return result != table.end() ? result->second : static_cast<MemoryCell *>(0);
	}


	//-----------------------------------------------------------------
	SINObject *	 SINObject::ObjectKeys(void) const 
		{ return std::for_each(table.begin(), table.end(), TableKeyFunctor(SINEW(SINObject))).keys; }


	//-----------------------------------------------------------------
	unsigned SINObject::NumberOfElements (void) const  
		{ return table.size(); }


	//-----------------------------------------------------------------

	const String SINObject::ToString(void) const {
		return ToString(std::set<unsigned>()); //If we wont to eleminat the last ',' we must do this: Erase(1, str_size - 3);
	}


	//-----------------------------------------------------------------

	bool SINObject::operator== (const Nil_t & n) const 
		{ return false; }
	
	
	//-----------------------------------------------------------------

	bool SINObject::operator!= (const Nil_t & n) const 
		{ return true; }
	

	//-----------------------------------------------------------------

	bool SINObject::operator== (const String & str) const 
		{ return false; }


	//-----------------------------------------------------------------
	
	bool SINObject::operator!= (const String & str) const 
		{ return true; }
	

	//-----------------------------------------------------------------

	bool SINObject::operator== (const Number num) const 
		{ return false; }
	

	//-----------------------------------------------------------------

	bool SINObject::operator!= (const Number num) const 
		{ return true; }
	

	//-----------------------------------------------------------------
	
	bool SINObject::operator== (const SINObject & obj) const 
		{ return id == obj.ID(); }


	//-----------------------------------------------------------------
	
	bool SINObject::operator!= (const SINObject & obj) const 
		{ return id != obj.ID(); }



	//-----------------------------------------------------------------
	
	String const string_cast(SIN::SINObject const & val) 
		{ return val.ToString(); }
	

	//-----------------------------------------------------------------
	
	String const string_cast(SIN::SINObject const * val) 
		{ return val->ToString(); }




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

}