#include "shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Shader::loadShader(const char* path, GLenum type)
{
	int res;
	char* result = new char[512];

	std::string code;
	std::ifstream shaderFile;

	shaderFile.open(path);
	std::stringstream shaderStream;
	shaderStream << shaderFile.rdbuf();
	shaderFile.close();
	code = shaderStream.str();

	const char* codeChar = code.c_str();

	unsigned int shaderId = glCreateShader(type);
	shaders.push_back(shaderId);
	id = shaderId;
	glShaderSource(shaderId, 1, &codeChar, NULL);
	glCompileShader(id);

	glGetShaderiv(id, GL_COMPILE_STATUS, &res);
	glGetShaderInfoLog(shaderId, 512, NULL, result);
	char infoLog[1024];
	glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
	std::cout << "CShader::Compile - GL_VERTEX_SHADER\n%s\n-----" << infoLog;
}

void Shader::create()
{
	id = glCreateProgram();
	for (unsigned int i = 0; i < shaders.size(); i++)
	{
		glAttachShader(id, shaders[i]);
	}
	glLinkProgram(id);
}

void Shader::setMat4(const char* name, glm::mat4x4 matrix) 
{
	glUniformMatrix4fv(glGetUniformLocation(id, name), 1, GL_FALSE, &matrix[0][0]);
}