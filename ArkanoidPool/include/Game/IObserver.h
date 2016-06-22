#ifndef IOBSERVER_H
#define IOBSERVER_H

#include "Dispatcher/IEvent.h"

// Observer : Interface to handle events.
class IObserver
{
public:
	// Default constructor.
	IObserver(void) {}

	// Default desctructor.
	virtual ~IObserver(void) {}

	// handleEvent : Handle event for derived classes.
	virtual void handleEvent(IEvent* event) = 0;
};

#endif // OBSERVER_H