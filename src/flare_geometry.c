static bool_t
intersection_ray_plane(ray3d Ray, plane3d Plane)
{
	if(Ray.Direction)

}

static bool_t
intersection_ray_triangle(ray3d Ray, triangle3d Triangle)
{

}

static bool_t
intersection_ray_aabb(ray3d Ray, aabb Box)
{

}

static bool_t
intersection_ray_obb(ray3d Ray, obb Box)
{

}


static bool_t
intersection_plane_plane(plane3d P, plane3d Q)
{
	vector3 Cross = vector3_cross(P.Normal, Q.Normal);
	float Length2 = vector3_length2(Cross);
	bool_t PlanesAreParallel = float_equal(Length2, 0);
	bool_t NoOverlap = (P.Offset != Q.Offset);
	if(PlanesAreParallel && NoOverlap)
	{
		return false;
	}
	return true;
}

static bool_t
intersection_plane_triangle(plane3d Plane, triangle3d Triangle)
{

}

static bool_t
intersection_plane_aabb(plane3d Plane, aabb Box)
{

}

static bool_t
intersection_plane_obb(plane3d Plane, obb Box)
{

}
