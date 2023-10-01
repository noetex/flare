#ifndef GL_VERSION_4_5
#define GL_VERSION_4_5 1

enum
{
	GL_CONTEXT_LOST = 0x0507,
	GL_NEGATIVE_ONE_TO_ONE = 0x935E,
	GL_ZERO_TO_ONE = 0x935F,
	GL_CLIP_ORIGIN = 0x935C,
	GL_CLIP_DEPTH_MODE = 0x935D,
	GL_QUERY_WAIT_INVERTED = 0x8E17,
	GL_QUERY_NO_WAIT_INVERTED = 0x8E18,
	GL_QUERY_BY_REGION_WAIT_INVERTED = 0x8E19,
	GL_QUERY_BY_REGION_NO_WAIT_INVERTED = 0x8E1A,
	GL_MAX_CULL_DISTANCES = 0x82F9,
	GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES = 0x82FA,
	GL_TEXTURE_TARGET = 0x1006,
	GL_QUERY_TARGET = 0x82EA,
	GL_GUILTY_CONTEXT_RESET = 0x8253,
	GL_INNOCENT_CONTEXT_RESET = 0x8254,
	GL_UNKNOWN_CONTEXT_RESET = 0x8255,
	GL_RESET_NOTIFICATION_STRATEGY = 0x8256,
	GL_LOSE_CONTEXT_ON_RESET = 0x8252,
	GL_NO_RESET_NOTIFICATION = 0x8261,
	GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT = 0x00000004,
	GL_COLOR_TABLE = 0x80D0,
	GL_POST_CONVOLUTION_COLOR_TABLE = 0x80D1,
	GL_POST_COLOR_MATRIX_COLOR_TABLE = 0x80D2,
	GL_PROXY_COLOR_TABLE = 0x80D3,
	GL_PROXY_POST_CONVOLUTION_COLOR_TABLE = 0x80D4,
	GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE = 0x80D5,
	GL_CONVOLUTION_1D = 0x8010,
	GL_CONVOLUTION_2D = 0x8011,
	GL_SEPARABLE_2D = 0x8012,
	GL_HISTOGRAM = 0x8024,
	GL_PROXY_HISTOGRAM = 0x8025,
	GL_MINMAX = 0x802E,
	GL_CONTEXT_RELEASE_BEHAVIOR = 0x82FB,
	GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH = 0x82FC,
};

