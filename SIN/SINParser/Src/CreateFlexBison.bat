del SINParserBison.cpp
del SINLexAnalyser.cpp
del ..\Include\SINParserBison.h
flex -L -oSINLexAnalyser.cpp SINLexAnalyser.l
bison -l -y --defines=..\Include\SINParserBison.h -o.\SINParserBison.cpp SINParser.y
pause;
