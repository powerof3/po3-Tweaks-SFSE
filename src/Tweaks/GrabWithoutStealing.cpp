#include "Tweaks.h"

namespace Tweaks::GrabWithoutStealing
{
	// shortcircuit SendStealAlarm
    struct GetOwnedNoCrime
	{
		static bool thunk([[maybe_unused]] std::uintptr_t a_extraDataList)
		{
			return true;
		}
		static inline REL::Relocation<decltype(thunk)> func;
	};

	void Install()
	{
        const REL::Relocation<std::uintptr_t> target{ REL::Offset(0x258D6FC), 0x304 };	// PlayerCharacter::StartGrabObject
		stl::write_thunk_call<GetOwnedNoCrime>(target.address());

		logger::info("\tInstalled GrabWithoutStealing");
	}
}
