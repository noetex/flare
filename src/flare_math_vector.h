typedef struct { float X, Y; } vector2;
typedef struct { float X, Y, Z; } vector3;
typedef struct { float X, Y, Z, W; } vector4;

static vector2 VECTOR2_ZERO = {0, 0};
static vector2 VECTOR2_UNIT_X = {1, 0};
static vector2 VECTOR2_UNIT_Y = {0, 1};
static vector3 VECTOR3_ZERO = {0, 0, 0};
static vector3 VECTOR3_UNIT_X = {1, 0, 0};
static vector3 VECTOR3_UNIT_Y = {0, 1, 0};
static vector3 VECTOR3_UNIT_Z = {0, 0, 1};
static vector4 VECTOR4_ZERO = {0, 0, 0, 0};
static vector4 VECTOR4_UNIT_X = {1, 0, 0, 0};
static vector4 VECTOR4_UNIT_Y = {0, 1, 0, 0};
static vector4 VECTOR4_UNIT_Z = {0, 0, 1, 0};
static vector4 VECTOR4_UNIT_W = {0, 0, 0, 1};

static float
vector2_dot(vector2 A, vector2 B)
{
	float Result = (A.X * B.X) + (A.Y * B.Y);
	return Result;
}

static float
vector3_dot(vector3 A, vector3 B)
{
	float Result = (A.X * B.X) + (A.Y * B.Y) + (A.Z * B.Z);
	return Result;
}

static float
vector4_dot(vector4 A, vector4 B)
{
	float Result = (A.X * B.X) + (A.Y * B.Y) + (A.Z * B.Z) + (A.W * B.W);
	return Result;
}

static float
vector2_length2(vector2 V)
{
	float Result = vector2_dot(V, V);
	return Result;
}

static float
vector3_length2(vector3 V)
{
	float Result = vector3_dot(V, V);
	return Result;
}

static float
vector4_length2(vector4 V)
{
	float Result = vector4_dot(V, V);
	return Result;
}

static float
vector2_length(vector2 V)
{
	float Length2 = vector2_length2(V);
	float Result = sqrtf(Length2);
	return Result;
}

static float
vector3_length(vector3 V)
{
	float Length2 = vector3_length2(V);
	float Result = sqrtf(Length2);
	return Result;
}

static float
vector4_length(vector4 V)
{
	float Length2 = vector4_length2(V);
	float Result = sqrtf(Length2);
	return Result;
}

static float
vector2_anglebetween(vector2 A, vector2 B)
{
	float Length2A = vector2_length2(A);
	float Length2B = vector2_length2(B);
	if((Length2A == 0) || (Length2B == 0))
	{
		return 0;
	}
	float LengthProduct = sqrtf(Length2A * Length2B);
	float Cosine = vector2_dot(A, B) / LengthProduct;
	float Result = acosf(Cosine);
	return Result;
}

static float
vector3_anglebetween(vector3 A, vector3 B)
{
	float Length2A = vector3_length2(A);
	float Length2B = vector3_length2(B);
	if((Length2A == 0) || (Length2B == 0))
	{
		return 0;
	}
	float LengthProduct = sqrtf(Length2A * Length2B);
	float Cosine = vector3_dot(A, B) / LengthProduct;
	float Result = acosf(Cosine);
	return Result;
}

static float
vector2_det(vector2 A, vector2 B)
{
	float Result = (A.X * B.Y) - (A.Y * B.X);
	return Result;
}

static vector2
vector2_add(vector2 A, vector2 B)
{
	vector2 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	return Result;
}

static vector3
vector3_add(vector3 A, vector3 B)
{
	vector3 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	Result.Z = A.Z + B.Z;
	return Result;
}

static vector4
vector4_add(vector4 A, vector4 B)
{
	vector4 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	Result.Z = A.Z + B.Z;
	Result.W = A.W + B.W;
	return Result;
}

static vector2
vector2_sub(vector2 A, vector2 B)
{
	vector2 Result;
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	return Result;
}

static vector3
vector3_sub(vector3 A, vector3 B)
{
	vector3 Result;
	Result.X = A.X - B.X;
	Result.X = A.Y - B.Y;
	Result.X = A.Z - B.Z;
	return Result;
}

static vector4
vector4_sub(vector4 A, vector4 B)
{
	vector4 Result;
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	Result.Z = A.Z - B.Z;
	Result.W = A.W - B.W;
	return Result;
}

static vector2
vector2_negate(vector2 V)
{
	vector2 Result;
	Result.X = -V.X;
	Result.Y = -V.Y;
	return Result;
}

