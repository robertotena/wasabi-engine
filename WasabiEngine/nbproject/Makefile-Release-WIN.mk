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
CND_CONF=Release-WIN
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/WasabiEngine/PhysicEngine/WorldContactListener.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPBranchBound.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/KeyboardEventHandler.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/MouseButtonEventHandler.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/QuitHandler.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/Event.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzySet.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIKeyboardInjectorHandler.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/ContactEventHandler.o \
	${OBJECTDIR}/WasabiEngine/Utils/Vectors.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolver.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/GameLoop.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshMap.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/SensorEventHandler.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyRule.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseMotionInjectorHandler.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/Material.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GraphicObject.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/ColourValue.o \
	${OBJECTDIR}/TinyXML/tinyxmlparser.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/Quaternion.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/Mesh.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/objLoader.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/GameObject.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/EventEngine.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/RenderSystem.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSimplex.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/SensorContactListener.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/SensorFactory.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolution.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/EventFactory.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyVariable.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseButtonInjectorHandler.o \
	${OBJECTDIR}/WasabiEngine/Utils/ConfigurationFileParser.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/Light.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/ParticleSystem.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSLeftShoulder.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolverState.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/ObjParser.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSRightShoulder.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshLoader.o \
	${OBJECTDIR}/WasabiEngine/Utils/MathUtil.o \
	${OBJECTDIR}/TinyXML/tinyxml.o \
	${OBJECTDIR}/WasabiEngine/PhysicEngine/ObjectContactListener.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTrapezoid.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/HandlerRegistration.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RoutePlanner.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTriangle.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/SDL_PumpEventsWrapper.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIResizeInjectorHandler.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPProblem.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUISystem.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyParser.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPPenalties.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/SceneryFactory.o \
	${OBJECTDIR}/TinyXML/tinyxmlerror.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSSingleton.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneNode.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneManager.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/VideoResizeEventHandler.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshPrototype.o \
	${OBJECTDIR}/WasabiEngine/PhysicEngine/Box2dWorld.o \
	${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicObject.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FzAnd.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/RadialParticleSystem.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/MouseMotionEventHandler.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/GameWorld3D.o \
	${OBJECTDIR}/TinyXML/tinystr.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/GameObjectManager.o \
	${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicEngine.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/TextureLoader.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/LinearParticleSystem.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RouteNode.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/GameSystemManager.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/Sensor.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/Entity.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/Camera.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPRestriction.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FzOr.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/QuitEventHandler.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GraphicEngine.o


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
	"${MAKE}"  -f nbproject/Makefile-Release-WIN.mk dist/Release-WIN/MinGW-Windows/libwasabiengine.a

dist/Release-WIN/MinGW-Windows/libwasabiengine.a: ${OBJECTFILES}
	${MKDIR} -p dist/Release-WIN/MinGW-Windows
	${RM} dist/Release-WIN/MinGW-Windows/libwasabiengine.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libwasabiengine.a ${OBJECTFILES} 
	$(RANLIB) dist/Release-WIN/MinGW-Windows/libwasabiengine.a

${OBJECTDIR}/WasabiEngine/PhysicEngine/WorldContactListener.o: WasabiEngine/PhysicEngine/WorldContactListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/PhysicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/PhysicEngine/WorldContactListener.o WasabiEngine/PhysicEngine/WorldContactListener.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPBranchBound.o: WasabiEngine/OptimizationEngine/LPBranchBound.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPBranchBound.o WasabiEngine/OptimizationEngine/LPBranchBound.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/KeyboardEventHandler.o: WasabiEngine/EventEngine/KeyboardEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/KeyboardEventHandler.o WasabiEngine/EventEngine/KeyboardEventHandler.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/MouseButtonEventHandler.o: WasabiEngine/EventEngine/MouseButtonEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/MouseButtonEventHandler.o WasabiEngine/EventEngine/MouseButtonEventHandler.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/QuitHandler.o: WasabiEngine/GameEngine/QuitHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/QuitHandler.o WasabiEngine/GameEngine/QuitHandler.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/Event.o: WasabiEngine/EventEngine/Event.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/Event.o WasabiEngine/EventEngine/Event.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzySet.o: WasabiEngine/AIEngine/FuzzyModule/FuzzySet.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzySet.o WasabiEngine/AIEngine/FuzzyModule/FuzzySet.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIKeyboardInjectorHandler.o: WasabiEngine/GraphicEngine/GUI/CEGUIKeyboardInjectorHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIKeyboardInjectorHandler.o WasabiEngine/GraphicEngine/GUI/CEGUIKeyboardInjectorHandler.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/ContactEventHandler.o: WasabiEngine/EventEngine/ContactEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/ContactEventHandler.o WasabiEngine/EventEngine/ContactEventHandler.cpp

${OBJECTDIR}/WasabiEngine/Utils/Vectors.o: WasabiEngine/Utils/Vectors.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/Utils
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/Utils/Vectors.o WasabiEngine/Utils/Vectors.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolver.o: WasabiEngine/OptimizationEngine/LPSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolver.o WasabiEngine/OptimizationEngine/LPSolver.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/GameLoop.o: WasabiEngine/GameEngine/GameLoop.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/GameLoop.o WasabiEngine/GameEngine/GameLoop.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshMap.o: WasabiEngine/GraphicEngine/MeshMap.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshMap.o WasabiEngine/GraphicEngine/MeshMap.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/SensorEventHandler.o: WasabiEngine/EventEngine/SensorEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/SensorEventHandler.o WasabiEngine/EventEngine/SensorEventHandler.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyRule.o: WasabiEngine/AIEngine/FuzzyModule/FuzzyRule.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyRule.o WasabiEngine/AIEngine/FuzzyModule/FuzzyRule.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseMotionInjectorHandler.o: WasabiEngine/GraphicEngine/GUI/CEGUIMouseMotionInjectorHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseMotionInjectorHandler.o WasabiEngine/GraphicEngine/GUI/CEGUIMouseMotionInjectorHandler.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Material.o: WasabiEngine/GraphicEngine/Material.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Material.o WasabiEngine/GraphicEngine/Material.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GraphicObject.o: WasabiEngine/GraphicEngine/GraphicObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GraphicObject.o WasabiEngine/GraphicEngine/GraphicObject.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/ColourValue.o: WasabiEngine/GraphicEngine/ColourValue.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/ColourValue.o WasabiEngine/GraphicEngine/ColourValue.cpp

${OBJECTDIR}/TinyXML/tinyxmlparser.o: TinyXML/tinyxmlparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/TinyXML
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/TinyXML/tinyxmlparser.o TinyXML/tinyxmlparser.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Quaternion.o: WasabiEngine/GraphicEngine/Quaternion.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Quaternion.o WasabiEngine/GraphicEngine/Quaternion.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Mesh.o: WasabiEngine/GraphicEngine/Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Mesh.o WasabiEngine/GraphicEngine/Mesh.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/objLoader.o: WasabiEngine/GraphicEngine/objLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/objLoader.o WasabiEngine/GraphicEngine/objLoader.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/GameObject.o: WasabiEngine/GameEngine/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/GameObject.o WasabiEngine/GameEngine/GameObject.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/EventEngine.o: WasabiEngine/EventEngine/EventEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/EventEngine.o WasabiEngine/EventEngine/EventEngine.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/RenderSystem.o: WasabiEngine/GraphicEngine/RenderSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/RenderSystem.o WasabiEngine/GraphicEngine/RenderSystem.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSimplex.o: WasabiEngine/OptimizationEngine/LPSimplex.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSimplex.o WasabiEngine/OptimizationEngine/LPSimplex.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/SensorContactListener.o: WasabiEngine/GameEngine/SensorContactListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/SensorContactListener.o WasabiEngine/GameEngine/SensorContactListener.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/SensorFactory.o: WasabiEngine/GameEngine/SensorFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/SensorFactory.o WasabiEngine/GameEngine/SensorFactory.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolution.o: WasabiEngine/OptimizationEngine/LPSolution.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolution.o WasabiEngine/OptimizationEngine/LPSolution.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/EventFactory.o: WasabiEngine/EventEngine/EventFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/EventFactory.o WasabiEngine/EventEngine/EventFactory.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyVariable.o: WasabiEngine/AIEngine/FuzzyModule/FuzzyVariable.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyVariable.o WasabiEngine/AIEngine/FuzzyModule/FuzzyVariable.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseButtonInjectorHandler.o: WasabiEngine/GraphicEngine/GUI/CEGUIMouseButtonInjectorHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseButtonInjectorHandler.o WasabiEngine/GraphicEngine/GUI/CEGUIMouseButtonInjectorHandler.cpp

${OBJECTDIR}/WasabiEngine/Utils/ConfigurationFileParser.o: WasabiEngine/Utils/ConfigurationFileParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/Utils
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/Utils/ConfigurationFileParser.o WasabiEngine/Utils/ConfigurationFileParser.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Light.o: WasabiEngine/GraphicEngine/Light.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Light.o WasabiEngine/GraphicEngine/Light.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/ParticleSystem.o: WasabiEngine/GraphicEngine/ParticleSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/ParticleSystem.o WasabiEngine/GraphicEngine/ParticleSystem.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSLeftShoulder.o: WasabiEngine/AIEngine/FuzzyModule/FSLeftShoulder.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSLeftShoulder.o WasabiEngine/AIEngine/FuzzyModule/FSLeftShoulder.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.o: WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.o WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolverState.o: WasabiEngine/OptimizationEngine/LPSolverState.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolverState.o WasabiEngine/OptimizationEngine/LPSolverState.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/ObjParser.o: WasabiEngine/GraphicEngine/ObjParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/ObjParser.o WasabiEngine/GraphicEngine/ObjParser.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSRightShoulder.o: WasabiEngine/AIEngine/FuzzyModule/FSRightShoulder.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSRightShoulder.o WasabiEngine/AIEngine/FuzzyModule/FSRightShoulder.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshLoader.o: WasabiEngine/GraphicEngine/MeshLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshLoader.o WasabiEngine/GraphicEngine/MeshLoader.cpp

${OBJECTDIR}/WasabiEngine/Utils/MathUtil.o: WasabiEngine/Utils/MathUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/Utils
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/Utils/MathUtil.o WasabiEngine/Utils/MathUtil.cpp

${OBJECTDIR}/TinyXML/tinyxml.o: TinyXML/tinyxml.cpp 
	${MKDIR} -p ${OBJECTDIR}/TinyXML
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/TinyXML/tinyxml.o TinyXML/tinyxml.cpp

${OBJECTDIR}/WasabiEngine/PhysicEngine/ObjectContactListener.o: WasabiEngine/PhysicEngine/ObjectContactListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/PhysicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/PhysicEngine/ObjectContactListener.o WasabiEngine/PhysicEngine/ObjectContactListener.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTrapezoid.o: WasabiEngine/AIEngine/FuzzyModule/FSTrapezoid.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTrapezoid.o WasabiEngine/AIEngine/FuzzyModule/FSTrapezoid.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/HandlerRegistration.o: WasabiEngine/EventEngine/HandlerRegistration.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/HandlerRegistration.o WasabiEngine/EventEngine/HandlerRegistration.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RoutePlanner.o: WasabiEngine/AIEngine/Routing/RoutePlanner.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/Routing
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RoutePlanner.o WasabiEngine/AIEngine/Routing/RoutePlanner.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTriangle.o: WasabiEngine/AIEngine/FuzzyModule/FSTriangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTriangle.o WasabiEngine/AIEngine/FuzzyModule/FSTriangle.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/SDL_PumpEventsWrapper.o: WasabiEngine/EventEngine/SDL_PumpEventsWrapper.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/SDL_PumpEventsWrapper.o WasabiEngine/EventEngine/SDL_PumpEventsWrapper.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIResizeInjectorHandler.o: WasabiEngine/GraphicEngine/GUI/CEGUIResizeInjectorHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIResizeInjectorHandler.o WasabiEngine/GraphicEngine/GUI/CEGUIResizeInjectorHandler.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPProblem.o: WasabiEngine/OptimizationEngine/LPProblem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPProblem.o WasabiEngine/OptimizationEngine/LPProblem.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUISystem.o: WasabiEngine/GraphicEngine/GUI/CEGUISystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUISystem.o WasabiEngine/GraphicEngine/GUI/CEGUISystem.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyParser.o: WasabiEngine/AIEngine/FuzzyModule/FuzzyParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyParser.o WasabiEngine/AIEngine/FuzzyModule/FuzzyParser.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPPenalties.o: WasabiEngine/OptimizationEngine/LPPenalties.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPPenalties.o WasabiEngine/OptimizationEngine/LPPenalties.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/SceneryFactory.o: WasabiEngine/GameEngine/SceneryFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/SceneryFactory.o WasabiEngine/GameEngine/SceneryFactory.cpp

${OBJECTDIR}/TinyXML/tinyxmlerror.o: TinyXML/tinyxmlerror.cpp 
	${MKDIR} -p ${OBJECTDIR}/TinyXML
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/TinyXML/tinyxmlerror.o TinyXML/tinyxmlerror.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSSingleton.o: WasabiEngine/AIEngine/FuzzyModule/FSSingleton.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSSingleton.o WasabiEngine/AIEngine/FuzzyModule/FSSingleton.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneNode.o: WasabiEngine/GraphicEngine/SceneNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneNode.o WasabiEngine/GraphicEngine/SceneNode.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneManager.o: WasabiEngine/GraphicEngine/SceneManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneManager.o WasabiEngine/GraphicEngine/SceneManager.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/VideoResizeEventHandler.o: WasabiEngine/EventEngine/VideoResizeEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/VideoResizeEventHandler.o WasabiEngine/EventEngine/VideoResizeEventHandler.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshPrototype.o: WasabiEngine/GraphicEngine/MeshPrototype.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshPrototype.o WasabiEngine/GraphicEngine/MeshPrototype.cpp

${OBJECTDIR}/WasabiEngine/PhysicEngine/Box2dWorld.o: WasabiEngine/PhysicEngine/Box2dWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/PhysicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/PhysicEngine/Box2dWorld.o WasabiEngine/PhysicEngine/Box2dWorld.cpp

${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicObject.o: WasabiEngine/PhysicEngine/PhysicObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/PhysicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicObject.o WasabiEngine/PhysicEngine/PhysicObject.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FzAnd.o: WasabiEngine/AIEngine/FuzzyModule/FzAnd.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FzAnd.o WasabiEngine/AIEngine/FuzzyModule/FzAnd.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/RadialParticleSystem.o: WasabiEngine/GraphicEngine/RadialParticleSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/RadialParticleSystem.o WasabiEngine/GraphicEngine/RadialParticleSystem.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/MouseMotionEventHandler.o: WasabiEngine/EventEngine/MouseMotionEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/MouseMotionEventHandler.o WasabiEngine/EventEngine/MouseMotionEventHandler.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/GameWorld3D.o: WasabiEngine/GameEngine/GameWorld3D.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/GameWorld3D.o WasabiEngine/GameEngine/GameWorld3D.cpp

${OBJECTDIR}/TinyXML/tinystr.o: TinyXML/tinystr.cpp 
	${MKDIR} -p ${OBJECTDIR}/TinyXML
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/TinyXML/tinystr.o TinyXML/tinystr.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/GameObjectManager.o: WasabiEngine/GameEngine/GameObjectManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/GameObjectManager.o WasabiEngine/GameEngine/GameObjectManager.cpp

${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicEngine.o: WasabiEngine/PhysicEngine/PhysicEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/PhysicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicEngine.o WasabiEngine/PhysicEngine/PhysicEngine.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/TextureLoader.o: WasabiEngine/GraphicEngine/TextureLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/TextureLoader.o WasabiEngine/GraphicEngine/TextureLoader.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/LinearParticleSystem.o: WasabiEngine/GraphicEngine/LinearParticleSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/LinearParticleSystem.o WasabiEngine/GraphicEngine/LinearParticleSystem.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RouteNode.o: WasabiEngine/AIEngine/Routing/RouteNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/Routing
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RouteNode.o WasabiEngine/AIEngine/Routing/RouteNode.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/GameSystemManager.o: WasabiEngine/GameEngine/GameSystemManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/GameSystemManager.o WasabiEngine/GameEngine/GameSystemManager.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/Sensor.o: WasabiEngine/GameEngine/Sensor.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/Sensor.o WasabiEngine/GameEngine/Sensor.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Entity.o: WasabiEngine/GraphicEngine/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Entity.o WasabiEngine/GraphicEngine/Entity.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Camera.o: WasabiEngine/GraphicEngine/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Camera.o WasabiEngine/GraphicEngine/Camera.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPRestriction.o: WasabiEngine/OptimizationEngine/LPRestriction.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPRestriction.o WasabiEngine/OptimizationEngine/LPRestriction.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FzOr.o: WasabiEngine/AIEngine/FuzzyModule/FzOr.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FzOr.o WasabiEngine/AIEngine/FuzzyModule/FzOr.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/QuitEventHandler.o: WasabiEngine/EventEngine/QuitEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/QuitEventHandler.o WasabiEngine/EventEngine/QuitEventHandler.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GraphicEngine.o: WasabiEngine/GraphicEngine/GraphicEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GraphicEngine.o WasabiEngine/GraphicEngine/GraphicEngine.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release-WIN
	${RM} dist/Release-WIN/MinGW-Windows/libwasabiengine.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
