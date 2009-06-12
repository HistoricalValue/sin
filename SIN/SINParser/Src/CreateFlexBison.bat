del SINParser.cpp
del SINLexAnalyser.cpp
del ..\Include\SINParser.h
flex -L -oSINLexAnalyser.cpp SINLexAnalyser.l
bison -l -y --defines=..\Include\SINParser.h -o.\SINParser.cpp SINParser.y
pause;
