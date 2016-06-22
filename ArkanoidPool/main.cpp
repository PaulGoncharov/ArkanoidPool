#include "Game/Game.h"
#include "Game/game_settings.h"
#include "Game/States/introstate.h"
#include "Dispatcher/Dispatcher.h"


#include <GL\gl.h>
#include <GL\glut.h>

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3d(1, 1, 1);
	Dispatcher* dispatcher = Dispatcher::GetInstance();
	dispatcher->sendEvent(update);

	glutSwapBuffers();

}

void Timer(int)
{
	Draw();
	glutTimerFunc(15, Timer, 0);
}

void MousePress(int button, int state, int x, int y)
{

}

void init(unsigned int width, unsigned int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
}

void Resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}


void KeyboardPressed(unsigned char key,
	int x, int y) {
	Dispatcher* dispatcher = Dispatcher::GetInstance();
	switch (key) {
		case 32:
		{
			dispatcher->sendEvent(SpacePressed);
			break;
		}
		case 27:
		{
			dispatcher->sendEvent(EscPressed);
			break;
		}
		case 'p':
		{
			dispatcher->sendEvent(pausePressed);
			break;
		}
		case 'd':
		{
			dispatcher->sendEvent(RightArrowPressed);
			break;
		}
		case 'a':
		{
			dispatcher->sendEvent(LeftArrowPressed);
			break;
		}
		case 'c':
		{
			dispatcher->sendEvent(Cheat);
			break;
		}
		default:
			break;

	}
}

void KeyboardReleased(unsigned char key,
	int x, int y) {
	Dispatcher* dispatcher = Dispatcher::GetInstance();
	switch (key) {
	case 'd':
	{
		dispatcher->sendEvent(RightArrowReleased);
		break;
	}
	case 'a':
	{
		dispatcher->sendEvent(LeftArrowReleased);
		break;
	}
	default:
		break;

	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(game::screenWidth, game::screenHeight);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("AcranoidPool");
	glutDisplayFunc(Draw);
	glutReshapeFunc(Resize);
	glutTimerFunc(15, Timer, 0);
	glutKeyboardFunc(KeyboardPressed);
	glutKeyboardUpFunc(KeyboardReleased);
	glutIgnoreKeyRepeat(1);
	init(game::screenWidth, game::screenHeight);

	Game& game = Game::instance();
	game.init();
	game.getView().setScreenResolution(game::screenWidth, game::screenHeight);

	// load the introstate
	game.changeState(IntroState::Instance());

	// Enter to the main loop
	glutMainLoop();
	return 0;
}

