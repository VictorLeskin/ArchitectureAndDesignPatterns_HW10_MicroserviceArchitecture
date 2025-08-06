///************************* OUTS HOMEWORK ****************************************

#include "cGameServer.hpp"
#include "cException.hpp"
#include "cRequestSpaceBattleOrganisation.hpp"
#include "cAuthServer.hpp"

cGameId cGameServer::createGame(const cListOfSpaceBattleParticipantas& participantsList)
{
	return auth_server->createGame(participantsList);
}

bool cGameServer::consume(const cMessage&msg)
{
	TGameOperation<std::string> t;

	if( false == cMessage::FromMessage(msg, t) )
		return false;

	if (false == auth_server->checkPlayer(t.gameId.id, t.userId.name))
		return false;

	bool ret = auth_server->validateToken(t.token, t.gameId.id);
	return ret;
}
