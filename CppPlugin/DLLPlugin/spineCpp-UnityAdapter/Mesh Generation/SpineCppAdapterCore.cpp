
#include "SpineCppAdapterCore.h"

Ref<std::string> Convert2StringAndFreePtr(void* ptr)
{
	if (ptr == nullptr) {
		return CreateRef<std::string>("empty string");
	}
	auto str = CreateRef<std::string>();
	str->append(static_cast<char*>(ptr));
	free(ptr);
	return str;
}

