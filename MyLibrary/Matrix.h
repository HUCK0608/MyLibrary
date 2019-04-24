#pragma once
#include "WindowsPlatform.h"
#include "MathSSE.h"
#include "Vector.h"
#include "Plane.h"
#include "Rotator.h"

struct FMatrix
{
public:
	union
	{
		MS_ALIGN(16) float M[4][4];
	};

public:
	FORCEINLINE FMatrix();
	FORCEINLINE FMatrix(const FPlane& InX, const FPlane& InY, const FPlane& InZ, const FPlane& InW);
	FORCEINLINE FMatrix(const FVector& InX, const FVector& InY, const FVector& InZ, const FVector& InW);
	

public:
	inline void SetIdentity();

	FORCEINLINE FMatrix operator*(const FMatrix& Other) const;
	FORCEINLINE FVector operator*(const FVector& V) const;

	inline bool operator==(const FMatrix& Other) const;
};

FORCEINLINE FMatrix::FMatrix()
{}

FORCEINLINE FMatrix::FMatrix(const FPlane& InX, const FPlane& InY, const FPlane& InZ, const FPlane& InW)
{
	M[0][0] = InX.X; M[0][1] = InX.Y;  M[0][2] = InX.Z;  M[0][3] = InX.W;
	M[1][0] = InY.X; M[1][1] = InY.Y;  M[1][2] = InY.Z;  M[1][3] = InY.W;
	M[2][0] = InZ.X; M[2][1] = InZ.Y;  M[2][2] = InZ.Z;  M[2][3] = InZ.W;
	M[3][0] = InW.X; M[3][1] = InW.Y;  M[3][2] = InW.Z;  M[3][3] = InW.W;
}

FORCEINLINE FMatrix::FMatrix(const FVector& InX, const FVector& InY, const FVector& InZ, const FVector& InW)
{
	M[0][0] = InX.X; M[0][1] = InX.Y;  M[0][2] = InX.Z;  M[0][3] = 0.0f;
	M[1][0] = InY.X; M[1][1] = InY.Y;  M[1][2] = InY.Z;  M[1][3] = 0.0f;
	M[2][0] = InZ.X; M[2][1] = InZ.Y;  M[2][2] = InZ.Z;  M[2][3] = 0.0f;
	M[3][0] = InW.X; M[3][1] = InW.Y;  M[3][2] = InW.Z;  M[3][3] = 1.0f;
}

inline void FMatrix::SetIdentity()
{
	M[0][0] = 1; M[0][1] = 0;  M[0][2] = 0;  M[0][3] = 0;
	M[1][0] = 0; M[1][1] = 1;  M[1][2] = 0;  M[1][3] = 0;
	M[2][0] = 0; M[2][1] = 0;  M[2][2] = 1;  M[2][3] = 0;
	M[3][0] = 0; M[3][1] = 0;  M[3][2] = 0;  M[3][3] = 1;
}

FORCEINLINE FMatrix FMatrix::operator*(const FMatrix& Other) const
{
	FMatrix Result;
	VectorMatrixMultiply(&Result, this, &Other);
	return Result;
}

FORCEINLINE FVector FMatrix::operator*(const FVector & V) const
{
	return FVector(
		V.X * M[0][0] + V.Y * M[1][0] + V.Z * M[2][0] + 1.0f * M[3][0],
		V.X * M[0][1] + V.Y * M[1][1] + V.Z * M[2][1] + 1.0f * M[3][1],
		V.X * M[0][2] + V.Y * M[1][2] + V.Z * M[2][2] + 1.0f * M[3][2]
	);
}

inline bool FMatrix::operator==(const FMatrix& Other) const
{
	for (int X = 0; X < 4; X++)
	{
		for (int Y = 0; Y < 4; Y++)
		{
			if (M[X][Y] != Other.M[X][Y])
			{
				return false;
			}
		}
	}

	return true;
}