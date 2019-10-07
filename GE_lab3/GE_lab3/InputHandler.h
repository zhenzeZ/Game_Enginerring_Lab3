#pragma once
#include "Command.h"

#include<iostream>

using namespace std;

class InputHandler
{
public:
	InputHandler(Input* input);
	~InputHandler();
	//method to bind commands
	void handleInput(SDL_Keycode event);

private:
	Command* left;
	Command* right;
	Command* up;
	Command* idle;

};

