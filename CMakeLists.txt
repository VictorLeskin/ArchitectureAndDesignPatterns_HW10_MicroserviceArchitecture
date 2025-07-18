cmake_minimum_required(VERSION 3.14)
project(ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
  MicroserviceArchitecture

  source/ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture.hpp
  source/ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture.cpp
  source/cUser.hpp
  source/cUser.cpp
  source/cSpaceBattle.hpp
  source/cSpaceBattle.cpp
  source/cListOfSpaceBattleParticipantas.hpp
  source/cListOfSpaceBattleParticipantas.cpp
  source/cAuthServer.hpp
  source/cAuthServer.cpp
  source/cGameServer.hpp
  source/cGameServer.cpp
  source/cGameParticipationRequest.hpp
  source/cGameParticipationRequest.cpp
  source/cGameId.hpp
  source/cGameId.cpp
  source/cMessage.hpp
  source/cMessage.cpp
  source/cRequestSpaceBattleOrganisation.hpp
  source/cRequestSpaceBattleOrganisation.cpp
  source/cRequestAccessToGame.hpp
  source/cRequestAccessToGame.cpp
  source/cException.hpp
  source/cException.cpp
  source/cMessagesDeque.hpp
  source/cMessagesDeque.cpp
#add source file here
  source/tests/test_ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture.cpp
  source/tests/test_cUser.cpp
  source/tests/test_cSpaceBattle.cpp
  source/tests/test_cListOfSpaceBattleParticipantas.cpp
  source/tests/test_cAuthServer.cpp
  source/tests/test_cGameServer.cpp
  source/tests/test_cGameParticipationRequest.cpp
  source/tests/test_cGameId.cpp
  source/tests/test_cMessage.cpp
  source/tests/test_cRequestSpaceBattleOrganisation.cpp
  source/tests/test_cRequestAccessToGame.cpp
  source/tests/test_cException.cpp
  source/tests/test_cMessagesDeque.cpp
#add test file here
)

target_include_directories(
   MicroserviceArchitecture PRIVATE 
   source
)

target_link_libraries(
  MicroserviceArchitecture
  GTest::gtest_main
  GTest::gmock_main
)

include(GoogleTest GoogleMock)
gtest_discover_tests(MicroserviceArchitecture)