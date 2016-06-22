#include <iostream>

#include "Game/Game.h"
#include "Game/States/gamestate.h"
#include "Game/States/introstate.h"
#include "Game/States/Level.h"

#include "View/View.h"

IntroState IntroState::m_IntroState;

void IntroState::init(Game* game)
{
	std::cout << "IntroState init" << std::endl;
}

void IntroState::cleanup(Game* game)
{
	std::cout << "IntroState cleanup" << std::endl;
}

void IntroState::pause(Game* game)
{
	std::cout << "IntroState pause" << std::endl;
}

void IntroState::resume(Game* game)
{
	std::cout << "IntroState resume" << std::endl;
}

void IntroState::handleEvent(Game* game, IEvent* event)
{
	auto eventType = event->getEventID();
	switch (eventType) {
		case EventType::SpacePressed:
		{
			game->changeState(Level::Instance());
			break;
		}
		case EventType::update:
		{
			game->update();
			break;
		}
		default:
			break;
			
	}
	
}

void IntroState::update(Game* game)
{
	game->draw();
}

void IntroState::draw(Game* game)
{
	// draw background
	unsigned width, height;
	game->getView().getScreenResolution(width, height);
	Rect rect(0, static_cast<float>(width), 0, static_cast<float>(height));
	game->getView().drawRect(rect, textures::introBackground);
}
