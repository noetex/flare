#ifndef GL_VERSION_4_1
#define GL_VERSION_4_1 1
GLAPI int GLAD_GL_VERSION_4_1;

enum
{
	GL_FIXED = 0x140C,
	GL_IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A,
	GL_IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B,
	GL_LOW_FLOAT = 0x8DF0,
	GL_MEDIUM_FLOAT = 0x8DF1,
	GL_HIGH_FLOAT = 0x8DF2,
	GL_LOW_INT = 0x8DF3,
	GL_MEDIUM_INT = 0x8DF4,
	GL_HIGH_INT = 0x8DF5,
	GL_SHADER_COMPILER = 0x8DFA,
	GL_SHADER_BINARY_FORMATS = 0x8DF8,
	GL_NUM_SHADER_BINARY_FORMATS = 0x8DF9,
	GL_MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB,
	GL_MAX_VARYING_VECTORS = 0x8DFC,
	GL_MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD,
	GL_RGB565 = 0x8D62,
	GL_PROGRAM_BINARY_RETRIEVABLE_HINT = 0x8257,
	GL_PROGRAM_BINARY_LENGTH = 0x8741,
	GL_NUM_PROGRAM_BINARY_FORMATS = 0x87FE,
	GL_PROGRAM_BINARY_FORMATS = 0x87FF,
	GL_VERTEX_SHADER_BIT = 0x00000001,
	GL_FRAGMENT_SHADER_BIT = 0x00000002,
	GL_GEOMETRY_SHADER_BIT = 0x00000004,
	GL_TESS_CONTROL_SHADER_BIT = 0x00000008,
	GL_TESS_EVALUATION_SHADER_BIT = 0x00000010,
	GL_ALL_SHADER_BITS = 0xFFFFFFFF,
	GL_PROGRAM_SEPARABLE = 0x8258,
	GL_ACTIVE_PROGRAM = 0x8259,
	GL_PROGRAM_PIPELINE_BINDING = 0x825A,
	GL_MAX_VIEWPORTS = 0x825B,
	GL_VIEWPORT_SUBPIXEL_BITS = 0x825C,
	GL_VIEWPORT_BOUNDS_RANGE = 0x825D,
	GL_LAYER_PROVOKING_VERTEX = 0x825E,
	GL_VIEWPORT_INDEX_PROVOKING_VERTEX = 0x825F,
	GL_UNDEFINED_VERTEX = 0x8260,
};

typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC)(void);
typedef void (APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint pipeline, GLuint program);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum type, GLsizei count, const GLchar *const*strings);
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei n, const GLuint *pipelines);
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei n, GLuint *pipelines);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint pipeline, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint program, GLint location, GLdouble v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint first, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint first, GLsizei count, const GLint *v);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint first, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint index, GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC)(GLenum target, GLuint index, GLfloat *data);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum target, GLuint index, GLdouble *data);

GLAPI PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
GLAPI PFNGLSHADERBINARYPROC glShaderBinary;
GLAPI PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
GLAPI PFNGLDEPTHRANGEFPROC glDepthRangef;
GLAPI PFNGLCLEARDEPTHFPROC glClearDepthf;
GLAPI PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;
GLAPI PFNGLPROGRAMBINARYPROC glProgramBinary;
GLAPI PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;
GLAPI PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;
GLAPI PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;
GLAPI PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;
GLAPI PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;
GLAPI PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;
GLAPI PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;
GLAPI PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;
GLAPI PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;
GLAPI PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;
GLAPI PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;
GLAPI PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;
GLAPI PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;
GLAPI PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;
GLAPI PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;
GLAPI PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;
GLAPI PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;
GLAPI PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;
GLAPI PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;
GLAPI PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;
GLAPI PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;
GLAPI PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;
GLAPI PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;
GLAPI PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;
GLAPI PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;
GLAPI PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;
GLAPI PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;
GLAPI PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;
GLAPI PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;
GLAPI PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;
GLAPI PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;
GLAPI PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;
GLAPI PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;
GLAPI PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;
GLAPI PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;
GLAPI PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;
GLAPI PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;
GLAPI PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;
GLAPI PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;
GLAPI PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;
GLAPI PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;
GLAPI PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;
GLAPI PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;
GLAPI PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;
GLAPI PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;
GLAPI PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;
GLAPI PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;
GLAPI PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;
GLAPI PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;
GLAPI PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;
GLAPI PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;
GLAPI PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;
GLAPI PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;
GLAPI PFNGLVIEWPORTARRAYVPROC glViewportArrayv;
GLAPI PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;
GLAPI PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;
GLAPI PFNGLSCISSORARRAYVPROC glScissorArrayv;
GLAPI PFNGLSCISSORINDEXEDPROC glScissorIndexed;
GLAPI PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;
GLAPI PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;
GLAPI PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;
GLAPI PFNGLGETFLOATI_VPROC glGetFloati_v;
GLAPI PFNGLGETDOUBLEI_VPROC glGetDoublei_v;

#endif
