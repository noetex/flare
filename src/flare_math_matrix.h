typedef struct
{
	vector4 AxisX;
	vector4 AxisY;
	vector4 AxisZ;
	vector4 AxisW;
} matrix4;

static matrix4 MATRIX4_IDENTITY =
{
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1},
};

static matrix4
matrix4_add(matrix4 A, matrix4 B)
{
	matrix4 Result;
	Result.AxisX = vector4_add(A.AxisX, B.AxisX);
	Result.AxisY = vector4_add(A.AxisY, B.AxisY);
	Result.AxisZ = vector4_add(A.AxisZ, B.AxisZ);
	Result.AxisW = vector4_add(A.AxisW, B.AxisW);
	return Result;
}

static matrix4
matrix4_sub(matrix4 A, matrix4 B)
{
	matrix4 Result;
	Result.AxisX = vector4_sub(A.AxisX, B.AxisX);
	Result.AxisY = vector4_sub(A.AxisY, B.AxisY);
	Result.AxisZ = vector4_sub(A.AxisZ, B.AxisZ);
	Result.AxisW = vector4_sub(A.AxisW, B.AxisW);
	return Result;
}

static matrix4
matrix4_negate(matrix4 M)
{
	matrix4 Result;
	Result.AxisX = vector4_negate(M.AxisX);
	Result.AxisY = vector4_negate(M.AxisY);
	Result.AxisZ = vector4_negate(M.AxisZ);
	Result.AxisW = vector4_negate(M.AxisW);
	return Result;
}

static matrix4
matrix4_mul_scalar(matrix4 M, float Scalar)
{
	matrix4 Result;
	Result.AxisX = vector4_mul(M.AxisX, Scalar);
	Result.AxisY = vector4_mul(M.AxisY, Scalar);
	Result.AxisZ = vector4_mul(M.AxisZ, Scalar);
	Result.AxisW = vector4_mul(M.AxisW, Scalar);
	return Result;
}

static matrix4
matrix4_div_scalar(matrix4 M, float Scalar)
{
	float Reciprocal = 1/Scalar;
	matrix4 Result = matrix4_mul_scalar(M, Reciprocal);
	return Result;
}

static vector4
matrix4_mul_vec4(matrix4 M, vector4 V)
{
	vector4 Result = vector4_mul(M.AxisX, V.X);
	Result = vector4_add(Result, vector4_mul(M.AxisY, V.Y));
	Result = vector4_add(Result, vector4_mul(M.AxisZ, V.Z));
	Result = vector4_add(Result, vector4_mul(M.AxisW, V.W));
	return Result;
}

static matrix4
matrix4_mul_matrix4(matrix4 A, matrix4 B)
{
	matrix4 Result;
	Result.AxisX = matrix4_mul_vec4(A, B.AxisX);
	Result.AxisY = matrix4_mul_vec4(A, B.AxisY);
	Result.AxisZ = matrix4_mul_vec4(A, B.AxisZ);
	Result.AxisW = matrix4_mul_vec4(A, B.AxisW);
	return Result;
}

static float
matrix4_det(matrix4 M)
{

}

static matrix4
matrix4_inverse(matrix4 M)
{

}

static matrix4
matrix4_rotate_x(float Angle)
{
	float S = sinf(Angle);
	float C = cosf(Angle);
	matrix4 Result;
	Result.AxisX = VECTOR4_UNIT_X;
	Result.AxisY = (vector4){0, C, S, 0};
	Result.AxisZ = (vector4){0, -S, C, 0};
	Result.AxisW = VECTOR4_UNIT_W;
	return Result;
}

static matrix4
matrix4_rorate_y(float Angle)
{
	float S = sinf(Angle);
	float C = cosf(Angle);
	matrix4 Result;
	Result.AxisX = (vector4){C, 0, -S, 0};
	Result.AxisY = VECTOR4_UNIT_Y;
	Result.AxisZ = (vector4){S, 0, C, 0};
	Result.AxisW = VECTOR4_UNIT_W;
	return Result;
}

static matrix4
matrix4_rotate_z(float Angle)
{
	float S = sinf(Angle);
	float C = cosf(Angle);
	matrix4 Result;
	Result.AxisX = (vector4){C, -S, 0, 0};
	Result.AxisY = (vector4){S, C, 0, 0};
	Result.AxisZ = VECTOR4_UNIT_Z;
	Result.AxisW = VECTOR4_UNIT_W;
	return Result;
}

static matrix4
matrix4_rotate_arbitrary(vector3 Axis, float Angle)
{
	Axis = vector3_unit(Axis);
	float C = cosf(Angle);
	float S = sinf(Angle);
	float OMC = 1 - C;
	float X2 = Axis.X * Axis.X;
	float Y2 = Axis.Y * Axis.Y;
	float Z2 = Axis.Z * Axis.Z;
	float XY = Axis.X * Axis.Y;
	float XZ = Axis.X * Axis.Z;
	float YZ = Axis.Y * Axis.Z;
	matrix4 Result;
	Result.AxisX.X = X2*OMC + C;
	Result.AxisX.Y = XY*OMC + Axis.Z*S;
	Result.AxisX.Z = XZ*OMC - Axis.Y*S;
	Result.AxisX.W = 0;
	Result.AxisY.X = XY*OMC - Axis.Z*S;
	Result.AxisY.Y = Y2*OMC + C;
	Result.AxisY.Z = YZ*OMC + Axis.X*S;
	Result.AxisY.W = 0;
	Result.AxisZ.X = XZ*OMC + Axis.Y*S;
	Result.AxisZ.Y = YZ*OMC - Axis.X*S;
	Result.AxisZ.Z = Z2*OMC + C;
	Result.AxisZ.W = 0;
	Result.AxisW = VECTOR4_UNIT_W;
	return Result;
}

static matrix4
matrix4_transpose(matrix4 M)
{
	matrix4 Result;
	Result.AxisX = (vector4){M.AxisX.X, M.AxisY.X, M.AxisZ.X, M.AxisW.X};
	Result.AxisY = (vector4){M.AxisX.Y, M.AxisY.Y, M.AxisZ.Y, M.AxisW.Y};
	Result.AxisZ = (vector4){M.AxisX.Z, M.AxisY.Z, M.AxisZ.Z, M.AxisW.Z};
	Result.AxisW = (vector4){M.AxisX.W, M.AxisY.W, M.AxisZ.W, M.AxisW.W};
	return Result;
}

static matrix4
matrix4_translate(vector3 Translation)
{
	matrix4 Result = MATRIX4_IDENTITY;
	Result.AxisW.X = Translation.X;
	Result.AxisW.Y = Translation.Y;
	Result.AxisW.Z = Translation.Z;
	return Result;
}

static matrix4
matrix4_scale(vector3 Scale)
{
	matrix4 Result = MATRIX4_IDENTITY;
	Result.AxisX.X = Scale.X;
	Result.AxisY.Y = Scale.Y;
	Result.AxisZ.Z = Scale.Z;
	return Result;
}

static matrix4
matrix4_perspective(float FieldOfView, float AspectRatio, float Near, float Far)
{
	float F = 1/tanf(FieldOfView/2);
	float Q = 1/(Near - Far);
	matrix4 Result;
	Result.AxisX = (vector4){AspectRatio*F, 0, 0, 0};
	Result.AxisY = (vector4){0, F, 0, 0};
	Result.AxisZ = (vector4){0, 0, Q*(Far+Near), -1};
	Result.AxisW = (vector4){0, 0, Q*(2*Far*Near), 0};
	return Result;
}
