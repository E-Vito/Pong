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
	static const uint16_t kWindowHeight = 1280u;
	static const uint16_t kWindowWidth = 960u;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	const std::string kTitle;
};