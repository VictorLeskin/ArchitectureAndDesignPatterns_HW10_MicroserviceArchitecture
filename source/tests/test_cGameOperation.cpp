///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cGameOperation.hpp"

// gTest grouping class
class test_cGameOperation : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cGameOperation : public cGameOperation
  {
  public:
    // add here members for free access.
    using cGameOperation::cGameOperation; // delegate constructors
  };

};
 
TEST_F(test_cGameOperation, test_ctor )
{
  Test_cGameOperation t;
}

