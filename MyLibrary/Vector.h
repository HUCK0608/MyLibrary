#pragma once
#include "MathUtility.h"

struct FVector
{
public:
	float X;
	float Y;
	float Z;

public:
	FVector() { X = 0.0f; Y = 0.0f; Z = 0.0f; }
	FVector(float InF) : X(InF), Y(InF), Z(InF) {}
	FVector(const float inX, const float inY, const float inZ) : X(inX), Y(inY), Z(inZ) {}

public:
	static const FVector ZeroVector;

	static const FVector OneVector;

	static const FVector UpVector;

	static const FVector DownVector;

	static const FVector ForwardVector;

	static const FVector BackVector;

	static const FVector RightVector;

	static const FVector LeftVector;

	FORCEINLINE FVector operator^(const FVector& V) const;

	FORCEINLINE static FVector CrossProduct(const FVector &A, const FVector &B);

	FORCEINLINE float operator|(const FVector& V) const;

	FORCEINLINE static float DotProduct(const FVector &A, const FVector &B);

	FORCEINLINE static float Dist(const FVector &V1, const FVector &V2);
	FORCEINLINE static float Distance(const FVector &V1, const FVector &V2) { return Dist(V1, V2); }

	FORCEINLINE static float DistSquared(const FVector &V1, const FVector &V2);

public:
	FORCEINLINE FVector operator+(const FVector &V) const;

	FORCEINLINE FVector operator-(const FVector &V) const;

	FORCEINLINE FVector operator*(const FVector &V) const;

	FORCEINLINE FVector operator/(const FVector &V) const;

	FORCEINLINE FVector operator+(float Bias) const;

	FORCEINLINE FVector operator-(float Bias) const;

	FORCEINLINE FVector operator*(float Scale) const;

	FORCEINLINE FVector operator/(float Scale) const;

	FORCEINLINE bool operator==(const FVector &V) const;

	FORCEINLINE bool operator!=(const FVector &V) const;

	bool Equals(const FVector &V, float Tolerance = KINDA_SMALL_NUMBER) const;

	FORCEINLINE bool AllComponentEqual(float Tolerance = KINDA_SMALL_NUMBER) const;

	FORCEINLINE FVector operator-() const;

	FORCEINLINE FVector operator+=(const FVector &V);

	FORCEINLINE FVector operator-=(const FVector &V);

	FORCEINLINE FVector operator*=(const FVector &V);

	FORCEINLINE FVector operator/=(const FVector &V);

	FORCEINLINE FVector operator*=(float Scale);

	FVector operator/=(float V);

	bool IsZero() const;

	float Size() const;

	float SizeSquared() const;

	FORCEINLINE FVector GetUnsafeNormal() const;

	FVector GetSafeNormal(float Tolerance=SMALL_NUMBER) const;

	FVector Reciprocal() const;
};

const FVector FVector::ZeroVector(0.0f, 0.0f, 0.0f);
const FVector FVector::OneVector(1.0f, 1.0f, 1.0f);
const FVector FVector::UpVector(0.0f, 0.0f, 1.0f);
const FVector FVector::DownVector(0.0f, 0.0f, -1.0f);
const FVector FVector::ForwardVector(1.0f, 0.0f, 0.0f);
const FVector FVector::BackVector(-1.0f, 0.0f, 0.0f);
const FVector FVector::RightVector(0.0f, 1.0f, 0.0f);
const FVector FVector::LeftVector(0.0f, -1.0f, 0.0f);

inline FVector FVector::operator^(const FVector & V) const
{
	return FVector
	(
		Y * V.Z - Z * V.Y,
		Z * V.X - X * V.Z,
		X * V.Y - Y * V.X
	);
}

FORCEINLINE FVector FVector::CrossProduct(const FVector & A, const FVector & B)
{
	return A ^ B;
}

FORCEINLINE float FVector::operator|(const FVector & V) const
{
	return X * V.X + Y * V.Y + Z * V.Z;
}

FORCEINLINE float FVector::DotProduct(const FVector & A, const FVector & B)
{
	return A | B;
}

FORCEINLINE float FVector::Dist(const FVector & V1, const FVector & V2)
{
	return FMath::Sqrt(FVector::DistSquared(V1, V2));
}

FORCEINLINE float FVector::DistSquared(const FVector & V1, const FVector & V2)
{
	return FMath::Square(V2.X - V1.X) + FMath::Square(V2.Y - V1.Y) + FMath::Square(V2.Z - V1.Z);
}

FORCEINLINE FVector FVector::operator+(const FVector & V) const
{
	return FVector(X + V.X, Y + V.Y, Z + V.Z);
}

