///************************* OUTS HOMEWORK ****************************************
#ifndef CREQUESTSPACEBATTLEORGANISATION_HPP
#define CREQUESTSPACEBATTLEORGANISATION_HPP

#include "cMessage.hpp"
#include "cUser.hpp"

class cRequestSpaceBattleOrganisation : public cMsgHeader
{
public:
	cRequestSpaceBattleOrganisation(const cUser& user, const cGameId& gameId);
	const cUser& User() const { return user; }
protected:
	cUser user;
	cGameId gameId;
};

#endif //#ifndef CREQUESTSPACEBATTLEORGANISATION_HPP
