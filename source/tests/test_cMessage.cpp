///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cMessage.hpp"

// gTest grouping class
class test_cMessage : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cMessage : public cMessage
  {
  public:
    // add here members for free access.
    Test_cMessage(const cMessage& m) : cMessage(m) {}
    using cMessage::cMessage; // delegate constructors
  };
};

