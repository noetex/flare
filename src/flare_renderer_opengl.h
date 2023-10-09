#define MAX_COUNT_VAO 4
#define MAX_COUNT_VBO 4

typedef struct
{
	GLuint Program;
	GLuint VertexArrays[MAX_COUNT_VAO];
	GLuint VertexBuffers[MAX_COUNT_VBO];
	GLuint VertexShader;
	GLuint GeometryShader
	GLuint FragmentShader;
} opengl_renderer;

static opengl_renderer
opengl_renderer_create(char* SourceVS, char* SourceGS, char* SourceFS)
{

}
