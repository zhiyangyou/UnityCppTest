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

	DLLEXPORT void DeleteSkeletonData(SkeletonData* skData) {
		//SafeDeletePointer(skData);

		if (!skData) {
			char buffLog[256] = { 0 };
			sprintf_s(buffLog, "%s %d delete pointer is null return ", __FILE__, __LINE__);
			CSDebugLog(buffLog);
			return;
		}
		delete (skData);
	}

	DLLEXPORT void* LoadSkeletonData(Atlas* atlas, const char* jsonContent) {
		SkeletonJson json(atlas);
		SkeletonData* skeletonData = json.readSkeletonData(jsonContent);
		CSDebugLog("jsonContent");
		CSDebugLog(jsonContent);
		return skeletonData;
	}

	DLLEXPORT void* LoadAtlas(const char* atlasFileContent, int dataLen) {
		Atlas* atlas = new (__FILE__, __LINE__) Atlas(atlasFileContent, dataLen, "", nullptr, true);
		return atlas;
	}

	DLLExport void DeleteAtlas(Atlas* atlas) {
		//SafeDeletePointer(atlas);
		if (!atlas) {
			char buffLog[256] = { 0 };
			sprintf_s(buffLog, "%s %d delete pointer is null return ", __FILE__, __LINE__);
			CSDebugLog(buffLog);
			return;
		}
		delete (atlas);
	}

}