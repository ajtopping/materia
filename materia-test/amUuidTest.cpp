#include "pch.h"

#include "../materia/amUuid.h"

TEST(amUuidTest, NewAmUuidNotEqualToZero)
{
	amUuid uuid;

	EXPECT_NE(uuid.get_data(), 0);
}

TEST(amUuidTest, NewAmUuidNotNil)
{
	amUuid uuid;

	EXPECT_FALSE(uuid.isNil());
}

TEST(amUuidTest, ZeroAmUuidIsNil)
{
	amUuid uuid(0);

	EXPECT_TRUE(uuid.isNil());
}

TEST(amUuidTest, TwoNewAmUuidAreNotEqual)
{
	amUuid uuid1;
	amUuid uuid2;

	EXPECT_NE(uuid1, uuid2);
}