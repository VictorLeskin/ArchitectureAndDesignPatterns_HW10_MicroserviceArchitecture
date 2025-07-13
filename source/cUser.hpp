///************************* OUTS HOMEWORK ****************************************
#ifndef CUSER_HPP
#define CUSER_HPP

#include <string>

class cUser
{
public:
	cUser(const std::string& name) : name(name) {}

	const std::string& Name() const { return name; }

protected:
	std::string name;
};

#endif //#ifndef CUSER_HPP
