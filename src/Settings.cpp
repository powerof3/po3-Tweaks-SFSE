#include "Settings.h"

void Settings::Load()
{
	LoadImpl(
		path, [&](CSimpleIniA& a_ini) {
			tweaks.Load(a_ini, true);
		},
		true);

	LoadImpl(
		userPath, [&](CSimpleIniA& a_ini) {
			tweaks.Load(a_ini, false);
		},
		false);
}

bool Settings::IsTweakInstalled(std::string_view a_tweak)
{
	const auto it = settingsMap.find(stl::as_string(a_tweak));
	return it != settingsMap.end() ? it->second : false;
}

void Settings::LoadImpl(const wchar_t* a_path, const std::function<void(CSimpleIniA&)> a_func, bool a_generate)
{
	CSimpleIniA ini;
	ini.SetUnicode();

	if (const auto rc = ini.LoadFile(a_path); !a_generate && rc < SI_OK) {
		return;
	}

	a_func(ini);

	if (a_generate) {
		(void)ini.SaveFile(a_path);
	}
}

void Settings::Fixes::Load([[maybe_unused]] CSimpleIniA& a_ini, [[maybe_unused]] bool a_set)
{
	return;
}

void Settings::Tweaks::Load(CSimpleIniA& a_ini, bool a_writeValues)
{
	const char* section = "Tweaks";

	get_value(a_ini, grabWithoutStealing, section, "bGrabWithoutStealing", ";Grabbing items won't count as stealing", a_writeValues);
	get_value(a_ini, justPayFine, section, "bSkipJailOnPayFine", ";Don't go to jail when paying fines", a_writeValues);
	get_value(a_ini, dontPickupReadBooks, section, "bDontPickupReadBooks", ";Don't pick up books you read unless they're quest items/skill books/can be sold", a_writeValues);
}

const Settings::Fixes& Settings::GetFixes() const
{
	return fixes;
}

const Settings::Tweaks& Settings::GetTweaks() const
{
	return tweaks;
}
