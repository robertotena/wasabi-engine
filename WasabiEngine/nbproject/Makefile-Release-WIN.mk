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
FC=gfortran
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_CONF=Release-WIN
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/WasabiEngine/PhysicEngine/WorldContactListener.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPBranchBound.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/KeyboardEventHandler.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/MouseButtonEventHandler.o \
	${OBJECTDIR}/Box2D/Dynamics/Joints/b2WeldJoint.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/QuitHandler.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/Event.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzySet.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIKeyboardInjectorHandler.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/ContactEventHandler.o \
	${OBJECTDIR}/Box2D/Common/b2Settings.o \
	${OBJECTDIR}/WasabiEngine/Utils/Vectors.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolver.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/LightPoint.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/GameLoop.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshMap.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/SensorEventHandler.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyRule.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseMotionInjectorHandler.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/Material.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GraphicObject.o \
	${OBJECTDIR}/Box2D/Dynamics/Joints/b2PulleyJoint.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/ColourValue.o \
	${OBJECTDIR}/TinyXML/tinyxmlparser.o \
	${OBJECTDIR}/Box2D/Collision/b2CollideCircle.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/Quaternion.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/Mesh.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/objLoader.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/GameObject.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/EventEngine.o \
	${OBJECTDIR}/Box2D/Dynamics/Joints/b2DistanceJoint.o \
	${OBJECTDIR}/Box2D/Collision/b2BroadPhase.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/RenderSystem.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSimplex.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/SensorContactListener.o \
	${OBJECTDIR}/Box2D/Collision/Shapes/b2PolygonShape.o \
	${OBJECTDIR}/Box2D/Dynamics/Contacts/b2PolygonContact.o \
	${OBJECTDIR}/Box2D/Dynamics/b2WorldCallbacks.o \
	${OBJECTDIR}/Box2D/Collision/Shapes/b2CircleShape.o \
	${OBJECTDIR}/Box2D/Dynamics/Joints/b2LineJoint.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/SensorFactory.o \
	${OBJECTDIR}/Box2D/Dynamics/Contacts/b2TOISolver.o \
	${OBJECTDIR}/Box2D/Collision/b2Collision.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolution.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/EventFactory.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyVariable.o \
	${OBJECTDIR}/Box2D/Dynamics/Joints/b2FrictionJoint.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseButtonInjectorHandler.o \
	${OBJECTDIR}/WasabiEngine/Utils/ConfigurationFileParser.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/Light.o \
	${OBJECTDIR}/Box2D/Dynamics/Joints/b2RevoluteJoint.o \
	${OBJECTDIR}/Box2D/Dynamics/Joints/b2PrismaticJoint.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/ParticleSystem.o \
	${OBJECTDIR}/Box2D/Dynamics/Contacts/b2CircleContact.o \
	${OBJECTDIR}/Box2D/Dynamics/Joints/b2MouseJoint.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSLeftShoulder.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolverState.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/ObjParser.o \
	${OBJECTDIR}/Box2D/Common/b2BlockAllocator.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSRightShoulder.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshLoader.o \
	${OBJECTDIR}/Box2D/Dynamics/Joints/b2Joint.o \
	${OBJECTDIR}/WasabiEngine/Utils/MathUtil.o \
	${OBJECTDIR}/TinyXML/tinyxml.o \
	${OBJECTDIR}/Box2D/Common/b2StackAllocator.o \
	${OBJECTDIR}/WasabiEngine/PhysicEngine/ObjectContactListener.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTrapezoid.o \
	${OBJECTDIR}/Box2D/Dynamics/Contacts/b2Contact.o \
	${OBJECTDIR}/Box2D/Collision/b2TimeOfImpact.o \
	${OBJECTDIR}/Box2D/Collision/b2DynamicTree.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/HandlerRegistration.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RoutePlanner.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTriangle.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIResizeInjectorHandler.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUISystem.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyParser.o \
	${OBJECTDIR}/Box2D/Common/b2Math.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/SpotLight.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPPenalties.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/SDL_PumpEventsWrapper.o \
	${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPProblem.o \
	${OBJECTDIR}/Box2D/Collision/b2Distance.o \
	${OBJECTDIR}/Box2D/Dynamics/Contacts/b2ContactSolver.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/SceneryFactory.o \
	${OBJECTDIR}/TinyXML/tinyxmlerror.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSSingleton.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneNode.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneManager.o \
	${OBJECTDIR}/Box2D/Collision/b2CollidePolygon.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/VideoResizeEventHandler.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshPrototype.o \
	${OBJECTDIR}/WasabiEngine/PhysicEngine/Box2dWorld.o \
	${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicObject.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FzAnd.o \
	${OBJECTDIR}/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/RadialParticleSystem.o \
	${OBJECTDIR}/WasabiEngine/EventEngine/MouseMotionEventHandler.o \
	${OBJECTDIR}/Box2D/Dynamics/b2World.o \
	${OBJECTDIR}/Box2D/Dynamics/Joints/b2GearJoint.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/GameWorld3D.o \
	${OBJECTDIR}/TinyXML/tinystr.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/GameObjectManager.o \
	${OBJECTDIR}/Box2D/Dynamics/b2Fixture.o \
	${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicEngine.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/TextureLoader.o \
	${OBJECTDIR}/WasabiEngine/GraphicEngine/LinearParticleSystem.o \
	${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RouteNode.o \
	${OBJECTDIR}/WasabiEngine/GameEngine/GameSystemManager.o \
	${OBJECTDIR}/Box2D/Dynamics/b2ContactManager.o \
	${OBJECTDIR}/Box2D/Dynamics/b2Island.o \
	${OBJECTDIR}/Box2D/Dynamics/b2Body.o \
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
CCFLAGS=-mwindows -Dmain=SDLmain
CXXFLAGS=-mwindows -Dmain=SDLmain

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libwasabiengine.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libwasabiengine.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libwasabiengine.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libwasabiengine.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libwasabiengine.a

${OBJECTDIR}/WasabiEngine/PhysicEngine/WorldContactListener.o: WasabiEngine/PhysicEngine/WorldContactListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/PhysicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/PhysicEngine/WorldContactListener.o WasabiEngine/PhysicEngine/WorldContactListener.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPBranchBound.o: WasabiEngine/OptimizationEngine/LPBranchBound.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPBranchBound.o WasabiEngine/OptimizationEngine/LPBranchBound.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/KeyboardEventHandler.o: WasabiEngine/EventEngine/KeyboardEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/KeyboardEventHandler.o WasabiEngine/EventEngine/KeyboardEventHandler.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/MouseButtonEventHandler.o: WasabiEngine/EventEngine/MouseButtonEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/MouseButtonEventHandler.o WasabiEngine/EventEngine/MouseButtonEventHandler.cpp

${OBJECTDIR}/Box2D/Dynamics/Joints/b2WeldJoint.o: Box2D/Dynamics/Joints/b2WeldJoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Joints
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Joints/b2WeldJoint.o Box2D/Dynamics/Joints/b2WeldJoint.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/QuitHandler.o: WasabiEngine/GameEngine/QuitHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/QuitHandler.o WasabiEngine/GameEngine/QuitHandler.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/Event.o: WasabiEngine/EventEngine/Event.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/Event.o WasabiEngine/EventEngine/Event.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzySet.o: WasabiEngine/AIEngine/FuzzyModule/FuzzySet.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzySet.o WasabiEngine/AIEngine/FuzzyModule/FuzzySet.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIKeyboardInjectorHandler.o: WasabiEngine/GraphicEngine/GUI/CEGUIKeyboardInjectorHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIKeyboardInjectorHandler.o WasabiEngine/GraphicEngine/GUI/CEGUIKeyboardInjectorHandler.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/ContactEventHandler.o: WasabiEngine/EventEngine/ContactEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/ContactEventHandler.o WasabiEngine/EventEngine/ContactEventHandler.cpp

${OBJECTDIR}/Box2D/Common/b2Settings.o: Box2D/Common/b2Settings.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Common
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Common/b2Settings.o Box2D/Common/b2Settings.cpp

${OBJECTDIR}/WasabiEngine/Utils/Vectors.o: WasabiEngine/Utils/Vectors.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/Utils
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/Utils/Vectors.o WasabiEngine/Utils/Vectors.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolver.o: WasabiEngine/OptimizationEngine/LPSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolver.o WasabiEngine/OptimizationEngine/LPSolver.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/LightPoint.o: WasabiEngine/GraphicEngine/LightPoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/LightPoint.o WasabiEngine/GraphicEngine/LightPoint.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/GameLoop.o: WasabiEngine/GameEngine/GameLoop.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/GameLoop.o WasabiEngine/GameEngine/GameLoop.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshMap.o: WasabiEngine/GraphicEngine/MeshMap.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshMap.o WasabiEngine/GraphicEngine/MeshMap.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/SensorEventHandler.o: WasabiEngine/EventEngine/SensorEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/SensorEventHandler.o WasabiEngine/EventEngine/SensorEventHandler.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyRule.o: WasabiEngine/AIEngine/FuzzyModule/FuzzyRule.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyRule.o WasabiEngine/AIEngine/FuzzyModule/FuzzyRule.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseMotionInjectorHandler.o: WasabiEngine/GraphicEngine/GUI/CEGUIMouseMotionInjectorHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseMotionInjectorHandler.o WasabiEngine/GraphicEngine/GUI/CEGUIMouseMotionInjectorHandler.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Material.o: WasabiEngine/GraphicEngine/Material.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Material.o WasabiEngine/GraphicEngine/Material.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GraphicObject.o: WasabiEngine/GraphicEngine/GraphicObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GraphicObject.o WasabiEngine/GraphicEngine/GraphicObject.cpp

${OBJECTDIR}/Box2D/Dynamics/Joints/b2PulleyJoint.o: Box2D/Dynamics/Joints/b2PulleyJoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Joints
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Joints/b2PulleyJoint.o Box2D/Dynamics/Joints/b2PulleyJoint.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/ColourValue.o: WasabiEngine/GraphicEngine/ColourValue.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/ColourValue.o WasabiEngine/GraphicEngine/ColourValue.cpp

${OBJECTDIR}/TinyXML/tinyxmlparser.o: TinyXML/tinyxmlparser.cpp 
	${MKDIR} -p ${OBJECTDIR}/TinyXML
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/TinyXML/tinyxmlparser.o TinyXML/tinyxmlparser.cpp

${OBJECTDIR}/Box2D/Collision/b2CollideCircle.o: Box2D/Collision/b2CollideCircle.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Collision
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Collision/b2CollideCircle.o Box2D/Collision/b2CollideCircle.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Quaternion.o: WasabiEngine/GraphicEngine/Quaternion.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Quaternion.o WasabiEngine/GraphicEngine/Quaternion.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Mesh.o: WasabiEngine/GraphicEngine/Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Mesh.o WasabiEngine/GraphicEngine/Mesh.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/objLoader.o: WasabiEngine/GraphicEngine/objLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/objLoader.o WasabiEngine/GraphicEngine/objLoader.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/GameObject.o: WasabiEngine/GameEngine/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/GameObject.o WasabiEngine/GameEngine/GameObject.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/EventEngine.o: WasabiEngine/EventEngine/EventEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/EventEngine.o WasabiEngine/EventEngine/EventEngine.cpp

${OBJECTDIR}/Box2D/Dynamics/Joints/b2DistanceJoint.o: Box2D/Dynamics/Joints/b2DistanceJoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Joints
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Joints/b2DistanceJoint.o Box2D/Dynamics/Joints/b2DistanceJoint.cpp

${OBJECTDIR}/Box2D/Collision/b2BroadPhase.o: Box2D/Collision/b2BroadPhase.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Collision
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Collision/b2BroadPhase.o Box2D/Collision/b2BroadPhase.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/RenderSystem.o: WasabiEngine/GraphicEngine/RenderSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/RenderSystem.o WasabiEngine/GraphicEngine/RenderSystem.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSimplex.o: WasabiEngine/OptimizationEngine/LPSimplex.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSimplex.o WasabiEngine/OptimizationEngine/LPSimplex.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/SensorContactListener.o: WasabiEngine/GameEngine/SensorContactListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/SensorContactListener.o WasabiEngine/GameEngine/SensorContactListener.cpp

${OBJECTDIR}/Box2D/Collision/Shapes/b2PolygonShape.o: Box2D/Collision/Shapes/b2PolygonShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Collision/Shapes
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Collision/Shapes/b2PolygonShape.o Box2D/Collision/Shapes/b2PolygonShape.cpp

${OBJECTDIR}/Box2D/Dynamics/Contacts/b2PolygonContact.o: Box2D/Dynamics/Contacts/b2PolygonContact.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Contacts
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Contacts/b2PolygonContact.o Box2D/Dynamics/Contacts/b2PolygonContact.cpp

${OBJECTDIR}/Box2D/Dynamics/b2WorldCallbacks.o: Box2D/Dynamics/b2WorldCallbacks.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/b2WorldCallbacks.o Box2D/Dynamics/b2WorldCallbacks.cpp

${OBJECTDIR}/Box2D/Collision/Shapes/b2CircleShape.o: Box2D/Collision/Shapes/b2CircleShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Collision/Shapes
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Collision/Shapes/b2CircleShape.o Box2D/Collision/Shapes/b2CircleShape.cpp

${OBJECTDIR}/Box2D/Dynamics/Joints/b2LineJoint.o: Box2D/Dynamics/Joints/b2LineJoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Joints
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Joints/b2LineJoint.o Box2D/Dynamics/Joints/b2LineJoint.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/SensorFactory.o: WasabiEngine/GameEngine/SensorFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/SensorFactory.o WasabiEngine/GameEngine/SensorFactory.cpp

${OBJECTDIR}/Box2D/Dynamics/Contacts/b2TOISolver.o: Box2D/Dynamics/Contacts/b2TOISolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Contacts
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Contacts/b2TOISolver.o Box2D/Dynamics/Contacts/b2TOISolver.cpp

${OBJECTDIR}/Box2D/Collision/b2Collision.o: Box2D/Collision/b2Collision.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Collision
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Collision/b2Collision.o Box2D/Collision/b2Collision.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolution.o: WasabiEngine/OptimizationEngine/LPSolution.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolution.o WasabiEngine/OptimizationEngine/LPSolution.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/EventFactory.o: WasabiEngine/EventEngine/EventFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/EventFactory.o WasabiEngine/EventEngine/EventFactory.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyVariable.o: WasabiEngine/AIEngine/FuzzyModule/FuzzyVariable.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyVariable.o WasabiEngine/AIEngine/FuzzyModule/FuzzyVariable.cpp

${OBJECTDIR}/Box2D/Dynamics/Joints/b2FrictionJoint.o: Box2D/Dynamics/Joints/b2FrictionJoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Joints
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Joints/b2FrictionJoint.o Box2D/Dynamics/Joints/b2FrictionJoint.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseButtonInjectorHandler.o: WasabiEngine/GraphicEngine/GUI/CEGUIMouseButtonInjectorHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIMouseButtonInjectorHandler.o WasabiEngine/GraphicEngine/GUI/CEGUIMouseButtonInjectorHandler.cpp

${OBJECTDIR}/WasabiEngine/Utils/ConfigurationFileParser.o: WasabiEngine/Utils/ConfigurationFileParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/Utils
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/Utils/ConfigurationFileParser.o WasabiEngine/Utils/ConfigurationFileParser.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Light.o: WasabiEngine/GraphicEngine/Light.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Light.o WasabiEngine/GraphicEngine/Light.cpp

${OBJECTDIR}/Box2D/Dynamics/Joints/b2RevoluteJoint.o: Box2D/Dynamics/Joints/b2RevoluteJoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Joints
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Joints/b2RevoluteJoint.o Box2D/Dynamics/Joints/b2RevoluteJoint.cpp

${OBJECTDIR}/Box2D/Dynamics/Joints/b2PrismaticJoint.o: Box2D/Dynamics/Joints/b2PrismaticJoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Joints
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Joints/b2PrismaticJoint.o Box2D/Dynamics/Joints/b2PrismaticJoint.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/ParticleSystem.o: WasabiEngine/GraphicEngine/ParticleSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/ParticleSystem.o WasabiEngine/GraphicEngine/ParticleSystem.cpp

${OBJECTDIR}/Box2D/Dynamics/Contacts/b2CircleContact.o: Box2D/Dynamics/Contacts/b2CircleContact.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Contacts
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Contacts/b2CircleContact.o Box2D/Dynamics/Contacts/b2CircleContact.cpp

${OBJECTDIR}/Box2D/Dynamics/Joints/b2MouseJoint.o: Box2D/Dynamics/Joints/b2MouseJoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Joints
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Joints/b2MouseJoint.o Box2D/Dynamics/Joints/b2MouseJoint.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSLeftShoulder.o: WasabiEngine/AIEngine/FuzzyModule/FSLeftShoulder.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSLeftShoulder.o WasabiEngine/AIEngine/FuzzyModule/FSLeftShoulder.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.o: WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.o WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolverState.o: WasabiEngine/OptimizationEngine/LPSolverState.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPSolverState.o WasabiEngine/OptimizationEngine/LPSolverState.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/ObjParser.o: WasabiEngine/GraphicEngine/ObjParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/ObjParser.o WasabiEngine/GraphicEngine/ObjParser.cpp

${OBJECTDIR}/Box2D/Common/b2BlockAllocator.o: Box2D/Common/b2BlockAllocator.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Common
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Common/b2BlockAllocator.o Box2D/Common/b2BlockAllocator.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSRightShoulder.o: WasabiEngine/AIEngine/FuzzyModule/FSRightShoulder.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSRightShoulder.o WasabiEngine/AIEngine/FuzzyModule/FSRightShoulder.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshLoader.o: WasabiEngine/GraphicEngine/MeshLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshLoader.o WasabiEngine/GraphicEngine/MeshLoader.cpp

${OBJECTDIR}/Box2D/Dynamics/Joints/b2Joint.o: Box2D/Dynamics/Joints/b2Joint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Joints
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Joints/b2Joint.o Box2D/Dynamics/Joints/b2Joint.cpp

${OBJECTDIR}/WasabiEngine/Utils/MathUtil.o: WasabiEngine/Utils/MathUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/Utils
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/Utils/MathUtil.o WasabiEngine/Utils/MathUtil.cpp

${OBJECTDIR}/TinyXML/tinyxml.o: TinyXML/tinyxml.cpp 
	${MKDIR} -p ${OBJECTDIR}/TinyXML
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/TinyXML/tinyxml.o TinyXML/tinyxml.cpp

${OBJECTDIR}/Box2D/Common/b2StackAllocator.o: Box2D/Common/b2StackAllocator.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Common
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Common/b2StackAllocator.o Box2D/Common/b2StackAllocator.cpp

${OBJECTDIR}/WasabiEngine/PhysicEngine/ObjectContactListener.o: WasabiEngine/PhysicEngine/ObjectContactListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/PhysicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/PhysicEngine/ObjectContactListener.o WasabiEngine/PhysicEngine/ObjectContactListener.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTrapezoid.o: WasabiEngine/AIEngine/FuzzyModule/FSTrapezoid.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTrapezoid.o WasabiEngine/AIEngine/FuzzyModule/FSTrapezoid.cpp

${OBJECTDIR}/Box2D/Dynamics/Contacts/b2Contact.o: Box2D/Dynamics/Contacts/b2Contact.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Contacts
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Contacts/b2Contact.o Box2D/Dynamics/Contacts/b2Contact.cpp

${OBJECTDIR}/Box2D/Collision/b2TimeOfImpact.o: Box2D/Collision/b2TimeOfImpact.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Collision
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Collision/b2TimeOfImpact.o Box2D/Collision/b2TimeOfImpact.cpp

${OBJECTDIR}/Box2D/Collision/b2DynamicTree.o: Box2D/Collision/b2DynamicTree.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Collision
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Collision/b2DynamicTree.o Box2D/Collision/b2DynamicTree.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/HandlerRegistration.o: WasabiEngine/EventEngine/HandlerRegistration.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/HandlerRegistration.o WasabiEngine/EventEngine/HandlerRegistration.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RoutePlanner.o: WasabiEngine/AIEngine/Routing/RoutePlanner.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/Routing
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RoutePlanner.o WasabiEngine/AIEngine/Routing/RoutePlanner.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTriangle.o: WasabiEngine/AIEngine/FuzzyModule/FSTriangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSTriangle.o WasabiEngine/AIEngine/FuzzyModule/FSTriangle.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIResizeInjectorHandler.o: WasabiEngine/GraphicEngine/GUI/CEGUIResizeInjectorHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUIResizeInjectorHandler.o WasabiEngine/GraphicEngine/GUI/CEGUIResizeInjectorHandler.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUISystem.o: WasabiEngine/GraphicEngine/GUI/CEGUISystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GUI/CEGUISystem.o WasabiEngine/GraphicEngine/GUI/CEGUISystem.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyParser.o: WasabiEngine/AIEngine/FuzzyModule/FuzzyParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FuzzyParser.o WasabiEngine/AIEngine/FuzzyModule/FuzzyParser.cpp

${OBJECTDIR}/Box2D/Common/b2Math.o: Box2D/Common/b2Math.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Common
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Common/b2Math.o Box2D/Common/b2Math.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/SpotLight.o: WasabiEngine/GraphicEngine/SpotLight.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/SpotLight.o WasabiEngine/GraphicEngine/SpotLight.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPPenalties.o: WasabiEngine/OptimizationEngine/LPPenalties.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPPenalties.o WasabiEngine/OptimizationEngine/LPPenalties.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/SDL_PumpEventsWrapper.o: WasabiEngine/EventEngine/SDL_PumpEventsWrapper.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/SDL_PumpEventsWrapper.o WasabiEngine/EventEngine/SDL_PumpEventsWrapper.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPProblem.o: WasabiEngine/OptimizationEngine/LPProblem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPProblem.o WasabiEngine/OptimizationEngine/LPProblem.cpp

${OBJECTDIR}/Box2D/Collision/b2Distance.o: Box2D/Collision/b2Distance.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Collision
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Collision/b2Distance.o Box2D/Collision/b2Distance.cpp

${OBJECTDIR}/Box2D/Dynamics/Contacts/b2ContactSolver.o: Box2D/Dynamics/Contacts/b2ContactSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Contacts
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Contacts/b2ContactSolver.o Box2D/Dynamics/Contacts/b2ContactSolver.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/SceneryFactory.o: WasabiEngine/GameEngine/SceneryFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/SceneryFactory.o WasabiEngine/GameEngine/SceneryFactory.cpp

${OBJECTDIR}/TinyXML/tinyxmlerror.o: TinyXML/tinyxmlerror.cpp 
	${MKDIR} -p ${OBJECTDIR}/TinyXML
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/TinyXML/tinyxmlerror.o TinyXML/tinyxmlerror.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSSingleton.o: WasabiEngine/AIEngine/FuzzyModule/FSSingleton.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FSSingleton.o WasabiEngine/AIEngine/FuzzyModule/FSSingleton.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneNode.o: WasabiEngine/GraphicEngine/SceneNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneNode.o WasabiEngine/GraphicEngine/SceneNode.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneManager.o: WasabiEngine/GraphicEngine/SceneManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/SceneManager.o WasabiEngine/GraphicEngine/SceneManager.cpp

${OBJECTDIR}/Box2D/Collision/b2CollidePolygon.o: Box2D/Collision/b2CollidePolygon.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Collision
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Collision/b2CollidePolygon.o Box2D/Collision/b2CollidePolygon.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/VideoResizeEventHandler.o: WasabiEngine/EventEngine/VideoResizeEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/VideoResizeEventHandler.o WasabiEngine/EventEngine/VideoResizeEventHandler.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshPrototype.o: WasabiEngine/GraphicEngine/MeshPrototype.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/MeshPrototype.o WasabiEngine/GraphicEngine/MeshPrototype.cpp

${OBJECTDIR}/WasabiEngine/PhysicEngine/Box2dWorld.o: WasabiEngine/PhysicEngine/Box2dWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/PhysicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/PhysicEngine/Box2dWorld.o WasabiEngine/PhysicEngine/Box2dWorld.cpp

${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicObject.o: WasabiEngine/PhysicEngine/PhysicObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/PhysicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicObject.o WasabiEngine/PhysicEngine/PhysicObject.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FzAnd.o: WasabiEngine/AIEngine/FuzzyModule/FzAnd.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FzAnd.o WasabiEngine/AIEngine/FuzzyModule/FzAnd.cpp

${OBJECTDIR}/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.o: Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Contacts
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.o Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/RadialParticleSystem.o: WasabiEngine/GraphicEngine/RadialParticleSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/RadialParticleSystem.o WasabiEngine/GraphicEngine/RadialParticleSystem.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/MouseMotionEventHandler.o: WasabiEngine/EventEngine/MouseMotionEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/MouseMotionEventHandler.o WasabiEngine/EventEngine/MouseMotionEventHandler.cpp

${OBJECTDIR}/Box2D/Dynamics/b2World.o: Box2D/Dynamics/b2World.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/b2World.o Box2D/Dynamics/b2World.cpp

${OBJECTDIR}/Box2D/Dynamics/Joints/b2GearJoint.o: Box2D/Dynamics/Joints/b2GearJoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics/Joints
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/Joints/b2GearJoint.o Box2D/Dynamics/Joints/b2GearJoint.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/GameWorld3D.o: WasabiEngine/GameEngine/GameWorld3D.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/GameWorld3D.o WasabiEngine/GameEngine/GameWorld3D.cpp

${OBJECTDIR}/TinyXML/tinystr.o: TinyXML/tinystr.cpp 
	${MKDIR} -p ${OBJECTDIR}/TinyXML
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/TinyXML/tinystr.o TinyXML/tinystr.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/GameObjectManager.o: WasabiEngine/GameEngine/GameObjectManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/GameObjectManager.o WasabiEngine/GameEngine/GameObjectManager.cpp

${OBJECTDIR}/Box2D/Dynamics/b2Fixture.o: Box2D/Dynamics/b2Fixture.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/b2Fixture.o Box2D/Dynamics/b2Fixture.cpp

${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicEngine.o: WasabiEngine/PhysicEngine/PhysicEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/PhysicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/PhysicEngine/PhysicEngine.o WasabiEngine/PhysicEngine/PhysicEngine.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/TextureLoader.o: WasabiEngine/GraphicEngine/TextureLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/TextureLoader.o WasabiEngine/GraphicEngine/TextureLoader.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/LinearParticleSystem.o: WasabiEngine/GraphicEngine/LinearParticleSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/LinearParticleSystem.o WasabiEngine/GraphicEngine/LinearParticleSystem.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RouteNode.o: WasabiEngine/AIEngine/Routing/RouteNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/Routing
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/Routing/RouteNode.o WasabiEngine/AIEngine/Routing/RouteNode.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/GameSystemManager.o: WasabiEngine/GameEngine/GameSystemManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/GameSystemManager.o WasabiEngine/GameEngine/GameSystemManager.cpp

${OBJECTDIR}/Box2D/Dynamics/b2ContactManager.o: Box2D/Dynamics/b2ContactManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/b2ContactManager.o Box2D/Dynamics/b2ContactManager.cpp

${OBJECTDIR}/Box2D/Dynamics/b2Island.o: Box2D/Dynamics/b2Island.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/b2Island.o Box2D/Dynamics/b2Island.cpp

${OBJECTDIR}/Box2D/Dynamics/b2Body.o: Box2D/Dynamics/b2Body.cpp 
	${MKDIR} -p ${OBJECTDIR}/Box2D/Dynamics
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Box2D/Dynamics/b2Body.o Box2D/Dynamics/b2Body.cpp

${OBJECTDIR}/WasabiEngine/GameEngine/Sensor.o: WasabiEngine/GameEngine/Sensor.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GameEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GameEngine/Sensor.o WasabiEngine/GameEngine/Sensor.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Entity.o: WasabiEngine/GraphicEngine/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Entity.o WasabiEngine/GraphicEngine/Entity.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/Camera.o: WasabiEngine/GraphicEngine/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/Camera.o WasabiEngine/GraphicEngine/Camera.cpp

${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPRestriction.o: WasabiEngine/OptimizationEngine/LPRestriction.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/OptimizationEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/OptimizationEngine/LPRestriction.o WasabiEngine/OptimizationEngine/LPRestriction.cpp

${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FzOr.o: WasabiEngine/AIEngine/FuzzyModule/FzOr.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/AIEngine/FuzzyModule/FzOr.o WasabiEngine/AIEngine/FuzzyModule/FzOr.cpp

${OBJECTDIR}/WasabiEngine/EventEngine/QuitEventHandler.o: WasabiEngine/EventEngine/QuitEventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/EventEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/EventEngine/QuitEventHandler.o WasabiEngine/EventEngine/QuitEventHandler.cpp

${OBJECTDIR}/WasabiEngine/GraphicEngine/GraphicEngine.o: WasabiEngine/GraphicEngine/GraphicEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/WasabiEngine/GraphicEngine
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/WasabiEngine/GraphicEngine/GraphicEngine.o WasabiEngine/GraphicEngine/GraphicEngine.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libwasabiengine.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
