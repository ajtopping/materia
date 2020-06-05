#include "iMouseDragOperationsHandler.h"

opMouseDragTransform * iMouseDragOperationsHandler::find_operation_from_screen_coordinates(int cartesian_x_coordinate, int cartesian_y_coordinate)
{
	auto rectangles = rectangleSpace_ref_.find_rectangles_containing_point(cartesian_x_coordinate, cartesian_y_coordinate);
	if (rectangles.empty())
	{
		fprintf(stdout, "No ssRectangle was clicked!");
		return nullptr;
	}
	else
	{
		int num_rectangles = 0;
		for (auto it = rectangles.begin(); it != rectangles.end(); it++)
		{
			num_rectangles++;
			amUuid rectangle_uuid = it->get_uuid();
			fprintf(stdout, "Clicked on ssRectangle:%llX\n", rectangle_uuid.get_data());

			amUuid composition_uuid = am_S_UniqueUuidAssociator::get_instance()->find(rectangle_uuid);
			if (composition_uuid.isNil())
			{
				fprintf(stdout, "    but found no associated entComposition...");
				return nullptr;
			}
			else
			{
				fprintf(stdout, "    and found an associated entComposition:%llX\n", composition_uuid.get_data());
				return operations_ref_.find(composition_uuid);
			}
		}

		return nullptr;
	}
}