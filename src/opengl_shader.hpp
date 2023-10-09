struct opengl_shader
{
	GLuint Program;
	void get_uniform_mat4(char*)
	{
		float[16] Result;
		int Location = glGetUniformLocation(this->Program, Name);
		glUniformMatrix4fv(Location, 1, GL_FALSE, &Result);
		return Result;
	}
};
