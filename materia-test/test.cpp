#include "pch.h"

#include "../materia/ssRectangle.h"
#include "../materia/ssRectangle.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Test, Test)
{
	ssRectangle rectangle = ssRectangle(0.0f, 0.0f, 1.0f, 1.0f);
	EXPECT_GE(rectangle.get_id(), 0);
}