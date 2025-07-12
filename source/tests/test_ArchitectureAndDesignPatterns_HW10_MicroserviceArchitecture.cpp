///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture.hpp"

// gTest grouping class
class test_ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture : public ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture
  {
  public:
    // add here members for free access.
    using ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture::ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture; // delegate constructors
  };

};
 
TEST_F(test_ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture, test_ctor )
{
  Test_ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture t;
}

