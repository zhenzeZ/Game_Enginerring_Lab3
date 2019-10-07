#ifndef PLAYER_H
#define PLAYER_H

#include "Input.h"
#include "PlayerFSM.h"
#include "AnimatedSprite.h"

class Player
{
private:
	PlayerFSM m_state;

	AnimatedSprite* m_currentSprite;
	std::vector<AnimatedSprite*> m_sprites;
	Player();

public:
	Player(const std::vector<AnimatedSprite*>& s);
	~Player();
	AnimatedSprite* getAnimatedSprite(Input* in);
	void update();
};

#endif // !PLAYER_H
