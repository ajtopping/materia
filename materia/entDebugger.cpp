
#include "entDebugger.h"

void entDebugger::debug_uuid(entComposition * ent)
{
	amUuid uuid = ent->get_uuid();
	fprintf(stdout, "entComposition:%llX\n", uuid.get_data());
}