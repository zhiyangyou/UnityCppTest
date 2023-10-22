#pragma once
#define SpineCppExport __declspec(dllexport)

#define SafeDeletePointer(p) 	if (!(p)) { char buffLog[256] = { 0 };sprintf_s(buffLog, "%s %d delete pointer is null return ", __FILE__, __LINE__);\
CSDebugLog(buffLog);\
return;\
}\
delete (p);