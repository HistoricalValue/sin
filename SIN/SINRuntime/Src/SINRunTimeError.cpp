#include "SINRunTimeError.h"

#include "SINAssert.h"



namespace SIN {

	//-----------------------------------------------------------------

	RunTimeError::RunTimeError(void) : line(-1), file(""), message("") {}

	//-----------------------------------------------------------------

	RunTimeError::RunTimeError(const String msg, const String & _file, const int & _line) :
		line(_line),
		file(_file),
		message(msg)
	{}

	//-----------------------------------------------------------------

	RunTimeError::RunTimeError(const RunTimeError & o) :
		line(o.line),
		file(o.file),
		message(o.message)
	{}

	//-----------------------------------------------------------------
	
	RunTimeError::~RunTimeError() {}
	
	//-----------------------------------------------------------------	
	
	int	RunTimeError::GetLine(void) const {	
		SINASSERT(line > 0);
		return line;	
	}

	//-----------------------------------------------------------------

	String RunTimeError::GetFile(void) const {
		SINASSERT(file.Length() != 0);
		return file;
	}
	
	//-----------------------------------------------------------------

	String RunTimeError::GetMessage(void) const {
		SINASSERT(message.Length() > 0);
		return message;
	}
	
	//-----------------------------------------------------------------

	String RunTimeError::CompleteMessage(void) const {
		return	to_string("Run Time Error: ")	+ 
				GetMessage()					+ 
				to_string("\nAt line: ")		+
				to_string(GetLine())			+
				to_string(" In file:")			+
				GetFile();
	}

	//-----------------------------------------------------------------
	
	void RunTimeError::SetLine(const int & _line) {
		SINASSERT(_line > 0);
		line = _line;
	}
	
	//-----------------------------------------------------------------

	void RunTimeError::SetFile(const String & _file) {
		SINASSERT(_file.Length() > 0);
		file = _file;
	}

	//-----------------------------------------------------------------

	void RunTimeError::SetMessage(const String & msg) {
		SINASSERT(msg.Length() > 0);
		message = msg;
	}
}	//namespace SIN