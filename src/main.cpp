#include "Fixes.h"
#include "Papyrus.h"
#include "Settings.h"
#include "Tweaks.h"

void MessageHandler(SFSE::MessagingInterface::Message* a_message)
{
	switch (a_message->type) {
	case SFSE::MessagingInterface::kPostLoad:
		{
			logger::info("{:*^50}", "POST LOAD"sv);

			Settings::GetSingleton()->Load();

			Tweaks::Install();
		}
		break;
	default:
		break;
	}
}

DLLEXPORT constinit auto SFSEPlugin_Version = []() noexcept {
	SFSE::PluginVersionData data{};

	data.PluginVersion(Version::MAJOR);
	data.PluginName(Version::PROJECT);
	data.AuthorName("powerofthree");
	data.UsesAddressLibrary(true);
	//data.UsesSigScanning(true);
	data.IsLayoutDependent(true);
	//data.HasNoStructUse(true);
	data.CompatibleVersions({ SFSE::RUNTIME_LATEST });

	return data;
}();

DLLEXPORT bool SFSEAPI SFSEPlugin_Load(const SFSE::LoadInterface* a_sfse)
{
	SFSE::Init(a_sfse);

	logger::info("Game version : {}", a_sfse->RuntimeVersion().string());
	logger::info("Plugin version : {}", Version::NAME);

	const auto messaging = SFSE::GetMessagingInterface();
	messaging->RegisterListener(MessageHandler);

	return true;
}
