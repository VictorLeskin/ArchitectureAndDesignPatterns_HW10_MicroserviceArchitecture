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

        cAuthServer authServer("simple_secret_key", 3600);
        cGameServer gameServer(&authServer);

        cUser organizer("Organizer");
        cUser participant1("Participant #1");
        cUser participant2("Participant #2");

        cListOfSpaceBattleParticipantas participantsList = { organizer, participant1, participant2 };

        cGameId gameId = gameServer.createGame(participantsList);

        cRequestAccessToGame reqAccessToGameOrganizer(organizer, gameId);
        cRequestAccessToGame reqAccessToGameParticipant1(participant1, gameId);
        cRequestAccessToGame reqAccessToGameParticipant2(participant2, gameId);

        std::string tokenOrganizer = authServer.issueToken(reqAccessToGameOrganizer);
        std::string tokenParticipant1 = authServer.issueToken(reqAccessToGameParticipant1);
        std::string tokenParticipant2 = authServer.issueToken(reqAccessToGameParticipant2);
        
        std::string s0("let's make pause");
        TGameOperation<std::string> goOrganizerMakePause;
        goOrganizerMakePause.userId = organizer;
        goOrganizerMakePause.token = tokenOrganizer;
        goOrganizerMakePause.gameId = gameId;
        goOrganizerMakePause.objId = cOjectId("");
        goOrganizerMakePause.operationId = cOperationId("test");
        goOrganizerMakePause.operationParameters = s0;

        std::string s1("I am agree");
        TGameOperation<std::string> goOrganizerParticipant1;
        goOrganizerParticipant1.userId = participant1;
        goOrganizerParticipant1.token = tokenParticipant1;
        goOrganizerParticipant1.gameId = gameId;
        goOrganizerParticipant1.objId = cOjectId("");
        goOrganizerParticipant1.operationId = cOperationId("test");
        goOrganizerParticipant1.operationParameters = s1;

        cMessage msg0 = cMessage::ToMessage< TGameOperation<std::string> >(goOrganizerMakePause);
        cMessage msg1 = cMessage::ToMessage< TGameOperation<std::string> >(goOrganizerParticipant1);

        EXPECT_TRUE( gameServer.consume(msg0) );
        EXPECT_TRUE( gameServer.consume(msg1) );

        //wrong user 
        cUser hacker("Hacker");

        std::string h0("I am agree");
        TGameOperation<std::string> goHakerJustToWatch;
        goHakerJustToWatch.userId = hacker;
        goHakerJustToWatch.token = tokenOrganizer;
        goHakerJustToWatch.gameId = gameId;
        goHakerJustToWatch.objId = cOjectId("");
        goHakerJustToWatch.operationId = cOperationId("test");
        goHakerJustToWatch.operationParameters = h0;
        cMessage msgH = cMessage::ToMessage< TGameOperation<std::string> >(goHakerJustToWatch);

        EXPECT_FALSE(gameServer.consume(msgH));
        
        // wrong token

        std::string wrongTokenOrganizer = tokenOrganizer;
        wrongTokenOrganizer[0] = 'X';

        TGameOperation<std::string> goOrganizerWithWrongToken;
        goOrganizerWithWrongToken.userId = organizer;
        goOrganizerWithWrongToken.token = wrongTokenOrganizer;
        goOrganizerWithWrongToken.gameId = gameId;
        goOrganizerWithWrongToken.objId = cOjectId("");
        goOrganizerWithWrongToken.operationId = cOperationId("test");
        goOrganizerWithWrongToken.operationParameters = s0;

        cMessage msgW = cMessage::ToMessage<TGameOperation<std::string>>(goOrganizerWithWrongToken);
        EXPECT_FALSE(gameServer.consume(msgW));

    }
    catch (std::exception& e)
    {
        FAIL() << "Exception catched";
    }
}
