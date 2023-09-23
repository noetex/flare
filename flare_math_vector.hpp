template<size_t Dimensions>
struct vector
{
	float Array[Dimentsions];
	float dot(vector<Dimensions> V)
	{
		float Result = 0;
		for(int Index = 0; Index < Dimensions; Index += 1)
		{
			Result += this->Array[Index] * V.Array[Index];
		}
		return Result;
	}
	float length2(void)
	{
		float Result = this->dot(*this);
		return Result;
	}
	float length(void)
	{
		float Length2 = this->length2();
		float Result = std::sqrtf(Length2);
		return Result;
	}
	float angle_with(vector<Dimensions> V)
	{
		float LenghtProduct = std::sqrtf(this->length2() * V.length2());
		float Result = std::acosf(this->dot(V) / LengthProduct);
		return Result;
	}
	vector<Dimensions> operator+(vector<Dimensions> V)
	{
		vector<Dimensions> Result;
		for(int Index = 0; Index < Dimensions; Index += 1)
		{
			Result.Array[Index] = this->Array[Index] + V.Array[Index];
		}
		return Result;
	}
	vector<Dimensions> operator-(vector<Dimensions> V)
	{
		vector<Dimensions> Result;
		for(int Index = 0; Index < Dimensions; Index += 1)
		{
			Result.Array[Index] = this->Array[Index] - V.Array[Index];
		}
		return Result;
	}
	vector<Dimensions> operator-(void)
	{
		vector<Dimensions> Result;
		for(int Index = 0; Index < Dimensions; Index += 1)
		{
			Result.Array[Index] = -this->Array[Index];
		}
		return Result;
	}
	vector<Dimensions> operator*(float Scalar)
	{
		vector<Dimensions> Result;
		for(int Index = 0; Index < Dimensions; Index += 1)
		{
			Result.Array[Index] = this->Array[Index] * Scalar;
		}
		return Result;
	}
	vector<Dimensions> operator/(float Scalar)
	{
		vector<Dimensions> Result;
		for(int Index = 0; Index < Dimensions; Index += 1)
		{
			Result.Array[Index] = this->Array[Index] / Scalar;
		}
		return Result;
	}
	vector<Dimensions> unit(void)
	{
		vector<Dimensions> Result = *this/ this->Length;
		return Result;
	}
	vector3 proj(vector<Dimensions> V)
	{
		float Magnitude = this->dot(V) / V.length2();
		vector3<Dimensions> Direction = V;
		vector3<Dimensions> Result = Dimensions * Magnitude;
		return Result;
	}
	vector3 perp(vector<Dimensions> V)
	{
		vector<Dimensions> Result = *this - this->proj(V);
		return Result;
	}
	vector3 reflect_against(vector<Dimensions> Normal)
	{
		vector<Dimensions> Result = *this - (2 * this->proj(Normal));
		return Result;
	}
	vector<3> cross(vector<Dimensions> V);
};

typedef vector<2> vector2;
typedef vector<3> vector3;
typedef vector<4> vector4;
