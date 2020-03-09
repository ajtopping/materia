#pragma once

// Maybe make into a namespace?

#include "mMesh.h"

#include <iostream>

class mMeshPrimitiveFactory
{
public:
	static mMesh * DefaultDiamond();
	static mMesh * DefaultPyramid();
	static mMesh * PlusSign();
	static mMesh * NdcPanel();
private:
	mMeshPrimitiveFactory() {};
};