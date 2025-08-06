///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cRequestSpaceBattleOrganisation.hpp"

// gTest grouping class
class test_cRequestSpaceBattleOrganisation : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cRequestSpaceBattleOrganisation : public cRequestSpaceBattleOrganisation
  {
  public:
    // add here members for free access.
    using cRequestSpaceBattleOrganisation::cRequestSpaceBattleOrganisation; // delegate constructors
  };

};
 
TEST_F(test_cRequestSpaceBattleOrganisation, test_ctor )
{
  Test_cRequestSpaceBattleOrganisation t(cUser(""),cGameId(""));
}

