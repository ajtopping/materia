#include "pch.h"

#include "../materia/ssRectangle.h"
#include "../materia/ssRectangle.cpp"

TEST(ssRectangleTest, SameBoundsWithInputPointsInReverseOrder)
{
	ssRectangle rectangle0 = ssRectangle(0.0f, 0.0f, 1.0f, 1.0f);
	ssRectangle rectangle1 = ssRectangle(1.0f, 1.0f, 0.0f, 0.0f);

	EXPECT_EQ(rectangle0.get_left(), rectangle1.get_left());
	EXPECT_EQ(rectangle0.get_right(), rectangle1.get_right());
	EXPECT_EQ(rectangle0.get_top(), rectangle1.get_top());
	EXPECT_EQ(rectangle0.get_bottom(), rectangle1.get_bottom());
}