static vector3
vector3_negate(vector3 V)
{
	vector3 Result;
	Result.X = -V.X;
	Result.Y = -V.Y;
	Result.Z = -V.Z;
	return Result;
}

static vector4
vector4_negate(vector4 V)
{
	vector4 Result;
	Result.X = -V.X;
	Result.Y = -V.Y;
	Result.Z = -V.Z;
	Result.W = -V.W;
	return Result;
}

static vector2
vector2_mul(vector2 V, float Scalar)
{
	vector2 Result;
	Result.X = V.X * Scalar;
	Result.Y = V.Y * Scalar;
	return Result;
}

static vector3
vector3_mul(vector3 V, float Scalar)
{
	vector3 Result;
	Result.X = V.X * Scalar;
	Result.Y = V.Y * Scalar;
	Result.Z = V.Z * Scalar;
	return Result;
}

static vector4
vector4_mul(vector4 V, float Scalar)
{
	vector4 Result;
	Result.X = V.X * Scalar;
	Result.Y = V.Y * Scalar;
	Result.Z = V.Z * Scalar;
	Result.W = V.W * Scalar;
	return Result;
}

static vector2
vector2_div(vector2 V, float Scalar)
{
	float Reciprocal = 1/Scalar;
	vector2 Result = vector2_mul(V, Reciprocal);
	return Result;
}

static vector3
vector3_div(vector3 V, float Scalar)
{
	float Reciprocal = 1/Scalar;
	vector3 Result = vector3_mul(V, Reciprocal);
	return Result;
}

static vector4
vector4_div(vector4 V, float Scalar)
{
	float Reciprocal = 1/Scalar;
	vector4 Result = vector4_mul(V, Reciprocal);
	return Result;
}

static vector2
vector2_unit(vector2 V)
{
	float Length2 = vector2_length2(V);
	if((Length2 == 0) || (Length2 == 1))
	{
		return V;
	}
	float Length = sqrtf(Length2);
	vector2 Result = vector2_div(V, Length);
	return Result;
}

static vector3
vector3_unit(vector3 V)
{
	float Length2 = vector3_length2(V);
	if((Length2 == 0) || (Length2 == 1))
	{
		return V;
	}
	float Length = sqrtf(Length2);
	vector3 Result = vector3_div(V, Length);
	return Result;
}

static vector4
vector4_unit(vector4 V)
{
	float Length2 = vector4_length2(V);
	if((Length2 == 0) || (Length2 == 1))
	{
		return V;
	}
	float Length = sqrtf(Length2);
	vector4 Result = vector4_div(V, Length);
	return Result;
}

static vector2
vector2_proj(vector2 A, vector2 B)
{
	float L2 = vector2_length2(B);
	if(L2 == 0)
	{
		return VECTOR2_ZERO;
	}
	vector2 Direction = B;
	float Magnitude = vector2_dot(A, B) / L2;
	vector2 Result = vector2_mul(Direction, Magnitude);
	return Result;
}

static vector3
vector3_proj(vector3 A, vector3 B)
{
	float L2 = vector3_length2(B);
	if(L2 == 0)
	{
		return VECTOR3_ZERO;
	}
	vector3 Direction = B;
	float Magnitude = vector3_dot(A, B) / L2;
	vector3 Result = vector3_mul(Direction, Magnitude);
	return Result;
}

static vector2
vector2_perp(vector2 A, vector2 B)
{
	vector2 Projected = vector2_proj(A, B);
	vector2 Result = vector2_sub(A, Projected);
	return Result;
}

static vector3
vector3_perp(vector3 A, vector3 B)
{
	vector3 Projected = vector3_proj(A, B);
	vector3 Result = vector3_sub(A, Projected);
	return Result;
}

static vector3
vector3_cross(vector3 A, vector3 B)
{
	vector3 Result;
	Result.X = (A.Y * B.Z) - (A.Z * B.Y);
	Result.Y = (A.Z * B.X) - (A.X * B.Z);
	Result.Z = (A.X * B.Y) - (A.Y * B.X);
	return Result;
}

static vector2
vector2_reflect(vector2 Vector, vector2 SurfaceNormal)
{
	vector2 Projection = vector2_proj(Vector, SurfaceNormal);
	vector2 Result = vector2_sub(Vector, vector2_mul(Projection, 2));
	return Result;
}

static vector3
vector3_reflect(vector3 Vector, vector3 SurfaceNormal)
{
	vector3 Projection = vector3_proj(Vector, SurfaceNormal);
	vector3 Result = vector3_sub(Vector, vector3_mul(Projection, 2));
	return Result;
}
