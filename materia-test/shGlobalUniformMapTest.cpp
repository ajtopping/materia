#include "pch.h"

#include "../materia/shGlobalUniformMap.cpp"
#include "../materia/shUniformT.tpp"

TEST(shGlobalUniformMapTest, UpdatingMissingUniformReturnsFalse)
{
	shGlobalUniformMap uniform_map;

	EXPECT_FALSE(uniform_map.update_uniform("Missing", 0));
}

TEST(shGlobalUniformMapTest, UpdatingFoundUniformReturnsTrue)
{
	shGlobalUniformMap uniform_map;
	shUniformT<int> uniform_int( "int_name" );
	shUniformT<int> uniform_int2("int_name2");
	shUniformT<float> uniform_float("float_name");

	uniform_map.add_uniform(&uniform_int);
	uniform_map.add_uniform(&uniform_int2);
	uniform_map.add_uniform(&uniform_float);

	EXPECT_TRUE(uniform_map.update_uniform("int_name", 0));
	EXPECT_TRUE(uniform_map.update_uniform("int_name2", 0));
	EXPECT_TRUE(uniform_map.update_uniform("float_name", 0.0f));

	EXPECT_FALSE(uniform_map.update_uniform("Missing", 0));
}