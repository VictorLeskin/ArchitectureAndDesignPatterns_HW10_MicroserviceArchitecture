///************************* OUTS HOMEWORK ****************************************
#ifndef CGAMEID_HPP
#define CGAMEID_HPP

#include <string>

class cGameId 
{ 
public:
  cGameId() = default;
  cGameId(std::string id) : id(id) {}

public: 
  std::string id; 
};

#endif //#ifndef CGAMEID_HPP
