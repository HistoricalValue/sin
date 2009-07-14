#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=

# Macros
PLATFORM=GNU-Linux-x86

# Include project Makefile
include GNUmakefile

# Object Directory
OBJECTDIR=build/Debug/${PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Common/Src/Common.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/BisonParseArguments.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINLoggerManager.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINParserBison.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINAST_Test/Src/SINAST_Tester.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINmain/Src/main.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINLogging_Test/Src/SINLoggingTester.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINString.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINStream.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINParserManage.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINInputStream.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINCommon.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINLexAnalyser.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINRecord.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINRuntime/Src/SINMemoryCell.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINCommon_Test/Src/SINCommonTester.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src/SINTestFactory.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINLogger.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINTreeNode.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src/SINTestCollection.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINNamer.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINOutputStream.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINASTMITTreeVisualizerXMLProducerVisitor.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src/SINTest.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SIN.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINFileOutputStream.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINRuntime/Src/SINSymbolTable.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINASTTreeVisualisationVisitor.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/ASTVisitor.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINParser_Test/Src/SINParserTester.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINParserAPI.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINSymbolTable_Test/Src/SINSymbolTableTester.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINRecordPrinter.o \
	${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINASTNode.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-pedantic -ansi -Wall -O0 -g
CXXFLAGS=-pedantic -ansi -Wall -O0 -g

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/${PLATFORM}/sin_netbeans

dist/Debug/${PLATFORM}/sin_netbeans: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/${PLATFORM}
	${LINK.cc} -o dist/Debug/${PLATFORM}/sin_netbeans ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Common/Src/Common.o: ../Common/Src/Common.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Common/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Common/Src/Common.o ../Common/Src/Common.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/BisonParseArguments.o: ../SINParser/Src/BisonParseArguments.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/BisonParseArguments.o ../SINParser/Src/BisonParseArguments.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINLoggerManager.o: ../SINLogging/Src/SINLoggerManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINLoggerManager.o ../SINLogging/Src/SINLoggerManager.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINParserBison.o: ../SINParser/Src/SINParserBison.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINParserBison.o ../SINParser/Src/SINParserBison.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINAST_Test/Src/SINAST_Tester.o: ../Tests/SINAST_Test/Src/SINAST_Tester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINAST_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINAST_Test/Src/SINAST_Tester.o ../Tests/SINAST_Test/Src/SINAST_Tester.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINmain/Src/main.o: ../SINmain/Src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINmain/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINmain/Src/main.o ../SINmain/Src/main.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINLogging_Test/Src/SINLoggingTester.o: ../Tests/SINLogging_Test/Src/SINLoggingTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINLogging_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINLogging_Test/Src/SINLoggingTester.o ../Tests/SINLogging_Test/Src/SINLoggingTester.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINString.o: ../SINCommon/Src/SINString.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINString.o ../SINCommon/Src/SINString.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINStream.o: ../SINCommon/Src/SINStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINStream.o ../SINCommon/Src/SINStream.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINParserManage.o: ../SINParser/Src/SINParserManage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINParserManage.o ../SINParser/Src/SINParserManage.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINInputStream.o: ../SINCommon/Src/SINInputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINInputStream.o ../SINCommon/Src/SINInputStream.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINCommon.o: ../SINCommon/Src/SINCommon.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINCommon.o ../SINCommon/Src/SINCommon.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINLexAnalyser.o: ../SINParser/Src/SINLexAnalyser.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINLexAnalyser.o ../SINParser/Src/SINLexAnalyser.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINRecord.o: ../SINLogging/Src/SINRecord.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINRecord.o ../SINLogging/Src/SINRecord.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINRuntime/Src/SINMemoryCell.o: ../SINRuntime/Src/SINMemoryCell.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINRuntime/Src/SINMemoryCell.o ../SINRuntime/Src/SINMemoryCell.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINCommon_Test/Src/SINCommonTester.o: ../Tests/SINCommon_Test/Src/SINCommonTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINCommon_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINCommon_Test/Src/SINCommonTester.o ../Tests/SINCommon_Test/Src/SINCommonTester.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src/SINTestFactory.o: ../Tests/SINTest/Src/SINTestFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src/SINTestFactory.o ../Tests/SINTest/Src/SINTestFactory.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINLogger.o: ../SINLogging/Src/SINLogger.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINLogger.o ../SINLogging/Src/SINLogger.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINTreeNode.o: ../SINAST/Src/SINTreeNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINTreeNode.o ../SINAST/Src/SINTreeNode.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src/SINTestCollection.o: ../Tests/SINTest/Src/SINTestCollection.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src/SINTestCollection.o ../Tests/SINTest/Src/SINTestCollection.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINNamer.o: ../SINCommon/Src/SINNamer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINNamer.o ../SINCommon/Src/SINNamer.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINOutputStream.o: ../SINCommon/Src/SINOutputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINOutputStream.o ../SINCommon/Src/SINOutputStream.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINASTMITTreeVisualizerXMLProducerVisitor.o: ../SINAST/Src/SINASTMITTreeVisualizerXMLProducerVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINASTMITTreeVisualizerXMLProducerVisitor.o ../SINAST/Src/SINASTMITTreeVisualizerXMLProducerVisitor.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src/SINTest.o: ../Tests/SINTest/Src/SINTest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINTest/Src/SINTest.o ../Tests/SINTest/Src/SINTest.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SIN.o: ../SINCommon/Src/SIN.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SIN.o ../SINCommon/Src/SIN.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINFileOutputStream.o: ../SINCommon/Src/SINFileOutputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINCommon/Src/SINFileOutputStream.o ../SINCommon/Src/SINFileOutputStream.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINRuntime/Src/SINSymbolTable.o: ../SINRuntime/Src/SINSymbolTable.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINRuntime/Src/SINSymbolTable.o ../SINRuntime/Src/SINSymbolTable.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINASTTreeVisualisationVisitor.o: ../SINAST/Src/SINASTTreeVisualisationVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINASTTreeVisualisationVisitor.o ../SINAST/Src/SINASTTreeVisualisationVisitor.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/ASTVisitor.o: ../SINAST/Src/ASTVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/ASTVisitor.o ../SINAST/Src/ASTVisitor.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINParser_Test/Src/SINParserTester.o: ../Tests/SINParser_Test/Src/SINParserTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINParser_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINParser_Test/Src/SINParserTester.o ../Tests/SINParser_Test/Src/SINParserTester.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINParserAPI.o: ../SINParser/Src/SINParserAPI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINParser/Src/SINParserAPI.o ../SINParser/Src/SINParserAPI.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINSymbolTable_Test/Src/SINSymbolTableTester.o: ../Tests/SINSymbolTable_Test/Src/SINSymbolTableTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINSymbolTable_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../Tests/SINSymbolTable_Test/Src/SINSymbolTableTester.o ../Tests/SINSymbolTable_Test/Src/SINSymbolTableTester.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINRecordPrinter.o: ../SINLogging/Src/SINRecordPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINLogging/Src/SINRecordPrinter.o ../SINLogging/Src/SINRecordPrinter.cpp

${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINASTNode.o: ../SINAST/Src/SINASTNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/trunk/SIN/SIN_netbeans/../SINAST/Src/SINASTNode.o ../SINAST/Src/SINASTNode.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/${PLATFORM}/sin_netbeans

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
