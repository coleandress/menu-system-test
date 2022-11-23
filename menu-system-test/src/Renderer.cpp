#include "Renderer.h"

Renderer::Renderer(Message& msg, const int& width, const int& height)
	: mMsg{ msg },
	  mWidth{ width },
	  mHeight{ height }
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		mMsg.fatalError("Call to SDL_Init failed (" + std::string(SDL_GetError()) + ")");

	mWindow = SDL_CreateWindow("Menu Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth, mHeight, 0);
	if (!mWindow)
		mMsg.fatalError("Call to SDL_CreateWindow failed (" + std::string(SDL_GetError()) + ")");

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	if (!mRenderer)
		mMsg.fatalError("Call to SDL_CreateRenderer failed (" + std::string(SDL_GetError()) + ")");
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

bool Renderer::makeMessageBox(const std::string& title, const std::string& text)
{
	return SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error", text.c_str(), NULL);
}

void Renderer::setRenderDrawColor(const int& r, const int& g, const int& b, const int& a)
{
	SDL_SetRenderDrawColor(mRenderer, r, g, b, a);
}

void Renderer::clear()
{
	SDL_RenderClear(mRenderer);
}

void Renderer::present()
{
	SDL_RenderPresent(mRenderer);
}

void Renderer::addRect(const RectName& rectName, const int& x, const int& y, const int& w, const int& h)
{
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	mRects.insert(std::make_pair(rectName, r));
}

// TODO: overload without draw color and make method to check draw color and log
void Renderer::fillRect(const RectName& rect, const int& r, const int& g, const int& b, const int& a)
{
	setRenderDrawColor(r, g, b, a);

	SDL_RenderFillRect(mRenderer, &mRects[rect]);
}

SDL_Renderer* Renderer::getRenderer() const
{
	return mRenderer;
}

const int& Renderer::getWidth() const
{
	return mWidth;
}

const int& Renderer::getHeight() const
{
	return mHeight;
}
