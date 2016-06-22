#ifndef SCATE_H
#define SCATE_H

#include "View/View.h"

class Scate
{
public:
	Scate();
	~Scate();

	// Modifiers
	void moveRight();
	void moveLeft();
	void update();
	void stopMove();
	void reset();

	// Accessors
	const Rect& getPos() const { return pos; }

private:
	void init();

	Rect pos;
	int m_acceleration;
	

	static const int defaultAcceleration;
	
};

#endif // SCATE_H