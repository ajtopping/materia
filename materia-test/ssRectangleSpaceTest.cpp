#include "pch.h"

#include "../materia/ssRectangleSpace.h"
#include "../materia/ssRectangleSpace.cpp"

TEST(ssRectangleSpaceTest, ReturnEmptyListWhenNoRectanglesInSpace)
{
	ssRectangleSpace space;

	std::forward_list<ssRectangle> found_rectangles = space.find_rectangles_containing_point(1.0f, 1.0f);

	EXPECT_TRUE(found_rectangles.empty());
}

TEST(ssRectangleSpaceTest, RectangleContainsPoint)
{
	ssRectangleSpace space;
	ssRectangle rectangle0 = ssRectangle(0.0f, 0.0f, 1.0f, 1.0f);
	ssRectangle rectangle1 = ssRectangle(1.0f, 1.0f, 2.0f, 2.0f);

	bool contains = space.rectangle_contains_point(rectangle0, 0.5f, 0.5f);
	bool not_contains = space.rectangle_contains_point(rectangle1, 0.5f, 0.5f);

	EXPECT_TRUE(contains);
	EXPECT_FALSE(not_contains);
}

TEST(ssRectangleSpaceTest, ReturnEmptyListWhenNoRectanglesContainsPoint)
{
	ssRectangleSpace space;
	ssRectangle rectangle0 = ssRectangle(0.0f, 0.0f, 1.0f, 1.0f);
	ssRectangle rectangle1 = ssRectangle(2.0f, 2.0f, 3.0f, 3.0f);
	space.insert_rectangle(rectangle0);
	space.insert_rectangle(rectangle1);
	std::forward_list<ssRectangle> found_rectangles = space.find_rectangles_containing_point(1.5f, 1.5f);

	EXPECT_TRUE(found_rectangles.empty());
}

TEST(ssRectangleSpaceTest, OneRectangleContainsPoint)
{
	ssRectangleSpace space;
	ssRectangle rectangle0 = ssRectangle(0.0f, 0.0f, 1.0f, 1.0f);
	ssRectangle rectangle1 = ssRectangle(2.0f, 2.0f, 3.0f, 3.0f);
	space.insert_rectangle(rectangle0);
	space.insert_rectangle(rectangle1);
	std::forward_list<ssRectangle> found_rectangles = space.find_rectangles_containing_point(0.5f, 0.5f);

	int num_rectangles = 0;
	for (auto it = found_rectangles.begin(); it != found_rectangles.end(); it++)
	{
		num_rectangles++;
	}

	EXPECT_EQ(num_rectangles, 1);
}

TEST(ssRectangleSpaceTest, TwoOverlappingRectangleContainsPoint)
{
	ssRectangleSpace space;
	ssRectangle rectangle0 = ssRectangle(0.0f, 0.0f, 1.0f, 1.0f);
	ssRectangle rectangle1 = ssRectangle(0.5f, 0.5f, 1.5f, 1.5f);
	space.insert_rectangle(rectangle0);
	space.insert_rectangle(rectangle1);
	std::forward_list<ssRectangle> found_rectangles = space.find_rectangles_containing_point(0.75f, 0.75f);

	int num_rectangles = 0;
	for (auto it = found_rectangles.begin(); it != found_rectangles.end(); it++)
	{
		num_rectangles++;
	}

	EXPECT_EQ(num_rectangles, 2);
}