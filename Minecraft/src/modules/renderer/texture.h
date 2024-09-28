#pragma once

class TextureAtlas
{
public:
	TextureAtlas() = default;

	void load(const char* path);
	void bind();
	void unbind();

	unsigned int getId() { return id; }
private:
	unsigned int id;
};