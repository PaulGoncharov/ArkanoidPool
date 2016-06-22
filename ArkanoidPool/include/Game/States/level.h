#ifndef LEVEL_H
#define LEVEL_H

#include "gamestate.h"

class Level : public GameState
{
public:
	virtual void init(Game* game) override;
	virtual void cleanup(Game* game) override;

	virtual void pause(Game* game) override;
	virtual void resume(Game* game) override;

	virtual void handleEvent(Game* game, IEvent* event) override;
	virtual void update(Game* game) override;
	virtual void draw(Game* game) override;

	static Level* Instance() {
		return &m_Level;
	}

protected:
	Level() :m_level_number(1) { }

private:
	static Level m_Level;
	unsigned m_level_number;
	static const unsigned levelMax;
};

#endif // LEVEL_H