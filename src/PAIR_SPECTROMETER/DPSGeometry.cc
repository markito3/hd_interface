#include <stdlib.h>
#include <iostream>
#include <map>

#include <JANA/JApplication.h>
#include <JANA/JEvent.h>
#include "PAIR_SPECTROMETER/DPSGeometry.h"

//---------------------------------
// DPSGeometry    (Constructor)
//---------------------------------
DPSGeometry::DPSGeometry(JEventLoop *loop)
{
    // read PS hodoscope counter energy bounds from calibdb
    std::vector<std::map<string,double> > result;
    loop->GetCalib("/PHOTON_BEAM/pair_spectrometer/fine/energy_range", result);
    if ((int)result.size() != NUM_FINE_COLUMNS) {
        jerr << "Error in DPSGeometry constructor: "
        << "failed to read fine PS energy_range table "
        << "from calibdb at /PHOTON_BEAM/pair_spectrometer/fine/energy_range" << std::endl;
        for (int arm=0; arm < NUM_ARMS; ++arm) {
            for (int i=0; i < NUM_FINE_COLUMNS; ++i) {
                m_energy_low[arm][i] = 0;
                m_energy_high[arm][i] = 0;
            }
        }
    }
    else {
        for (unsigned int i=0; i < result.size(); ++i) {
            m_energy_low[0][i] = (result[i])["Elow_north"];
            m_energy_high[0][i] = (result[i])["Ehigh_north"];
            m_energy_low[1][i] = (result[i])["Elow_south"];
            m_energy_high[1][i] = (result[i])["Ehigh_south"];
        }
    }
}

DPSGeometry::~DPSGeometry() { }

double DPSGeometry::getElow(int arm,int column) const
{
    if (arm >=0 && arm <=1 && column > 0 && column <= NUM_FINE_COLUMNS)
        return m_energy_low[arm][column-1];
    else
        return 0;
}

double DPSGeometry::getEhigh(int arm,int column) const
{
    if (arm >=0 && arm <=1 && column > 0 && column <= NUM_FINE_COLUMNS)
        return m_energy_high[arm][column-1];
    else
        return 0;
}
