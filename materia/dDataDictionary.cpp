#include "dDataDictionary.h"

dDataDictionary * dDataDictionary::instance_ = nullptr;

dDataDictionary * dDataDictionary::get_instance()
{
	if (!instance_)
	{
		instance_ = new dDataDictionary();
	}
	return instance_;
}

void dDataDictionary::add_datablock(std::string datablock_name, dDataBlock * datablock_ptr)
{
	this->data_dictionary_.insert_or_assign(datablock_name, datablock_ptr);
}

dDataBlock * dDataDictionary::get_datablock(std::string datablock_name)
{
	try
	{
		return this->data_dictionary_.at(datablock_name);
	}
	catch ( std::exception e )
	{
		fprintf(stdout, "Could not find a datablock named '%s' in the dDataDictionary! Returning nullptr...\n", datablock_name.c_str());
		return nullptr;
	}
}