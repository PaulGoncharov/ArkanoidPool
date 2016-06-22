#include <iostream>

#include "Game/Game.h"
#include "Game/States/losestate.h"

#include "View/View.h"

LoseState LoseState::m_loseState;

void LoseState::init(Game* game)
{
	std::cout << "LoseState init" << std::endl;
}

void LoseState::cleanup(Game* game)
{
	std::cout << "LoseState cleanup" << std::endl;
}

void LoseState::pause(Game* game)
{
	std::cout << "LoseState pause" << std::endl;
}

void LoseState::resume(Game* game)
{
	std::cout << "LoseState resume" << std::endl;
}

void LoseState::handleEvent(Game* game, IEvent* event)
{
	auto eventType = event->getEventID();
	switch (eventType) {
	case EventType::update:
	{
		game->update();
		break;
	}
	default:
		break;
	}

}

void LoseState::update(Game* game)
{
	game->draw();
}

void LoseState::draw(Game* game)
{
	// draw background
	unsigned width, height;
	game->getView().getScreenResolution(width, height);
	Rect rect(0, static_cast<float>(width), 0, static_cast<float>(height));
	game->getView().drawRect(rect, textures::loseBackground);
}
