

#include "unity_spinecpp_plugin.h"

extern "C"
{

	void (*CSDebugLog)(const char* msg);
	DLLExport void InitCSDebugLog(void (*csharpFunctionPtr)(const char* msg)) {
		CSDebugLog = csharpFunctionPtr;

		CSDebugLog("C++ Logger Init Success");
	}

	DLLExport int CppFunction(int a, float b) {
		return a + (int)b;
	} 
}