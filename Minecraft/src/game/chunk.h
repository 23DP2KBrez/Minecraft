#pragma once
#include "modules/renderer/mesh.h"

struct NeighbourChunks
{

};

class Chunk
{
public:
	Chunk();

	Mesh* mesh;
	NeighbourChunks neighbour;
	uint8_t* blocks;
private:

};
