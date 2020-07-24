#include "compManager.h"

template <class T>
amUuid compMananger<T>::NewComponent()
{
	amUuid new_uuid;
	tmap_.insert(new_uuid, new T);

	return new_uuid;
}

template <class T>
bool compMananger<T>::DeleteComponent( amUuid uuid_to_free )
{
	T * tptr = tmap_.find(uuid_to_free);

	if (tptr == nullptr)
	{
		return false;
	}

	delete tptr;
	tmap_.remove(uuid_to_free);

	return true;
}