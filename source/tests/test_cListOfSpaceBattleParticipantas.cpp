///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cListOfSpaceBattleParticipantas.hpp"
#include "cUser.hpp"

// gTest grouping class
class test_cListOfSpaceBattleParticipantas : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cListOfSpaceBattleParticipantas : public cListOfSpaceBattleParticipantas
  {
  public:
    // add here members for free access.
    using cListOfSpaceBattleParticipantas::cListOfSpaceBattleParticipantas; // delegate constructors
  };

};
 
TEST_F(test_cListOfSpaceBattleParticipantas, test_ctor )
{
  cUser u("a");
  Test_cListOfSpaceBattleParticipantas t = { u };
}

