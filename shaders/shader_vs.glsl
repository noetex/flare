#version 330 core

layout (location = 0) in vec3 Position;

uniform mat4 View;
uniform mat4 Perspective;

void main(void)
{
	gl_Position = Perspective * View * vec4(Position, 1.0);
}
