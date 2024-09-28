#pragma once
#include "modules/renderer/mesh.h"


struct NeighbourChunks
{

};

class Chunk
{
public:
	Chunk();

	ChunkMesh* mesh;
	NeighbourChunks neighbour;
	uint8_t* blocks;
private:

};
