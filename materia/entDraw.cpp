#include "entDraw.h"

void entDraw::Draw(amUuid entity_uuid)
{
	if (!util::HasComponent<Renderer *>(entity_uuid))
	{
		fprintf(stdout, "Entity has no Renderer. Skipping...\n");
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
		fprintf(stdout, "Entity has no mTransform. Using default...\n");
		renderer_ptr->Draw();
	}

	
}

void entDraw::DrawScene(amUuid scene_uuid)
{
	if ( !am_S_Uuid_T<entScene *>::has(scene_uuid) )
	{
		fprintf(stdout, "entDraw::DrawScene: No entScene with uuid %llu exists.\n", scene_uuid.get_data());
	}

	entScene * scene = am_S_Uuid_T<entScene *>::find(scene_uuid);

	auto scene_set = scene->getEntityUuidSet();

	for (auto iter = scene_set.begin(); iter != scene_set.end(); iter++)
	{
		entDraw::Draw(*iter);
	}
}

void entDraw::DrawScene(entScene & scene_ref)
{
	auto scene_set = scene_ref.getEntityUuidSet();

	for (auto iter = scene_set.begin(); iter != scene_set.end(); iter++)
	{
		entDraw::Draw(*iter);
	}
}