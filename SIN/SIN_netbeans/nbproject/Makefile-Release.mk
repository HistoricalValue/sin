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
OBJECTDIR=build/Release/${PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/Common/Src/Common.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINParserBison.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINLoggerManager.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINParserManageExpression.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINAST_Test/Src/SINAST_Tester.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINmain/Src/main.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINString.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINLogging_Test/Src/SINLoggingTester.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINStream.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINInputStream.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINCommon.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINLexAnalyser.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINRecord.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINCommon_Test/Src/SINCommonTester.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINLogger.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src/SINTreeNode.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINNamer.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINOutputStream.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINTest/Src/SINTest.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SIN.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src/ASTVisitor.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINParser_Test/Src/SINParserTester.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINParserAPI.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINRecordPrinter.o \
	${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src/SINASTNode.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/${PLATFORM}/sin_netbeans

dist/Release/${PLATFORM}/sin_netbeans: ${OBJECTFILES}
	${MKDIR} -p dist/Release/${PLATFORM}
	${LINK.cc} -o dist/Release/${PLATFORM}/sin_netbeans ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/tmp/cs540/SIN/Common/Src/Common.o: ../Common/Src/Common.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/Common/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/Common/Src/Common.o ../Common/Src/Common.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINParserBison.o: ../SINParser/Src/SINParserBison.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINParserBison.o ../SINParser/Src/SINParserBison.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINLoggerManager.o: ../SINLogging/Src/SINLoggerManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINLoggerManager.o ../SINLogging/Src/SINLoggerManager.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINParserManageExpression.o: ../SINParser/Src/SINParserManageExpression.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINParserManageExpression.o ../SINParser/Src/SINParserManageExpression.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINAST_Test/Src/SINAST_Tester.o: ../Tests/SINAST_Test/Src/SINAST_Tester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINAST_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINAST_Test/Src/SINAST_Tester.o ../Tests/SINAST_Test/Src/SINAST_Tester.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINmain/Src/main.o: ../SINmain/Src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINmain/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINmain/Src/main.o ../SINmain/Src/main.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINString.o: ../SINCommon/Src/SINString.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINString.o ../SINCommon/Src/SINString.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINLogging_Test/Src/SINLoggingTester.o: ../Tests/SINLogging_Test/Src/SINLoggingTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINLogging_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINLogging_Test/Src/SINLoggingTester.o ../Tests/SINLogging_Test/Src/SINLoggingTester.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINStream.o: ../SINCommon/Src/SINStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINStream.o ../SINCommon/Src/SINStream.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINInputStream.o: ../SINCommon/Src/SINInputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINInputStream.o ../SINCommon/Src/SINInputStream.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINCommon.o: ../SINCommon/Src/SINCommon.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINCommon.o ../SINCommon/Src/SINCommon.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINLexAnalyser.o: ../SINParser/Src/SINLexAnalyser.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINLexAnalyser.o ../SINParser/Src/SINLexAnalyser.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINRecord.o: ../SINLogging/Src/SINRecord.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINRecord.o ../SINLogging/Src/SINRecord.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINCommon_Test/Src/SINCommonTester.o: ../Tests/SINCommon_Test/Src/SINCommonTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINCommon_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINCommon_Test/Src/SINCommonTester.o ../Tests/SINCommon_Test/Src/SINCommonTester.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINLogger.o: ../SINLogging/Src/SINLogger.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINLogger.o ../SINLogging/Src/SINLogger.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src/SINTreeNode.o: ../SINAST/Src/SINTreeNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src/SINTreeNode.o ../SINAST/Src/SINTreeNode.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINNamer.o: ../SINCommon/Src/SINNamer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINNamer.o ../SINCommon/Src/SINNamer.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINOutputStream.o: ../SINCommon/Src/SINOutputStream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SINOutputStream.o ../SINCommon/Src/SINOutputStream.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINTest/Src/SINTest.o: ../Tests/SINTest/Src/SINTest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINTest/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINTest/Src/SINTest.o ../Tests/SINTest/Src/SINTest.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SIN.o: ../SINCommon/Src/SIN.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINCommon/Src/SIN.o ../SINCommon/Src/SIN.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src/ASTVisitor.o: ../SINAST/Src/ASTVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src/ASTVisitor.o ../SINAST/Src/ASTVisitor.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINParser_Test/Src/SINParserTester.o: ../Tests/SINParser_Test/Src/SINParserTester.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINParser_Test/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/Tests/SINParser_Test/Src/SINParserTester.o ../Tests/SINParser_Test/Src/SINParserTester.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINParserAPI.o: ../SINParser/Src/SINParserAPI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINParser/Src/SINParserAPI.o ../SINParser/Src/SINParserAPI.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINRecordPrinter.o: ../SINLogging/Src/SINRecordPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINLogging/Src/SINRecordPrinter.o ../SINLogging/Src/SINRecordPrinter.cpp

${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src/SINASTNode.o: ../SINAST/Src/SINASTNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/tmp/cs540/SIN/SINAST/Src/SINASTNode.o ../SINAST/Src/SINASTNode.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/${PLATFORM}/sin_netbeans

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
