#pragma once

#include "rMesh.h"
#include "mTransfrom.h"

class oRenderableMesh
{
public:
	mTransform transform;

	void set_renderer(rMesh*);
	void set_mesh(mMesh*);

	void render();
	bool is_up_to_date() { return up_to_date_; };

	bool update();
	
private:
	rMesh * renderer_ = nullptr;
	mMesh * mesh_ = nullptr;

	bool up_to_date_ = true;

	void update_();
	
};