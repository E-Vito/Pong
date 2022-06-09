#pragma once

#include <string>
#include <SDL.h>

class Game
{
public:
	Game() = delete;
	Game(const std::string& title);
	~Game();

	bool init();
	void quit();
	void render();


	SDL_Window* getGameWindow() const;
	SDL_Renderer* getGameRenderer() const;

private:
	static const int16_t kWindowHeight = 1280;
	static const int16_t kWindowWidth = 960;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	const std::string kTitle;
};