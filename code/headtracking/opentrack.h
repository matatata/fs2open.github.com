
#ifndef HEADTRACKING_OPENTRACK_H
#define HEADTRACKING_OPENTRACK_H

#ifdef HAVE_OPENTRACKCLIENT_LIBRARY


#include "headtracking/headtracking.h"
#include "headtracking/headtracking_internal.h"


#define OTR_REQUIRED 1

#include "opentrackclient/opentrackclient.h"


namespace headtracking
{
	namespace opentrack
	{
		class OpenTrackProvider : public internal::HeadTrackingProvider
		{
		private:
			
		public:
			OpenTrackProvider();

			virtual ~OpenTrackProvider();

			bool query(HeadTrackingStatus* statusOut) override;

			static SCP_string getName();
		};
	}
}



#endif // HAVE_OPENTRACKCLIENT_LIBRARY

#endif // HEADTRACKING_OPENTRACK_H
