#include "entDraw.h"

void entDraw::Draw(amUuid entity_uuid)
{
	if (!util::component::HasComponent<Renderer>(entity_uuid))
	{
		fprintf(stdout, "Entity has no Renderer. Skipping...\n");
		return;
	}

	Renderer & renderer_ref = util::component::GetComponent<Renderer>(entity_uuid);
	
	mTransform transform;

	glm::mat4 camera_matrix = util::camera::GetActiveCameraViewMatrix();

	if (util::component::HasComponent<mTransform>(entity_uuid))
	{
		transform = util::component::GetComponent<mTransform>(entity_uuid);
		renderer_ref.Draw(camera_matrix * transform.get_composition_matrix());
	}
	else
	{
		fprintf(stdout, "Entity has no mTransform. Using default...\n");
		renderer_ref.Draw(camera_matrix);
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