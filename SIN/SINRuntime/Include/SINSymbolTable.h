#ifndef __SIN_SYMBOL_TABLE_H__
#define __SIN_SYMBOL_TABLE_H__

#include <map>
#include <list>
#include <utility>
#include "SINString.h"
#include "SINMemoryCell.h"


#include "SINMemoryCellAST.h"
#include "SINMemoryCellBool.h"
#include "SINMemoryCellFunction.h"
#include "SINMemoryCellNil.h"
#include "SINMemoryCellNumber.h"
#include "SINMemoryCellObject.h"
#include "SINMemoryCellString.h"


namespace SIN {
	class SymbolTable {
	public:	
		typedef std::pair<const String, MemoryCell *> SymbolTableValue;

		SymbolTable(void);
		~SymbolTable();

		void	SetArgument		(const String &, MemoryCell *);
		void	SetArgument		(const SymbolTableValue &);
		void	SetArguments	(const std::list<SymbolTableValue> &);
		
		
		void	SetLocal		(const String &, MemoryCell *);
		void	SetLocal		(const SymbolTableValue &);
		void	SetLocals		(const std::list<SymbolTableValue> &);


		const MemoryCell *	LookupLocal		(const String &) const ;
		MemoryCell *		LookupLocal		(const String &);

		const MemoryCell *	LookupArgument	(const String &) const;
		MemoryCell *		LookupArgument	(const String &);

	private:
		typedef std::map<String, MemoryCell *> MemoryMap;

		MemoryMap locals;
		MemoryMap arguments;

	};

}	//namespace SIN

#endif //__SIN_SYMBOL_TABLE_H__