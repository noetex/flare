struct triangle3d
{
	vector3 Vertex[3];
	vector3 normal2(void);
	vector3 normal(void);
};

vector3 triangle3d::normal2(void)
{
	vector3 Edge1 = this->Vertex[1] - this->Vertex[0];
	vector3 Edge2 = this->Vertex[2] - this->Vertex[0];
	vector3 Result = Edge1.cross(Edge2);
	return Result;
}

vector3 triangle3d::normal(void)
{
	vector3 Vector = this->normal2();
	vector3 Result = Vector.normal();
	return Result;
}

