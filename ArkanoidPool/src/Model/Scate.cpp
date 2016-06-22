#include "Model/Scate.h"
#include "Game/game_settings.h"

const int Scate::defaultAcceleration = 15;

Scate::Scate()
: m_acceleration(0)
{
	init();
}

Scate::~Scate()
{
}

void Scate::init() {
	pos.top = static_cast<float>(game::screenHeight);
	pos.bottom = static_cast<float>(game::screenHeight - 25);
	pos.left = static_cast<float>(game::screenWidth / 2 - 50);
	pos.right = static_cast<float>(game::screenWidth / 2 + 50);
}

void Scate::update() {
	if (m_acceleration > 0) {
		if ((pos.right < game::screenWidth - defaultAcceleration)) {
			pos.left += m_acceleration;
			pos.right += m_acceleration;
		}
	}
	else if (m_acceleration < 0){
		if (pos.left > defaultAcceleration) {
			pos.left += m_acceleration;
			pos.right += m_acceleration;
		}
	}
}

void Scate::moveLeft() {
	m_acceleration = -defaultAcceleration;
}

void Scate::moveRight() {
 	m_acceleration = defaultAcceleration;
}

void Scate::stopMove() {
	m_acceleration = 0;
}

void Scate::reset() {
	m_acceleration = 0;
	init();
}
