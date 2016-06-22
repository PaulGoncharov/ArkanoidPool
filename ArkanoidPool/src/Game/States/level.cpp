#include "Game/Game.h"
#include "Game/States/gamestate.h"
#include "Game/States/level.h"
#include "Game/States/winstate.h"
#include "Game/States/losestate.h"

#include <iostream>


Level Level::m_Level;
const unsigned Level::levelMax = 2;

void Level::init(Game* game)
{
	std::cout << "Level init" << std::endl;
	switch (m_level_number) {
		case 1:
		{
			game->loadLevel(assets::firstLevel);
			break;
		}
		case 2:
		{
			game->loadLevel(assets::secondLevel);
			break;
		}
		default:
			break;
	}
}

void Level::cleanup(Game* game)
{
	game->getModel().reset();
	std::cout << "Level cleanup" << std::endl;
}

void Level::pause(Game* game)
{
	game->setRun(false);
	std::cout << "Level pause" << std::endl;
}

void Level::resume(Game* game)
{
	game->setRun(false);
	std::cout << "Level resume" << std::endl;
}

void Level::handleEvent(Game* game, IEvent* event)
{
	auto eventType = event->getEventID();
	switch (eventType) {
	case EventType::pausePressed:
	{
		if (game->isRunning()) {
			game->pause();
		}
		else {
			game->resume();
		}
		std::cout << "Level::pause pressed" << std::endl;
		break;
	}
	case EventType::LeftArrowPressed:
	{
		game->getModel().getScate().moveLeft();
		std::cout << "Level::Left arrow pressed" << std::endl;
		break;
	}
	case EventType::RightArrowPressed:
	{
		game->getModel().getScate().moveRight();
		std::cout << "Level::Right arrow pressed" << std::endl;
		break;
	}
	case EventType::LeftArrowReleased:
	{
		game->getModel().getScate().stopMove();
		std::cout << "Level::Left arrow released" << std::endl;
		break;
	}
	case EventType::RightArrowReleased:
	{
		game->getModel().getScate().stopMove();
		std::cout << "Level::Right arrow released" << std::endl;
		break;
	}
	case EventType::update:
	{
		game->update();
		break;
	}
	case EventType::SpacePressed:
	{
		game->getModel().getBall().launch();
		break;
	}
	case EventType::Cheat:
	{
		if (m_level_number == levelMax) {
			game->changeState(WinState::Instance());
		}
		else {
			m_level_number++;
			game->changeState(Level::Instance());
		}
		break;
	}
	default:
		break;

	}
}

void Level::update(Game* game)
{
	if(game->isRunning()) {
		game->getModel().update();
	}

	if (game->getModel().getLives() == 0) {
		game->changeState(LoseState::Instance());
	}

	if (game->getModel().getAliveBriksNumber() == 0) {
		if (m_level_number == levelMax) {
			game->changeState(WinState::Instance());
		}
		else {
			m_level_number++;
			game->changeState(Level::Instance());
		}
	}
	game->draw();
}

void Level::draw(Game* game)
{
	// draw background
	unsigned width, height;
	game->getView().getScreenResolution(width, height);
	Rect rect(0, static_cast<float>(width), 0, static_cast<float>(height));
	game->getView().drawRect(rect, textures::mainBackground);

	// draw ball
	Ball& ball = game->getModel().getBall();
	game->getView().drawRect(ball.getPos(), textures::mainBall);

	// draw briks
	std::vector<Brick>& briks = game->getModel().getBriks();
	
	for (std::size_t i = 0; i < briks.size(); ++i) {
		Brick& brick = briks[i];
		if (!brick.isAlive()) {
			continue;
		}
		
		// TODO return texture string id via stasit map
		switch (brick.getHits()) {
		case 1: 
			{
				  game->getView().drawRect(brick.getCoord(), textures::brick1hit);
				break;
			}
			case 2:
			{
					  game->getView().drawRect(brick.getCoord(), textures::brick2hits);
				break;
			}
			case 3:
			{
					  game->getView().drawRect(brick.getCoord(), textures::brick3hits);
				break;
			}
			default:
				break;
		}
	}

	// draw scate
	Scate& scate = game->getModel().getScate();
	game->getView().drawRect(scate.getPos(), textures::scate);

	// draw level
	game->getView().drawText(game::levelXCoord, game::levelYCoord, std::string(std::to_string(m_level_number)));

	// draw lives
	std::string lives(std::to_string(game->getModel().getLives()));
	game->getView().drawText(game::deadPoolsXCoord, game::deadPoolsYCoord, lives);

	// draw lives
	std::string scores(std::to_string(game->getModel().getScores()));
	game->getView().drawText(game::scoreXCoord, game::scoreYCoord, scores);
}
