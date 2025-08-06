///************************* OUTS HOMEWORK ****************************************

#include "cMessage.hpp"
#include "cException.hpp"
#include "cUser.hpp"
#include "cRequestSpaceBattleOrganisation.hpp"

template<> void to_json<cMsgHeader>(nlohmann::json& j, const cMsgHeader& h)
{
	j["userId"] = h.userId.name;
	j["token"] = h.token;
	j["gameId"] = h.gameId.id;
	j["objId"] = h.objId.id;
	j["operationId"] = h.operationId.id;
}

template<> void from_json<cMsgHeader>(const nlohmann::json& j, cMsgHeader& h)
{
	j.at("userId").get_to(h.userId.name);
	j.at("token").get_to(h.token);
	j.at("gameId").get_to(h.gameId.id);
	j.at("objId").get_to(h.objId.id);
	j.at("operationId").get_to(h.operationId.id);
}

template<> void to_json<cUser>(nlohmann::json& j, const cUser& h)
{
	j["name"] = h.Name();
}

template<> inline void from_json<cUser>(const nlohmann::json& j, cUser& h)
{
	std::string s;
	j.at("name").get_to(s);
	h = cUser(s);
}

template<> cMessage cMessage::ToMessage<cRequestSpaceBattleOrganisation>(const cRequestSpaceBattleOrganisation& operation)
{
	cMessage msg;

	const cMsgHeader &header = operation;

	nlohmann::json jHeader;
	to_json(jHeader, header);
	msg.sHeader = jHeader.dump();

	nlohmann::json jParameters;
	to_json(jParameters, operation.User() );
	msg.sParameters = jParameters.dump();

	return msg;
}

template<> bool cMessage::FromMessage<cRequestSpaceBattleOrganisation>(const cMessage& msg, cRequestSpaceBattleOrganisation& operation)
{
	nlohmann::json j = nlohmann::json::parse(msg.sParameters);
	cUser u("");
	cGameId g("");
	from_json(j, u);
	operation = cRequestSpaceBattleOrganisation(u,g);
	return true;
}


template<> cMessage cMessage::ToMessage<cRequestAccessToGame>(const cRequestAccessToGame& operation)
{
	cMessage m;
	throw cException("not implemented");
	return m;
}

void to_json(nlohmann::json& j, const std::string& name)
{
	j = nlohmann::json
	{
			{ "str", name }
	};
}

void from_json(const nlohmann::json& j, std::string& name)
{
	j.at("str").get_to(name);
}
