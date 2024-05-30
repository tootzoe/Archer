




UE_ROOT = D:/UE5/UE_5.4

INCLUDEPATH += $$UE_ROOT/Engine/Source \
                           $$UE_ROOT/Engine/Intermediate/Build/Win64/UE4Editor/Inc \
                           $$UE_ROOT/Engine/Intermediate/Build/Win64/UE4Editor/Inc/Engine/UHT \
                           $$UE_ROOT/Engine/Source/Runtime \
                           $$UE_ROOT/Engine/Source/Runtime/Engine/Classes \
                           $$UE_ROOT/Engine/Source/Runtime/Engine/Public \
                           $$UE_ROOT/Engine/Source/Runtime/TraceLog/Public \
                           $$UE_ROOT/Engine/Source/Runtime/Core/Public \
                           $$UE_ROOT/Engine/Source/Runtime/CoreUObject/Public \
                           $$UE_ROOT/Engine/Source/Runtime/UMG/Public \
                           $$UE_ROOT/Engine/Source/Runtime/Experimental/Chaos/Public \
                           $$UE_ROOT/Engine/Source/Runtime/AIModule/Classes \
                           $$UE_ROOT/Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public

######  Project reletived
INCLUDEPATH += ./../Intermediate/Build/Win64/UnrealEditor/Inc/Archer/UHT

INCLUDEPATH += ./Archer




DEFINES += "USE_QTCREATOR"
DEFINES += "ARCHER_API=  "

DEFINES += "BlueprintCallable" "Blueprintable"  \
           "BlueprintImplementableEvent" \
           "BlueprintNativeEvent" \
           "_Implementation" "VisibleAnywhere" \
            "EditAnywhere" "BlueprintReadWrite" \
            "Category" "BlueprintReadOnly" \
            "Transient" "VisibleDefaultsOnly" \
            "EditDefaultsOnly" "EditInstanceOnly" \
            "AllowPrivateAccess"


#####

DISTFILES += \
    Archer.Target.cs \
    Archer/Archer.Build.cs \
    ArcherEditor.Target.cs

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
    Archer/Character/StateMachines/Locomotion/LocomotionStates/Slowmo.h \
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
    Archer/Character/StateMachines/Locomotion/LocomotionStates/Slowmo.cpp \
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









