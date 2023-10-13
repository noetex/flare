#if 0
typedef struct
{
	bool_t IsValid;
	float* GeometryVertices;
	float* TextureVertices;
	float* NormalVertices;
	float* ParameterSpaceVertices;
} obj_format_info;

static char* TAG_VERTEX_GEOMETRIC = "v";
static char* TAG_VERTEX_TEXTURE = "vt";
static char* TAG_VERTEX_NORMAL = "vn";
static char* TAG_VERTEX_PARAM_SPACE = "vp";

static char* TAG_FREEFORM_ATTRIB_DEGREE = "deg";
static char* TAG_FREEFORM_ATTRIB_BASISMATRIX = "bmat";
static char* TAG_FREEFORM_ATTRIB_STEPSIZE = "step";

static char* TAG_ELEMENT_POINT = "p";
static char* TAG_ELEMENT_LINE = "l";
static char* TAG_ELEMENT_FACE = "f";
static char* TAG_ELEMENT_CURVE = "curv";
static char* TAG_ELEMENT_CURVE2D = "curv2";
static char* TAG_ELEMENT_SURFACE = "surf";

static char* TAG_FREEFORM_STATEMENT_PARAM_VAL = "parm";
static char* TAG_FREEFORM_STATEMENT_TRIM = "trim";
static char* TAG_FREEFORM_STATEMENT_HOLE = "hole";
static char* TAG_FREEFORM_STATEMENT_SPECIAL_CURVE = "scrv";
static char* TAG_FREEFORM_STATEMENT_SPECIAL_POINT = "sp";
static char* TAG_FREEFORM_STATEMENT_END = "end";

static char* TAG_CONNECT = "con";

static char* TAG_GROUP_NAME = "g";
static char* TAG_GROUP_SMOOTHING = "S";
static char* TAG_GROUP_MERGING = "mg";
static char* TAG_GROUP_OBJECT_NAME = "o";

static char* TAG_RENDER_ATTRIB_BEVEL_INTERP = "bevel";
static char* TAG_RENDER_ATTRIB_COLOR_INTERP = "c_interp";
static char* TAG_RENDER_ATTRIB_DISSOLVE_INTERP = "d_interp";
static char* TAG_RENDER_ATTRIB_LEVEL_OF_DETAIL = "lod";
static char* TAG_RENDER_ATTRIB_MATERIAL_NAME = "msemtl";
static char* TAG_RENDER_ATTRIB_MATERIAL_LIB = "mtllib";
static char* TAG_RENDER_ATTRIB_SHADOW_CASTING = "shadow_obj";
static char* TAG_RENDER_ATTRIB_RAY_TRACING = "trace_obj";
static char* TAG_RENDER_ATTRIB_CURVE_TECH = "ctech";
static char* TAG_RENDER_ATTRIB_SURFACE_TECH = "stech";


static obj_format_info
get_obj(file_handle File)
{
	char Line[128];
	obj_format_info Result = {0};
	while(file_read_line(File, Line, sizeof(Line)))
	{

	}
	return Result;
}
#endif

typedef struct
{
	struct { float X, Y, Z; } *Vertices;
	struct { float U, V, W; } *TexCoords;
	struct { uint32_t Index[3]; } *Faces;
	size_t NumVertices;
	size_t NumTexCoords;
	size_t NumFaces;
} model;
