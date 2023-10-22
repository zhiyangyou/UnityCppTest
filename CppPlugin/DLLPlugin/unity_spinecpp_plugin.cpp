#include "unity_spinecpp_plugin.h"
#include <spine/spine.h>
using namespace spine;

extern "C" {

	void loadBinary(const String& binaryFile, const String& atlasFile) {

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

}