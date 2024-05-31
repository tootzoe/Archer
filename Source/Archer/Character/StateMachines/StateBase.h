// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class  FStateBase
{
public:
    FStateBase();
    ~FStateBase();

    virtual void Begin() = 0;
    virtual void End() = 0;
};
