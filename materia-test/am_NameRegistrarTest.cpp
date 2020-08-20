#include "pch.h"

#include "../materia/am_NameRegistrar.cpp"

TEST(am_NameRegistrarTest, HasNameAndUuid)
{
	am_NameRegistrar nr;

	amUuid uuid1;
	amUuid uuid2;

	std::string name1 = "name1";
	std::string name2 = "name2";

	nr.insert(name1, uuid1);
	nr.insert(name2, uuid2);

	EXPECT_TRUE(nr.has_name("name1"));
	EXPECT_TRUE(nr.has_uuid(uuid1));

	EXPECT_TRUE(nr.has_name("name2"));
	EXPECT_TRUE(nr.has_uuid(uuid2));

	EXPECT_FALSE(nr.has_name("this_name_does_not_exist"));
	EXPECT_FALSE(nr.has_uuid(amUuid(0)));
}

TEST(am_S_NameRegistrarTest, ReplaceName)
{
	am_NameRegistrar nr;

	amUuid uuid1;

	std::string name1 = "name1";
	std::string name2 = "name2";

	nr.insert(name1, uuid1);
	nr.rename_or_insert(name2, uuid1);
	std::string found_name = nr.find_name(uuid1);

	EXPECT_EQ(found_name, name2);
}

TEST(am_NameRegistrarTest, ReplaceUuid)
{
	am_NameRegistrar nr;

	amUuid uuid1;
	amUuid uuid2;

	std::string name1 = "name1";

	nr.insert(name1, uuid1);
	nr.rename_or_insert(name1, uuid2);
	amUuid found_uuid = nr.find_uuid(name1);

	EXPECT_EQ(found_uuid, uuid2);
}

TEST(am_NameRegistrarTest, ThrowExceptionOnDuplicateNameInsert)
{
	am_NameRegistrar nr;

	amUuid uuid1;
	amUuid uuid2;

	std::string name1 = "name1";

	nr.insert(name1, uuid1);

	EXPECT_THROW(nr.insert(name1, uuid2), invalid_name_insert_error);
}

TEST(am_NameRegistrarTest, ThrowExceptionOnDuplicateUuidInsert)
{
	am_NameRegistrar nr;

	amUuid uuid1;

	std::string name1 = "name1";
	std::string name2 = "name2";

	nr.insert(name1, uuid1);

	EXPECT_THROW(nr.insert(name2, uuid1), invalid_name_insert_error);
}