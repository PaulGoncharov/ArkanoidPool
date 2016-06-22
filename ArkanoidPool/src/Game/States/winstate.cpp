#include <iostream>

#include "Game/Game.h"
#include "Game/States/winstate.h"

#include "View/View.h"

WinState WinState::m_winState;

void WinState::init(Game* game)
{
	std::cout << "WinState init" << std::endl;
}

void WinState::cleanup(Game* game)
{
	std::cout << "WinState cleanup" << std::endl;
}

void WinState::pause(Game* game)
{
	std::cout << "WinState pause" << std::endl;
}

void WinState::resume(Game* game)
{
	std::cout << "WinState resume" << std::endl;
}

void WinState::handleEvent(Game* game, IEvent* event)
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

void WinState::update(Game* game)
{
	game->draw();
}

void WinState::draw(Game* game)
{
	// draw background
	unsigned width, height;
	game->getView().getScreenResolution(width, height);
	Rect rect(0, static_cast<float>(width), 0, static_cast<float>(height));
	game->getView().drawRect(rect, textures::winBackground);
}
