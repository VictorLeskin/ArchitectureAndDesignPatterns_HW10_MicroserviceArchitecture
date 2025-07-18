///************************* OUTS HOMEWORK ****************************************
#ifndef CMESSAGE_HPP
#define CMESSAGE_HPP

#include <string>
#include "nlohmann/json.hpp"

#include "cGameId.hpp"

class cOjectId { public: std::string id; };
class cOperationId { public: std::string id; };

class cMsgHeader
{
public:
	cMsgHeader(cGameId gameId, cOjectId objId, cOperationId operationId) 
	  : gameId(gameId), objId(objId), operationId(operationId) {}
	cMsgHeader(const char* gameId, const char* objId, const char* operationId)
		: gameId(gameId), objId(objId), operationId(operationId) {
	}

public:
	virtual ~cMsgHeader() = default;

	cGameId gameId;
	cOjectId objId;
	cOperationId operationId;

};

class cGameOperation
{
public:
	cGameOperation() {}

public:
	virtual ~cGameOperation() = default;

	cGameId gameId;
	cOjectId objId;
	cOperationId operationId;
};


template<typename OPERATION_PARAMETERS>
class TGameOperation : public cGameOperation
{
public:
	TGameOperation()
	{
	}
	OPERATION_PARAMETERS operationParameters;
};

template<typename T> void to_json(nlohmann::json& j, const T& operation);
template<typename T> void from_json(const nlohmann::json& j, T &operation);


class cRequestSpaceBattleOrganisation;

class cMessage
{
public:
	cMessage() {}
	cMessage(std::string sHeader, std::string sParameters) 
		: sHeader(sHeader), sParameters(sParameters) {}

	template<typename T>
	static cMessage ToMessage(const T& operation)
	{
		cMessage msg;

		cMsgHeader header(operation.gameId, operation.objId, operation.operationId);

		nlohmann::json jHeader;
		to_json(jHeader, header);
		msg.sHeader = jHeader.dump();

		nlohmann::json jParameters;
		to_json(jParameters, operation.operationParameters);
		msg.sParameters = jParameters.dump();

		return msg;
	}

	template<typename T>
	static bool FromMessage(const cMessage& message, T &t );


	const std::string& Header() const { return sHeader; }
	const std::string& Parameters() const { return sParameters; }

protected:
	std::string sHeader, sParameters;
};

class cRequestSpaceBattleOrganisation;
class cRequestAccessToGame;

template<> cMessage cMessage::ToMessage<cRequestSpaceBattleOrganisation>(const cRequestSpaceBattleOrganisation& operation);
template<> cMessage cMessage::ToMessage<cRequestAccessToGame>(const cRequestAccessToGame& operation);
#endif //#ifndef CMESSAGE_HPP
