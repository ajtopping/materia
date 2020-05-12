#include "pch.h"

#include "../materia/amTptr.h"

TEST(amTptrTest, TypeIdAreEqual)
{

	float floatA = 0.0f;
	float floatB = 2.0f;

	int intA = 0;
	int intB = 1;

	amTptr<float> floatTA(&floatA);
	amTptr<float> floatTB(&floatB);

	amTptr<int> intTA(&intA);
	amTptr<int> intTB(&intB);

	EXPECT_EQ(typeid(floatTA.get_ptr()), typeid(floatTB.get_ptr()));
	EXPECT_EQ(typeid(intTA.get_ptr()), typeid(intTB.get_ptr()));

	EXPECT_NE(typeid(floatTA.get_ptr()), typeid(intTA.get_ptr()));
}

TEST(amTptrTest, GetAndWriteToInt)
{
	int intA = 1;

	amTptr<int> intTA(&intA);

	EXPECT_EQ(*intTA.get_ptr(), 1);

	*intTA.get_ptr() = 2;

	EXPECT_EQ(*intTA.get_ptr(), 2);
}