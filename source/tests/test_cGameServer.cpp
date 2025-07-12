///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cGameServer.hpp"

// gTest grouping class
class test_cGameServer : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cGameServer : public cGameServer
  {
  public:
    // add here members for free access.
    using cGameServer::cGameServer; // delegate constructors
  };

};
 
TEST_F(test_cGameServer, test_ctor )
{
  Test_cGameServer t;
}

