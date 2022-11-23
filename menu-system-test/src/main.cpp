#include "message.h"
#include "Renderer.h"
#include "ImageTexture.h"



int main(int, char**)
{
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	const int LOGICAL_WIDTH = 1920;
	const int LOGICAL_HEIGHT = 1080;

	Message msg;
	Renderer renderer{ msg, SCREEN_WIDTH, SCREEN_HEIGHT };

	bool isRunning = true;
	SDL_Event e;

	int button1Width = 200;
	int button1Height = 50;
	int button2Width = 200;
	int button2Height = 50;

	renderer.addRect(
		BUTTON_1, 
		(renderer.getWidth() - button1Width) / 2, 
		(renderer.getHeight() - button1Height) / 2 - 100,
		button1Width, 
		button1Height
	);

	renderer.addRect(
		BUTTON_2,
		(renderer.getWidth() - button2Width) / 2,
		(renderer.getHeight() - button2Height) / 2,
		button1Width,
		button1Height
	);

	ImageTexture bg{ msg, renderer, "assets/img/BG_PlaceholderV1.png" };
	ImageTexture title{ msg, renderer, "assets/img/Title_PlaceholderV1.png" };
	ImageTexture button1{ msg, renderer, "assets/img/Button_PlaceholderV1.png" };

	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				isRunning = false;
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
			{
				isRunning = false;
			}
		}

		renderer.setRenderDrawColor(0, 0, 0, 255);

		renderer.clear();

		// Draw everything else
		//renderer.fillRect(BUTTON_1, 0, 255, 0, 255);
		//renderer.fillRect(BUTTON_2, 0, 0, 255, 255);
		bg.render(0, 0, LOGICAL_WIDTH, LOGICAL_HEIGHT);

		title.render(
			LOGICAL_WIDTH / 2 - title.getWidth() / 2,
			(LOGICAL_HEIGHT / 2 - title.getHeight() / 2) - 300,
			title.getWidth(),
			title.getHeight()
		);

		button1.render(
			LOGICAL_WIDTH / 2 - button1.getWidth() / 2,
			(LOGICAL_HEIGHT / 2 - button1.getHeight() / 2) - 50,
			button1.getWidth(),
			button1.getHeight()
		);

		button1.render(
			LOGICAL_WIDTH / 2 - button1.getWidth() / 2,
			(LOGICAL_HEIGHT / 2 - button1.getHeight() / 2) + 75,
			button1.getWidth(),
			button1.getHeight()
		);

		button1.render(
			LOGICAL_WIDTH / 2 - button1.getWidth() / 2,
			(LOGICAL_HEIGHT / 2 - button1.getHeight() / 2) + 200,
			button1.getWidth(),
			button1.getHeight()
		);

		button1.render(
			LOGICAL_WIDTH / 2 - button1.getWidth() / 2,
			(LOGICAL_HEIGHT / 2 - button1.getHeight() / 2) + 325,
			button1.getWidth(),
			button1.getHeight()
		);

		button1.render(
			LOGICAL_WIDTH / 2 - button1.getWidth() / 2,
			(LOGICAL_HEIGHT / 2 - button1.getHeight() / 2) + 450,
			button1.getWidth(),
			button1.getHeight()
		);

		renderer.present();
	}

	return 0;
}