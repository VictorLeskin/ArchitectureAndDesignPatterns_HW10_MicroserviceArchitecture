///************************* OUTS HOMEWORK ****************************************
#ifndef CGAMESERVER_HPP
#define CGAMESERVER_HPP

#include "cMessagesDeque.hpp"
#include "cGameId.hpp"
#include "cListOfSpaceBattleParticipantas.hpp"

class cAuthServer;

class cGameServer
{
protected:
	cGameServer() : auth_server(nullptr) {}
public:
	cGameServer(cAuthServer* auth_server) : auth_server(auth_server) {}

	cGameId createGame(const cListOfSpaceBattleParticipantas& participantsList);

	void push_back(const cMessage& item)
	{
		deque.push_back(item);
	}

	bool pop_front(cMessage& item)
	{
		return deque.pop_front(item);
	}

	bool consume(const cMessage&);

protected:
	cAuthServer* auth_server;
	cMessagesDeque deque;
};

#endif //#ifndef CGAMESERVER_HPP
