#include "ImageTexture.h"

ImageTexture::ImageTexture(Message& msg, Renderer& renderer, std::string path)
	: mMsg{ msg },
	  mRenderer{ renderer },
	  mPath{ path }
{
	SDL_Texture* newTexture{ nullptr };
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == nullptr)
	{
		mMsg.fatalError("Failed to load image [" + mPath + "]!  SDL_Image Error: (" + std::string(IMG_GetError()) + ")");
	}

	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));  // TODO: study this line

	newTexture = SDL_CreateTextureFromSurface(mRenderer.getRenderer(), loadedSurface);

	if (newTexture == nullptr)
	{
		mMsg.fatalError("Failed to create texture from [" + mPath + "]  SDL Error : (" + std::string(SDL_GetError()) + ")");
	}

	mWidth = loadedSurface->w;
	mHeight = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);
	mTexture = newTexture;
}

ImageTexture::~ImageTexture()
{
	if (mTexture != nullptr)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = nullptr;
		mWidth = 0;
		mHeight = 0;
	}
}

void ImageTexture::render(int x, int y)
{
	SDL_Rect renderQuad{ x, y, mWidth, mHeight };
	SDL_RenderCopy(mRenderer.getRenderer(), mTexture, NULL, &renderQuad);
}

void ImageTexture::render(int x, int y, int w, int h)
{
	SDL_Rect renderQuad{ x, y, w, h };
	SDL_RenderCopy(mRenderer.getRenderer(), mTexture, NULL, &renderQuad);
}

int ImageTexture::getWidth() const
{
	return mWidth;
}

int ImageTexture::getHeight() const
{
	return mHeight;
}
