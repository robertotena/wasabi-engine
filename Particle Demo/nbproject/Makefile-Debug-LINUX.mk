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
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug-LINUX
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Demo/Demo.o \
	${OBJECTDIR}/Demo/ActorControlHandler.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Demo/SimpleCameraControlHandler.o \
	${OBJECTDIR}/Demo/SimpleActor.o \
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
LDLIBSOPTIONS=/home/fran/NetBeansProjects/WasabiEngine/dist/Debug-LINUX/GNU-Linux-x86/libwasabiengine.a -L/usr/lib -lSDL -lSDL_image -lGL -lGLU

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug-LINUX.mk dist/Debug-LINUX/GNU-Linux-x86/particle_demo

dist/Debug-LINUX/GNU-Linux-x86/particle_demo: /home/fran/NetBeansProjects/WasabiEngine/dist/Debug-LINUX/GNU-Linux-x86/libwasabiengine.a

dist/Debug-LINUX/GNU-Linux-x86/particle_demo: ${OBJECTFILES}
	${MKDIR} -p dist/Debug-LINUX/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/particle_demo ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Demo/Demo.o: Demo/Demo.cpp 
	${MKDIR} -p ${OBJECTDIR}/Demo
	${RM} $@.d
	$(COMPILE.cc) -g -D__UNIX -D_GNU_SOURCE=1 -D_REENTRANT -I. -I../WasabiEngine -MMD -MP -MF $@.d -o ${OBJECTDIR}/Demo/Demo.o Demo/Demo.cpp

${OBJECTDIR}/Demo/ActorControlHandler.o: Demo/ActorControlHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/Demo
	${RM} $@.d
	$(COMPILE.cc) -g -D__UNIX -D_GNU_SOURCE=1 -D_REENTRANT -I. -I../WasabiEngine -MMD -MP -MF $@.d -o ${OBJECTDIR}/Demo/ActorControlHandler.o Demo/ActorControlHandler.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D__UNIX -D_GNU_SOURCE=1 -D_REENTRANT -I. -I../WasabiEngine -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Demo/SimpleCameraControlHandler.o: Demo/SimpleCameraControlHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/Demo
	${RM} $@.d
	$(COMPILE.cc) -g -D__UNIX -D_GNU_SOURCE=1 -D_REENTRANT -I. -I../WasabiEngine -MMD -MP -MF $@.d -o ${OBJECTDIR}/Demo/SimpleCameraControlHandler.o Demo/SimpleCameraControlHandler.cpp

${OBJECTDIR}/Demo/SimpleActor.o: Demo/SimpleActor.cpp 
	${MKDIR} -p ${OBJECTDIR}/Demo
	${RM} $@.d
	$(COMPILE.cc) -g -D__UNIX -D_GNU_SOURCE=1 -D_REENTRANT -I. -I../WasabiEngine -MMD -MP -MF $@.d -o ${OBJECTDIR}/Demo/SimpleActor.o Demo/SimpleActor.cpp

${OBJECTDIR}/Demo/SimpleCamera.o: Demo/SimpleCamera.cpp 
	${MKDIR} -p ${OBJECTDIR}/Demo
	${RM} $@.d
	$(COMPILE.cc) -g -D__UNIX -D_GNU_SOURCE=1 -D_REENTRANT -I. -I../WasabiEngine -MMD -MP -MF $@.d -o ${OBJECTDIR}/Demo/SimpleCamera.o Demo/SimpleCamera.cpp

# Subprojects
.build-subprojects:
	cd /home/fran/NetBeansProjects/WasabiEngine && ${MAKE}  -f Makefile CONF=Debug-LINUX

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug-LINUX
	${RM} dist/Debug-LINUX/GNU-Linux-x86/particle_demo

# Subprojects
.clean-subprojects:
	cd /home/fran/NetBeansProjects/WasabiEngine && ${MAKE}  -f Makefile CONF=Debug-LINUX clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
