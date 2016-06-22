#ifndef WINSTATE_H
#define WINSTATE_H

#include "gamestate.h"

class WinState : public GameState
{
public:
	virtual void init(Game* game) override;
	virtual void cleanup(Game* game) override;

	virtual void pause(Game* game) override;
	virtual void resume(Game* game) override;

	void handleEvent(Game* game, IEvent* event) override;
	virtual void update(Game* game) override;
	virtual void draw(Game* game) override;

	static WinState* Instance() {
		return &m_winState;
	}

protected:
	WinState() { }

private:
	static WinState m_winState;
};

#endif // WINSTATE_H