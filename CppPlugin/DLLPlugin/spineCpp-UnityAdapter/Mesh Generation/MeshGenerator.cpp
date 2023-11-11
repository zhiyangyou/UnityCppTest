
#include "MeshGenerator.h"

#include <spine/spine.h>

namespace SpineUnity {





	MeshGenerator::MeshGenerator()
	{
		submeshes->add(CreateRef<spine::Vector<int>>()); // start with 1 submesh.
	}

	

}