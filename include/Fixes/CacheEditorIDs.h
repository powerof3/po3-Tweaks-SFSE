#pragma once

#include "Cache.h"

namespace Fixes::CacheEditorIDs
{
	template <class T>
	struct GetFormEditorIDLength
	{
		static std::uint32_t thunk(T* a_this)
		{
			return Cache::EditorID::GetSingleton()->GetEditorIDLength(a_this);
		}
		static inline REL::Relocation<decltype(thunk)> func;
		static inline constexpr size_t                 idx{ 0x4C };
	};

	template <class T>
	struct GetFormEditorID
	{
		static const char* thunk(const T* a_this)
		{
			return Cache::EditorID::GetSingleton()->GetEditorID(a_this);
		}
		static inline REL::Relocation<decltype(thunk)> func;
		static inline constexpr size_t                 idx{ 0x4D };
	};

	template <class T>
	struct SetFormEditorID
	{
		static bool thunk(T* a_this, const char* a_str)
		{
			if (!string::is_empty(a_str) && !a_this->IsCreated()) {
				Cache::EditorID::GetSingleton()->CacheEditorID(a_this, a_str);
			}
			return func(a_this, a_str);
		}
		static inline REL::Relocation<decltype(thunk)> func;
		static inline constexpr size_t                 idx{ 0x4E };
	};

	template <class T>
	void HookEditorID(const std::size_t a_vtblIdx)
	{
		stl::write_vfunc<T, GetFormEditorIDLength<T>>(a_vtblIdx);
		stl::write_vfunc<T, GetFormEditorID<T>>(a_vtblIdx);
		stl::write_vfunc<T, SetFormEditorID<T>>(a_vtblIdx);
	}
}
