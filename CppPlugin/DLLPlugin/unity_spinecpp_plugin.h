#pragma once
#include <sstream>
#define SpineCppExport __declspec(dllexport)

#define SafeDeletePointer(p) 	if (!(p)) { char buffLog[256] = { 0 };sprintf_s(buffLog, "%s %d delete pointer is null return ", __FILE__, __LINE__);\
CSDebugLog(buffLog);\
return;\
}\
delete (p);

extern void (*CSDebugLog)(const char* msg);

template<typename... Args>
void UnityDebugLog(Args...args) {
	std::ostringstream oss;
	int dummy[] = { 0, (oss << args, 0)... };
	CSDebugLog(oss.str().c_str());
}