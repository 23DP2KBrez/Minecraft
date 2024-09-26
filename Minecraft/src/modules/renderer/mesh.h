#pragma once
#include <cstdint>
#include <vector>
#include "glm/gtc/matrix_transform.hpp"

const int CHUNK_SIZE = 16;

class ChunkMesh
{
public:
	ChunkMesh() = default;
	ChunkMesh(uint8_t* blocks);
	~ChunkMesh();
	void createMesh();
	void renderMesh();

	glm::mat4 getModelMatrix();
private:
	unsigned int VAO;
	unsigned int VBO;

	uint8_t* blocks;

	std::vector<float> vertices;
};