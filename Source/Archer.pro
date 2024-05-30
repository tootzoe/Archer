




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

DEFINES += "BlueprintCallable" \
           "BlueprintImplementableEvent" \
           "BlueprintNativeEvent" \
           "_Implementation" "VisibleAnywhere" \
            "EditAnywhere" "BlueprintReadWrite" \
            "Category" "BlueprintReadOnly" \
            "Transient" "VisibleDefaultsOnly" \
            "EditDefaultsOnly"


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
    Archer/TimeManagement/SlowTimeManager.h \
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
    Archer/TimeManagement/SlowTimeManager.cpp \
    Archer/Weapons/Projectile.cpp









