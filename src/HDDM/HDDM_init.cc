#include <JANA/JEventLoop.h>
using namespace jana;

#include "HDDM/DEventWriterREST_factory.h"
#include "HDDM/DEventWriterHDDM_factory.h"
#include "HDDM/DEventHitStatistics_factory.h"

jerror_t HDDM_init(JEventLoop *loop)
{
	/// Create and register HDDM data factories
    loop->AddFactory(new DEventWriterREST_factory());
	loop->AddFactory(new DEventWriterHDDM_factory());
	loop->AddFactory(new DEventHitStatistics_factory());

	return NOERROR;
}


