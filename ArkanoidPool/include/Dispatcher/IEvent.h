#ifndef IEVENT_H
#define IEVENT_H

// Set of all known events events
enum EventType {
	LeftArrowPressed,
	RightArrowPressed,
	LeftArrowReleased,
	RightArrowReleased,
	SpacePressed,
	pausePressed,
	EscPressed,
	MousePressed,
	update,
	Cheat
};

// Interface for events.
class IEvent
{
	public:
	// Default constructor.
	IEvent(void) {}

	// Default desctructor.
	~IEvent(void) {}

	// Accessors 
	int getEventID(void) const { return m_nEventID; }

	// Modifiers 
	void setEventID(int _nEventID) { m_nEventID = _nEventID; }


private:
	int m_nEventID;	// Type of event.
};

#endif // IEVENT_H