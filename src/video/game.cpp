#include <stdexcept>
#include <sstream>
#include <iostream>
#include <SDL.h>

#include "game.hpp"

Game::Game() :
	mWindow(nullptr),
	mRenderer(nullptr),
	mGameIsRunning(false)
{}

Game::~Game()
{
	close();
}

void Game::init(const std::string& title, int w, int h, int x, int y)
{
	std::ostringstream errorMsg;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//printf("SDL could not initialize! Error: %s\n", SDL_GetError());
		errorMsg << "SDL could not initialize! Error: " << SDL_GetError() << "\n";
		throw std::runtime_error(errorMsg.str());
	}
	else
	{
		//try creating the window
		mWindow = SDL_CreateWindow(title.c_str(), x, y, w, h, SDL_WINDOW_SHOWN);
		if (mWindow != nullptr)
		{
			//printf("SDL could not create window! Error: %s\n", SDL_GetError());
			errorMsg << "SDL could not create window! Error: " << SDL_GetError() << "\n";
			throw std::runtime_error(errorMsg.str());
		}
		else
		{
			if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			{
				printf("SDL could not set texture filtering!\n");
			}
			//try creating the window's rendering context
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (mRenderer == nullptr)
			{
				//printf("SDL could not create renderer! Error: %s\n", SDL_GetError());
				errorMsg << "SDL could not create renderer! Error:" << SDL_GetError() << "\n";
				throw std::runtime_error(errorMsg.str());
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
	std::cout << "Game initialized successfully" << std::endl;
}

//Cleanup all resources used by the game and shutdown SDL's functions
void Game::close()
{
	//free game textures

	//free fonts

	//free window/renderer
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);

	//quit SDL subsystems
	SDL_Quit();
}

void Game::handleEvents()
{

}

void Game::gameLoop()
{
	SDL_Event e;
	mGameIsRunning = true;

	while (mGameIsRunning)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				endGameLoop();
			}
		}
	}
}

void Game::endGameLoop()
{
	mGameIsRunning = false;
}

SDL_Renderer* Game::getRenderer() const
{
	return mRenderer;
}