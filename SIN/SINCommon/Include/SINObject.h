#ifndef __SIN_OBJECT_H__
#define __SIN_OBJECT_H__


#include <map>
#include <list>
#include <utility>

#include "SINTypes.h"
#include "SINString.h"
#include "SINMemoryCell.h"

namespace SIN {
	class SinObject {
	public:
		typedef std::list<String>				ObjectKeysList;
		typedef std::map<String, MemoryCell *>	ObjectTable;
		typedef std::pair<String, MemoryCell *> ObjectTableValue;

		//Constructors
		SinObject();
		//SinObject(const SinObject &);

		//destructor
		~SinObject();

		unsigned		ID() const;
		bool			CanCollecte(void) const;
		unsigned		ReferenceCounter(void) const;
		void			IncrementReferenceCounter(void);
		void			DecrementReferenceCounter(void);


		void			SetValue(MemoryCell *);
		void			SetValue(const ObjectTableValue &);
		void			SetValue(const String &, MemoryCell *);		
		MemoryCell*		GetValue(const String &) const;
		

		//e.g. a.#keys and a.#size 
		ObjectKeysList	ObjectKeys(void) const;
		unsigned		ObjectSize(void) const;
		const String	ToString(void) const;


		bool operator== (const Nil_t &) const;	
		bool operator!= (const Nil_t &) const;	

		bool operator== (const String &) const;	
		bool operator!= (const String &) const;	

		bool operator== (const Number) const;		
		bool operator!= (const Number) const;		

		bool operator== (const SinObject &) const;
		bool operator!= (const SinObject &) const;

	private:
		unsigned	rc;		//The reference counter of the object
		unsigned	id;		//The signle id of the object
		unsigned	index;	
		ObjectTable table;
	};
	extern String const string_cast(SIN::SinObject const & val);




	//////////////////////////////////////////////////////////////////////////////

	class SinObjectFactory {
	public:
		static void					SingletonCreate(void);
		static bool					SingletonCreated(void);
		static void					SingletonDestroy(void);
		static SinObjectFactory&	SingletonInstance(void);

		static const unsigned		NextID(void);
		const unsigned				InstanceNextID(void);
	
	private:
		unsigned next_id;

		SinObjectFactory(void);
		~SinObjectFactory(void);

		static SinObjectFactory *	singleton;
		static bool					singleton_created;

	}; // class SinObjectFactory

}


#endif //__SIN_OBJECT_H__