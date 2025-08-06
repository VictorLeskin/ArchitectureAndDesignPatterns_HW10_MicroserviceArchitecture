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
  // 1. Инициализация сервиса
  Test_cAuthServer auth("simple_secret_key", 3600);

  // 2. Создаем игру
  std::vector<std::string> players = { "player1", "player2" };
  std::string game_id = auth.createGame(players);
  EXPECT_EQ( game_id, "game_1" );

  // 3. Получаем токен для player1
  try {
    std::string token = auth.issueToken("player1", game_id);

    // 4. Проверяем токен
    EXPECT_TRUE(auth.validateToken(token, game_id)) << "Token is valid!" << std::endl;
  }
  catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  std::string token = auth.issueToken("player1", game_id);
  std::cout << "Token for player1: " << token << std::endl;

  // 4. Проверяем токен
  EXPECT_FALSE(auth.validateToken(token, "game_id99999"));
}

