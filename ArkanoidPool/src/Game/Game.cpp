#include "Game/Game.h"
#include "Game/States/gamestate.h"
#include "Dispatcher/Dispatcher.h"
#include "Dispatcher/IEvent.h"

#include <iostream>

Game::Game() {
	//init();
}

void Game::init()
{
	m_running = true;

	// Register client and events.
	Dispatcher* dispatcher = Dispatcher::GetInstance();
	dispatcher->registerClient(EventType::LeftArrowPressed, this);
	dispatcher->registerClient(EventType::RightArrowPressed, this);
	dispatcher->registerClient(EventType::LeftArrowReleased, this);
	dispatcher->registerClient(EventType::RightArrowReleased, this);
	dispatcher->registerClient(EventType::SpacePressed, this);
	dispatcher->registerClient(EventType::pausePressed, this);
	dispatcher->registerClient(EventType::EscPressed, this);
	dispatcher->registerClient(EventType::update, this);
	dispatcher->registerClient(EventType::Cheat, this);

	// initialize model and view
	view.init();

	std::cout << "Game init" << std::endl;
}

void Game::cleanup()
{
	// cleanup the all states
	while (!states.empty()) {
		states.back()->cleanup(this);
		states.pop_back();
	}

	std::cout << "Game cleanup" << std::endl;
}

void Game::changeState(GameState* state)
{
	// cleanup the current state
	if (!states.empty()) {
		states.back()->cleanup(this);
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->init(this);
}

void Game::update()
{
	// let the state update the game
	states.back()->update(this);
}

void Game::draw()
{
	// let the state draw the screen
	states.back()->draw(this);
}

void Game::handleEvent(IEvent* event) {
	states.back()->handleEvent(this, event);
}

void Game::loadLevel(const std::string& fileName) {
	model.loadLevel(fileName);
}

void Game::pause() {
	states.back()->pause(this);
}

void Game::resume() {
	states.back()->resume(this);
}

void Game::setRun(bool isRunning) {
	m_running = isRunning;
}

