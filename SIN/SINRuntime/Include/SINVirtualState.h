#ifndef __SIN_VM_VIRTUALMACHINE_H__
#define __SIN_VM_VIRTUALMACHINE_H__

#include "SINMemoryCell.h"
#include "SINMemoryCellNil.h"
#include "SINMemoryCellString.h"
#include "SINMemoryCellNumber.h"
#include <list>
#include <stack>
#include "SINFunction.h"

namespace SIN {
	namespace VM {
		class VirtualState {
		public:
			typedef void (*print_handler_t)(String const&);
			void SetPrintHandler(print_handler_t _h) { print_handler = _h; }
			print_handler_t GetPrintHandler(void) const { return print_handler; }
			void Print(String const& _msg) { (*print_handler)(_msg); }

			MemoryCell* ReturnValue(void) const { return retval; }
			void ReturnValueNil(void) { retval = &nil; }
			void ReturnValueString(String const& _s) { str.SetValue(_s); retval = &str; }
			void ReturnValueNumber(SIN::Types::Number_t const& _num) { num.SetValue(_num); retval = &num; }

			struct Error {
				String const message;
				char const* file;
				unsigned int line;
				Error(String const& _message, char const* _file, unsigned int _line):
					message(_message), file(_file), line(_line) { }
			};

			struct Frame {
				SIN::Types::Function_t& f;
				SymbolTable st;
				SymbolTable* previous_environment;
				Frame(Types::Function_t& _f, SymbolTable* _pe): f(_f), previous_environment(_pe) { }
			};

			typedef std::list<Error> errors_t;
			void AppendError(String const& _message, char const* _file, unsigned int _line)
				{ errors.push_back(Error(_message, _file, _line)); }
			errors_t const& Errors(void) const { return errors; }
			bool HasError(void) const { return errors.size() > 0; }

			typedef std::stack<Frame> stack_t;
			void PushFrame(Types::Function_t* _f_p, SymbolTable* _previous_environment) { stack.push(Frame(*_f_p, _previous_environment)); }
			void PopFrame(void) { stack.pop(); }
			stack_t const& Stack(void) const { return stack; }
		private:
			print_handler_t print_handler;
			MemoryCell* retval;
			MemoryCellNil nil;
			MemoryCellString str;
			MemoryCellNumber num;

			stack_t stack;
			errors_t errors;
		}; // class VirtualMachine
	} // namespace VM
} // namespace SIN

#endif // __SIN_VM_VIRTUALMACHINE_H__
