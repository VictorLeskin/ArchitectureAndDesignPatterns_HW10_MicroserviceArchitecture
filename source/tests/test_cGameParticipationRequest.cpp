///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cGameParticipationRequest.hpp"

// gTest grouping class
class test_cGameParticipationRequest : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cGameParticipationRequest : public cGameParticipationRequest
  {
  public:
    // add here members for free access.
    using cGameParticipationRequest::cGameParticipationRequest; // delegate constructors
  };

};
 
TEST_F(test_cGameParticipationRequest, test_ctor )
{
  Test_cGameParticipationRequest t;
}

