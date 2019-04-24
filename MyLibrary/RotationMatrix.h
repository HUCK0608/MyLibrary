#pragma once
#include "Matrix.h"

class FRotationMatrix : public FMatrix
{
public:
	static FMatrix MakeFromX(float Roll);
	static FMatrix MakeFromY(float Pitch);
	static FMatrix MakeFromZ(float Yaw);
};

FMatrix FRotationMatrix::MakeFromX(float Roll)
{
	float SR, CR;
	FMath::SinCos(&SR, &CR, FMath::DegreesToRadians(Roll));
	return FMatrix(
		FPlane(1.0f, 0.0f,	0.0f,	0.0f),
		FPlane(0.0f, CR,    -SR,	0.0f),
		FPlane(0.0f, SR,	CR,		0.0f),
		FPlane(0.0f, 0.0f,	0.0f,	1.0f)
	);
}

inline FMatrix FRotationMatrix::MakeFromY(float Pitch)
{
	float SP, CP;
	FMath::SinCos(&SP, &CP, FMath::DegreesToRadians(Pitch));
	return FMatrix(
		FPlane(CP,	 0.0f,   SP,	0.0f),
		FPlane(0.0f, 1.0f,   0.0f,	0.0f),
		FPlane(-SP,	 0.0f,   CP,	0.0f),
		FPlane(0.0f, 0.0f,   0.0f,	1.0f)
	);
}

inline FMatrix FRotationMatrix::MakeFromZ(float Yaw)
{
	float SY, CY;
	FMath::SinCos(&SY, &CY, FMath::DegreesToRadians(Yaw));
	return FMatrix(
		FPlane(CY,		SY,		0.0f, 0.0f),
		FPlane(-SY,		CY,		0.0f, 0.0f),
		FPlane(0.0f,	0.0f,	1.0f, 0.0f),
		FPlane(0.0f,	0.0f,	0.0f, 1.0f)
	);
}
