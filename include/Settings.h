#pragma once

class Settings : public ISingleton<Settings>
{
public:
	struct Fixes
	{
		void Load(CSimpleIniA& a_ini, bool a_writeValues);

		//members
		bool loadEDID{ true };
	};

	struct Tweaks
	{
		void Load(CSimpleIniA& a_ini, bool a_writeValues);

		// members
		bool justPayFine{ true };
		bool grabWithoutStealing{ true };
		bool dontPickupReadBooks{ true };
		bool disableDockingIMOD{ true };
	};

	void Load();

	[[nodiscard]] const Fixes&  GetFixes() const;
	[[nodiscard]] const Tweaks& GetTweaks() const;

	bool IsTweakInstalled(std::string_view a_tweak);

private:
	template <class T>
	static void get_value(CSimpleIniA& a_ini, T& a_value, const char* a_section, const char* a_key, const char* a_comment, bool a_writeValues)
	{
		if (a_writeValues) {
			ini::get_value(a_ini, a_value, a_section, a_key, a_comment);
		} else {
			ini::get_value(a_ini, a_value, a_section, a_key);
		}

		if constexpr (std::is_same_v<bool, T>) {
			GetSingleton()->settingsMap.emplace(a_key, a_value);
		} else if constexpr (std::is_floating_point_v<T>) {
			GetSingleton()->settingsMap.emplace(a_key, a_value != 1.0);
		} else if constexpr (std::is_arithmetic_v<T>) {
			GetSingleton()->settingsMap.emplace(a_key, a_value != 0);
		}
	}

	void LoadImpl(const wchar_t* a_path, const std::function<void(CSimpleIniA&)> a_func, bool a_generate);

	// members
	Fixes  fixes{};
	Tweaks tweaks{};

	ankerl::unordered_dense::map<std::string, bool> settingsMap{};

	const wchar_t* path{ L"Data/SFSE/Plugins/po3_TweaksSF.ini" };
	const wchar_t* userPath{ L"Data/SFSE/Plugins/po3_TweaksSF_Custom.ini" };
};
