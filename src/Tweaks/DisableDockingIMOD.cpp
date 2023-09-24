#include "Tweaks.h"

namespace Tweaks::DisableDockingIMOD
{
	struct IMOD
	{
		static std::uintptr_t thunk(RE::TESForm* a_imod,
			float                                a_strength,
			std::uintptr_t                       a_arg3,
			std::uintptr_t                       a_arg4,
			float                                a_arg5,
			float                                a_arg6,
			std::int32_t                         a_arg7)
		{
			if (a_imod && (a_imod->GetFormID() == 0x514C || a_imod->GetFormID() == 0x16AB6E)) {
				return 0;
			}

			return func(a_imod, a_strength, a_arg3, a_arg4, a_arg5, a_arg6, a_arg7);
		}
		static inline REL::Relocation<decltype(thunk)> func;
	};

	void Install()
	{
		const REL::Relocation<std::uintptr_t> target{ REL::Offset(0x1D80EA4), 0x16C };  // PlayerCharacter::StartGrabObject
		stl::write_thunk_call<IMOD>(target.address());

		logger::info("\tInstalled DisableSpaceshipDockingIMOD");
	}
}
