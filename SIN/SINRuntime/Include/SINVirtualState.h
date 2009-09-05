#ifndef __SIN_VM_VIRTUALMACHINE_H__
#define __SIN_VM_VIRTUALMACHINE_H__

#include "SINMemoryCell.h"
#include "SINMemoryCellNil.h"
#include "SINMemoryCellString.h"
#include "SINMemoryCellNumber.h"
#include "SINMemoryCellObject.h"
#include "SINMemoryCellNativeResource.h"
#include "SINObject.h"
#include <list>
#include <deque>
#include "SINFunction.h"
#include "SINEnvironment.h"
#include "SINAlloc.h"

#ifdef _DEBUG
#define INVAR SINASSERT(curr_frame >= 0u); SINASSERT(curr_frame < stack.size());
#else
#define INVAR
#endif // _DEBUG

namespace SIN {
	namespace VM {
		class VirtualState {
		public:
			typedef void (*print_handler_t)(String const&);
			void SetPrintHandler(print_handler_t _h) { print_handler = _h; }
			print_handler_t GetPrintHandler(void) const { return print_handler; }
			void Print(String const& _msg) { (*print_handler)(_msg); }

			void ReturnValue(MemoryCell* value);
			void  ReturnValueNil(void) { ReturnValue(SINEW(MemoryCellNil)); }
			void  ReturnValueString(Types::String_t const& _s) { ReturnValue(SINEWCLASS(MemoryCellString, (_s))); }
			void  ReturnValueNumber(Types::Number_t const& _num) { ReturnValue(SINEWCLASS(MemoryCellNumber, (_num))); }
			void  ReturnValueObject(Types::Object_t const& _obj_inst) { ReturnValue(SINEWCLASS(MemoryCellObject, (_obj_inst))); }
			void  ReturnValueResource(MemoryCellNativeResource* const& _r) { ReturnValue(_r); }

			struct Error {
				String const message;
				char const* file;
				unsigned int line;
				Error(String const& _message, char const* _file, unsigned int _line):
					message(_message), file(_file), line(_line) { }
			};

			struct Frame {
				Environment env;
				Frame(void): env() { }
				Frame(Frame const& _o): env(_o.env) { }
				~Frame(void) { }
			};

			typedef std::list<Error> errors_t;
			void AppendError(String const& _message, char const* _file, unsigned int _line);
			errors_t const& Errors(void) const { return errors; }
			bool HasError(void) const { return errors.size() > 0; }

			void PushState(void) {INVAR
				SINASSERT(curr_frame == stack.size() - 1);
				stack.push_back(Frame());
				++curr_frame;
			INVAR}
			void RestoreState(void) {INVAR
				SINASSERT(curr_frame == stack.size() - 1);
				stack.pop_back();
				--curr_frame;
			INVAR}
			Frame& CurrentFrame(void) {INVAR return stack.at(curr_frame); }
			VirtualState& Down(void) {INVAR SINASSERT(curr_frame > 0u); --curr_frame; INVAR return *this; }
			VirtualState& Up(void) {INVAR SINASSERT(curr_frame < stack.size() - 1); ++curr_frame; INVAR return *this; }
			VirtualState& Top(void) {INVAR curr_frame = stack.size() - 1; INVAR return *this; }
			bool InCall(void) {INVAR return curr_frame > 0; }

			Frame& BaseFrame(void) {INVAR return *base_frame; }

			// Convenience
			Environment& CurrentEnvironment(void) { return CurrentFrame().env; }
			SymbolTable& CurrentStable(void) { return CurrentFrame().env.stable; }
			Namer& CurrentAvrilNamer(void) { return CurrentFrame().env.avrilNamer; }
			Environment& BaseEnvironment(void) { return BaseFrame().env; }
			SymbolTable& BaseStable(void) { return BaseFrame().env.stable; }
			Namer& BaseAvrilNamer(void) { return BaseFrame().env.avrilNamer; }

			VirtualState(void): print_handler(0x00),
				stack(1, Frame()), curr_frame(0u), errors(), base_frame(0x00)
			{
				base_frame = &stack.front();
			}
			~VirtualState(void) { }
		private:
			print_handler_t print_handler;

			//typedef std::deque<Frame> stack_t;
			// Debugging
			struct stack_t: public std::deque<Frame> {
				stack_t(size_type _how_many = 0, Frame const& _stuff = Frame()): std::deque<Frame>(_how_many, _stuff) { }
				~stack_t(void) { }
			}; // struct stack_t
			stack_t stack;
			stack_t::size_type curr_frame;
			errors_t errors;
			Frame* base_frame;

			// Unusable
			VirtualState(VirtualState const&);
		}; // class VirtualMachine
	} // namespace VM
} // namespace SIN

#endif // __SIN_VM_VIRTUALMACHINE_H__
