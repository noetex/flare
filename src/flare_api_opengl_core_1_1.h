#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1

enum
{
	GL_COLOR_LOGIC_OP = 0x0BF2,
	GL_POLYGON_OFFSET_UNITS = 0x2A00,
	GL_POLYGON_OFFSET_POINT = 0x2A01,
	GL_POLYGON_OFFSET_LINE = 0x2A02,
	GL_POLYGON_OFFSET_FILL = 0x8037,
	GL_POLYGON_OFFSET_FACTOR = 0x8038,
	GL_TEXTURE_BINDING_1D = 0x8068,
	GL_TEXTURE_BINDING_2D = 0x8069,
	GL_TEXTURE_INTERNAL_FORMAT = 0x1003,
	GL_TEXTURE_RED_SIZE = 0x805C,
	GL_TEXTURE_GREEN_SIZE = 0x805D,
	GL_TEXTURE_BLUE_SIZE = 0x805E,
	GL_TEXTURE_ALPHA_SIZE = 0x805F,
	GL_DOUBLE = 0x140A,
	GL_PROXY_TEXTURE_1D = 0x8063,
	GL_PROXY_TEXTURE_2D = 0x8064,
	GL_R3_G3_B2 = 0x2A10,
	GL_RGB4 = 0x804F,
	GL_RGB5 = 0x8050,
	GL_RGB8 = 0x8051,
	GL_RGB10 = 0x8052,
	GL_RGB12 = 0x8053,
	GL_RGB16 = 0x8054,
	GL_RGBA2 = 0x8055,
	GL_RGBA4 = 0x8056,
	GL_RGB5_A1 = 0x8057,
	GL_RGBA8 = 0x8058,
	GL_RGB10_A2 = 0x8059,
	GL_RGBA12 = 0x805A,
	GL_RGBA16 = 0x805B,
};

typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint *textures);
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint *textures);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);

GLAPI PFNGLDRAWARRAYSPROC glDrawArrays;
GLAPI PFNGLDRAWELEMENTSPROC glDrawElements;
GLAPI PFNGLPOLYGONOFFSETPROC glPolygonOffset;
GLAPI PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D;
GLAPI PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D;
GLAPI PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D;
GLAPI PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D;
GLAPI PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D;
GLAPI PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D;
GLAPI PFNGLBINDTEXTUREPROC glBindTexture;
GLAPI PFNGLDELETETEXTURESPROC glDeleteTextures;
GLAPI PFNGLGENTEXTURESPROC glGenTextures;
GLAPI PFNGLISTEXTUREPROC glIsTexture;

#endif
