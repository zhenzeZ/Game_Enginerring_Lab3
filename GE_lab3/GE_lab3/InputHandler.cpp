#include "InputHandler.h"

InputHandler::InputHandler(Input* input)
{
	left = new Left(input);
	right = new Right(input);
	up = new Up(input);
	idle = new Down(input);

}

InputHandler::~InputHandler()
{
}


void InputHandler::handleInput(SDL_Keycode event)
{

	switch (event)
	{
	case SDLK_UP:
		up->execute();
		cout << "up" << endl;
		break;
	case SDLK_LEFT:
		left->execute();
		cout << "left" << endl;
		break;
	case SDLK_RIGHT:
		right->execute();
		cout << "right" << endl;
		break;
	case SDLK_DOWN:
		idle->execute();
		cout << "down" << endl;
		break;
	default:
		break;
	}

}
