




#TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

#
# below one line project name need to be lowercaes
PRJNAMETOOT = Archer
DEFINES += "ARCHER_API="
DEFINES += "ARCHER_API(...)="
#
DEFINES += "UCLASS()=ARCHER_API"
DEFINES += "UCLASS(...)=ARCHER_API"
#
# this is true during development with unreal-editor...

DEFINES += "WITH_EDITORONLY_DATA=1"

## this project only
DEFINES += PLATFORM_ANDROID
##


INCLUDEPATH += ../Intermediate/Build/Win64/UnrealEditor/Inc/$$PRJNAMETOOT/UHT
INCLUDEPATH += $$PRJNAMETOOT $$PRJNAMETOOT/Public $$PRJNAMETOOT/Private
#INCLUDEPATH += ../Plugins/NNEPostProcessing/Source/NNEPostProcessing/Public
# we should follow UE project struct to include files, start from prj.Build.cs folder
#
#  The Thirdparty libs
#
#
#
include(defs.pri)
include(inc.pri)
#
## this project only
# INCLUDEPATH += $$UESRCROOT/Runtime/Renderer/Private
##
#
#

HEADERS += \
    Archer/AI/BTS_FindPlayer.h \
    Archer/AI/EnemyAIController.h \
    Archer/AI/EnemyBehaviorTree.h \
    Archer/AI/Wave/WaveSystem.h \
    Archer/Archer.h \
    Archer/Camera/ArcherCameraActorBase.h \
    Archer/Camera/ArcherPlayerCameraManager.h \
    Archer/Camera/OrbitalCameraActor.h \
    Archer/Camera/PrecisionCameraActor.h \
    Archer/Character/Animation/CharacterAnimInstance.h \
    Archer/Character/Animation/CharacterAnimationSlots.h \
    Archer/Character/Animation/CharacterAnimationStates.h \
    Archer/Character/Animation/CharacterAnimations.h \
    Archer/Character/ArcherCharacter.h \
    Archer/Character/CharacterBase.h \
    Archer/Character/Mechanics/ArchTrace.h \
    Archer/Character/Mechanics/CharacterMechanics.h \
    Archer/Character/Movement/CharacterMovement.h \
    Archer/Character/StateMachines/Locomotion/LocomotionStateMachine.h \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/ClimbState.h \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/DashState.h \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/JumpState.h \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/LocomotionStateBase.h \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/RunState.h \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/SlowmoState.h \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/WalkState.h \
    Archer/Character/StateMachines/Mechanics/MechanicsStateMachine.h \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/AimReadyState.h \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/AutoAimState.h \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/EmptyState.h \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/FreeAimState.h \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/MechanicStateBase.h \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/PrecisionAimState.h \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/ShieldState.h \
    Archer/Character/StateMachines/StateBase.h \
    Archer/Character/StateMachines/StateMachineBase.h \
    Archer/Enemies/Enemy.h \
    Archer/General/ArcherGameInstance.h \
    Archer/General/ArcherGameMode.h \
    Archer/General/ArcherGameState.h \
    Archer/Level/InteractiveElement.h \
    Archer/Level/RoomManager.h \
    Archer/Player/ArcherPlayerController.h \
    Archer/TimeManagement/SlowTimeManager.h \
    Archer/Utilities/Debug.h \
    Archer/Weapons/Projectile.h

SOURCES += \
    Archer/AI/BTS_FindPlayer.cpp \
    Archer/AI/EnemyAIController.cpp \
    Archer/AI/EnemyBehaviorTree.cpp \
    Archer/AI/Wave/WaveSystem.cpp \
    Archer/Archer.cpp \
    Archer/Camera/ArcherCameraActorBase.cpp \
    Archer/Camera/ArcherPlayerCameraManager.cpp \
    Archer/Camera/OrbitalCameraActor.cpp \
    Archer/Camera/PrecisionCameraActor.cpp \
    Archer/Character/Animation/CharacterAnimInstance.cpp \
    Archer/Character/Animation/CharacterAnimations.cpp \
    Archer/Character/ArcherCharacter.cpp \
    Archer/Character/CharacterBase.cpp \
    Archer/Character/Mechanics/ArchTrace.cpp \
    Archer/Character/Mechanics/CharacterMechanics.cpp \
    Archer/Character/Movement/CharacterMovement.cpp \
    Archer/Character/StateMachines/Locomotion/LocomotionStateMachine.cpp \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/ClimbState.cpp \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/DashState.cpp \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/JumpState.cpp \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/LocomotionStateBase.cpp \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/RunState.cpp \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/SlowmoState.cpp \
    Archer/Character/StateMachines/Locomotion/LocomotionStates/WalkState.cpp \
    Archer/Character/StateMachines/Mechanics/MechanicsStateMachine.cpp \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/AimReadyState.cpp \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/AutoAimState.cpp \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/EmptyState.cpp \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/FreeAimState.cpp \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/MechanicStateBase.cpp \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/PrecisionAimState.cpp \
    Archer/Character/StateMachines/Mechanics/MechanicsStates/ShieldState.cpp \
    Archer/Character/StateMachines/StateBase.cpp \
    Archer/Character/StateMachines/StateMachineBase.cpp \
    Archer/Enemies/Enemy.cpp \
    Archer/General/ArcherGameInstance.cpp \
    Archer/General/ArcherGameMode.cpp \
    Archer/General/ArcherGameState.cpp \
    Archer/Level/InteractiveElement.cpp \
    Archer/Level/RoomManager.cpp \
    Archer/Player/ArcherPlayerController.cpp \
    Archer/TimeManagement/SlowTimeManager.cpp \
    Archer/Weapons/Projectile.cpp

DISTFILES += \
    Archer.Target.cs \
    Archer/Archer.Build.cs \
    ArcherEditor.Target.cs
