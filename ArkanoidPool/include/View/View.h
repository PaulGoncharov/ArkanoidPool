#ifndef VIEW_H
#define VIEW_H

#include "TextureManager.h"

struct Rect
{
	Rect(){};
	Rect(float left, float right, float bottom, float top)
	: left(left)
	, right(right)
	, bottom(bottom)
	, top(top)
	{}

	float left;
	float top;
	float right;
	float bottom;
};

// Responsible for rendering textures and text
class View
{
public:
	View();
	~View();

	void init();

	void drawRect(const Rect& screenCoords, const std::string& textureIdent);
	void drawText(unsigned x, unsigned y, const std::string& label);

	void setScreenResolution(unsigned width, unsigned height);
	void getScreenResolution(unsigned& width, unsigned& height) const;

private:
	void renderRect(const Rect& screenCoords, const Texture* texture);

	TextureManager textureManager;
	unsigned screenHeight, screenWidth;
};

#endif // VIEW_H