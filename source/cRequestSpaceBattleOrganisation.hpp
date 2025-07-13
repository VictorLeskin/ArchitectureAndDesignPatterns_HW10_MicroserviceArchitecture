///************************* OUTS HOMEWORK ****************************************
#ifndef CREQUESTSPACEBATTLEORGANISATION_HPP
#define CREQUESTSPACEBATTLEORGANISATION_HPP

#include "cMessage.hpp"
#include "cUser.hpp"

class cRequestSpaceBattleOrganisation : public cMsgHeader
{
public:
	cRequestSpaceBattleOrganisation(cUser user) : cMsgHeader( "", "", "registerNewGame" ), user(user)
	{
	}
	const cUser& User() const { return user; }
protected:
	cUser user;
};

#endif //#ifndef CREQUESTSPACEBATTLEORGANISATION_HPP
