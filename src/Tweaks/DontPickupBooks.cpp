#include "Tweaks.h"

namespace Tweaks::DontPickupBooks
{
	namespace detail
	{
		bool is_quest_item(std::uintptr_t a_extraDataList)
		{
			using func_t = decltype(&is_quest_item);
			REL::Relocation<func_t> func{ REL::Offset(0x014265C8) };
			return func(a_extraDataList);
		}

		bool has_extra_data(std::uintptr_t a_extraDataList, std::uint8_t a_type)
		{
			using func_t = decltype(&has_extra_data);
			REL::Relocation<func_t> func{ REL::Offset(0x0125D414) };
			return func(a_extraDataList, a_type);
		}

		bool is_normal_book(RE::TESObjectREFR* a_objREFR)
		{
			if (const auto baseObject = a_objREFR->GetBaseObject()) {
				if (baseObject->Is(RE::FormType::kBOOK)) {
					if (has_extra_data(a_objREFR->extraDataList, static_cast<std::uint8_t>(RE::EXTRA_DATA_TYPE::kAliasInstanceArray)) || a_objREFR->GetValue() > 0) {
						return false;
					}
					const auto flags = *stl::adjust_pointer<std::uint8_t>(baseObject, 0x258);
					if ((flags & 8) == 0) {
						return false;  // HasBeen NOT Read
					}
					if ((flags & 1) != 0) {
						return false;  // Teaches AV
					}
					if ((flags & 4) != 0) {
						return false;  // Teaches Spell
					}
					if ((flags & 16) != 0) {
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
		static void Thunk(RE::Actor* a_player, RE::TESObjectREFR* a_objREFR, std::int32_t a_count, bool a_playPickUpSounds)
		{
			if (detail::is_normal_book(a_objREFR)) {
				return;
			}

			return func(a_player, a_objREFR, a_count, a_playPickUpSounds);
		}
		static inline REL::Relocation<decltype(Thunk)> func;
		static inline std::size_t                      idx{ 0x15B };
	};

	void Install()
	{
		stl::write_vfunc<PickupObject>(RE::VTABLE::PlayerCharacter[25]);  // why is it in the middle???

		logger::info("\tInstalled DontPickupReadBooks");
	}
}
