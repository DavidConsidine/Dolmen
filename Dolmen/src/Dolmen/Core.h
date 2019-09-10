#pragma once

#include <memory>

#ifdef DM_PLATFORM_WINDOWS

#else
	#error Dolmen is not supported on this platform.
#endif

#ifdef DM_DEBUG
	#define DM_ENABLE_ASSERTS
#endif

#ifdef DM_ENABLE_ASSERTS

#else

#endif

namespace Dolmen
{
	template<typename T>
	using ScopePtr = std::unique_ptr<T>;

	template<typename T>
	using RefPtr = std::shared_ptr<T>;
}
