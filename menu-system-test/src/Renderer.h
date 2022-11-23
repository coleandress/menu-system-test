#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <map>
#include <memory>

#include "message.h"
#include "UtilConstants.h"


class Renderer
{
public:
	Renderer(Message& msg, const int& width, const int& height);
	~Renderer();

	static bool makeMessageBox(const std::string& title, const std::string& text);
	void setRenderDrawColor(const int& r, const int& g, const int& b, const int& a);
	void clear();
	void present();

	void addRect(const RectName& rectName, const int& x, const int& y, const int& w, const int& h);
	void fillRect(const RectName& rectName, const int& r, const int& g, const int& b, const int& a);

	SDL_Renderer* getRenderer() const;
	const int& getWidth() const;
	const int& getHeight() const;

private:
	Message& mMsg;
	SDL_Window* mWindow{ nullptr };
	SDL_Renderer* mRenderer{ nullptr };

	const int mWidth;
	const int mHeight;
	std::map<RectName, SDL_Rect> mRects;
};

