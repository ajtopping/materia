#include "pch.h"

TEST(TypeIdOpTest, TypeIdInt)
{
	
	int intA;
	int intB = 0;


	EXPECT_EQ(typeid(int), typeid(int));
	EXPECT_EQ(typeid(int), typeid(intA));
	EXPECT_EQ(typeid(int), typeid(intB));
	EXPECT_EQ(typeid(intA), typeid(intB));
}