#ifndef __SIN_VM_VIRTUALMACHINE_H__
#define __SIN_VM_VIRTUALMACHINE_H__

#include "SINMemoryCell.h"
#include "SINMemoryCellNil.h"
#include "SINMemoryCellString.h"

namespace SIN {
	namespace VM {
		class VirtualMachine {
		public:
			typedef void (*print_handler_t)(String const&);
			void SetPrintHandler(print_handler_t _h) { print_handler = _h; }
			print_handler_t GetPrintHandler(void) const { return print_handler; }
			void Print(String const& _msg) { (*print_handler)(_msg); }

			MemoryCell* ReturnValue(void) const { return retval; }
			void ReturnValueNil(void) { retval = &nil; }
			void ReturnValueString(String const& _s) { str = _s; }

		private:
			print_handler_t print_handler;
			MemoryCell* retval;
			MemoryCellNil nil;
			MemoryCellString str;
		}; // class VirtualMachine
	} // namespace VM
} // namespace SIN

#endif // __SIN_VM_VIRTUALMACHINE_H__
