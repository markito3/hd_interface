// $Id$
//
//    File: DSCHit_factory.h
// Created: Tue Aug  6 12:53:32 EDT 2013
// Creator: davidl (on Darwin harriet.jlab.org 11.4.2 i386)
//

#ifndef _DSCHit_factory_
#define _DSCHit_factory_

#include <JANA/JFactory.h>
#include <DANA/DApplication.h>
#include <HDGEOMETRY/DGeometry.h>
#include <TTAB/DTTabUtilities.h>
#include "START_COUNTER/DSCHit.h"
#include "START_COUNTER/DSCDigiHit.h"


class DSCHit_factory:public jana::JFactory<DSCHit>{
	public:
		DSCHit_factory(){};
		~DSCHit_factory(){};

		// overall scale factors
		double a_scale;
		double t_scale;
        double t_base;
		double t_tdc_base;

		// calibration constants stored by channel
		vector<double>  a_gains;
		vector<double>  a_pedestals;
		vector<double>  adc_time_offsets;
		vector<double>  tdc_time_offsets;
		vector<vector<double> >timewalk_parameters;

		//map<string,double>  propogation_corr_factors;
		//double<string,double>  attenuation_corr_factors;
		
		double DELTA_T_ADC_TDC_MAX;
		double HIT_TIME_WINDOW;
		double ADC_THRESHOLD;
        double USE_TIMEWALK_CORRECTION;
        int MAX_SECTORS;

		DSCHit* FindMatch(vector<DSCHit*>&schits,int sector, double T);

		const double GetConstant(const vector<double>  &the_table,
					 const int in_sector) const;
		const double GetConstant(const vector<double>  &the_table,
					 const DSCDigiHit *the_digihit) const;
		const double GetConstant(const vector<double>  &the_table,
					 const DSCHit *the_hit) const;
		//const double GetConstant(const vector<double>  &the_table,
		//			 const DTranslationTable *ttab,
		//			 const int in_rocid, const int in_slot, const int in_channel) const;

	private:
		jerror_t init(void);						///< Called once at program start.
		jerror_t brun(jana::JEventLoop *eventLoop, int32_t runnumber);	///< Called everytime a new run number is detected.
		jerror_t evnt(jana::JEventLoop *eventLoop, uint64_t eventnumber);	///< Called every event.
		jerror_t erun(void);						///< Called everytime run number changes, provided brun has been called.
		jerror_t fini(void);						///< Called after last event of last event source has been processed.

        bool CHECK_FADC_ERRORS;
	bool REQUIRE_ADC_TDC_MATCH;
};

#endif // _DSCHit_factory_

