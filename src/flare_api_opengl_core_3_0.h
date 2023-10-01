#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1
GLAPI int GLAD_GL_VERSION_3_0;

enum
{
	GL_COMPARE_REF_TO_TEXTURE = 0x884E,
	GL_CLIP_DISTANCE0 = 0x3000,
	GL_CLIP_DISTANCE1 = 0x3001,
	GL_CLIP_DISTANCE2 = 0x3002,
	GL_CLIP_DISTANCE3 = 0x3003,
	GL_CLIP_DISTANCE4 = 0x3004,
	GL_CLIP_DISTANCE5 = 0x3005,
	GL_CLIP_DISTANCE6 = 0x3006,
	GL_CLIP_DISTANCE7 = 0x3007,
	GL_MAX_CLIP_DISTANCES = 0x0D32,
	GL_MAJOR_VERSION = 0x821B,
	GL_MINOR_VERSION = 0x821C,
	GL_NUM_EXTENSIONS = 0x821D,
	GL_CONTEXT_FLAGS = 0x821E,
	GL_COMPRESSED_RED = 0x8225,
	GL_COMPRESSED_RG = 0x8226,
	GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT = 0x00000001,
	GL_RGBA32F = 0x8814,
	GL_RGB32F = 0x8815,
	GL_RGBA16F = 0x881A,
	GL_RGB16F = 0x881B,
	GL_VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD,
	GL_MAX_ARRAY_TEXTURE_LAYERS = 0x88FF,
	GL_MIN_PROGRAM_TEXEL_OFFSET = 0x8904,
	GL_MAX_PROGRAM_TEXEL_OFFSET = 0x8905,
	GL_CLAMP_READ_COLOR = 0x891C,
	GL_FIXED_ONLY = 0x891D,
	GL_MAX_VARYING_COMPONENTS = 0x8B4B,
	GL_TEXTURE_1D_ARRAY = 0x8C18,
	GL_PROXY_TEXTURE_1D_ARRAY = 0x8C19,
	GL_TEXTURE_2D_ARRAY = 0x8C1A,
	GL_PROXY_TEXTURE_2D_ARRAY = 0x8C1B,
	GL_TEXTURE_BINDING_1D_ARRAY = 0x8C1C,
	GL_TEXTURE_BINDING_2D_ARRAY = 0x8C1D,
	GL_R11F_G11F_B10F = 0x8C3A,
	GL_UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B,
	GL_RGB9_E5 = 0x8C3D,
	GL_UNSIGNED_INT_5_9_9_9_REV = 0x8C3E,
	GL_TEXTURE_SHARED_SIZE = 0x8C3F,
	GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76,
	GL_TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F,
	GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80,
	GL_TRANSFORM_FEEDBACK_VARYINGS = 0x8C83,
	GL_TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84,
	GL_TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85,
	GL_PRIMITIVES_GENERATED = 0x8C87,
	GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88,
	GL_RASTERIZER_DISCARD = 0x8C89,
	GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A,
	GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B,
	GL_INTERLEAVED_ATTRIBS = 0x8C8C,
	GL_SEPARATE_ATTRIBS = 0x8C8D,
	GL_TRANSFORM_FEEDBACK_BUFFER = 0x8C8E,
	GL_TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F,
	GL_RGBA32UI = 0x8D70,
	GL_RGB32UI = 0x8D71,
	GL_RGBA16UI = 0x8D76,
	GL_RGB16UI = 0x8D77,
	GL_RGBA8UI = 0x8D7C,
	GL_RGB8UI = 0x8D7D,
	GL_RGBA32I = 0x8D82,
	GL_RGB32I = 0x8D83,
	GL_RGBA16I = 0x8D88,
	GL_RGB16I = 0x8D89,
	GL_RGBA8I = 0x8D8E,
	GL_RGB8I = 0x8D8F,
	GL_RED_INTEGER = 0x8D94,
	GL_GREEN_INTEGER = 0x8D95,
	GL_BLUE_INTEGER = 0x8D96,
	GL_RGB_INTEGER = 0x8D98,
	GL_RGBA_INTEGER = 0x8D99,
	GL_BGR_INTEGER = 0x8D9A,
	GL_BGRA_INTEGER = 0x8D9B,
	GL_SAMPLER_1D_ARRAY = 0x8DC0,
	GL_SAMPLER_2D_ARRAY = 0x8DC1,
	GL_SAMPLER_1D_ARRAY_SHADOW = 0x8DC3,
	GL_SAMPLER_2D_ARRAY_SHADOW = 0x8DC4,
	GL_SAMPLER_CUBE_SHADOW = 0x8DC5,
	GL_UNSIGNED_INT_VEC2 = 0x8DC6,
	GL_UNSIGNED_INT_VEC3 = 0x8DC7,
	GL_UNSIGNED_INT_VEC4 = 0x8DC8,
	GL_INT_SAMPLER_1D = 0x8DC9,
	GL_INT_SAMPLER_2D = 0x8DCA,
	GL_INT_SAMPLER_3D = 0x8DCB,
	GL_INT_SAMPLER_CUBE = 0x8DCC,
	GL_INT_SAMPLER_1D_ARRAY = 0x8DCE,
	GL_INT_SAMPLER_2D_ARRAY = 0x8DCF,
	GL_UNSIGNED_INT_SAMPLER_1D = 0x8DD1,
	GL_UNSIGNED_INT_SAMPLER_2D = 0x8DD2,
	GL_UNSIGNED_INT_SAMPLER_3D = 0x8DD3,
	GL_UNSIGNED_INT_SAMPLER_CUBE = 0x8DD4,
	GL_UNSIGNED_INT_SAMPLER_1D_ARRAY = 0x8DD6,
	GL_UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7,
	GL_QUERY_WAIT = 0x8E13,
	GL_QUERY_NO_WAIT = 0x8E14,
	GL_QUERY_BY_REGION_WAIT = 0x8E15,
	GL_QUERY_BY_REGION_NO_WAIT = 0x8E16,
	GL_BUFFER_ACCESS_FLAGS = 0x911F,
	GL_BUFFER_MAP_LENGTH = 0x9120,
	GL_BUFFER_MAP_OFFSET = 0x9121,
	GL_DEPTH_COMPONENT32F = 0x8CAC,
	GL_DEPTH32F_STENCIL8 = 0x8CAD,
	GL_FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD,
	GL_INVALID_FRAMEBUFFER_OPERATION = 0x0506,
	GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210,
	GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211,
	GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212,
	GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213,
	GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214,
	GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215,
	GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216,
	GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217,
	GL_FRAMEBUFFER_DEFAULT = 0x8218,
	GL_FRAMEBUFFER_UNDEFINED = 0x8219,
	GL_DEPTH_STENCIL_ATTACHMENT = 0x821A,
	GL_MAX_RENDERBUFFER_SIZE = 0x84E8,
	GL_DEPTH_STENCIL = 0x84F9,
	GL_UNSIGNED_INT_24_8 = 0x84FA,
	GL_DEPTH24_STENCIL8 = 0x88F0,
	GL_TEXTURE_STENCIL_SIZE = 0x88F1,
	GL_TEXTURE_RED_TYPE = 0x8C10,
	GL_TEXTURE_GREEN_TYPE = 0x8C11,
	GL_TEXTURE_BLUE_TYPE = 0x8C12,
	GL_TEXTURE_ALPHA_TYPE = 0x8C13,
	GL_TEXTURE_DEPTH_TYPE = 0x8C16,
	GL_UNSIGNED_NORMALIZED = 0x8C17,
	GL_FRAMEBUFFER_BINDING = 0x8CA6,
	GL_DRAW_FRAMEBUFFER_BINDING = 0x8CA6,
	GL_RENDERBUFFER_BINDING = 0x8CA7,
	GL_READ_FRAMEBUFFER = 0x8CA8,
	GL_DRAW_FRAMEBUFFER = 0x8CA9,
	GL_READ_FRAMEBUFFER_BINDING = 0x8CAA,
	GL_RENDERBUFFER_SAMPLES = 0x8CAB,
	GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0,
	GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1,
	GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2,
	GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3,
	GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4,
	GL_FRAMEBUFFER_COMPLETE = 0x8CD5,
	GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6,
	GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7,
	GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER = 0x8CDB,
	GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER = 0x8CDC,
	GL_FRAMEBUFFER_UNSUPPORTED = 0x8CDD,
	GL_MAX_COLOR_ATTACHMENTS = 0x8CDF,
	GL_COLOR_ATTACHMENT0 = 0x8CE0,
	GL_COLOR_ATTACHMENT1 = 0x8CE1,
	GL_COLOR_ATTACHMENT2 = 0x8CE2,
	GL_COLOR_ATTACHMENT3 = 0x8CE3,
	GL_COLOR_ATTACHMENT4 = 0x8CE4,
	GL_COLOR_ATTACHMENT5 = 0x8CE5,
	GL_COLOR_ATTACHMENT6 = 0x8CE6,
	GL_COLOR_ATTACHMENT7 = 0x8CE7,
	GL_COLOR_ATTACHMENT8 = 0x8CE8,
	GL_COLOR_ATTACHMENT9 = 0x8CE9,
	GL_COLOR_ATTACHMENT10 = 0x8CEA,
	GL_COLOR_ATTACHMENT11 = 0x8CEB,
	GL_COLOR_ATTACHMENT12 = 0x8CEC,
	GL_COLOR_ATTACHMENT13 = 0x8CED,
	GL_COLOR_ATTACHMENT14 = 0x8CEE,
	GL_COLOR_ATTACHMENT15 = 0x8CEF,
	GL_COLOR_ATTACHMENT16 = 0x8CF0,
	GL_COLOR_ATTACHMENT17 = 0x8CF1,
	GL_COLOR_ATTACHMENT18 = 0x8CF2,
	GL_COLOR_ATTACHMENT19 = 0x8CF3,
	GL_COLOR_ATTACHMENT20 = 0x8CF4,
	GL_COLOR_ATTACHMENT21 = 0x8CF5,
	GL_COLOR_ATTACHMENT22 = 0x8CF6,
	GL_COLOR_ATTACHMENT23 = 0x8CF7,
	GL_COLOR_ATTACHMENT24 = 0x8CF8,
	GL_COLOR_ATTACHMENT25 = 0x8CF9,
	GL_COLOR_ATTACHMENT26 = 0x8CFA,
	GL_COLOR_ATTACHMENT27 = 0x8CFB,
	GL_COLOR_ATTACHMENT28 = 0x8CFC,
	GL_COLOR_ATTACHMENT29 = 0x8CFD,
	GL_COLOR_ATTACHMENT30 = 0x8CFE,
	GL_COLOR_ATTACHMENT31 = 0x8CFF,
	GL_DEPTH_ATTACHMENT = 0x8D00,
	GL_STENCIL_ATTACHMENT = 0x8D20,
	GL_FRAMEBUFFER = 0x8D40,
	GL_RENDERBUFFER = 0x8D41,
	GL_RENDERBUFFER_WIDTH = 0x8D42,
	GL_RENDERBUFFER_HEIGHT = 0x8D43,
	GL_RENDERBUFFER_INTERNAL_FORMAT = 0x8D44,
	GL_STENCIL_INDEX1 = 0x8D46,
	GL_STENCIL_INDEX4 = 0x8D47,
	GL_STENCIL_INDEX8 = 0x8D48,
	GL_STENCIL_INDEX16 = 0x8D49,
	GL_RENDERBUFFER_RED_SIZE = 0x8D50,
	GL_RENDERBUFFER_GREEN_SIZE = 0x8D51,
	GL_RENDERBUFFER_BLUE_SIZE = 0x8D52,
	GL_RENDERBUFFER_ALPHA_SIZE = 0x8D53,
	GL_RENDERBUFFER_DEPTH_SIZE = 0x8D54,
	GL_RENDERBUFFER_STENCIL_SIZE = 0x8D55,
	GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56,
	GL_MAX_SAMPLES = 0x8D57,
	GL_FRAMEBUFFER_SRGB = 0x8DB9,
	GL_HALF_FLOAT = 0x140B,
	GL_MAP_READ_BIT = 0x0001,
	GL_MAP_WRITE_BIT = 0x0002,
	GL_MAP_INVALIDATE_RANGE_BIT = 0x0004,
	GL_MAP_INVALIDATE_BUFFER_BIT = 0x0008,
	GL_MAP_FLUSH_EXPLICIT_BIT = 0x0010,
	GL_MAP_UNSYNCHRONIZED_BIT = 0x0020,
	GL_COMPRESSED_RED_RGTC1 = 0x8DBB,
	GL_COMPRESSED_SIGNED_RED_RGTC1 = 0x8DBC,
	GL_COMPRESSED_RG_RGTC2 = 0x8DBD,
	GL_COMPRESSED_SIGNED_RG_RGTC2 = 0x8DBE,
	GL_RG = 0x8227,
	GL_RG_INTEGER = 0x8228,
	GL_R8 = 0x8229,
	GL_R16 = 0x822A,
	GL_RG8 = 0x822B,
	GL_RG16 = 0x822C,
	GL_R16F = 0x822D,
	GL_R32F = 0x822E,
	GL_RG16F = 0x822F,
	GL_RG32F = 0x8230,
	GL_R8I = 0x8231,
	GL_R8UI = 0x8232,
	GL_R16I = 0x8233,
	GL_R16UI = 0x8234,
	GL_R32I = 0x8235,
	GL_R32UI = 0x8236,
	GL_RG8I = 0x8237,
	GL_RG8UI = 0x8238,
	GL_RG16I = 0x8239,
	GL_RG16UI = 0x823A,
	GL_RG32I = 0x823B,
	GL_RG32UI = 0x823C,
	GL_VERTEX_ARRAY_BINDING = 0x85B5,
};

