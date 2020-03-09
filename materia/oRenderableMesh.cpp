#include "oRenderableMesh.h"

void oRenderableMesh::render()
{
	if ( !is_up_to_date() )
	{
		update_();
	}

	if (renderer_ != nullptr)
	{
		renderer_->Draw(this->transform.get_composition_matrix());
	}
}

void oRenderableMesh::set_mesh(mMesh * mesh)
{
	mesh_ = mesh;
	up_to_date_ = false;
}

void oRenderableMesh::set_renderer(rMesh * renderer)
{
	renderer_ = renderer;
	up_to_date_ = false;
}

bool oRenderableMesh::update()
{
	if (is_up_to_date())
	{
		return false;
	}

	update_();
	return true;
}

void oRenderableMesh::update_()
{
	if (renderer_ != nullptr && mesh_ != nullptr)
	{
		renderer_->SetMesh(*mesh_);
	}

	up_to_date_ = true;
}