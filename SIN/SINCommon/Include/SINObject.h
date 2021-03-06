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
			typedef std::list<String> ObjectKeysList;
			typedef InstanceProxy<MemoryCell> memcell_t;
			typedef std::map<String, memcell_t> ObjectTable;
			typedef std::pair<String, memcell_t> ObjectTableValue;

			//Constructor
			Object(void);
			Object(Object const&);

			//destructor
			~Object(void);

			unsigned		ID() const;
			bool			IsUnreferenced(void) const;
			unsigned		ReferenceCounter(void) const;
			void			IncrementReferenceCounter(void);
			void			DecrementReferenceCounter(void);


			void			SetValue(MemoryCell *);
			void			SetValue(const ObjectTableValue &);
			void			SetValue(const String &, MemoryCell *);		
			memcell_t&		GetValue(const String &);
			bool			HasMember(const String &) const;
			bool			LookupFailed(memcell_t const& previous_result) const;
			void			UnsetValue(const String &);
			
			void			MarkForDeletion(void);
			bool			IsMarckedForDeletion(void) const;
			
			//e.g. a.#keys and a.#size 
			//create a new object with new. Caller is responsible to delete the new object
			Object *		ObjectKeys(void) const;
			Object *		Clone(void) const;
			unsigned		NumberOfElements (void) const;
			const String	ToString(void) const;



			bool operator== (const Nil_t &) const;	
			bool operator== (const Boolean_t &) const;
			bool operator== (const String_t &) const;	
			bool operator== (const Number_t) const;		
			bool operator== (const Object_t &) const;
			bool operator== (const Function_t &) const;
			bool operator== (const Metacode_t &) const;
			bool operator== (const LibraryFunction_t &) const;

			bool operator!= (const Nil_t &) const;	
			bool operator!= (const Boolean_t &) const;
			bool operator!= (const String_t &) const;	
			bool operator!= (const Number_t) const;		
			bool operator!= (const Object_t &) const;
			bool operator!= (const Function_t &) const;
			bool operator!= (const Metacode_t &) const;
			bool operator!= (const LibraryFunction_t &) const;

			

		private:
			bool		marckedForDeletion;
			unsigned	rc;		//The reference counter of the object
			unsigned	id;		//The signle id of the object
			unsigned	index;	//Current arithemtic index for the next key
			ObjectTable table;

			
			///////////////////////////////
			//	private method API
			const String ToString(std::set<unsigned> &) const;
		};


		//////////////////////////////////////////////////////////////////////////////

		class ObjectFactory {
		public:
			static void				SingletonCreate(void);
			static bool				SingletonCreated(void);
			static void				SingletonDestroy(void);
			static ObjectFactory&	SingletonInstance(void);

			static const unsigned	NextID(void);
			const unsigned			InstanceNextID(void);

		private:
			unsigned			next_id;

			ObjectFactory(void);
			~ObjectFactory(void);

			static ObjectFactory *	singleton;
			static bool					singleton_created;
		}; // class ObjectFactory
	}	//namespace Types
	extern String const to_string(SIN::Types::Object const * val);
	extern String const to_string(SIN::Types::Object const & val);

}	//namespace SIN


#endif //__SIN_OBJECT_H__
