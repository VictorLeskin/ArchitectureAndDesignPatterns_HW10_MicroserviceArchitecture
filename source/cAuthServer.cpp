///************************* OUTS HOMEWORK ****************************************

#include "cAuthServer.hpp"

#include <random>
#include <algorithm>

std::string cAuthServer::createGame(const std::vector<std::string>& players) {
  std::string id = generateSimpleId();
  games[id] = players;
  return id;
}

std::string cAuthServer::issueToken(const std::string& user_id, const std::string& game_id) {
  if (games.find(game_id) == games.end()) {
    throw std::runtime_error("Game not found");
  }

  auto& players = games[game_id];
  if (std::find(players.begin(), players.end(), user_id) == players.end()) {
    throw std::runtime_error("User not in game");
  }

  return jwt::create()
    .set_payload_claim("user_id", jwt::claim(user_id))
    .set_payload_claim("game_id", jwt::claim(game_id))
    .sign(jwt::algorithm::hs256{ secret_key });
}

bool cAuthServer::validateToken(const std::string& token, const std::string& game_id) {
  try {
    auto decoded = jwt::decode(token);
    jwt::verify()
      .allow_algorithm(jwt::algorithm::hs256{ secret_key })
      .verify(decoded);

    return decoded.get_payload_claim("game_id").as_string() == game_id;
  }
  catch (...) {
    return false;
  }
}

std::string cAuthServer::generateSimpleId() {
  static int counter = 0;
  return "game_" + std::to_string(++counter);
}