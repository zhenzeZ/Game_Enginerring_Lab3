#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <vector>
#include "Debug.h"
#include <SDL.h>
#include <SDL_timer.h>

using namespace std;

class AnimatedSprite {
public:
	AnimatedSprite();
	AnimatedSprite(SDL_Texture* Texture);
	AnimatedSprite(SDL_Texture* Texture, SDL_Rect& IntRect);
	~AnimatedSprite();

	Uint32& getTime();
	vector<SDL_Rect>& getFrames();
	SDL_Rect& getFrame(int);
	SDL_Texture* m_spriteTexture;

	int getCurrentFrame();

	void addFrame(SDL_Rect&);
	void update();
	void setRect(SDL_Rect& rect);
private:
	vector<SDL_Rect> m_frames;
	Uint32 frameTime;

	int m_current_frame;
	int startTime;
	int runTime;

};

#endif // !ANIMATED_SPRITE_H