typedef void (APIENTRYP PFNGLCOLORMASKIPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum target, GLuint index, GLboolean *data);
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint *data);
typedef void (APIENTRYP PFNGLENABLEIPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEIPROC)(GLenum target, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISENABLEDIPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)(void);
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC)(GLenum target, GLenum clamp);
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC)(GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC)(void);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC)(GLuint index, GLint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC)(GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC)(GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC)(GLuint index, GLuint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC)(GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program, GLuint color, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint *framebuffers);
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void* (APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint *arrays);
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);

GLAPI PFNGLCOLORMASKIPROC glColorMaski;
GLAPI PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
GLAPI PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
GLAPI PFNGLENABLEIPROC glEnablei;
GLAPI PFNGLDISABLEIPROC glDisablei;
GLAPI PFNGLISENABLEDIPROC glIsEnabledi;
GLAPI PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
GLAPI PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
GLAPI PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
GLAPI PFNGLBINDBUFFERBASEPROC glBindBufferBase;
GLAPI PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
GLAPI PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
GLAPI PFNGLCLAMPCOLORPROC glClampColor;
GLAPI PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
GLAPI PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
GLAPI PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
GLAPI PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
GLAPI PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
GLAPI PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
GLAPI PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
GLAPI PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
GLAPI PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
GLAPI PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
GLAPI PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
GLAPI PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
GLAPI PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
GLAPI PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
GLAPI PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
GLAPI PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
GLAPI PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
GLAPI PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
GLAPI PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
GLAPI PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
GLAPI PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
GLAPI PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
GLAPI PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
GLAPI PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
GLAPI PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
GLAPI PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
GLAPI PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
GLAPI PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
GLAPI PFNGLUNIFORM1UIPROC glUniform1ui;
GLAPI PFNGLUNIFORM2UIPROC glUniform2ui;
GLAPI PFNGLUNIFORM3UIPROC glUniform3ui;
GLAPI PFNGLUNIFORM4UIPROC glUniform4ui;
GLAPI PFNGLUNIFORM1UIVPROC glUniform1uiv;
GLAPI PFNGLUNIFORM2UIVPROC glUniform2uiv;
GLAPI PFNGLUNIFORM3UIVPROC glUniform3uiv;
GLAPI PFNGLUNIFORM4UIVPROC glUniform4uiv;
GLAPI PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
GLAPI PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
GLAPI PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
GLAPI PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
GLAPI PFNGLCLEARBUFFERIVPROC glClearBufferiv;
GLAPI PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
GLAPI PFNGLCLEARBUFFERFVPROC glClearBufferfv;
GLAPI PFNGLCLEARBUFFERFIPROC glClearBufferfi;
GLAPI PFNGLGETSTRINGIPROC glGetStringi;
GLAPI PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
GLAPI PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
GLAPI PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
GLAPI PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
GLAPI PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
GLAPI PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
GLAPI PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
GLAPI PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
GLAPI PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
GLAPI PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
GLAPI PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
GLAPI PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
GLAPI PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
GLAPI PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
GLAPI PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
GLAPI PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
GLAPI PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
GLAPI PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
GLAPI PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
GLAPI PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
GLAPI PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
GLAPI PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
GLAPI PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
GLAPI PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
GLAPI PFNGLISVERTEXARRAYPROC glIsVertexArray;

#endif
