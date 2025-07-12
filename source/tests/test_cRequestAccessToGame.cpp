///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cRequestAccessToGame.hpp"
#include "cUser.hpp"
#include "cGameId.hpp"

// gTest grouping class
class test_cRequestAccessToGame : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cRequestAccessToGame : public cRequestAccessToGame
  {
  public:
    // add here members for free access.
    using cRequestAccessToGame::cRequestAccessToGame; // delegate constructors
  };

};
 
TEST_F(test_cRequestAccessToGame, test_ctor )
{
  cUser user("U");
  cGameId gameId("GI");
  Test_cRequestAccessToGame t( user, gameId );
}

