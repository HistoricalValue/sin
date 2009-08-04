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
AS=

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include GNUmakefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTNodes.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINRun_Test/Src/SINRunTester.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINParserBison.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINmain/Src/main.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINStream.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellAST.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellNumber.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINCommon_Test/Src/SINCommonTester.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src/SINTestFactory.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINLogger.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINTreeNode.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINNamer.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAST_Test/Src/SINAST_Tester_main.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src/SINTest.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINFileOutputStream.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINSymbolTable.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/ASTVisitor.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINParser_Test/Src/SINParserTester.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellBool.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINParserAPI.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINAlloc/Src/SINAlloc.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellNil.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAST_Test/Src/SINAST_StrictTreeNode_Tester.o \
	${OBJECTDIR}/_ext/_DOTDOT/Common/Src/Common.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellObject.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINLoggerManager.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINString.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINLogging_Test/Src/SINLoggingTester.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAlloc_Test/Src/SINAllocTester.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINBufferedOutputStream.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/LexAndBisonParseArguments.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINParserManage.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINInputStream.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/LexUtility.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINTreeEvaluationVisitor.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINObject_Test/Src/SINObjectTester.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINCommon.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINRecord.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINLexAnalyzer.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellString.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCell.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINObject.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src/SINTestCollection.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellFunction.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINOutputStream.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTMITTreeVisualizerXMLProducerVisitor.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SIN.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTTreeVisualisationVisitor.o \
	${OBJECTDIR}/_ext/_DOTDOT/Tests/SINSymbolTable_Test/Src/SINSymbolTableTester.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINRecordPrinter.o \
	${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTNode.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-pedantic -ansi -Wall -O0 -g -fno-rtti
CXXFLAGS=-pedantic -ansi -Wall -O0 -g -fno-rtti

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/sin_netbeans

dist/Debug/GNU-Linux-x86/sin_netbeans: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sin_netbeans ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTNodes.o: nbproject/Makefile-${CND_CONF}.mk ../SINAST/Src/SINASTNodes.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTNodes.o ../SINAST/Src/SINASTNodes.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINRun_Test/Src/SINRunTester.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINRun_Test/Src/SINRunTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINRun_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINRun_Test/Src/SINRunTester.o ../Tests/SINRun_Test/Src/SINRunTester.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINParserBison.o: nbproject/Makefile-${CND_CONF}.mk ../SINParser/Src/SINParserBison.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINParserBison.o ../SINParser/Src/SINParserBison.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINmain/Src/main.o: nbproject/Makefile-${CND_CONF}.mk ../SINmain/Src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINmain/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINmain/Src/main.o ../SINmain/Src/main.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINStream.o: nbproject/Makefile-${CND_CONF}.mk ../SINCommon/Src/SINStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINStream.o ../SINCommon/Src/SINStream.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellAST.o: nbproject/Makefile-${CND_CONF}.mk ../SINRuntime/Src/SINMemoryCellAST.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellAST.o ../SINRuntime/Src/SINMemoryCellAST.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellNumber.o: nbproject/Makefile-${CND_CONF}.mk ../SINRuntime/Src/SINMemoryCellNumber.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellNumber.o ../SINRuntime/Src/SINMemoryCellNumber.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINCommon_Test/Src/SINCommonTester.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINCommon_Test/Src/SINCommonTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINCommon_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINCommon_Test/Src/SINCommonTester.o ../Tests/SINCommon_Test/Src/SINCommonTester.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src/SINTestFactory.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINTest/Src/SINTestFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src/SINTestFactory.o ../Tests/SINTest/Src/SINTestFactory.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINLogger.o: nbproject/Makefile-${CND_CONF}.mk ../SINLogging/Src/SINLogger.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINLogger.o ../SINLogging/Src/SINLogger.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINTreeNode.o: nbproject/Makefile-${CND_CONF}.mk ../SINAST/Src/SINTreeNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINTreeNode.o ../SINAST/Src/SINTreeNode.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINNamer.o: nbproject/Makefile-${CND_CONF}.mk ../SINCommon/Src/SINNamer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINNamer.o ../SINCommon/Src/SINNamer.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAST_Test/Src/SINAST_Tester_main.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINAST_Test/Src/SINAST_Tester_main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAST_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAST_Test/Src/SINAST_Tester_main.o ../Tests/SINAST_Test/Src/SINAST_Tester_main.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src/SINTest.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINTest/Src/SINTest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src/SINTest.o ../Tests/SINTest/Src/SINTest.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINFileOutputStream.o: nbproject/Makefile-${CND_CONF}.mk ../SINCommon/Src/SINFileOutputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINFileOutputStream.o ../SINCommon/Src/SINFileOutputStream.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINSymbolTable.o: nbproject/Makefile-${CND_CONF}.mk ../SINRuntime/Src/SINSymbolTable.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINSymbolTable.o ../SINRuntime/Src/SINSymbolTable.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/ASTVisitor.o: nbproject/Makefile-${CND_CONF}.mk ../SINAST/Src/ASTVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/ASTVisitor.o ../SINAST/Src/ASTVisitor.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINParser_Test/Src/SINParserTester.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINParser_Test/Src/SINParserTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINParser_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINParser_Test/Src/SINParserTester.o ../Tests/SINParser_Test/Src/SINParserTester.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellBool.o: nbproject/Makefile-${CND_CONF}.mk ../SINRuntime/Src/SINMemoryCellBool.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellBool.o ../SINRuntime/Src/SINMemoryCellBool.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINParserAPI.o: nbproject/Makefile-${CND_CONF}.mk ../SINParser/Src/SINParserAPI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINParserAPI.o ../SINParser/Src/SINParserAPI.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINAlloc/Src/SINAlloc.o: nbproject/Makefile-${CND_CONF}.mk ../SINAlloc/Src/SINAlloc.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINAlloc/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINAlloc/Src/SINAlloc.o ../SINAlloc/Src/SINAlloc.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellNil.o: nbproject/Makefile-${CND_CONF}.mk ../SINRuntime/Src/SINMemoryCellNil.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellNil.o ../SINRuntime/Src/SINMemoryCellNil.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAST_Test/Src/SINAST_StrictTreeNode_Tester.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINAST_Test/Src/SINAST_StrictTreeNode_Tester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAST_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAST_Test/Src/SINAST_StrictTreeNode_Tester.o ../Tests/SINAST_Test/Src/SINAST_StrictTreeNode_Tester.cpp

${OBJECTDIR}/_ext/_DOTDOT/Common/Src/Common.o: nbproject/Makefile-${CND_CONF}.mk ../Common/Src/Common.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Common/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Common/Src/Common.o ../Common/Src/Common.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellObject.o: nbproject/Makefile-${CND_CONF}.mk ../SINRuntime/Src/SINMemoryCellObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellObject.o ../SINRuntime/Src/SINMemoryCellObject.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINLoggerManager.o: nbproject/Makefile-${CND_CONF}.mk ../SINLogging/Src/SINLoggerManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINLoggerManager.o ../SINLogging/Src/SINLoggerManager.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINString.o: nbproject/Makefile-${CND_CONF}.mk ../SINCommon/Src/SINString.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINString.o ../SINCommon/Src/SINString.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINLogging_Test/Src/SINLoggingTester.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINLogging_Test/Src/SINLoggingTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINLogging_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINLogging_Test/Src/SINLoggingTester.o ../Tests/SINLogging_Test/Src/SINLoggingTester.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAlloc_Test/Src/SINAllocTester.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINAlloc_Test/Src/SINAllocTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAlloc_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINAlloc_Test/Src/SINAllocTester.o ../Tests/SINAlloc_Test/Src/SINAllocTester.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINBufferedOutputStream.o: nbproject/Makefile-${CND_CONF}.mk ../SINCommon/Src/SINBufferedOutputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINBufferedOutputStream.o ../SINCommon/Src/SINBufferedOutputStream.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/LexAndBisonParseArguments.o: nbproject/Makefile-${CND_CONF}.mk ../SINParser/Src/LexAndBisonParseArguments.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/LexAndBisonParseArguments.o ../SINParser/Src/LexAndBisonParseArguments.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINParserManage.o: nbproject/Makefile-${CND_CONF}.mk ../SINParser/Src/SINParserManage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINParserManage.o ../SINParser/Src/SINParserManage.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINInputStream.o: nbproject/Makefile-${CND_CONF}.mk ../SINCommon/Src/SINInputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINInputStream.o ../SINCommon/Src/SINInputStream.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/LexUtility.o: nbproject/Makefile-${CND_CONF}.mk ../SINParser/Src/LexUtility.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/LexUtility.o ../SINParser/Src/LexUtility.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINTreeEvaluationVisitor.o: nbproject/Makefile-${CND_CONF}.mk ../SINRuntime/Src/SINTreeEvaluationVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINTreeEvaluationVisitor.o ../SINRuntime/Src/SINTreeEvaluationVisitor.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINObject_Test/Src/SINObjectTester.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINObject_Test/Src/SINObjectTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINObject_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINObject_Test/Src/SINObjectTester.o ../Tests/SINObject_Test/Src/SINObjectTester.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINCommon.o: nbproject/Makefile-${CND_CONF}.mk ../SINCommon/Src/SINCommon.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINCommon.o ../SINCommon/Src/SINCommon.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINRecord.o: nbproject/Makefile-${CND_CONF}.mk ../SINLogging/Src/SINRecord.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINRecord.o ../SINLogging/Src/SINRecord.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINLexAnalyzer.o: nbproject/Makefile-${CND_CONF}.mk ../SINParser/Src/SINLexAnalyzer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINParser/Src/SINLexAnalyzer.o ../SINParser/Src/SINLexAnalyzer.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellString.o: nbproject/Makefile-${CND_CONF}.mk ../SINRuntime/Src/SINMemoryCellString.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellString.o ../SINRuntime/Src/SINMemoryCellString.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCell.o: nbproject/Makefile-${CND_CONF}.mk ../SINRuntime/Src/SINMemoryCell.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCell.o ../SINRuntime/Src/SINMemoryCell.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINObject.o: nbproject/Makefile-${CND_CONF}.mk ../SINCommon/Src/SINObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINObject.o ../SINCommon/Src/SINObject.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src/SINTestCollection.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINTest/Src/SINTestCollection.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINTest/Src/SINTestCollection.o ../Tests/SINTest/Src/SINTestCollection.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellFunction.o: nbproject/Makefile-${CND_CONF}.mk ../SINRuntime/Src/SINMemoryCellFunction.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINRuntime/Src/SINMemoryCellFunction.o ../SINRuntime/Src/SINMemoryCellFunction.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINOutputStream.o: nbproject/Makefile-${CND_CONF}.mk ../SINCommon/Src/SINOutputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SINOutputStream.o ../SINCommon/Src/SINOutputStream.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTMITTreeVisualizerXMLProducerVisitor.o: nbproject/Makefile-${CND_CONF}.mk ../SINAST/Src/SINASTMITTreeVisualizerXMLProducerVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTMITTreeVisualizerXMLProducerVisitor.o ../SINAST/Src/SINASTMITTreeVisualizerXMLProducerVisitor.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SIN.o: nbproject/Makefile-${CND_CONF}.mk ../SINCommon/Src/SIN.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINCommon/Src/SIN.o ../SINCommon/Src/SIN.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTTreeVisualisationVisitor.o: nbproject/Makefile-${CND_CONF}.mk ../SINAST/Src/SINASTTreeVisualisationVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTTreeVisualisationVisitor.o ../SINAST/Src/SINASTTreeVisualisationVisitor.cpp

${OBJECTDIR}/_ext/_DOTDOT/Tests/SINSymbolTable_Test/Src/SINSymbolTableTester.o: nbproject/Makefile-${CND_CONF}.mk ../Tests/SINSymbolTable_Test/Src/SINSymbolTableTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINSymbolTable_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/Tests/SINSymbolTable_Test/Src/SINSymbolTableTester.o ../Tests/SINSymbolTable_Test/Src/SINSymbolTableTester.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINRecordPrinter.o: nbproject/Makefile-${CND_CONF}.mk ../SINLogging/Src/SINRecordPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINLogging/Src/SINRecordPrinter.o ../SINLogging/Src/SINRecordPrinter.cpp

${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTNode.o: nbproject/Makefile-${CND_CONF}.mk ../SINAST/Src/SINASTNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../Common/Include -I../SINAlloc/Include -I../SINAST/Include -I../SINCommon/Include -I../SINLogging/Include -I../SINmain/Include -I../SINParser/Include -I../SINRuntime/Include -I../Tests/SINAlloc_Test/Include -I../Tests/SINAST_Test/Include -I../Tests/SINCommon_Test/Include -I../Tests/SINLogging_Test/Include -I../Tests/SINObject_Test/Include -I../Tests/SINParser_Test/Include -I../Tests/SINRun_Test/Include -I../Tests/SINSymbolTable_Test/Include -I../Tests/SINTest/Include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/SINAST/Src/SINASTNode.o ../SINAST/Src/SINASTNode.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/sin_netbeans

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