typedef void (APIENTRYP PFNGLCLIPCONTROLPROC)(GLenum origin, GLenum depth);
typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint xfb, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint xfb, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei n, GLuint *buffers);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint buffer, GLenum access);
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint buffer, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint buffer, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint framebuffer, GLenum buf);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint framebuffer, GLenum src);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint framebuffer, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint renderbuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC)(GLenum target, GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint texture, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint texture, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint texture, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint texture);
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint unit, GLuint texture);
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint texture, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint texture, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint vaobj, GLuint buffer);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint vaobj, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei n, GLuint *samplers);
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei n, GLuint *pipelines);
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC)(GLenum target, GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)(void);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFNGLREADNPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFNGLGETNMAPDVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
typedef void (APIENTRYP PFNGLGETNMAPFVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
typedef void (APIENTRYP PFNGLGETNMAPIVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint *v);
typedef void (APIENTRYP PFNGLGETNPIXELMAPFVPROC)(GLenum map, GLsizei bufSize, GLfloat *values);
typedef void (APIENTRYP PFNGLGETNPIXELMAPUIVPROC)(GLenum map, GLsizei bufSize, GLuint *values);
typedef void (APIENTRYP PFNGLGETNPIXELMAPUSVPROC)(GLenum map, GLsizei bufSize, GLushort *values);
typedef void (APIENTRYP PFNGLGETNPOLYGONSTIPPLEPROC)(GLsizei bufSize, GLubyte *pattern);
typedef void (APIENTRYP PFNGLGETNCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
typedef void (APIENTRYP PFNGLGETNCONVOLUTIONFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
typedef void (APIENTRYP PFNGLGETNSEPARABLEFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
typedef void (APIENTRYP PFNGLGETNHISTOGRAMPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
typedef void (APIENTRYP PFNGLGETNMINMAXPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC)(void);

GLAPI PFNGLCLIPCONTROLPROC glClipControl;
GLAPI PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks;
GLAPI PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase;
GLAPI PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange;
GLAPI PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv;
GLAPI PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v;
GLAPI PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v;
GLAPI PFNGLCREATEBUFFERSPROC glCreateBuffers;
GLAPI PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage;
GLAPI PFNGLNAMEDBUFFERDATAPROC glNamedBufferData;
GLAPI PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData;
GLAPI PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData;
GLAPI PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData;
GLAPI PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData;
GLAPI PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer;
GLAPI PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange;
GLAPI PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer;
GLAPI PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange;
GLAPI PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv;
GLAPI PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v;
GLAPI PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv;
GLAPI PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData;
GLAPI PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers;
GLAPI PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer;
GLAPI PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri;
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture;
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer;
GLAPI PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer;
GLAPI PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers;
GLAPI PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer;
GLAPI PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData;
GLAPI PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData;
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv;
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv;
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv;
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi;
GLAPI PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer;
GLAPI PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus;
GLAPI PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv;
GLAPI PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv;
GLAPI PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers;
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage;
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample;
GLAPI PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv;
GLAPI PFNGLCREATETEXTURESPROC glCreateTextures;
GLAPI PFNGLTEXTUREBUFFERPROC glTextureBuffer;
GLAPI PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange;
GLAPI PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D;
GLAPI PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D;
GLAPI PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D;
GLAPI PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample;
GLAPI PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample;
GLAPI PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D;
GLAPI PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D;
GLAPI PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D;
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D;
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D;
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D;
GLAPI PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D;
GLAPI PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D;
GLAPI PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D;
GLAPI PFNGLTEXTUREPARAMETERFPROC glTextureParameterf;
GLAPI PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv;
GLAPI PFNGLTEXTUREPARAMETERIPROC glTextureParameteri;
GLAPI PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv;
GLAPI PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv;
GLAPI PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv;
GLAPI PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap;
GLAPI PFNGLBINDTEXTUREUNITPROC glBindTextureUnit;
GLAPI PFNGLGETTEXTUREIMAGEPROC glGetTextureImage;
GLAPI PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage;
GLAPI PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv;
GLAPI PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv;
GLAPI PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv;
GLAPI PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv;
GLAPI PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv;
GLAPI PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv;
GLAPI PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays;
GLAPI PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib;
GLAPI PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib;
GLAPI PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer;
GLAPI PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer;
GLAPI PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers;
GLAPI PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding;
GLAPI PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat;
GLAPI PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat;
GLAPI PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat;
GLAPI PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor;
GLAPI PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv;
GLAPI PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv;
GLAPI PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv;
GLAPI PFNGLCREATESAMPLERSPROC glCreateSamplers;
GLAPI PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines;
GLAPI PFNGLCREATEQUERIESPROC glCreateQueries;
GLAPI PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v;
GLAPI PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv;
GLAPI PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v;
GLAPI PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv;
GLAPI PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion;
GLAPI PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage;
GLAPI PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage;
GLAPI PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus;
GLAPI PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage;
GLAPI PFNGLGETNTEXIMAGEPROC glGetnTexImage;
GLAPI PFNGLGETNUNIFORMDVPROC glGetnUniformdv;
GLAPI PFNGLGETNUNIFORMFVPROC glGetnUniformfv;
GLAPI PFNGLGETNUNIFORMIVPROC glGetnUniformiv;
GLAPI PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv;
GLAPI PFNGLREADNPIXELSPROC glReadnPixels;
GLAPI PFNGLGETNMAPDVPROC glGetnMapdv;
GLAPI PFNGLGETNMAPFVPROC glGetnMapfv;
GLAPI PFNGLGETNMAPIVPROC glGetnMapiv;
GLAPI PFNGLGETNPIXELMAPFVPROC glGetnPixelMapfv;
GLAPI PFNGLGETNPIXELMAPUIVPROC glGetnPixelMapuiv;
GLAPI PFNGLGETNPIXELMAPUSVPROC glGetnPixelMapusv;
GLAPI PFNGLGETNPOLYGONSTIPPLEPROC glGetnPolygonStipple;
GLAPI PFNGLGETNCOLORTABLEPROC glGetnColorTable;
GLAPI PFNGLGETNCONVOLUTIONFILTERPROC glGetnConvolutionFilter;
GLAPI PFNGLGETNSEPARABLEFILTERPROC glGetnSeparableFilter;
GLAPI PFNGLGETNHISTOGRAMPROC glGetnHistogram;
GLAPI PFNGLGETNMINMAXPROC glGetnMinmax;
GLAPI PFNGLTEXTUREBARRIERPROC glTextureBarrier;

#endif
