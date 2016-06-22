#include "View/View.h"
#include "Game/game_settings.h"
#include <GL/glut.h>

View::View()
{
	screenWidth = game::screenWidth;
	screenWidth = game::screenHeight;
}


View::~View()
{
}

void View::init() {
	textureManager.loadTextures();
}

void View::drawRect(const Rect& screenCoords, const std::string& textureIdent) {
	const TexturesMap *texturesPool = textureManager.getTexturesPool();

	// Do we have necessary texture 
	TexturesMap::const_iterator mIt = texturesPool->find(textureIdent);

	if (mIt != texturesPool->end()) {
		renderRect(screenCoords, (*mIt).second.get());
	}
}
void View::renderRect(const Rect& screenCoords, const Texture* texture) {
	glBindTexture(GL_TEXTURE_2D, texture->id);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(screenCoords.left, screenCoords.top);

	glTexCoord2f(0, 1);
	glVertex2f(screenCoords.left, screenCoords.bottom);

	glTexCoord2f(1, 1);
	glVertex2f(screenCoords.right, screenCoords.bottom);

	glTexCoord2f(1, 0);
	glVertex2f(screenCoords.right, screenCoords.top);
	glEnd();
}

void View::drawText(unsigned int x, unsigned y, const std::string& label) {
	glColor3d(0, 0, 0);
	const char *c = label.c_str();
	int length = label.size();
	glRasterPos2i(x, y); 
	for (int i = 0; i<length; i++){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)c[i]); 
	}
}

void View::setScreenResolution(unsigned width, unsigned height) {
	screenWidth = width;
	screenHeight = height;
}

void View::getScreenResolution(unsigned& width, unsigned& height) const {
	width = screenWidth;
	height = screenHeight;
}