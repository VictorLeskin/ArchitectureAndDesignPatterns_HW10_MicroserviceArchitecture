///************************* OUTS HOMEWORK ****************************************

#include "cGameServer.hpp"
#include "cException.hpp"
#include "cRequestSpaceBattleOrganisation.hpp"

cGameId cGameServer::getGameId()
{
	cMessage item;
	if (false == pop_front(item))
		throw(cException("There is not request for gameId "));

	cRequestSpaceBattleOrganisation r(cUser(""));

	cMessage::FromMessage(item, r);

	throw(cException("not implemented"));

	return cGameId("gameId #1");
}
