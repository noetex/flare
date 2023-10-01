struct quaternion
{
	quaternion(void) = default;
	quaternion(float, float, float);
	quaternion operator*(quaternion);
	void operator*=(quaternion);
	matrix4 as_matrix4(void);

	vector3 V;
	float W;
};

quaternion::quaternion(float Pitch, float Yaw, float Roll)
{
	float AngleX = Pitch/2;
	float AngleY = Yaw/2;
	float AngleZ = Roll/2;
	float CX = cosf(AngleX);
	float SX = sinf(AngleX);
	float CY = cosf(AngleY);
	float SY = sinf(AngleY);
	float CZ = cosf(AngleZ);
	float SZ = sinf(AngleZ);
	this->W = (CX * CY * CZ) + (SX * SY * SZ);
	this->V.X = (SX * CY * CZ) - (CX * SY * SZ);
	this->V.Y = (CX * SY * CZ) + (SX * CY * SZ);
	this->V.Z = (CX * CY * SZ) - (SX * SY * CZ);
}

quaternion quaternion::operator*(quaternion Q)
{
	quaternion Result;
	Result.W = (this->W * Q.W) - this->V.dot(Q.V);
	Result.V = this->V.cross(Q.V) + (Q.V * this->W) + (this->V * Q.W);
	return Result;
}

void quaternion::operator*=(quaternion Q)
{
	*this = *this * Q;
}

matrix4 quaternion::as_matrix4(void)
{
	float X2 = this->V.X * this->V.X;
	float Y2 = this->V.Y * this->V.Y;
	float Z2 = this->V.Z * this->V.Z;
	float XY = this->V.X * this->V.Y;
	float XZ = this->V.X * this->V.Z;
	float XW = this->V.X * this->W;
	float YZ = this->V.Y * this->V.Z;
	float YW = this->V.Y * this->V.Z;
	float ZW = this->V.Z * this->W;
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
