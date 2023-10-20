#include "Tweaks.h"

namespace Tweaks::JustPayFine
{
	struct PayFine
	{
		static void thunk(RE::Actor* a_player, std::uintptr_t a_faction, [[maybe_unused]] bool a_goToJail, bool a_removeStolenItems)
		{
			return func(a_player, a_faction, a_player->IsInSpace(true) ? a_goToJail : false, a_removeStolenItems);
		}
		static inline REL::Relocation<decltype(thunk)> func;
		static inline std::size_t                      idx{ 0x14B };
	};

	void Install()
	{
		stl::write_vfunc<PayFine>(RE::VTABLE::PlayerCharacter[38]);

		const REL::Relocation<std::uintptr_t> console{ REL::ID(110020), 0xB9 };
		stl::write_thunk_call<PayFine>(console.address());  // Console

		const REL::Relocation<std::uintptr_t> papyrus{ REL::ID(171509), 0x10 };
		stl::write_thunk_jump<PayFine>(papyrus.address());  // Papyrus

		logger::info("\tInstalled JustPayFine");
	}
}
