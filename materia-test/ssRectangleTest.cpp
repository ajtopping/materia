#include "pch.h"

#include "../materia/ssRectangle.h"
#include "../materia/ssRectangle.cpp"
#include "../materia/amUuid.h"
#include "../materia/mTransform.h"
#include "../materia/mTransform.cpp"
#include "../materia/am_S_UniqueUuidAssociator.h"
#include "../materia/am_S_UniqueUuidAssociator.cpp"
#include "../materia/am_S_Uuid_T.tpp"

TEST(ssRectangleTest, ConstructedFromPositiveBoundsHasCorrectBounds)
{
	ssRectangle rectangle1(0.0f, 0.0f, 1.0f, 1.0f);
	ssRectangle rectangle2(1.0f, 1.0f, 0.0f, 0.0f);
	ssRectangle rectangle3(10.0f, 10.0f, 20.0f, 20.0f);

	EXPECT_EQ(rectangle1.get_world_left(), 0.0f);
	EXPECT_EQ(rectangle1.get_world_right(), 1.0f);
	EXPECT_EQ(rectangle1.get_world_top(), 1.0f);
	EXPECT_EQ(rectangle1.get_world_bottom(), 0.0f);

	EXPECT_EQ(rectangle2.get_world_left(), 0.0f);
	EXPECT_EQ(rectangle2.get_world_right(), 1.0f);
	EXPECT_EQ(rectangle2.get_world_top(), 1.0f);
	EXPECT_EQ(rectangle2.get_world_bottom(), 0.0f);

	EXPECT_EQ(rectangle3.get_world_left(), 10.0f);
	EXPECT_EQ(rectangle3.get_world_right(), 20.0f);
	EXPECT_EQ(rectangle3.get_world_top(), 20.0f);
	EXPECT_EQ(rectangle3.get_world_bottom(), 10.0f);
}

TEST(ssRectangleTest, ConstructedFromNegativeBoundsHasCorrectBounds)
{
	ssRectangle rectangle1(-1.0f, -1.0f, 0.0f, 0.0f);
	ssRectangle rectangle2(0.0f, 0.0f, -1.0f, -1.0f);
	ssRectangle rectangle3(-10.0f, -10.0f, -20.0f, -20.0f);

	EXPECT_EQ(rectangle1.get_world_left(), -1.0f);
	EXPECT_EQ(rectangle1.get_world_right(), 0.0f);
	EXPECT_EQ(rectangle1.get_world_top(), 0.0f);
	EXPECT_EQ(rectangle1.get_world_bottom(), -1.0f);

	EXPECT_EQ(rectangle2.get_world_left(), -1.0f);
	EXPECT_EQ(rectangle2.get_world_right(), 0.0f);
	EXPECT_EQ(rectangle2.get_world_top(), 0.0f);
	EXPECT_EQ(rectangle2.get_world_bottom(), -1.0f);

	EXPECT_EQ(rectangle3.get_world_left(), -20.0f);
	EXPECT_EQ(rectangle3.get_world_right(), -10.0f);
	EXPECT_EQ(rectangle3.get_world_top(), -10.0f);
	EXPECT_EQ(rectangle3.get_world_bottom(), -20.0f);
}

TEST(ssRectangleTest, SameBoundsWithInputPointsInReverseOrder)
{
	ssRectangle rectangle0 = ssRectangle(0.0f, 0.0f, 1.0f, 1.0f);
	ssRectangle rectangle1 = ssRectangle(1.0f, 1.0f, 0.0f, 0.0f);

	EXPECT_EQ(rectangle0.get_world_left(), rectangle1.get_world_left());
	EXPECT_EQ(rectangle0.get_world_right(), rectangle1.get_world_right());
	EXPECT_EQ(rectangle0.get_world_top(), rectangle1.get_world_top());
	EXPECT_EQ(rectangle0.get_world_bottom(), rectangle1.get_world_bottom());
}