///************************* OUTS HOMEWORK ****************************************
#ifndef CLISTOFSPACEBATTLEPARTICIPANTAS_HPP
#define CLISTOFSPACEBATTLEPARTICIPANTAS_HPP

#include <initializer_list>
#include <vector>
#include <string>
#include "cUser.hpp"

class cListOfSpaceBattleParticipantas
{
public:
	cListOfSpaceBattleParticipantas(std::initializer_list<cUser> list);

	std::vector<std::string> Players() const
	{
		std::vector<std::string> ret;
		for (const auto& u : users)
			ret.push_back(u.Name());
		return ret;
	}

	std::vector<cUser> users;
};

#endif //#ifndef CLISTOFSPACEBATTLEPARTICIPANTAS_HPP
