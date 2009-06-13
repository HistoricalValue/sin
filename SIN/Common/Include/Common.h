#ifndef __SIN_COMMON_H__
#define __SIN_COMMON_H__

#include <string>
#include <sstream>


namespace SIN {


	template<class T>
	std::string string_cast(const T a){
		std::ostringstream os;
		os<<a;
		return os.str();
	}



}	//end of template

#endif __SIN_COMMON_H__