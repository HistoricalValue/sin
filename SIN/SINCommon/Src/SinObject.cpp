
#include <algorithm>
#include <functional>


#include "SINAlloc.h"
#include "SINObject.h"
#include "SINAssert.h"
//include "SINMemoryCell.h
//#include "SINMemoryCellAST.h"
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




namespace SIN {
	


	///--------------------		SinObject		---------------------------///



	///--------------------------------------------------
	///	static functions and functors

	//-----------------------------------------------------------------
	
	struct TableKeyFunctor : public std::unary_function<const SinObject::ObjectTableValue &, void> {
		SinObject::ObjectKeysList keys;	
		void operator() (const SinObject::ObjectTableValue & otv) 
			{ keys.push_back(otv.first); }
	};




	///--------------------------------------------------
	///	private methods



	///--------------------------------------------------
	///	public methods
	
	//-----------------------------------------------------------------
	//constructors
	SinObject::SinObject() : id(SinObjectFactory::NextID()), index(0) {}
	


	//-----------------------------------------------------------------
	//destructors
	SinObject::~SinObject() {}



	//-----------------------------------------------------------------

	unsigned SinObject::ID() const 
		{ return id; }



	//-----------------------------------------------------------------

	bool SinObject::CanCollecte (void) const 
		{ return rc == 0 ? true: false; }

	
	//-----------------------------------------------------------------

	unsigned SinObject::ReferenceCounter (void) const 
		{ return rc; }
	
	
	//-----------------------------------------------------------------

	void SinObject::IncrementReferenceCounter (void)
		{ ++rc;}
	

	//-----------------------------------------------------------------

	void SinObject::DecrementReferenceCounter	(void) { 
		SINASSERT(rc > 0);
		--rc;
	}



	//-----------------------------------------------------------------
	
	void SinObject::SetValue(MemoryCell * value) 
		{ table[String() << index++] = value; }


	//-----------------------------------------------------------------

	void SinObject::SetValue (const String & key, MemoryCell * value) 
		{ table[key] = value; }


	//-----------------------------------------------------------------

	void SinObject::SetValue (const ObjectTableValue & otv) 
		{ SetValue(otv.first, otv.second); }
	
	
	//-----------------------------------------------------------------

	MemoryCell * SinObject::GetValue (const String & key) const {
		ObjectTable::const_iterator result = table.find(key);
		return result != table.end() ? result->second : static_cast<MemoryCell *>(0);
	}


	//-----------------------------------------------------------------
	SinObject::ObjectKeysList SinObject::ObjectKeys(void) const {
		TableKeyFunctor keys = std::for_each(table.begin(), table.end(), TableKeyFunctor());		
		return ObjectKeysList(keys.keys);
	}


	//-----------------------------------------------------------------
	unsigned SinObject::ObjectSize(void) const  
		{ return table.size(); }


	//-----------------------------------------------------------------

	const String SinObject::ToString(void) const {
		
		String str = String() << "Object (" << id << "){";
		
		for (ObjectTable::const_iterator i = table.begin(); i != table.end(); ++i)
			switch(i->second->Type()) {
				case MemoryCell::BOOL_MCT		: TO_STRING_APPEND(MemoryCellBool);
				case MemoryCell::STRING_MCT		: TO_STRING_APPEND(MemoryCellString);
				case MemoryCell::NUMBER_MCT		: TO_STRING_APPEND(MemoryCellNumber);
				//case MemoryCell::AST_MCT		: APPEND_TO_STR();
				case MemoryCell::OBJECT_MCT		:  {				
					SinObject obj = static_cast<MemoryCellObject *>(i->second)->GetValue();	
					id == obj.ID() ? str << i->first << ": self" : str << i->first << ":" << obj;
					break;
				}
				//case MemoryCell::FUNCTION_MCT	: APPEND_TO_STR();
				default: SINASSERT(0);
			}
		
		str << "}";
		return String(str);
	}


	//-----------------------------------------------------------------

	bool SinObject::operator== (const Nil_t & n) const 
		{ return false; }
	
	
	//-----------------------------------------------------------------

	bool SinObject::operator!= (const Nil_t & n) const 
		{ return true; }
	

	//-----------------------------------------------------------------

	bool SinObject::operator== (const String & str) const 
		{ return false; }


	//-----------------------------------------------------------------
	
	bool SinObject::operator!= (const String & str) const 
		{ return true; }
	

	//-----------------------------------------------------------------

	bool SinObject::operator== (const Number num) const 
		{ return false; }
	

	//-----------------------------------------------------------------

	bool SinObject::operator!= (const Number num) const 
		{ return true; }
	

	//-----------------------------------------------------------------
	
	bool SinObject::operator== (const SinObject & obj) const 
		{ return id == obj.ID(); }


	//-----------------------------------------------------------------
	
	bool SinObject::operator!= (const SinObject & obj) const 
		{ return id != obj.ID(); }



	//-----------------------------------------------------------------
	
	String const string_cast(SIN::SinObject const & val) 
		{ return val.ToString(); }
	






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