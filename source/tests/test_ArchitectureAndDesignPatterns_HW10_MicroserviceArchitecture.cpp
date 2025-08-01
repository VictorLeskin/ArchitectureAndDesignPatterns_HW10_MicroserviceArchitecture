///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture.hpp"
#include "cAuthServer.hpp"
#include "cGameId.hpp"
#include "cGameParticipationRequest.hpp"
#include "cGameServer.hpp"
#include "cListOfSpaceBattleParticipantas.hpp"
#include "cMessage.hpp"
#include "cSpaceBattle.hpp"
#include "cUser.hpp"
#include "cRequestSpaceBattleOrganisation.hpp"
#include "cRequestAccessToGame.hpp"
#include "cException.hpp"


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

    
    void getConfirmedAccessToGame(cUser&)
    {
        throw cException("not implemented");
    }
  };

};
 
TEST_F(test_ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture, test_ctor )
{
  //Test_ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture t;
}

TEST_F(test_ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture, test_HWScenario)
{   
    try
    {
        Test_ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture t;

        cGameServer gameServer;
        cAuthServer authServer;

        cUser organizer("Organizer");
        cUser participant1("Participant #1");
        cUser participant2("Participant #2");

        cListOfSpaceBattleParticipantas participantsList = { organizer, participant1, participant2 };

        cRequestSpaceBattleOrganisation req(organizer);

        cMessage msg = cMessage::ToMessage<cRequestSpaceBattleOrganisation>(req);

        gameServer.push_back(msg);

        cGameId gameId = gameServer.getGameId();

        cRequestAccessToGame reqAccessToGameOrganizer(organizer, gameId);
        cRequestAccessToGame reqAccessToGameParticipant1(participant1, gameId);
        cRequestAccessToGame reqAccessToGameParticipant2(participant2, gameId);

        cMessage msg0 = cMessage::ToMessage<cRequestAccessToGame>(reqAccessToGameOrganizer);
        cMessage msg1 = cMessage::ToMessage<cRequestAccessToGame>(reqAccessToGameParticipant1);
        cMessage msg2 = cMessage::ToMessage<cRequestAccessToGame>(reqAccessToGameParticipant2);

        gameServer.push_back(msg0);
        gameServer.push_back(msg1);
        gameServer.push_back(msg2);


        t.getConfirmedAccessToGame(organizer);
        t.getConfirmedAccessToGame(participant1);
        t.getConfirmedAccessToGame(participant2);
    }
    catch (std::exception& e)
    {
        FAIL() << "Exception catched";
    }
}

#include "jwt-cpp/jwt.h"

#pragma comment(lib, "crypt32")
#pragma comment(lib, "ws2_32.lib")

TEST_F(test_ArchitectureAndDesignPatterns_HW10_MicroserviceArchitecture, test_CreateJWT)
{
  // Чтение ключей
  std::string rsa_pub_key = "-----BEGIN PUBLIC KEY-----...";
  std::string rsa_priv_key = "-----BEGIN PRIVATE KEY-----...";

  // Создание токена
  auto token = jwt::create()
  .set_issuer("auth0")
  .sign(jwt::algorithm::rs256(rsa_pub_key, rsa_priv_key));

  try {
    auto decoded = jwt::decode(token);
    auto verifier = jwt::verify()
      .allow_algorithm(jwt::algorithm::rs256(rsa_pub_key))
      .with_issuer("auth0");

    verifier.verify(decoded);
    std::cout << "Token is valid" << std::endl;

    // Получение данных из payload
    if (decoded.has_payload_claim("user")) {
      std::cout << "User: "
        << decoded.get_payload_claim("user").as_string()
        << std::endl;
    }
  }
  catch (const std::exception& e) {
    std::cerr << "Verification failed: " << e.what() << std::endl;
  }
  catch (...) {
    std::cerr << "Unknown error" << std::endl;
  }


}