#ifndef __SIN_VM_VIRTUALMACHINE_H__
#define __SIN_VM_VIRTUALMACHINE_H__

#include "SINMemoryCell.h"
#include "SINMemoryCellNil.h"
#include "SINMemoryCellString.h"
#include "SINMemoryCellNumber.h"
#include "SINMemoryCellObject.h"
#include "SINObject.h"
#include <list>
#include <deque>
#include "SINFunction.h"


#define INVAR SINASSERT(curr_frame >= 0u); SINASSERT(curr_frame < stack.size());

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

			typedef std::deque<Frame> stack_t;
			void PushFrame(Types::Function_t* _f_p, SymbolTable* _previous_environment) {INVAR
				SINASSERT(curr_frame == stack.size() - 1);
				stack.push_back(Frame(*_f_p, _previous_environment));
				++curr_frame;
			INVAR}
			void PopFrame(void) {INVAR
				SINASSERT(curr_frame == stack.size() - 1);
				stack.pop_back();
				--curr_frame;
			INVAR}
			Frame& CurrentFrame(void) {INVAR return stack.at(curr_frame); }
			VirtualState& Down(void) {INVAR SINASSERT(curr_frame > 0u); --curr_frame; INVAR return *this; }
			VirtualState& Up(void) {INVAR SINASSERT(curr_frame < stack.size() - 1); ++curr_frame; INVAR return *this; }
			VirtualState& Top(void) {INVAR curr_frame = stack.size(); INVAR return *this; }
			bool InCall(void) {INVAR return !stack.empty(); }

			VirtualState(void): print_handler(0x00), retval(&nil), nil(), str(), num(), obj(&obj_inst), obj_inst(),
				stack(), curr_frame(0u), errors()
				{ }
		private:
			print_handler_t print_handler;
			MemoryCell* retval;
			MemoryCellNil nil;
			MemoryCellString str;
			MemoryCellNumber num;
			MemoryCellObject obj;
			Types::Object obj_inst;

			stack_t stack;
			stack_t::size_type curr_frame;
			errors_t errors;
		}; // class VirtualMachine
	} // namespace VM
} // namespace SIN

#endif // __SIN_VM_VIRTUALMACHINE_H__
