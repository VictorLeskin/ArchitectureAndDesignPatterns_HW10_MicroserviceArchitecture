///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cSpaceBattle.hpp"

// gTest grouping class
class test_cSpaceBattle : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cSpaceBattle : public cSpaceBattle
  {
  public:
    // add here members for free access.
    using cSpaceBattle::cSpaceBattle; // delegate constructors
  };

};
 
TEST_F(test_cSpaceBattle, test_ctor )
{
  Test_cSpaceBattle t;
}

