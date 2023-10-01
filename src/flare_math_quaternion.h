typedef struct
{
	vector3 V;
	float W;
} quaternion;

static quaternion
quaterion_mul_quaternion(quaternion A, quaternion B)
{
	quaternion Result;
	Result.W = (A.W * B.W) - vector3_dot(A.V, B.V);
	Result.V = vector3_cross(A.V, B.V);
	Result.V = vector3_add(Result.V, vector3_mul(A.V, B.W));
	Result.V = vector3_add(Result.V, vector3_mul(B.V, A.W));
	return Result;
}

static quaternion
quaternion_from_euler(float Pitch, float Yaw, float Roll)
{
	Pitch /= 2;
	Yaw /= 2;
	Roll /= 2;
	float CP = cosf(Pitch);
	float CY = cosf(Yaw);
	float CR = cosf(Roll);
	float SP = sinf(Pitch);
	float SY = sinf(Yaw);
	float SR = sinf(Roll);
	quaternion Result;
	Result.W = (CP * CY * CR) + (SP * SY * SR);
	Result.V.X = (SP * CY * CR) - (CP * SY * SR);
	Result.V.Y = (CP * SY * CR) + (SP * CY * SR);
	Result.V.Z = (CP * CY * SR) - (SP * SY * CR);
	return Result;
}

static matrix4
quaternion_to_matrix4(quaternion Q)
{
	float X2 = Q.V.X * Q.V.X;
	float Y2 = Q.V.Y * Q.V.Y;
	float Z2 = Q.V.Z * Q.V.Z;
	float XY = Q.V.X * Q.V.Y;
	float XZ = Q.V.X * Q.V.Z;
	float XW = Q.V.X * Q.W;
	float YZ = Q.V.Y * Q.V.Z;
	float YW = Q.V.Y * Q.V.Z;
	float ZW = Q.V.Z * Q.W;
	matrix4 Result;
	Result.AxisX.X = 1 - (2*Y2) - (2*Z2);
	Result.AxisX.Y = (2*XY) - (2*ZW);
	Result.AxisX.Z = (2*XZ) - (2*YW);
	Result.AxisX.W = 0;
	Result.AxisY.X = (2*XY) + (2*ZW);
	Result.AxisY.Y = 1 - (2*X2) - (2*Z2);
	Result.AxisY.Z = (2*YZ) - (2*YW);
	Result.AxisY.W = 0;
	Result.AxisZ.X = (2*XZ) + (2*YW);
	Result.AxisZ.Y = (2*YZ) + (2*YW);
	Result.AxisZ.Z = 1 - (2*X2) - (2*Y2);
	Result.AxisZ.W = 0;
	Result.AxisW = VECTOR4_UNIT_W;
}
