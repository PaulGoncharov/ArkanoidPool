#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>

#include "Brick.h"
#include "Ball.h"
#include "Scate.h"

// Model: content all game elements
class Model
{
public:
	Model();
	~Model();

	// Modifiers
	void loadLevel(const std::string fileName);
	void update();
	void reset();

	// Accessors
	unsigned getLives() const;
	unsigned getScores() const { return m_scores; };
	unsigned getAliveBriksNumber() const { return m_aliveBriks; }

	std::vector<Brick>& getBriks(){ return m_briks; };
	Scate& getScate() { return m_scate; }
	Ball& getBall() { return m_ball; }

private:
	void checkCollision();

	std::vector<Brick> m_briks;		// List of all loaded bricks
	Scate m_scate;
	Ball m_ball;

	int m_aliveBriks;
	unsigned m_scores;

	static const unsigned scoreStep;


};

#endif // MODEL_H