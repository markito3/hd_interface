// $Id$

#include <JANA/JEventLoop.h>
using namespace jana;

#include "DAQ/DBeamCurrent_factory.h"
#include "DAQ/Df250Config.h"
#include "DAQ/Df250PulseIntegral.h"
#include "DAQ/Df250StreamingRawData.h"
#include "DAQ/Df250WindowSum.h"
#include "DAQ/Df250PulseRawData.h"
#include "DAQ/Df250TriggerTime.h"
#include "DAQ/Df250PulseTime.h"
#include "DAQ/Df250PulsePedestal.h"
#include "DAQ/Df250PulseData.h"
#include "DAQ/Df250WindowRawData.h"
#include "DAQ/Df125Config.h"
#include "DAQ/Df125TriggerTime.h"
#include "DAQ/Df125PulseIntegral.h"
#include "DAQ/Df125PulseTime.h"
#include "DAQ/Df125PulsePedestal.h"
#include "DAQ/Df125PulseRawData.h"
#include "DAQ/Df125WindowRawData.h"
#include "DAQ/Df125CDCPulse.h"
#include "DAQ/Df125FDCPulse.h"
#include "DAQ/DF1TDCConfig.h"
#include "DAQ/DF1TDCHit.h"
#include "DAQ/DF1TDCTriggerTime.h"
#include "DAQ/DCAEN1290TDCConfig.h"
#include "DAQ/DCAEN1290TDCHit.h"
#include "DAQ/DCODAEventInfo.h"
#include "DAQ/DCODAControlEvent.h"
#include "DAQ/DCODAROCInfo.h"
#include "DAQ/DTSscalers.h"
#include "DAQ/DEPICSvalue.h"
#include "DAQ/DEventTag.h"
#include "DAQ/Df250BORConfig.h"
#include "DAQ/Df125BORConfig.h"
#include "DAQ/DF1TDCBORConfig.h"
#include "DAQ/DCAEN1290TDCBORConfig.h"
#include "DAQ/DTSGBORConfig.h"
#include "DAQ/DL1Info.h"
#include "DAQ/Df250Scaler.h"
#include "DAQ/Df250AsyncPedestal.h"
#include "DAQ/DDIRCTriggerTime.h"
#include "DAQ/DDIRCTDCHit.h"
#include "DAQ/DDIRCADCHit.h"
#include "DAQ/DGEMSRSWindowRawData.h"
#include "DAQ/Df125EmulatorAlgorithm_factory.h"
#include "DAQ/Df125EmulatorAlgorithm_factory_v2.h"
#include "DAQ/Df250EmulatorAlgorithm_factory.h"
#include "DAQ/Df250EmulatorAlgorithm_factory_v1.h"
#include "DAQ/Df250EmulatorAlgorithm_factory_v2.h"
#include "DAQ/Df250EmulatorAlgorithm_factory_v3.h"

jerror_t DAQ_init(JEventLoop *loop)
{
	/// Create and register DTranslationTable factory
	loop->AddFactory(new DBeamCurrent_factory());
	loop->AddFactory(new JFactory<Df250Config>());
	loop->AddFactory(new JFactory<Df250PulseIntegral>());
	loop->AddFactory(new JFactory<Df250StreamingRawData>());
	loop->AddFactory(new JFactory<Df250WindowSum>());
	loop->AddFactory(new JFactory<Df250PulseRawData>());
	loop->AddFactory(new JFactory<Df250TriggerTime>());
	loop->AddFactory(new JFactory<Df250PulseTime>());
	loop->AddFactory(new JFactory<Df250PulsePedestal>());
	loop->AddFactory(new JFactory<Df250PulseData>());
	loop->AddFactory(new JFactory<Df250WindowRawData>());
	loop->AddFactory(new JFactory<Df125Config>());
	loop->AddFactory(new JFactory<Df125TriggerTime>());
	loop->AddFactory(new JFactory<Df125PulseIntegral>());
	loop->AddFactory(new JFactory<Df125PulseTime>());
	loop->AddFactory(new JFactory<Df125PulsePedestal>());
	loop->AddFactory(new JFactory<Df125PulseRawData>());
	loop->AddFactory(new JFactory<Df125WindowRawData>());
	loop->AddFactory(new JFactory<Df125CDCPulse>());
	loop->AddFactory(new JFactory<Df125FDCPulse>());
	loop->AddFactory(new JFactory<DF1TDCHit>());
	loop->AddFactory(new JFactory<DF1TDCConfig>());
	loop->AddFactory(new JFactory<DF1TDCTriggerTime>());
	loop->AddFactory(new JFactory<DCAEN1290TDCConfig>());
	loop->AddFactory(new JFactory<DCAEN1290TDCHit>());
	loop->AddFactory(new JFactory<DCODAEventInfo>());
	loop->AddFactory(new JFactory<DCODAControlEvent>());
	loop->AddFactory(new JFactory<DCODAROCInfo>());
	loop->AddFactory(new JFactory<DTSscalers>());
	loop->AddFactory(new JFactory<DEPICSvalue>());
	loop->AddFactory(new JFactory<DEventTag>());
	loop->AddFactory(new JFactory<Df250BORConfig>());
	loop->AddFactory(new JFactory<Df125BORConfig>());
	loop->AddFactory(new JFactory<DF1TDCBORConfig>());
	loop->AddFactory(new JFactory<DCAEN1290TDCBORConfig>());
	loop->AddFactory(new JFactory<DTSGBORConfig>());
	loop->AddFactory(new JFactory<DL1Info>());
	loop->AddFactory(new JFactory<Df250Scaler>());
	loop->AddFactory(new JFactory<Df250AsyncPedestal>());
	loop->AddFactory(new JFactory<DDIRCTriggerTime>());
	loop->AddFactory(new JFactory<DDIRCTDCHit>());
	loop->AddFactory(new JFactory<DDIRCADCHit>());
	loop->AddFactory(new JFactory<DGEMSRSWindowRawData>());
	loop->AddFactory(new Df125EmulatorAlgorithm_factory());
	loop->AddFactory(new Df125EmulatorAlgorithm_factory_v2());
	loop->AddFactory(new Df250EmulatorAlgorithm_factory());
	loop->AddFactory(new Df250EmulatorAlgorithm_factory_v1()); 
	loop->AddFactory(new Df250EmulatorAlgorithm_factory_v2()); 
	loop->AddFactory(new Df250EmulatorAlgorithm_factory_v3()); 
	return NOERROR;
}