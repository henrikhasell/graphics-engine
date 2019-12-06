#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>
#include <SDL2/SDL.h>

class Texture
{
public:
	Texture();
	~Texture();
	bool load(const char path[]);
	bool load(SDL_Surface* surface);
	void bind(GLenum texture = GL_TEXTURE0) const;
private:
	GLuint texture;
};

#endif // TEXTURE_HPP