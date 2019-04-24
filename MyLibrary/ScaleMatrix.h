#pragma once
#include "Matrix.h"

class FScaleMatrix : public FMatrix
{
public:
	FScaleMatrix(float Scale);
	FScaleMatrix(const FVector& Scale);

public:
	static FMatrix Make(float Scale)
	{
		return FScaleMatrix(Scale);
	}

	static FMatrix Make(const FVector& Scale)
	{
		return FScaleMatrix(Scale);
	}
};

FORCEINLINE FScaleMatrix::FScaleMatrix(float Scale)
	: FMatrix(
		FPlane(Scale,	0.0f,	0.0f,	0.0f),
		FPlane(0.0f,	Scale,	0.0f,	0.0f),
		FPlane(0.0f,	0.0f,	Scale,	0.0f),
		FPlane(0.0f,	0.0f,	0.0f,	1.0f)
	)
{}

FORCEINLINE FScaleMatrix::FScaleMatrix(const FVector& Scale)
	: FMatrix(
		FPlane(Scale.X,	0.0f,		0.0f,		0.0f),
		FPlane(0.0f,	Scale.Y,	0.0f,		0.0f),
		FPlane(0.0f,	0.0f,		Scale.Z,	0.0f),
		FPlane(0.0f,	0.0f,		0.0f,		1.0f)
	)
{}
