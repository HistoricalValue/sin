del SINParserBison.cpp
del SINLexAnalyzer.cpp
del ..\Include\SINParserBison.h
flex -L -oSINLexAnalyzer.cpp SINLexAnalyzer.l
bison -l -y --defines=..\Include\SINParserBison.h -o.\SINParserBison.cpp SINParser.y -v
pause;
