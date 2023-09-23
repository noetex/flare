#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
GLAPI int GLAD_GL_VERSION_2_1;

enum
{
	GL_PIXEL_PACK_BUFFER = 0x88EB,
	GL_PIXEL_UNPACK_BUFFER = 0x88EC,
	GL_PIXEL_PACK_BUFFER_BINDING = 0x88ED,
	GL_PIXEL_UNPACK_BUFFER_BINDING = 0x88EF,
	GL_FLOAT_MAT2x3 = 0x8B65,
	GL_FLOAT_MAT2x4 = 0x8B66,
	GL_FLOAT_MAT3x2 = 0x8B67,
	GL_FLOAT_MAT3x4 = 0x8B68,
	GL_FLOAT_MAT4x2 = 0x8B69,
	GL_FLOAT_MAT4x3 = 0x8B6A,
	GL_SRGB = 0x8C40,
	GL_SRGB8 = 0x8C41,
	GL_SRGB_ALPHA = 0x8C42,
	GL_SRGB8_ALPHA8 = 0x8C43,
	GL_COMPRESSED_SRGB = 0x8C48,
	GL_COMPRESSED_SRGB_ALPHA = 0x8C49,
};

typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

GLAPI PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
GLAPI PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
GLAPI PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
GLAPI PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
GLAPI PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
GLAPI PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;

#endif
