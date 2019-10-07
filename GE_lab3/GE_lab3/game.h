#pragma once
#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_timer.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include "Player.h"
#include "InputHandler.h"
#include "Input.h"

using namespace std;

class Game {

public:
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void update();
	void render();

	bool m_exitGame;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	SDL_Texture* m_idleTexture;
	SDL_Texture* m_upTexture;
	SDL_Texture* m_leftTexture;
	SDL_Texture* m_rightTexture;
	AnimatedSprite* m_idle;
	AnimatedSprite* m_up;
	AnimatedSprite* m_left;
	AnimatedSprite* m_right;

	Player* m_player;
	InputHandler* m_handler;
	Input* m_input;

	std::vector<AnimatedSprite*> m_Sprites;
	SDL_Rect bounds = { 0,0,88,88 };
	SDL_Rect rect;
};



#endif // !GAME