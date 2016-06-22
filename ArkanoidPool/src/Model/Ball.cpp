#include "Model/Model.h"
#include "Model/Ball.h"
#include "Model/Scate.h"
#include "Game/game_settings.h"
#include <iostream>

const float Ball::diameter = 30;
const int Ball::defaultXAcceleration = 5;
const int Ball::defaultYAcceleration = -5;

Ball::Ball(Model *model)
: m_model(model)
, m_launched(false)
, m_lives(3)
, dx(0)
, dy(0)
{
	initPos();
}

Ball::~Ball()
{
}

void Ball::update() {
	if (m_launched) {

		pos.left += dx;
		pos.right += dx;
		pos.top += dy;
		pos.bottom += dy;


		if ((pos.left <= 0) || pos.right >= game::screenWidth) {
			dx = -dx;
		}

		if (pos.bottom <= game::roof) {
			dy = -dy;
		}

		checkScateReflection();

		if (pos.bottom >= game::screenHeight) {
			m_lives--;
			reset();
		}
	}
	else {
		const Rect& scatePos = m_model->getScate().getPos();
		pos.left = static_cast<float>(scatePos.left + (scatePos.right - scatePos.left) / 2 - diameter / 2);
		pos.right = static_cast<float>(scatePos.left + (scatePos.right - scatePos.left) / 2 + diameter / 2);
	}
}

void Ball::initPos() {
	const Rect& scatePos = m_model->getScate().getPos();
	pos.top = static_cast<float>(scatePos.bottom);
	pos.bottom = static_cast<float>(scatePos.bottom - diameter);
	pos.left = static_cast<float>(scatePos.left + (scatePos.right - scatePos.left)/2 - diameter / 2);
	pos.right = static_cast<float>(scatePos.left + (scatePos.right - scatePos.left) / 2 + diameter / 2);
	int qwe = 0;
}

void Ball::launch() {
	if (!m_launched) {
		m_launched = true;
		dx = defaultXAcceleration;
		dy = defaultYAcceleration;
	}
}

void Ball::reset() {
	m_launched = false;
	initPos();
}

void Ball::checkScateReflection() {
	const Rect& scatePos = m_model->getScate().getPos();
	isCollision(scatePos);
}


bool Ball::isCollision(const Rect& elemPos) {

	// Some magick  calcilations
	float ball_x = (pos.right - pos.left) / 2 + pos.left;
	float ball_y = (pos.top - pos.bottom) / 2 + pos.bottom;
	float brickHeight = elemPos.top - elemPos.bottom;
	float brickWidth = elemPos.right - elemPos.left;
	bool wasCollision = false;

	if (abs(ball_x - elemPos.left - brickWidth / 2 - 2) <= (diameter / 2 + brickWidth / 2)
		&& abs(ball_y - elemPos.bottom - brickHeight / 2 - 2) <= (diameter / 2 + brickHeight / 2))
	{
		if ((sqrt((elemPos.left + brickWidth / 2 - ball_x)*(elemPos.left + brickWidth / 2 - ball_x) +
			(elemPos.bottom + brickHeight / 2 - ball_y)*(elemPos.bottom + brickHeight / 2 - ball_y)) -
			(brickWidth / 2 - 1)*sqrt(2.0) - diameter / 2) > (diameter / 2)*(sqrt(2.0) - 1)) {
		}
		else {
			wasCollision = true;
		}
	}

	if (wasCollision) {
		if (abs(ball_x - elemPos.left - brickWidth / 2) < abs(ball_y - elemPos.bottom - brickHeight / 2)*brickWidth / brickHeight)
		{
			dy *= -1;
		}
		else 
		{
			dx *= -1;
		}
	}

	return wasCollision;
}
