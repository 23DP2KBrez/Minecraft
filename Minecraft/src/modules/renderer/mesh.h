#pragma once
#include <cstdint>
#include <vector>
#include "glm/gtc/matrix_transform.hpp"

const int CHUNK_SIZE = 16;
const float UV_SIZE = 1.0f / 16.0f;

static inline int getBlockIndex(int x, int y, int z)
{
	return x * CHUNK_SIZE * CHUNK_SIZE + y * CHUNK_SIZE + z;
}

class Mesh
{
public:
	Mesh() = default;
	Mesh(uint8_t* blocks);
	~Mesh();
	void createMesh();
	void renderMesh();

	glm::mat4 getModelMatrix();
private:
	unsigned int VAO;
	unsigned int VBO;

	unsigned int TBO;

	uint8_t* blocks;

	std::vector<float> vertices;
};