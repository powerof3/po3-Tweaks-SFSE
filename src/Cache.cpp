#include "Cache.h"

namespace Cache
{
	void EditorID::CacheEditorID(const RE::TESForm* a_form, const char* a_editorID)
	{
		Locker locker(_lock);

		RE::BGSEditorID editorID{};
		editorID.Register(a_editorID, a_form);

		_formIDToEditorIDMap.emplace(a_form->GetFormID(), editorID);
	}

	std::uint32_t EditorID::GetEditorIDLength(std::uint32_t a_formID)
	{
		const auto it = _formIDToEditorIDMap.find(a_formID);
		if (it != _formIDToEditorIDMap.end()) {
			return it->second.length();
		}

		return 0;
	}

	std::uint32_t EditorID::GetEditorIDLength(const RE::TESForm* a_form)
	{
		return GetEditorIDLength(a_form->GetFormID());
	}

	const char* EditorID::GetEditorID(std::uint32_t a_formID)
	{
		const auto it = _formIDToEditorIDMap.find(a_formID);
		if (it != _formIDToEditorIDMap.end()) {
			return it->second.c_str();
		}

		static std::string emptyStr;
		return emptyStr.c_str();
	}

	const char* EditorID::GetEditorID(const RE::TESForm* a_form)
	{
		return GetEditorID(a_form->GetFormID());
	}
}

extern "C" DLLEXPORT const char* GetFormEditorID(std::uint32_t a_formID)
{
	return Cache::EditorID::GetSingleton()->GetEditorID(a_formID);
}
