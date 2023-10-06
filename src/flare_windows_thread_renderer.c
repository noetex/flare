static GLuint
CreateOpenGLShader(char* Source, GLenum Type)
{
	HANDLE File = CreateFileA(Source, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	Assert(File != INVALID_HANDLE_VALUE);
	DWORD FileSize = GetFileSize(File, 0);
	char* String = VirtualAlloc(0, FileSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	DWORD BytesRead = 0;
	ReadFile(File, String, FileSize, &BytesRead, 0);
	Assert(BytesRead == FileSize);
	GLuint Result = glCreateShader(Type);
	glShaderSource(Result, 1, &String, 0);
	glCompileShader(Result);
	GLint IsCompiled = 0;
	glGetShaderiv(Result, GL_COMPILE_STATUS, &Status);
	if(!IsCompiled)
	{
		GLint LogLength = 0;
		glGetShaderiv(Result, GL_INFO_LOG_LENGTH, &LogLength);
		char* ErrorLog = VirtualAlloc(0, LogLength, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		glGetShaderInfoLog(Result, LogLength, 0, ErrorLog);
		MessageBoxA(0, ErrorLog, "Shader Error Log", MB_OK);
		VirtualFree(ErrorLog, 0, MEM_RELEASE);
	}
	VirtualFree(String, 0, MEM_RELEASE);
	return Result;
}

static GLuint
CreateOpenGLProgram(GLuint VertexShader, GLuint FragmentShader)
{
	GLuint Result = glCreateProgram();
	glAttachShader(Result, VertexShader);
	glAttachShader(Result, FragmentShader);
	glLinkProgram(Result);
	glDeleteShader(VertexShader);
	glDeleteShader(FragmentShader);
	GLint IsLinked = 0;
	glGetProgramiv(Result, GL_LINK_STATUS, &IsLinked);
	if(!IsLinked)
	{
		GLint LogLength = 0;
		glGetProgramiv(Result, GL_INFO_LOG_LENGTH, &LogLength);
		char* ErrorLog = VirtualAlloc(0, LogLength, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		glGetProgramInfoLog(Result, sizeof(ErrorLog), 0, ErrorLog);
		MessageBoxA(0, ErrorLog, "Shader Error Log", MB_OK);
		VirtualFree(ErrorLog, 0, MEM_RELEASE);
	}
	return Result;
}

float TRIANGLE_VERTS[] =
{
	-0.5, -0.5, 0.0,
	0.0, 0.5, 0.0,
	0.5, -0.5, 0.0,
};

static DWORD WINAPI
thread_renderer(LPVOID Parameter)
{
	HWND Window = (HWND)Parameter;
	HDC WindowDC = GetDC(Window);
	HGLRC ContextGL = create_opengl_context(WindowDC);
	Assert(glewInit() == GLEW_OK);
	ShowWindow(Window, SW_MAXIMIZE);
	GLuint VertexShader = CreateOpenGLShader("../shader_vs.glsl", GL_VERTEX_SHADER);
	GLuint FragmentShader = CreateOpenGLShader("../shader_fs.glsl", GL_FRAGMENT_SHADER);
	GLuint ShaderProgram = CreateOpenGLProgram(VertexShader, FragmentShader);
	glUseProgram(ShaderProgram);

	GLuint VertexArray;
	GLuint VertexBuffer;
	glGenVertexArrays(1, &VertexArray);
	glGenBuffers(1, &VertexBuffer);

	glBindVertexArray(VertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, VetexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(TRIANGLE_VERTS), TRIANGLE_VERTS, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	for(;;)
	{
		MSG Message;
		while(PeekMessageW(&Message, 0, 0, 0, PM_REMOVE))
		{

		}

		SwapBuffers(WindowDC);
	}
	return 0;
}
