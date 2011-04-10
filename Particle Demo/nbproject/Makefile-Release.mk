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
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Demo/DemoSystemManager.o \
	${OBJECTDIR}/Demo/ActorControlHandler.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Demo/SimpleCameraControlHandler.o \
	${OBJECTDIR}/Demo/SimpleActor.o \
	${OBJECTDIR}/Demo/GraphicDemo.o \
	${OBJECTDIR}/Demo/SimpleCamera.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Release.mk dist/Release/MinGW-Windows/particle_demo.exe

dist/Release/MinGW-Windows/particle_demo.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Release/MinGW-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/particle_demo ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Demo/DemoSystemManager.o: Demo/DemoSystemManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/Demo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Demo/DemoSystemManager.o Demo/DemoSystemManager.cpp

${OBJECTDIR}/Demo/ActorControlHandler.o: Demo/ActorControlHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/Demo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Demo/ActorControlHandler.o Demo/ActorControlHandler.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Demo/SimpleCameraControlHandler.o: Demo/SimpleCameraControlHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/Demo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Demo/SimpleCameraControlHandler.o Demo/SimpleCameraControlHandler.cpp

${OBJECTDIR}/Demo/SimpleActor.o: Demo/SimpleActor.cpp 
	${MKDIR} -p ${OBJECTDIR}/Demo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Demo/SimpleActor.o Demo/SimpleActor.cpp

${OBJECTDIR}/Demo/GraphicDemo.o: Demo/GraphicDemo.cpp 
	${MKDIR} -p ${OBJECTDIR}/Demo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Demo/GraphicDemo.o Demo/GraphicDemo.cpp

${OBJECTDIR}/Demo/SimpleCamera.o: Demo/SimpleCamera.cpp 
	${MKDIR} -p ${OBJECTDIR}/Demo
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Demo/SimpleCamera.o Demo/SimpleCamera.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/MinGW-Windows/particle_demo.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
