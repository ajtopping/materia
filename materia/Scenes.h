#pragma once

#include "entScene.h"
#include "rRenderLayer.h"
#include "rMesh.h"
#include "rNdcPanel.h"
#include "mMeshPrimitiveFactory.h"

namespace content
{
	namespace scene
	{
		void SetupDefaultScene( rRenderLayer & );
		void SetupRtScene( rRenderLayer & );
	}
}