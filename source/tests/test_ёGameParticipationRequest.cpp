///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "퇖ameParticipationRequest.hpp"

// gTest grouping class
class test_퇖ameParticipationRequest : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_퇖ameParticipationRequest : public 퇖ameParticipationRequest
  {
  public:
    // add here members for free access.
    using 퇖ameParticipationRequest::퇖ameParticipationRequest; // delegate constructors
  };

};
 
TEST_F(test_퇖ameParticipationRequest, test_ctor )
{
  Test_퇖ameParticipationRequest t;
}

