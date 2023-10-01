typedef struct
{
	vector3 Vertex[3];
} triangle3d;

typedef struct
{
	vector3 P0;
	vector3 P1;
} line_segment3d;

typedef struct
{
	vector3 Origin;
	vector3 Direction;
} ray3d;

typedef struct
{
	vector3 Normal;
	float D;
} plane;

typedef struct
{
	vector3 MinPoint;
	vector3 MaxPoint;
} aabb;

typedef struct
{
	vector3
} oob;
