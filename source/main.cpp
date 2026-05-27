#include "GarrysMod/Lua/Interface.h"
#include "Discord.h"
#include <string>
#include <thread>

using namespace GarrysMod::Lua;
using namespace std;

// MessagePush
void PUSH_MSG(string name, string msg, string url) {
	DiscordWebhook webhook(url);

	webhook.setUsername(name);
	webhook.setContent(msg);

	webhook.execute();
}

LUA_FUNCTION(MessagePush)
{
	string n = LUA->CheckString(1);
	string m = LUA->CheckString(2);
	string u = LUA->CheckString(3);

	thread thr(PUSH_MSG, n, m, u);
	thr.detach();

	return 0;
}

GMOD_MODULE_OPEN()
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);

	LUA->PushCFunction(MessagePush);
	LUA->SetField(-2, "MessagePush");

	LUA->Pop();

	return 0;
}

GMOD_MODULE_CLOSE()
{
	return 0;
}
