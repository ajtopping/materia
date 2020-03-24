#pragma once

/// <summary>
/// A singleton that uniquely maps one UUID to another UUID.
/// </summary>
/// <remarks>
/// This will become obsolete very quickly.
/// </remarks>

#include <unordered_map>
#include <rpc.h>

class am_S_UniqueUuidAssociator
{
public:
	am_S_UniqueUuidAssociator(am_S_UniqueUuidAssociator const&) = delete;
	void operator=(am_S_UniqueUuidAssociator const&) = delete;

	static am_S_UniqueUuidAssociator * get_instance();
	void insert(UUID, UUID);
	UUID find(UUID);
private:
	am_S_UniqueUuidAssociator() {};

	std::unordered_map<UUID, UUID> dictionary_;

	static am_S_UniqueUuidAssociator * instance_;
};