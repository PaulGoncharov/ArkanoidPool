#ifndef GAME_H
#define GAME_H
#include "IObserver.h" 

#include <vector>
#include <string>

#include "Model/Model.h"
#include "View/View.h"

class GameState;

// Contains model/view and translate all events to the current cotroller
class Game : public IObserver
{
public:
	void init();
	void cleanup();

	void changeState(GameState* state);

	void update();
	void draw();

	bool isRunning() const { return m_running; }
	void quit() { m_running = false; }

	void setRun(bool isRunning);

	void pause();
	void resume() ;

	void loadLevel(const std::string& asset);

	View& getView() { return view; }
	Model& getModel() { return model; }

	// Meyers sigleton realization
	static Game& instance(){
		static Game instance;
		return instance;
	}

	// IObserver implementation
	virtual void handleEvent(IEvent* event);

private:
	Game();

	Model model;	// Contains all game elements
	View view;		// Responsible for rendering

	std::vector<GameState*> states;	// the stack of states
	bool m_running;					// is game running
};

#endif // GAME_H
