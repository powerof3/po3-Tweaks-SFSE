#include "Fixes.h"
#include "Settings.h"

namespace Fixes
{
	void Install()
	{
		logger::info("[FIXES]");

		const auto& fixes = Settings::GetSingleton()->GetFixes();

		if (fixes.loadEDID) {
			CacheEditorIDs::Install();
		}
	}
}
