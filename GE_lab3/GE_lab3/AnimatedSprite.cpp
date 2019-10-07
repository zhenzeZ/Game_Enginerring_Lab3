#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
	m_current_frame = 0;
	startTime = SDL_GetTicks();
	runTime = 0;
}

AnimatedSprite::AnimatedSprite(SDL_Texture* t) : m_spriteTexture(t), m_current_frame(0) {}

AnimatedSprite::AnimatedSprite(SDL_Texture* t, SDL_Rect& rect) : m_spriteTexture(t), m_current_frame(0) {
	m_frames.push_back(rect);
}

AnimatedSprite::~AnimatedSprite() {}

Uint32& AnimatedSprite::getTime() {
	return frameTime;
}

vector<SDL_Rect>& AnimatedSprite::getFrames() {
	return m_frames;
}

SDL_Rect& AnimatedSprite::getFrame(int n) {
	return m_frames[n];
}

void AnimatedSprite::addFrame(SDL_Rect& frame) {
	m_frames.push_back(frame);
	frameTime = 1000 / m_frames.size();
}

int AnimatedSprite::getCurrentFrame() {
	return m_current_frame;
}

void AnimatedSprite::update() {
	runTime = SDL_GetTicks() - startTime;

	if (runTime > frameTime * (getCurrentFrame() + 1)) {
		if (m_frames.size() > m_current_frame + 1)
		{
			m_current_frame++;
		}
		else {
			m_current_frame = 0;
			startTime = SDL_GetTicks();
			runTime = 0;
		}
	}
}

void AnimatedSprite::setRect(SDL_Rect& rect)
{
	m_frames.at(m_current_frame) = rect;
}

