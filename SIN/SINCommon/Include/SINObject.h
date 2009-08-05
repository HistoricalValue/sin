#ifndef __SIN_OBJECT_H__
#define __SIN_OBJECT_H__


#include <map>
#include <set>
#include <list>
#include <utility>

#include "SINTypes.h"
#include "SINString.h"
#include "SINMemoryCell.h"

namespace SIN {

	namespace Types {

		class Object {
		public:
			typedef std::list<String>				ObjectKeysList;
			typedef std::map<String, MemoryCell *>	ObjectTable;
			typedef std::pair<String, MemoryCell *> ObjectTableValue;

			//Constructors
			Object();
			//Object(const Object &);

			//destructor
			~Object();

			unsigned		ID() const;
			bool			IsUnreferenced(void) const;
			unsigned		ReferenceCounter(void) const;
			void			IncrementReferenceCounter(void);
			void			DecrementReferenceCounter(void);


			void			SetValue(MemoryCell *);
			void			SetValue(const ObjectTableValue &);
			void			SetValue(const String &, MemoryCell *);		
			MemoryCell*		GetValue(const String &) const;
			
			void			MarckedForDeletion(void);
			bool			IsMarckedForDeletion(void) const;
			
			//e.g. a.#keys and a.#size 
			//create a new object with new. Caller is responsible to delete the new object
			Object *		ObjectKeys(void) const;
			unsigned		NumberOfElements (void) const;
			const String	ToString(void) const;


			bool operator== (const Nil_t &) const;	
			bool operator!= (const Nil_t &) const;	

			bool operator== (const String &) const;	
			bool operator!= (const String &) const;	

			bool operator== (const Number) const;		
			bool operator!= (const Number) const;		

			bool operator== (const Object &) const;
			bool operator!= (const Object &) const;

		private:
			bool		marckedForDeletion;
			unsigned	rc;		//The reference counter of the object
			unsigned	id;		//The signle id of the object
			unsigned	index;	//Current arithemtic index for the next key
			ObjectTable table;

			const String ToString(std::set<unsigned> &) const;
			//const String 
		};


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
			unsigned			next_id;

			SinObjectFactory(void);
			~SinObjectFactory(void);

			static SinObjectFactory *	singleton;
			static bool					singleton_created;
		}; // class SinObjectFactory
	}	//namespace Types
	extern String const to_string(SIN::Types::Object const * val);
	extern String const to_string(SIN::Types::Object const & val);

}	//namespace SIN


#endif //__SIN_OBJECT_H__