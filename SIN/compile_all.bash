#!/bin/bash
g++ -pedantic -Wall -ansi -O0 -g -Wl,--export-dynamic -o sin `find . -name Include -print0 | xargs -0 ruby   -e 'print ARGV.map{|s|"-I#{s}"}.join(" ")' ` `find . -name '*.cpp' -print0 | xargs -0 ruby -e 'puts(ARGV.map{|s|"#{s}"}.join(" "))'`
