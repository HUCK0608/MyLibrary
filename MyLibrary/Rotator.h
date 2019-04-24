#pragma once
#include "WindowsPlatform.h"

struct FRotator
{
public:
	float Pitch;
	float Yaw;
	float Roll;

public:
	FORCEINLINE FRotator() {}
	FORCEINLINE FRotator(float InPitch, float InYaw, float InRoll) : Pitch(InPitch), Yaw(InYaw), Roll(InRoll) {}
};