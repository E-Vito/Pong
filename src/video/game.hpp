#pragma once

#include <string>
#include <SDL.h>

class Game
{
public:
	Game();
	~Game();

	void init(const std::string& title, int w, int h, int x, int y);
	void close();

	void handleEvents();
	void gameLoop();
	void endGameLoop();

	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	bool mGameIsRunning;
};