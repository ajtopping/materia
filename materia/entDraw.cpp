#include "entDraw.h"

void entDraw::Draw(amUuid entity_uuid)
{
	if (!util::HasComponent<Renderer *>(entity_uuid))
	{
		fprintf(stdout, "Entity has no Renderer. Skipping...");
	}

	Renderer * renderer_ptr = util::GetComponent<Renderer *>(entity_uuid);

	mTransform * transform_ptr;

	if (util::HasComponent<mTransform *>(entity_uuid))
	{
		transform_ptr = util::GetComponent<mTransform *>(entity_uuid);
		renderer_ptr->Draw(transform_ptr->get_composition_matrix());
	}
	else
	{
		fprintf(stdout, "Entity has no mTransform. Using default...");
		renderer_ptr->Draw();
	}

	
}