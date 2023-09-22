#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMMNOSOUND

#include "RE/Starfield.h"
#include "SFSE/SFSE.h"

#include <ClibUtil/simpleINI.hpp>
#include <ClibUtil/string.hpp>
#include <ClibUtil/singleton.hpp>
#include <ankerl/unordered_dense.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <xbyak/xbyak.h>

namespace logger = SFSE::log;
namespace string = clib_util::string;
namespace ini = clib_util::ini;

using namespace std::literals;
using namespace clib_util::singleton;

namespace stl
{
	using namespace SFSE::stl;

	void asm_replace(std::uintptr_t a_from, std::size_t a_size, std::uintptr_t a_to);

	template <class T>
	void asm_replace(std::uintptr_t a_from)
	{
		asm_replace(a_from, T::size, reinterpret_cast<std::uintptr_t>(T::func));
	}

	template <class T>
	void write_thunk_jump(std::uintptr_t a_src)
	{
		SFSE::AllocTrampoline(14);

		auto& trampoline = SFSE::GetTrampoline();
		T::func = trampoline.write_branch<5>(a_src, T::Thunk);
	}

	inline std::string as_string(std::string_view a_view)
	{
		return { a_view.data(), a_view.size() };
	}
}

#define DLLEXPORT extern "C" [[maybe_unused]] __declspec(dllexport)

#include "Version.h"
