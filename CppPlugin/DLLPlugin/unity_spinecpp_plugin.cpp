#include "unity_spinecpp_plugin.h"
#include <spine/spine.h>
using namespace spine;

extern "C" {

	void (*CSDebugLog)(const char* msg);
	DLLExport void InitCSDebugLog(void (*csharpFunctionPtr)(const char* msg)) {
		CSDebugLog = csharpFunctionPtr;

		CSDebugLog("C++ Logger Init Success");
	}

	DLLExport int CppFunction(int a, float b) {
		return a + (int)b;
	}

	DLLEXPORT void loadBinary(const String& binaryFile, const String& atlasFile) {

		Atlas* atlas = nullptr;
		SkeletonData* skeletonData = nullptr;
		AnimationStateData* stateData = nullptr;
		Skeleton* skeleton = nullptr;
		AnimationState* state = nullptr;

		atlas = new (__FILE__, __LINE__) Atlas(atlasFile, NULL);
		assert(atlas != NULL);

		SkeletonBinary binary(atlas);
		skeletonData = binary.readSkeletonDataFile(binaryFile);
		assert(skeletonData);

		skeleton = new (__FILE__, __LINE__) Skeleton(skeletonData);
		assert(skeleton != NULL);

		stateData = new (__FILE__, __LINE__) AnimationStateData(skeletonData);
		assert(stateData != NULL);
		stateData->setDefaultMix(0.4f);

		state = new (__FILE__, __LINE__) AnimationState(stateData);
	}

	DLLEXPORT void* LoadAtlas(const char* atlasFileContent, int dataLen) {
		CSDebugLog("CS loadAtlas content");
		CSDebugLog(atlasFileContent);
		Atlas* atlas = new (__FILE__, __LINE__) Atlas(atlasFileContent, dataLen, "", nullptr, true);
		return atlas;
	}

	DLLExport void DeleteAtlas(char* atlas) {
		if (!atlas) {
			CSDebugLog("CS : try to delete null pointer . return ");
			return;
		}
		delete atlas;
	}

}