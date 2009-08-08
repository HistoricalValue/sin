#!/bin/bash

find . \( -iname '*.h' -o -iname '*.cpp' \) \! -iname 'SINParserBison.*' \! -iname 'SINLexAnalyzer.*' -print0 | xargs -0 wc -l | sort -rn |less 
