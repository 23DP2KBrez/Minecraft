#include "chunk.h"

Chunk::Chunk()
{
	blocks = new uint8_t[4096];
	memset(blocks, 0, 4096);

	mesh = new Mesh(blocks);
}

