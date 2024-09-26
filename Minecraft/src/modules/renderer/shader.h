#pragma once
#include "glad/glad.h"
#include "glm/glm.hpp"
#include <vector>

class Shader
{
public:
	void loadShader(const char* path, GLenum type);
	void create();

	unsigned int getId() { return id; }

	void setInt();
	void setFloat();
	void setVec3();
	void setMat4(const char* name, glm::mat4x4 matrix);

private:
	std::vector<unsigned int> shaders;
	unsigned int id;
};