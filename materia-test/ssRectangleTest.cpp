#include "pch.h"

#include "../materia/ssRectangle.h"
#include "../materia/ssRectangle.cpp"

TEST(ssRectangleTest, ConstructedFromPositiveBoundsHasCorrectBounds)
{
	ssRectangle rectangle1(0.0f, 0.0f, 1.0f, 1.0f);
	ssRectangle rectangle2(1.0f, 1.0f, 0.0f, 0.0f);
	ssRectangle rectangle3(10.0f, 10.0f, 20.0f, 20.0f);

	EXPECT_EQ(rectangle1.get_left(), 0.0f);
	EXPECT_EQ(rectangle1.get_right(), 1.0f);
	EXPECT_EQ(rectangle1.get_top(), 1.0f);
	EXPECT_EQ(rectangle1.get_bottom(), 0.0f);

	EXPECT_EQ(rectangle2.get_left(), 0.0f);
	EXPECT_EQ(rectangle2.get_right(), 1.0f);
	EXPECT_EQ(rectangle2.get_top(), 1.0f);
	EXPECT_EQ(rectangle2.get_bottom(), 0.0f);

	EXPECT_EQ(rectangle3.get_left(), 10.0f);
	EXPECT_EQ(rectangle3.get_right(), 20.0f);
	EXPECT_EQ(rectangle3.get_top(), 20.0f);
	EXPECT_EQ(rectangle3.get_bottom(), 10.0f);
}

TEST(ssRectangleTest, ConstructedFromNegativeBoundsHasCorrectBounds)
{
	ssRectangle rectangle1(-1.0f, -1.0f, 0.0f, 0.0f);
	ssRectangle rectangle2(0.0f, 0.0f, -1.0f, -1.0f);
	ssRectangle rectangle3(-10.0f, -10.0f, -20.0f, -20.0f);

	EXPECT_EQ(rectangle1.get_left(), -1.0f);
	EXPECT_EQ(rectangle1.get_right(), 0.0f);
	EXPECT_EQ(rectangle1.get_top(), 0.0f);
	EXPECT_EQ(rectangle1.get_bottom(), -1.0f);

	EXPECT_EQ(rectangle2.get_left(), -1.0f);
	EXPECT_EQ(rectangle2.get_right(), 0.0f);
	EXPECT_EQ(rectangle2.get_top(), 0.0f);
	EXPECT_EQ(rectangle2.get_bottom(), -1.0f);

	EXPECT_EQ(rectangle3.get_left(), -20.0f);
	EXPECT_EQ(rectangle3.get_right(), -10.0f);
	EXPECT_EQ(rectangle3.get_top(), -10.0f);
	EXPECT_EQ(rectangle3.get_bottom(), -20.0f);
}

TEST(ssRectangleTest, SameBoundsWithInputPointsInReverseOrder)
{
	ssRectangle rectangle0 = ssRectangle(0.0f, 0.0f, 1.0f, 1.0f);
	ssRectangle rectangle1 = ssRectangle(1.0f, 1.0f, 0.0f, 0.0f);

	EXPECT_EQ(rectangle0.get_left(), rectangle1.get_left());
	EXPECT_EQ(rectangle0.get_right(), rectangle1.get_right());
	EXPECT_EQ(rectangle0.get_top(), rectangle1.get_top());
	EXPECT_EQ(rectangle0.get_bottom(), rectangle1.get_bottom());
}