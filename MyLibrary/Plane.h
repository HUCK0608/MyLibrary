#pragma once
#include "Vector.h"

MS_ALIGN(16) struct FPlane : public FVector
{
public:
	float W;

public:
	FORCEINLINE FPlane();
	FORCEINLINE FPlane(float InX, float InY, float InZ, float InW);
};

FORCEINLINE FPlane::FPlane()
{}

FORCEINLINE FPlane::FPlane(float InX, float InY, float InZ, float InW)
	:	FVector(InX, InY, InZ)
	,	W(InW)
{}
