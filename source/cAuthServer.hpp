///************************* OUTS HOMEWORK ****************************************
#ifndef CAUTHSERVER_HPP
#define CAUTHSERVER_HPP

 #include <string>
#include <vector>
#include <map>
#include <chrono>
#include <jwt-cpp/jwt.h>
#include <nlohmann/json.hpp>

struct GameInfo {
  std::string game_id;
  std::vector<std::string> participants;
  std::time_t creation_time;
};

struct AuthConfig {
  std::string secret_key;
  int token_expiration_sec;
};

class cAuthServer {
public:
  cAuthServer(const std::string& secret, int token_expiry)
    : secret_key(secret), token_expiry_seconds(token_expiry) {}

  std::string createGame(const std::vector<std::string>& players);
  std::string issueToken(const std::string& user_id, const std::string& game_id);
  bool validateToken(const std::string& token, const std::string& game_id);

private:
  std::string secret_key;
  int token_expiry_seconds;
  std::map<std::string, std::vector<std::string>> games;

  std::string generateSimpleId();
};

#endif //#ifndef CAUTHSERVER_HPP
