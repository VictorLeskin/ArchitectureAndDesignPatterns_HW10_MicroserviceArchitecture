///************************* OUTS HOMEWORK ****************************************
#ifndef CLISTOFSPACEBATTLEPARTICIPANTAS_HPP
#define CLISTOFSPACEBATTLEPARTICIPANTAS_HPP

#include <initializer_list>
#include <vector>
#include "cUser.hpp"

class cListOfSpaceBattleParticipantas
{
public:
	cListOfSpaceBattleParticipantas(std::initializer_list<cUser> list);

	std::vector<cUser> users;
};

#endif //#ifndef CLISTOFSPACEBATTLEPARTICIPANTAS_HPP
