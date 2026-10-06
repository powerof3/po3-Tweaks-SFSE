#include "Cache.h"
#include "Fixes.h"
#include "PCH.h"
#include "Papyrus.h"
#include "Settings.h"
#include "Tweaks.h"

void MessageHandler(SFSE::MessagingInterface::Message* a_message)
{
	switch (a_message->type) {
	case SFSE::MessagingInterface::kPostLoad:
		{
			REX::INFO("{:*^50}", "POST LOAD"sv);
			Settings::GetSingleton()->Load();

			Fixes::Install();
			Tweaks::Install();
		}
		break;
	default:
		break;
	}
}

SFSE_EXPORT constinit auto SFSEPlugin_Version = []() noexcept {
	SFSE::PluginVersionData data{};

	data.PluginVersion(Version::MAJOR);
	data.PluginName(Version::PROJECT);
	data.AuthorName("powerofthree");
	data.UsesSigScanning(false);
	data.UsesAddressLibrary(true);
	data.HasNoStructUse(false);
	data.IsLayoutDependent(true);
	data.CompatibleVersions({ SFSE::RUNTIME_LATEST });

	return data;
}();

SFSE_PLUGIN_LOAD(const SFSE::LoadInterface* a_sfse)
{
	SFSE::Init(a_sfse, { .trampoline = true, .trampolineSize = 56 });
	SFSE::GetMessagingInterface()->RegisterListener(MessageHandler);
	return true;
}
