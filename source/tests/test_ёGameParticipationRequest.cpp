///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "�GameParticipationRequest.hpp"

// gTest grouping class
class test_�GameParticipationRequest : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_�GameParticipationRequest : public �GameParticipationRequest
  {
  public:
    // add here members for free access.
    using �GameParticipationRequest::�GameParticipationRequest; // delegate constructors
  };

};
 
TEST_F(test_�GameParticipationRequest, test_ctor )
{
  Test_�GameParticipationRequest t;
}

