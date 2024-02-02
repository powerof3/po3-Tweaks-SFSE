#pragma once

namespace Cache
{
	class EditorID : public ISingleton<EditorID>
	{
	public:
		void CacheEditorID(const RE::TESForm* a_form, const char* a_editorID);

        std::uint32_t GetEditorIDLength(std::uint32_t a_formID);
        std::uint32_t GetEditorIDLength(const RE::TESForm* a_form);

	    const char* GetEditorID(std::uint32_t a_formID);
		const char* GetEditorID(const RE::TESForm* a_form);

	private:
		using Lock = std::mutex;
		using Locker = std::scoped_lock<Lock>;

		mutable Lock                                                           _lock;
		ankerl::unordered_dense::segmented_map<std::uint32_t, RE::BGSEditorID> _formIDToEditorIDMap;
	};
}