FORCEINLINE FVector FVector::operator-(const FVector & V) const
{
	return FVector(X - V.X, Y - V.Y, Z - V.Z);
}

FORCEINLINE FVector FVector::operator*(const FVector & V) const
{
	return FVector(X * V.X, Y * V.Y, Z * V.Z);
}

FORCEINLINE FVector FVector::operator/(const FVector & V) const
{
	return FVector(X / V.X, Y / V.Y, Z / V.Z);
}

FORCEINLINE FVector FVector::operator+(float Bias) const
{
	return FVector(X + Bias, Y + Bias, Z + Bias);
}

FORCEINLINE FVector FVector::operator-(float Bias) const
{
	return FVector(X - Bias, Y - Bias, Z - Bias);
}

FORCEINLINE FVector FVector::operator*(float Scale) const
{
	return FVector(X * Scale, Y * Scale, Z * Scale);
}

FORCEINLINE FVector FVector::operator/(float Scale) const
{
	const float RScale = 1.f / Scale;
	return FVector(X * RScale, Y * RScale, Z * RScale);
}

FORCEINLINE bool FVector::operator==(const FVector & V) const
{
	return X == V.X && Y == V.Y && Z == V.Z;
}

FORCEINLINE bool FVector::operator!=(const FVector & V) const
{
	return X != V.X || Y != V.Y || Z != V.Z;
}

FORCEINLINE bool FVector::Equals(const FVector & V, float Tolerance) const
{
	return FMath::Abs(X - V.X) <= Tolerance && FMath::Abs(Y - V.Y) <= Tolerance && FMath::Abs(Z - V.Z) <= Tolerance;
}

FORCEINLINE bool FVector::AllComponentEqual(float Tolerance) const
{
	return FMath::Abs(X - Y) <= Tolerance && FMath::Abs(X - Z) <= Tolerance && FMath::Abs(Y - Z) <= Tolerance;
}

FORCEINLINE FVector FVector::operator-() const
{
	return FVector(-X, -Y, -Z);
}

FORCEINLINE FVector FVector::operator+=(const FVector & V)
{
	X += V.X; Y += V.Y;	Z += V.Z;
	return *this;
}

FORCEINLINE FVector FVector::operator-=(const FVector & V)
{
	X -= V.X; Y -= V.Y; Z -= V.Z;
	return *this;
}

FORCEINLINE FVector FVector::operator*=(const FVector & V)
{
	X *= V.X; Y *= V.Y; Z *= V.Z;
	return *this;
}

FORCEINLINE FVector FVector::operator/=(const FVector & V)
{
	X /= V.X; Y /= V.Y; Z /= V.Z;
	return *this;
}

FORCEINLINE FVector FVector::operator*=(float Scale)
{
	X *= Scale; Y *= Scale; Z *= Scale;
	return *this;
}

FORCEINLINE FVector FVector::operator/=(float V)
{
	const float RV = 1.f / V;
	X *= RV; Y *= RV; Z *= RV;
	return *this;
}

FORCEINLINE bool FVector::IsZero() const
{
	return X == 0.f && Y == 0.f && Z == 0.f;
}

FORCEINLINE float FVector::Size() const
{
	return FMath::Sqrt(X * X + Y * Y + Z * Z);
}

FORCEINLINE float FVector::SizeSquared() const
{
	return X * X + Y * Y + Z * Z;
}

FORCEINLINE FVector FVector::GetUnsafeNormal() const
{
	const float Scale = FMath::InvSqrt(X * X + Y * Y + Z * Z);
	return FVector(X * Scale, Y * Scale, Z * Scale);
}

FORCEINLINE FVector FVector::GetSafeNormal(float Tolerance) const
{
	const float SquareSum = X * X + Y * Y + Z * Z;

	if (SquareSum == 1.f)
	{
		return *this;
	}
	else if (SquareSum < Tolerance)
	{
		return FVector::ZeroVector;
	}
	const float Scale = FMath::InvSqrt(SquareSum);
	return FVector(X * Scale, Y * Scale, Z * Scale);
}

FORCEINLINE FVector FVector::Reciprocal() const
{
	FVector RecVector;

	if (X != 0.f)
		RecVector.X = 1.f / X;
	else
		RecVector.X = BIG_NUMBER;

	if (Y != 0.f)
		RecVector.Y = 1.f / Y;
	else
		RecVector.Y = BIG_NUMBER;

	if (Z != 0.f)
		RecVector.Z = 1.f / Z;
	else
		RecVector.Z = BIG_NUMBER;

	return RecVector;
}