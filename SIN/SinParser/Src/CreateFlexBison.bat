flex -L -oSinLexAnalyser.cpp SinLexAnalyser.l
bison -l -y --defines=..\Include\SinParser.hpp -o.\SinParser.cpp SinParser.y
pause;
