#ifndef __SIN_RUN_TIME_ERRORS_H__
#define __SIN_RUN_TIME_ERRORS_H__


#include "SINString.h"

namespace SIN {
	
	class RunTimeError {
	public:
		

		RunTimeError(void);
		RunTimeError(const String msg, const String & _file, const int & _line);
		RunTimeError(const RunTimeError &);

		virtual ~RunTimeError();
		
		virtual int		GetLine(void) const;
		virtual String	GetFile(void) const;
		virtual String	GetMessage(void) const;
		virtual String	CompleteMessage(void) const;

		virtual void	SetLine(const int & _line);
		virtual void	SetFile(const String & _file);
		virtual void	SetMessage(const String & msg);

	protected:
		int		line;
		String	file;
		String	message;
		
	};
	
}	//namespace SIN


#endif //__SIN_RUN_TIME_ERRORS_H__