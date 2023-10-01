struct ray3d
{
	bool_t intersects(obb);
	bool_t intersects(aabb);
	bool_t intersects(plane3d);
	bool_t intersects(triangle3d);

	vector3 Origin;
	vector3 Direction;
};

bool_t ray3d::intersects(plane3d Plane)
{
	float Dot = Plane.Normal.dot(this->Direction);
	bool_t AreParallel = float_cmp_zero(Dot);
	bool_t PlaneIsCulled = Dot < 0;
	//bool_t RayPointsAway = ; // TODO: only when culling enabled
	if(AreParallel | PlaneIsCulled)
	{
		return false;
	}


}

bool_t ray3d::intersects(triangle3d Triangle)
{
	vector3 TriangleNormal = Triangle.normal2();
	float Dot = TriangleNormal.dot(this->Direction);
	bool_t RayParallelToTriangle = float_cmp_zero(Dot);
	if(RayParallelToTriangle)
	{
		return false;
	}

}
