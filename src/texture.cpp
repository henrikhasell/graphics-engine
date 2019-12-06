#include "texture.hpp"

Texture::Texture()
{
	glGenTextures(1, &texture);

	bind();

	const GLubyte pixels[] = {
		0xff, 0xff, 0xff,
		0xaa, 0xaa, 0xaa,
		0xaa, 0xaa, 0xaa,
		0xff, 0xff, 0xff
	};

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		2,
		2, 0,
		GL_RGB, GL_UNSIGNED_BYTE,
		pixels
	);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

Texture::~Texture()
{
	glDeleteTextures(1, &texture);
}

bool Texture::load(const char path[])
{
	return false;
}

bool Texture::load(SDL_Surface* surface)
{
	return false;
}

void Texture::bind(GLenum texture) const
{
	glBindTexture(GL_TEXTURE_2D, this->texture);
}