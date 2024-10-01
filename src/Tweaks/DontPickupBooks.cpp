#include "Tweaks.h"

namespace Tweaks::DontPickupBooks
{
	namespace detail
	{
		bool is_normal_book(RE::TESObjectREFR* a_objREFR)
		{
			if (const auto baseObject = a_objREFR->GetBaseObject()) {
				if (const auto book = baseObject->As<RE::TESObjectBOOK>()) {
					const auto flags = book->data.flags;
					if (flags.none(RE::OBJ_BOOK::Flag::kHasBeenRead)) {
						return false;  // HasBeen NOT Read
					}
					if (a_objREFR->extraDataList->HasQuestObjectAlias() || a_objREFR->extraDataList->HasType(RE::ExtraDataType::kAliasInstanceArray)) {
						return false;
					}
					if (a_objREFR->GetValue() > 0) {
						return false;
					}
					if (flags.any(RE::OBJ_BOOK::Flag::kAdvancesActorValue)) {
						return false;  // Teaches AV
					}
					if (flags.any(RE::OBJ_BOOK::Flag::kTeachesSpell)) {
						return false;  // Teaches Spell
					}
					if (flags.any(RE::OBJ_BOOK::Flag::kTeachesPerk)) {
						return false;  // Teaches Perk
					}
					return true;
				}
			}
			return false;
		}
	}

	struct PickupObject
	{
		static void thunk(RE::Actor* a_player, RE::TESObjectREFR* a_objREFR, std::int32_t a_count, bool a_playPickUpSounds)
		{
			if (detail::is_normal_book(a_objREFR)) {
				return;
			}

			return func(a_player, a_objREFR, a_count, a_playPickUpSounds);
		}
		static inline REL::Relocation<decltype(thunk)> func;
		static inline std::size_t                      idx{ 0x15B };
	};

	void Install()
	{
		stl::write_vfunc<PickupObject>(RE::VTABLE::PlayerCharacter[38]);

		logger::info("\tInstalled DontPickupReadBooks");
	}
}
