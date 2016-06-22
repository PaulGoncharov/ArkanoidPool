#ifndef BRICK_H
#define BRICK_H

#include "View/View.h"

class Brick
{
public:
	Brick();
	Brick(int x, int y, unsigned width, unsigned height, unsigned hits);
	~Brick();

	// Modifiers
	void boom();	// whnen collision occured

	// Accessors
	bool isAlive() const { return !destroyed; }
	int getHits() const { return hits; }
	const Rect& getCoord() const { return pos; }
	
	//const std::string& getCurrentTexture() const;

private:
	bool destroyed;
	int hits;
	Rect pos;
	
	//static std::map<unsigned, std::string> textureMap;
};

#endif // BRICK_H