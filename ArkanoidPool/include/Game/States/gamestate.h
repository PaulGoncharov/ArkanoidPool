#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game/Game.h"
#include "Dispatcher/IEvent.h"
#include "Game/assets_description.h"
#include "Game/game_settings.h"

class GameState
{
public:
	virtual void init(Game* game) = 0;
	virtual void cleanup(Game* game) = 0;

	virtual void pause(Game* game) = 0;
	virtual void resume(Game* game) = 0;

	virtual void handleEvent(Game* game, IEvent* event) = 0;
	virtual void update(Game* game) = 0;
	virtual void draw(Game* game) = 0;

	void changeState(Game* game, GameState* state) {
		game->changeState(state);
	}

protected:
	GameState() { }
};

#endif // GAMESTATE_H