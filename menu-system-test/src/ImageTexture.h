#pragma once

#include <SDL2/SDL_image.h>
#include "message.h"
#include "Renderer.h"

class ImageTexture
{
public:
	ImageTexture(Message& msg, Renderer& renderer, std::string path);
	~ImageTexture();

	void render(int x, int y);
	void render(int x, int y, int w, int h);

	int getWidth() const;
	int getHeight() const;

private:
	Message& mMsg;
	Renderer& mRenderer;


	SDL_Texture* mTexture{ nullptr };
	std::string mPath{};
	int mWidth{};
	int mHeight{};
};

