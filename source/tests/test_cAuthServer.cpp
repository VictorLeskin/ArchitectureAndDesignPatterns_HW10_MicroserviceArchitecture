///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cAuthServer.hpp"

// gTest grouping class
class test_cAuthServer : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cAuthServer : public cAuthServer
  {
  public:
    // add here members for free access.
    using cAuthServer::cAuthServer; // delegate constructors
  };

};
 
TEST_F(test_cAuthServer, test_ctor )
{
  Test_cAuthServer t;
}

