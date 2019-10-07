#include <iostream>
#include "Player.h"
#include "Idle.h"
#include "Debug.h"

Player::Player()
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::Player(const std::vector<AnimatedSprite*>& s) : m_sprites(s), m_currentSprite(s[0])
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite* Player::getAnimatedSprite(Input* in)
{

	switch (in->getCurrent())
	{
	case Input::Action::IDLE:
		//std::cout << "Player Idling" << std::endl;
		m_state.idle();
		m_currentSprite = m_sprites[0];
		break;
	case Input::Action::UP:
		//std::cout << "Player Up" << std::endl;
		m_state.jumping();
		m_currentSprite = m_sprites[1];
		break;
	case Input::Action::LEFT:
		//std::cout << "Player Left" << std::endl;
		m_state.climbing();
		m_currentSprite = m_sprites[2];
		break;
	case Input::Action::RIGHT:
		//std::cout << "Player Idling" << std::endl;
		m_state.climbing();
		m_currentSprite = m_sprites[3];
		break;
	default:
		break;
	}

	int frame = m_currentSprite->getCurrentFrame();
	m_currentSprite->setRect(m_currentSprite->getFrame(frame));

	return m_currentSprite;
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_currentSprite->update();
}