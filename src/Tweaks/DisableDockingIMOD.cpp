#include "Tweaks.h"

#include "RE/T/TESDeathEvent.h"

namespace Tweaks::DisableDockingIMOD
{
	struct TriggerImageSpaceModifier
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

	class HUDHandler : public ISingleton<HUDHandler>, public RE::BSTEventSink<RE::TESDeathEvent>
	{
	public:
		RE::EventResult ProcessEvent(const RE::TESDeathEvent& a_event, RE::BSTEventSource<RE::TESDeathEvent>* a_eventSource) override;
	};

    RE::EventResult HUDHandler::ProcessEvent(const RE::TESDeathEvent& a_event, RE::BSTEventSource<RE::TESDeathEvent>*)
    {
		if (const auto actor = a_event.actorDying; actor && !a_event.dead) {
			logger::info("{} [{}]", actor->GetDisplayFullName(), actor->refCount);
		}

		return RE::EventResult::kContinue;
    }

	void Install()
	{
		const REL::Relocation<std::uintptr_t> target{ REL::ID(120385), 0x16C };  // ShipActionCameraState::InitCameraPath ?
		stl::write_thunk_call<TriggerImageSpaceModifier>(target.address());

		RE::TESDeathEvent::GetEventSource()->RegisterSink(HUDHandler::GetSingleton());

			logger::info("\tInstalled DisableSpaceshipDockingIMOD");
	}

}
