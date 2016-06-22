#ifndef BALL_H
#define BALL_H

#include "View/View.h"

// Forward declaration
class Model;

// 
class Ball
{
public:
	Ball(Model* model);
	~Ball();

	// Modifiers
	void launch();
	void update();
	void reset();
	
	// Accessors
	bool isLaunched(){ return m_launched; }
	bool isCollision(const Rect& elemPos);

	unsigned getLives() const { return m_lives; }
	const Rect& getPos() const { return pos; }

private:
	void initPos();
	void checkScateReflection();
	
	Model *m_model;		// Parent
	unsigned m_lives;
	bool m_launched;
	Rect pos;
	int dx;				// Motion vector
	int dy;
	
	static const float diameter;
	static const int defaultXAcceleration;
	static const int defaultYAcceleration;
	
};

#endif // BALL_H