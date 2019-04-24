#pragma once
#include "Matrix.h"

class FTranslationMatrix : public FMatrix
{
public:
	FTranslationMatrix(const FVector& Delta);

	static FMatrix Make(FVector const& Delta)
	{
		return FTranslationMatrix(Delta);
	}
};

FORCEINLINE FTranslationMatrix::FTranslationMatrix(const FVector& Delta)
	: FMatrix(
		FPlane(1.0f,	0.0f,	 0.0f,	  0.0f),
		FPlane(0.0f,	1.0f,	 0.0f,	  0.0f),
		FPlane(0.0f,	0.0f,	 1.0f,    0.0f),
		FPlane(Delta.X, Delta.Y, Delta.Z, 1.0f)
	)
{}
