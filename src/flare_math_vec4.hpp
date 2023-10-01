struct vector3
{
	float X, Y, Z, W;
	float dot(vector3);
	float length2(void);
	float length(void);
	float angle_with(vector3);
	vector3 operator+(vector3);
	vector3 operator-(vector3);
	vector3 operator-(void);
	vector3 operator*(float);
	vector3 operator/(float);
	vector3 cross(vector3);
	vector3 unit(void);
	vector3 reflect_against(vector3);
	vector3 project_into(vector3);
	vector3 perpedicular_to(vector3);
};

float vector3::dot(vector3 V)
{
	float Result = (this->X * V.X);
	Result += (this->Y * V.Y);
	Result += (this->Z * V.Z);
	return Result;
}

float vector3::length2(void)
{
	vector3 Vector = *this;
	float Result = Vector.dot(Vector);
	return Result;
}

float vector3::length(void)
{
	float Length2 = this->length2();
	float Result = sqrtf(Length2);
	return Result;
}

float vector3::angle_with(vector3 V)
{
	float Cosine = this->dot(V) / (this->length() * V.length());
	float Result = acosf(Cosine);
	return Result;
}

vector3 vector3::operator+(vector3 V)
{
	vector3 Result;
	Result.X = this->X + V.X;
	Result.Y = this->Y + V.Y;
	Result.Z = this->Z + V.Z;
	return Result;
}

vector3 vector3::operator-(vector3 V)
{
	vector3 Result;
	Result.X = this->X - V.X;
	Result.Y = this->Y - V.Y;
	Result.Z = this->Z - V.Z;
	return Result;
}

vector3 vector3::operator-(void)
{
	vector3 Result;
	Result.X = -this->X;
	Result.Y = -this->Y;
	Result.Z = -this->Z;
	return Result;
}

vector3 vector3::operator*(float Scalar)
{
	vector3 Result;
	Result.X = this->X * Scalar;
	Result.Y = this->Y * Scalar;
	Result.Z = this->Z * Scalar;
	return Result;
}

vector3 vector3::operator/(float Scalar)
{
	vector3 Vector = *this;
	vector3 Result = Vector * (1/Scalar);
	return Result;
}

vector3 vector3::cross(vector3 V)
{
	vector3 Result;
	Result.X = (this->Y * V.Z) - (this->Z * V.Y);
	Result.Y = (this->Z * V.X) - (this->X * V.Z);
	Result.Z = (this->X * V.Y) - (this->Y * V.X);
	return Result;
}

vector3 vector3::unit(void)
{
	vector3 Vector = *this;
	float Length = Vector.length();
	vector3 Result = Vector / Length;
	return Result;
}

vector3 vector3::project_into(vector3 B)
{
	float Length2 = B.length2();
	vector3 Result = (B * this->dot(B)) / Length2;
	return Result;
}

vector3 vector3::perpedicular_to(vector3 B)
{
	vector3 Projected = this->project_into(B);
	vector3 Result = *this - Projected;
	return Result;
}

vector3 vector3::reflect_against(vector3 SurfaceNormal)
{
	return {0};
}
