///************************* OUTS HOMEWORK ****************************************
#ifndef CGAMESERVER_HPP
#define CGAMESERVER_HPP
class cMessage;

class cGameServer
{
public:
	void push_back(const cMessage& msg);
};

#endif //#ifndef CGAMESERVER_HPP
