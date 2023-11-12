#pragma once

#include <memory>
#include <string>
#include <cstdio>
#include <cassert>
#include <spine/dll.h>

template<typename T>
using Ref = std::shared_ptr<T>;

template <typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args && ... args) {
	return std::make_shared<T>(std::forward<Args>(args)...);
}

template< typename... Args >
Ref <std::string >string_sprintf(const char* format, Args... args) {
	int length = std::snprintf(nullptr, 0, format, args...);
	assert(length >= 0);

	char* buf = new char[length + 1];
	std::snprintf(buf, length + 1, format, args...);

	std::string str(buf);
	auto refStr = CreateRef<std::string>(buf);
	delete[] buf;
	return refStr;
}


Ref<std::string> Convert2StringAndFreePtr(void* ptr);

namespace SpineUnity
{
	
}
