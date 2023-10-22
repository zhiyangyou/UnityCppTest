

#include "unity_spinecpp_plugin.h"
#include <spine/spine.h>
extern "C"
{
	// Function pointer to the C# function
	// The syntax is like this: ReturnType (*VariableName)(ParamType ParamName, ...)
	int(*CsharpFunction)(int a, float b);

	// C++ function that C# calls
	// Takes the function pointer for the C# function that C++ can call
	DLLExport void Init(int(*csharpFunctionPtr)(int, float))
	{
		CsharpFunction = csharpFunctionPtr;
	}

	// Example function that calls into C#
	DLLExport void Foo()
	{
		// It's just a function call like normal!
		int retVal = CsharpFunction(2, 3.14f);
	}


	DLLExport int CppFunction(int a, float b) {
		return a + (int)b;
	}
}