#include "Dispatcher/Dispatcher.h"

Dispatcher::Dispatcher(void)
{
}

void Dispatcher::dispatchEvent(IEvent* event)
{
	//	Make an iterator that will iterate through all of our clients
	//	that should receive this event.
	std::pair<std::multimap<int, IObserver*>::iterator,
		std::multimap<int, IObserver*>::iterator> range;

	//	Find all clients that should get this event.
	range = m_Clients.equal_range(event->getEventID());

	//	Go through all the clients that were registered to receive this event.
	for (std::multimap<int, IObserver *>::iterator iter = range.first; iter != range.second; ++iter)
	{
		//	Send the event to this client.
		(*iter).second->handleEvent(event);
	}
}

Dispatcher::~Dispatcher(void)
{

}

Dispatcher* Dispatcher::GetInstance(void)
{
	static Dispatcher instance;
	return &instance;
}

void Dispatcher::shutdown(void)
{
	if (!m_Clients.empty())
		m_Clients.clear();
	if (!m_EventList.empty())
		m_EventList.clear();
}

void Dispatcher::registerClient(int _nEventID, IObserver* _pClient)
{
	m_Clients.insert(std::make_pair(_nEventID, _pClient));
}

void Dispatcher::unregisterClient(IObserver * _pClient)
{
	//	Make an iterator that will iterate through all of our clients
	//	that should receive this event.
	std::multimap<int, IObserver*>::iterator iter = m_Clients.begin();

	while (iter != m_Clients.end())
	{
		if ((*iter).second == _pClient)
			iter = m_Clients.erase(iter);
		else iter++;
	}
}

void Dispatcher::sendEvent(int event)
{
	IEvent newEvent;
	newEvent.setEventID(event);
	m_EventList.push_back(newEvent);
	processEvents();
}

void Dispatcher::processEvents()
{
	while (m_EventList.size())
	{
		dispatchEvent(&m_EventList.front());
		m_EventList.pop_front();
	}
}