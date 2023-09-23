struct plane
{
	vector3 Normal;
	float Offset;

	float distance_from(vector3);
};

float plane::distance_from(vector3 Point)
{
	float Result = Point.dot(this->Normal) - this->Offset;
	return Result;
}
