#ifdef HAVE_OPENTRACKCLIENT_LIBRARY

#include "headtracking/opentrack.h"


namespace headtracking
{
	namespace opentrack
	{

		OpenTrackProvider::OpenTrackProvider()
		{
			// Try to get initial test data
			OTRHeadpose data;
			
			if (!OTRGetData(&data))
			{
				throw internal::HeadTrackingException("Failed to get test data set!");
			}

			mprintf(("Got opentrackclient version %s (%s)\n",OTRGetVersion(),OTRGetProvider()));
		}

		OpenTrackProvider::~OpenTrackProvider()
		{
		}

		bool OpenTrackProvider::query(HeadTrackingStatus* statusOut)
		{
			OTRHeadpose data;
			if(!OTRGetData(&data))
			{
				return false;
			}

			// Angles are in radians
			statusOut->pitch = data.Pitch / PI;
			statusOut->yaw = data.Yaw / PI;
			statusOut->roll = data.Roll / PI;

			// Coordinates are in millimeters
			statusOut->x = data.X / 1000.0f;
			statusOut->y = data.Y / 1000.0f;
			statusOut->z = data.Z / 1000.0f;

			return true;
		}

		SCP_string OpenTrackProvider::getName()
		{
			return "OpenTrack";
		}
	}
}

#endif // HAVE_OPENTRACKCLIENT_LIBRARY