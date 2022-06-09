#include <SDL.h>

#include "game.hpp"

Game::Game(const std::string& title) : kTitle(title), mWindow(nullptr), mRenderer(nullptr) {}

Game::~Game()
{
	quit();
}

bool Game::init()
{
	bool initSuccess = true;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! Error: %s\n", SDL_GetError());
		initSuccess = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("SDL did not set hint. Linear texture filtering not enabled!\n");
		}
		//Create game window
		mWindow = SDL_CreateWindow(kTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								   kWindowWidth, kWindowHeight, SDL_WINDOW_SHOWN);
		if (mWindow == nullptr)
		{
			printf("SDL could not create window! Error: %s\n", SDL_GetError());
			initSuccess = false;
		}
		else
		{
			//Create game window rendering context
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (mRenderer == nullptr)
			{
				printf("SDL could not create renderer! Error: %s\n", SDL_GetError());
				initSuccess = false;
			}
			else
			{
				//Initialize the render color
				SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize SDL image loading

				//Initialize SDL font loading

				//initialize SDL audio loading
			}
		}
	}
	return initSuccess;
}

//Cleanup all resources used by the game and shutdown SDL's functions
void Game::quit()
{
	//free game textures

	//free fonts

	//free window/renderer
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	mRenderer = nullptr;
	mWindow = nullptr;

	//quit SDL subsystems
	SDL_Quit();
}

void Game::render()
{
	SDL_RenderPresent(mRenderer);
}

SDL_Window* Game::getGameWindow() const
{
	return mWindow;
}

SDL_Renderer* Game::getGameRenderer() const
{
	return mRenderer;
}