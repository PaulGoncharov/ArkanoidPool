#ifndef LOSESTATE_H
#define LOSESTATE_H

#include "gamestate.h"

class LoseState : public GameState
{
public:
	virtual void init(Game* game) override;
	virtual void cleanup(Game* game) override;

	virtual void pause(Game* game) override;
	virtual void resume(Game* game) override;

	void handleEvent(Game* game, IEvent* event) override;
	virtual void update(Game* game) override;
	virtual void draw(Game* game) override;

	static LoseState* Instance() {
		return &m_loseState;
	}

protected:
	LoseState() { }

private:
	static LoseState m_loseState;
};

#endif // LOSESTATE_H