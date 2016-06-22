#ifndef INTROSTATE_H
#define INTROSTATE_H

#include "gamestate.h"

class IntroState : public GameState
{
public:
	virtual void init(Game* game) override;
	virtual void cleanup(Game* game) override;

	virtual void pause(Game* game) override;
	virtual void resume(Game* game) override;

	void handleEvent(Game* game, IEvent* event) override;
	virtual void update(Game* game) override;
	virtual void draw(Game* game) override;

	static IntroState* Instance() {
		return &m_IntroState;
	}

protected:
	IntroState() { }

private:
	static IntroState m_IntroState;
};

#endif // INTROSTATE_H