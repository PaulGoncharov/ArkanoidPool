#ifndef DISPATCHER_H_
#define DISPATCHER_H_

#include "Game/IObserver.h"

#include <list>
#include <map>
#include <vector>

// MessageSystem : Handles all the messages.
class Dispatcher
{

public:
	~Dispatcher();	//Default destructor

	// Sigleton realization
	static Dispatcher* GetInstance(void);

	//Clean up 
	void shutdown();

	// Register a client to listen for events from the dispatcher.
	void registerClient(int eventID, IObserver* client);

	// Unregister a client from the dispatcher.
	void unregisterClient(IObserver* client);

	// Sends an event to the dispatcher to be processed.
	void sendEvent(int _nEvent);

	// Process all sent events.
	void processEvents();

private:
	void dispatchEvent(IEvent* _pEvent);					// dispatchEvent

	std::multimap<int, IObserver*> m_Clients;				// List of all the clients registered to receive events.
	std::list<IEvent> m_EventList;							// List of all the events .

	Dispatcher();											// Default constructor.

	
};

#endif //DISPATCHER_H_ 