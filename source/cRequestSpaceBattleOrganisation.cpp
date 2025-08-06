///************************* OUTS HOMEWORK ****************************************

#include "cRequestSpaceBattleOrganisation.hpp"

cRequestSpaceBattleOrganisation::cRequestSpaceBattleOrganisation(
	const cUser& user, const cGameId& gameId) :
	cMsgHeader(user, "", gameId, cOjectId(""), cOperationId("registerNewGame")),
	user(user), gameId(gameId)
{
}