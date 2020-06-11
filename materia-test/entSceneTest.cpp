#include "pch.h"

#include "../materia/entComposition.hpp"
#include "../materia/entScene.hpp"

TEST(entSceneTest, EmptySceneReturnsEmptySet)
{
	entScene scene;

	auto set = scene.getEntityUuidSet();

	EXPECT_TRUE(set.empty());
}

TEST(entSceneTest, InsertingIntoSceneReturnsNonEmptySet)
{
	entScene scene;
	entComposition composition;

	scene.addCompositionEntity(composition);

	auto set = scene.getEntityUuidSet();

	EXPECT_FALSE(set.empty());
}

TEST(entSceneTest, FindingNonContainedCompositionReturnsNilUuid)
{
	entScene scene;
	entComposition composition;

	amUuid found_uuid = scene.findEntityUuid(composition);

	EXPECT_TRUE(found_uuid.isNil());
}

TEST(entSceneTest, FindingContainedCompositionReturnsCorrectUuid)
{
	entScene scene;
	entComposition composition;

	scene.addCompositionEntity(composition);
	amUuid found_uuid = scene.findEntityUuid(composition);

	EXPECT_EQ(composition.get_uuid(), found_uuid);
}

TEST(entSceneTest, ReturnedSetIsCorrectSizeTwoElements)
{
	entScene scene;
	entComposition composition1;
	entComposition composition2;

	scene.addCompositionEntity(composition1);
	scene.addCompositionEntity(composition2);
	auto set = scene.getEntityUuidSet();

	EXPECT_NE(composition1.get_uuid(), composition2.get_uuid());
	
	EXPECT_EQ(2, set.size());
}