#include "Tweaks.h"
#include "Settings.h"

namespace Tweaks
{
	void Install()
	{
		logger::info("[TWEAKS]");

		const auto tweaks = Settings::GetSingleton()->GetTweaks();

		if (tweaks.justPayFine) {
			JustPayFine::Install();
		}

		if (tweaks.grabWithoutStealing) {
			GrabWithoutStealing::Install();
		}

		if (tweaks.dontPickupReadBooks) {
			DontPickupBooks::Install();
		}

		if (tweaks.disableDockingIMOD) {
			DisableDockingIMOD::Install();
		}
	}
}
