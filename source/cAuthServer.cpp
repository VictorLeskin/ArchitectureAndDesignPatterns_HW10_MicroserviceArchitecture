///************************* OUTS HOMEWORK ****************************************

#include "cAuthServer.hpp"

#include <random>
#include <algorithm>

std::string cAuthServer::createGame(const cListOfSpaceBattleParticipantas& participantsList)
{
  std::vector<std::string> players;
  return createGame(participantsList.Players());
}

std::string cAuthServer::createGame(const std::vector<std::string>& players) {
  std::string id = generateSimpleId();
  games[id] = players;
  return id;
}

bool cAuthServer::checkPlayer(const std::string& gameId, const std::string& playerName)
{
  if (games.find(gameId) == games.end())
    return false;
  const std::vector<std::string>& players = games[gameId];
  return std::find(  players.begin(), players.end(), playerName) != players.end();
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

std::string cAuthServer::issueToken(const cRequestAccessToGame& req)
{
  return issueToken(req.user.Name(), req.gameId.id);
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
  return "game_" + std::to_string(++counter);
}