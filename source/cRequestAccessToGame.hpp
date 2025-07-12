///************************* OUTS HOMEWORK ****************************************
#ifndef CREQUESTACCESSTOGAME_HPP
#define CREQUESTACCESSTOGAME_HPP

#include "cUser.hpp"
#include "cGameId.hpp"

class cRequestAccessToGame
{
public:
	cRequestAccessToGame(cUser& user, cGameId& gameId) : user(user), gameId(gameId)
	{
	}

public:
	cUser user;
	cGameId gameId;
};

#endif //#ifndef CREQUESTACCESSTOGAME_HPP
