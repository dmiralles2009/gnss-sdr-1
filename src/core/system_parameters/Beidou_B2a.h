/*!
 * \file BEIDOU_B2a.h
 * \brief  Defines system parameters for Beidou B2a signal and CNAV2 data
 * \note Code added as part of GSoC 2018 program
 * \author Dong Kyeong Lee, 2018. dole7890(at)colorado.edu
 * \see <a href="http://m.beidou.gov.cn/xt/gfxz/201712/P020171226742357364174.pdf">beidou ICD</a>
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2015  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */


#ifndef GNSS_SDR_BEIDOU_B2a_H_
#define GNSS_SDR_BEIDOU_B2a_H_

#include "MATH_CONSTANTS.h"
#include "gnss_frequencies.h"
#include <cstdint>
#include <map>
#include <string>
#include <utility>
#include <vector>


const double BEIDOU_B2a_FREQ_HZ = FREQ5;                      //!< BEIDOU B2a carrier frequency [Hz]
const double BEIDOU_B2a_CODE_RATE_HZ = 10.23e6;               //!< BEIDOU B2a code rate [chips/s]
const double BEIDOU_B2a_CODE_LENGTH_CHIPS = 10230;            //!< BEIDOU B2a C/A code length [chips]
const double BEIDOU_B2a_CODE_PERIOD = 0.001;                  //!< BEIDOU B2a C/A code period [seconds]
const double BEIDOU_B2a_CHIP_PERIOD = 9.775171065493646e-08;  //!< BEIDOU B2a C/A chip period [seconds]
const double BEIDOU_B2a_SYMBOL_RATE_SPS = 200;                //BEIDOU symbol rate

const int32_t BEIDOU_NBR_SATS = 63;      // Total number of satellites
const double BEIDOU_LEAP_SECONDS = -33;  // uniform scale and 33 seconds behind TAI. However, this should be in the broadcast message

const std::string BEIDOU_CNAV2_PREAMBLE = {"111000100100110111101000"};
const double BEIDOU_CNAV2_PREAMBLE_DURATION_S = 0.120;    //[s]
const int32_t BEIDOU_CNAV2_PREAMBLE_LENGTH_BITS = 24;     //[bits]
const int32_t BEIDOU_CNAV2_PREAMBLE_LENGTH_SYMBOLS = 24;  //[symbols]

const int32_t BEIDOU_CNAV2_PREAMBLE_PERIOD_SYMBOLS = 600;
const int32_t BEIDOU_CNAV2_TELEMETRY_RATE_BITS_SECOND = 100;                                                                                  //bps
const int32_t BEIDOU_CNAV2_TELEMETRY_SYMBOLS_PER_BIT = 2;                                                                                     //spb
const int32_t BEIDOU_CNAV2_TELEMETRY_SYMBOLS_PER_PREAMBLE_BIT = 5;                                                                            //spb
const int32_t BEIDOU_CNAV2_TELEMETRY_RATE_SYMBOLS_SECOND = BEIDOU_CNAV2_TELEMETRY_RATE_BITS_SECOND * BEIDOU_CNAV2_TELEMETRY_SYMBOLS_PER_BIT;  //sps
const int32_t BEIDOU_CNAV2_FRAME_SYMBOLS = 600;                                                                                               //Number of symbols per string in the CNAV2 message
const int32_t BEIDOU_CNAV2_DATA_BITS = 288;
const int32_t BEIDOU_CNAV2_DATA_BYTES = 36;        //Number of bits per string in the CNAV2 message
const int32_t BEIDOU_CNAV2_MESSAGE_SYMBOLS = 576;  //STRING DATA WITHOUT PREAMBLE
const int32_t BEIDOU_CNAV2_CODES_PER_SYMBOLS = 5;

const int32_t BEIDOU_CNAV2_CRC_BITS = 24;
const int32_t BEIDOU_CNAV2_CRC_SEED = 0;
const int32_t BEIDOU_CNAV2_CRC_POLY = 0x1864CFB;

//!< carrier and code frequencies
const int32_t BEIDOU_B2a_CNAV_DATA_PAGE_BITS = 300;
const int32_t BEIDOU_B2a_SYMBOLS_PER_BIT = 1;
const int32_t BEIDOU_B2a_SAMPLES_PER_SYMBOL = 5;
const int32_t BEIDOU_B2a_CNAV_DATA_PAGE_SYMBOLS = 600;
const int32_t BEIDOU_B2a_HISTORY_DEEP = 5;

const double BEIDOU_B2ad_CODE_RATE_HZ = 10.23e6;      //!< BEIDOU_B2a data code rate [chips/s]
const int32_t BEIDOU_B2ad_CODE_LENGTH_CHIPS = 10230;  //!< BEIDOU_B2a data  code length [chips]
const double BEIDOU_B2ad_PERIOD = 0.001;              //!< BEIDOU_B2a data code period [seconds]
const int32_t BEIDOU_B2ad_PERIOD_MS = 1;

const double BEIDOU_B2ap_CODE_RATE_HZ = 10.23e6;      //!< BEIDOU_B2a pilot code rate [chips/s]
const int32_t BEIDOU_B2ap_CODE_LENGTH_CHIPS = 10230;  //!< BEIDOU_B2a pilot code length [chips]
const double BEIDOU_B2ap_PERIOD = 0.001;              //!< BEIDOU_B2a pilot code period [seconds]

//!<Beidou secondary codes. Data component has a fixed sequence as secondary code which are the same for every satellite
const int32_t BEIDOU_B2ad_SECONDARY_CODE_LENGTH = 5;  // Each bit is 1 ms (one primary code sequence)
const std::string BEIDOU_B2ad_SECONDARY_CODE = "00010";

//!<TODO Beidou pilot code is a Weil code which is currently not implemented
//!<Beidou secondary codes. Pilot component has a truncated Weill sequence, each satellite has it's own code
const int32_t BEIDOU_B2ap_SECONDARY_CODE_LENGTH = 100;  //B2a code is 100 chips long; Each bit is 1 ms (one primary code sequence)
const std::string BEIDOU_B2ap_SECONDARY_CODE = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";


//!<Initialization registers for the primary codes for B2a data signal
const int8_t BEIDOU_B2ad_INIT_REG[63][13] =
    {
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0},
        {1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0},
        {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1},
        {1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1},
        {1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0},
        {1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
        {1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
        {1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0},
        {1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0},


};

const int8_t BEIDOU_B2ap_INIT_REG[63][13] =
    {
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0},
        {1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0},
        {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1},
        {1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1},
        {1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0},
        {1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
        {1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
        {1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0},
        {1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
};

// BEIDOU CNAV2 NAVIGATION MESSAGE STRUCTURE
// NAVIGATION MESSAGE FIELDS POSITIONS

// CRC
const std::vector<std::pair<int32_t, int32_t>> CRC24({{264, 24}});

// Common
const std::vector<std::pair<int32_t, int32_t>> PRN({{1, 6}});
const std::vector<std::pair<int32_t, int32_t>> MesType({{7, 6}});
const std::vector<std::pair<int32_t, int32_t>> SOW({{13, 18}});
const std::vector<std::pair<int32_t, int32_t>> CRC({{265, 24}});

// Type 10 (288 bits)
const std::vector<std::pair<int32_t, int32_t>> WN_10({{31, 13}});
const std::vector<std::pair<int32_t, int32_t>> DIF_10({{44, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_10({{45, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_10({{46, 1}});
const std::vector<std::pair<int32_t, int32_t>> SISMAI_10({{47, 4}});
const std::vector<std::pair<int32_t, int32_t>> DIF_B1C_10({{51, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_B1C_10({{52, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_B1C_10({{53, 1}});
const std::vector<std::pair<int32_t, int32_t>> IODE_10({{54, 8}});
// Ephemeris I (203 bits)
const std::vector<std::pair<int32_t, int32_t>> t_oe_10({{62, 11}});
const std::vector<std::pair<int32_t, int32_t>> SatType_10({{73, 2}});
const std::vector<std::pair<int32_t, int32_t>> dA_10({{75, 26}});
const std::vector<std::pair<int32_t, int32_t>> A_dot_10({{101, 25}});
const std::vector<std::pair<int32_t, int32_t>> dn_0_10({{126, 17}});
const std::vector<std::pair<int32_t, int32_t>> dn_0_dot_10({{143, 23}});
const std::vector<std::pair<int32_t, int32_t>> M_0_10({{166, 33}});
const std::vector<std::pair<int32_t, int32_t>> e_10({{199, 33}});
const std::vector<std::pair<int32_t, int32_t>> omega_10({{232, 33}});
// Ephemeris I End

// Type 11 (288 bits)
const std::vector<std::pair<int32_t, int32_t>> HS_11({{31, 2}});
const std::vector<std::pair<int32_t, int32_t>> DIF_11({{33, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_11({{34, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_11({{35, 1}});
const std::vector<std::pair<int32_t, int32_t>> SISMAI_11({{36, 4}});
const std::vector<std::pair<int32_t, int32_t>> DIF_B1C_11({{40, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_B1C_11({{41, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_B1C_11({{42, 1}});
// Ephemeris II (222 bits)
const std::vector<std::pair<int32_t, int32_t>> Omega_0_11({{43, 33}});
const std::vector<std::pair<int32_t, int32_t>> i_0_11({{76, 33}});
const std::vector<std::pair<int32_t, int32_t>> Omega_dot_11({{109, 19}});
const std::vector<std::pair<int32_t, int32_t>> i_0_dot_11({{128, 15}});
const std::vector<std::pair<int32_t, int32_t>> C_IS_11({{143, 16}});
const std::vector<std::pair<int32_t, int32_t>> C_IC_11({{159, 16}});
const std::vector<std::pair<int32_t, int32_t>> C_RS_11({{175, 24}});
const std::vector<std::pair<int32_t, int32_t>> C_RC_11({{199, 24}});
const std::vector<std::pair<int32_t, int32_t>> C_US_11({{223, 21}});
const std::vector<std::pair<int32_t, int32_t>> C_UC_11({{244, 21}});
// Ephemeris II End


// Type 30 (288 bits)
const std::vector<std::pair<int32_t, int32_t>> HS_30({{31, 2}});
const std::vector<std::pair<int32_t, int32_t>> DIF_30({{33, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_30({{34, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_30({{35, 1}});
const std::vector<std::pair<int32_t, int32_t>> SISMAI_30({{36, 4}});
const std::vector<std::pair<int32_t, int32_t>> DIF_B1C_30({{40, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_B1C_30({{41, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_B1C_30({{42, 1}});
// Clock Correction Parameters (69 bits)
const std::vector<std::pair<int32_t, int32_t>> t_oc_30({{43, 11}});
const std::vector<std::pair<int32_t, int32_t>> a_0_30({{54, 25}});
const std::vector<std::pair<int32_t, int32_t>> a_1_30({{79, 22}});
const std::vector<std::pair<int32_t, int32_t>> a_2_30({{101, 11}});
// Clock Correction Parameters End
const std::vector<std::pair<int32_t, int32_t>> IODC_30({{112, 10}});
const std::vector<std::pair<int32_t, int32_t>> T_GDB2ap_30({{122, 12}});
const std::vector<std::pair<int32_t, int32_t>> ISC_B2ad_30({{134, 12}});
// Ionospheric Delay Correction Model Parameters (74 bits)
const std::vector<std::pair<int32_t, int32_t>> alpha_1_30({{146, 10}});
const std::vector<std::pair<int32_t, int32_t>> alpha_2_30({{156, 8}});
const std::vector<std::pair<int32_t, int32_t>> alpha_3_30({{164, 8}});
const std::vector<std::pair<int32_t, int32_t>> alpha_4_30({{172, 8}});
const std::vector<std::pair<int32_t, int32_t>> alpha_5_30({{180, 8}});
const std::vector<std::pair<int32_t, int32_t>> alpha_6_30({{188, 8}});
const std::vector<std::pair<int32_t, int32_t>> alpha_7_30({{196, 8}});
const std::vector<std::pair<int32_t, int32_t>> alpha_8_30({{204, 8}});
const std::vector<std::pair<int32_t, int32_t>> alpha_9_30({{212, 8}});
// Ionospheric Delay Correction Model Parameters End
const std::vector<std::pair<int32_t, int32_t>> T_GDB1Cp_30({{220, 12}});
const std::vector<std::pair<int32_t, int32_t>> Rev_30({{232, 33}});


// Type 31 (288 bits)
const std::vector<std::pair<int32_t, int32_t>> HS_31({{31, 2}});
const std::vector<std::pair<int32_t, int32_t>> DIF_31({{33, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_31({{34, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_31({{35, 1}});
const std::vector<std::pair<int32_t, int32_t>> SISMAI_31({{36, 4}});
const std::vector<std::pair<int32_t, int32_t>> DIF_B1C_31({{40, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_B1C_31({{41, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_B1C_31({{42, 1}});
// Clock Correction Parameters (69 bits)
const std::vector<std::pair<int32_t, int32_t>> t_oc_31({{43, 11}});
const std::vector<std::pair<int32_t, int32_t>> a_0_31({{54, 25}});
const std::vector<std::pair<int32_t, int32_t>> a_1_31({{79, 22}});
const std::vector<std::pair<int32_t, int32_t>> a_2_31({{101, 11}});
// Clock Correction Parameters End
const std::vector<std::pair<int32_t, int32_t>> IODC_31({{112, 10}});
const std::vector<std::pair<int32_t, int32_t>> WN_a_31({{122, 13}});
const std::vector<std::pair<int32_t, int32_t>> t_oa_31({{135, 8}});
// Reduced Almanac Parameters Sat 1(38 bits)
const std::vector<std::pair<int32_t, int32_t>> PRN_a1_31({{143, 6}});
const std::vector<std::pair<int32_t, int32_t>> SatType1_31({{149, 2}});
const std::vector<std::pair<int32_t, int32_t>> delta_A1_31({{151, 8}});
const std::vector<std::pair<int32_t, int32_t>> Omega_01_31({{159, 7}});
const std::vector<std::pair<int32_t, int32_t>> Phi_01_31({{166, 7}});
const std::vector<std::pair<int32_t, int32_t>> Health1_31({{173, 8}});
// Reduced Almanac Parameters End
// Reduced Almanac Parameters Sat 2(38 bits)
const std::vector<std::pair<int32_t, int32_t>> PRN_a2_31({{181, 6}});
const std::vector<std::pair<int32_t, int32_t>> SatType2_31({{187, 2}});
const std::vector<std::pair<int32_t, int32_t>> delta_A2_31({{189, 8}});
const std::vector<std::pair<int32_t, int32_t>> Omega_02_31({{197, 7}});
const std::vector<std::pair<int32_t, int32_t>> Phi_02_31({{204, 7}});
const std::vector<std::pair<int32_t, int32_t>> Health2_31({{211, 8}});
// Reduced Almanac Parameters End
// Reduced Almanac Parameters Sat 3(38 bits)
const std::vector<std::pair<int32_t, int32_t>> PRN_a3_31({{219, 6}});
const std::vector<std::pair<int32_t, int32_t>> SatType3_31({{225, 2}});
const std::vector<std::pair<int32_t, int32_t>> delta_A3_31({{227, 8}});
const std::vector<std::pair<int32_t, int32_t>> Omega_03_31({{235, 7}});
const std::vector<std::pair<int32_t, int32_t>> Phi_03_31({{242, 7}});
const std::vector<std::pair<int32_t, int32_t>> Health3_31({{249, 8}});
// Reduced Almanac Parameters End
const std::vector<std::pair<int32_t, int32_t>> Rev_31({{257, 8}});


// Type 32 (288 bits)
const std::vector<std::pair<int32_t, int32_t>> HS_32({{31, 2}});
const std::vector<std::pair<int32_t, int32_t>> DIF_32({{33, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_32({{34, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_32({{35, 1}});
const std::vector<std::pair<int32_t, int32_t>> SISMAI_32({{36, 4}});
const std::vector<std::pair<int32_t, int32_t>> DIF_B1C_32({{40, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_B1C_32({{41, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_B1C_32({{42, 1}});
// Clock Correction Parameters (69 bits)
const std::vector<std::pair<int32_t, int32_t>> t_oc_32({{43, 11}});
const std::vector<std::pair<int32_t, int32_t>> a_0_32({{54, 25}});
const std::vector<std::pair<int32_t, int32_t>> a_1_32({{79, 22}});
const std::vector<std::pair<int32_t, int32_t>> a_2_32({{101, 11}});
// Clock Correction Parameters End
const std::vector<std::pair<int32_t, int32_t>> IODC_32({{112, 10}});
// EOP Parameters (138 bits)
const std::vector<std::pair<int32_t, int32_t>> t_EOP_32({{122, 16}});
const std::vector<std::pair<int32_t, int32_t>> PM_X_32({{138, 21}});
const std::vector<std::pair<int32_t, int32_t>> PM_X_dot_32({{159, 15}});
const std::vector<std::pair<int32_t, int32_t>> PM_Y_32({{174, 21}});
const std::vector<std::pair<int32_t, int32_t>> PM_Y_dot_32({{195, 15}});
const std::vector<std::pair<int32_t, int32_t>> dUT1_32({{210, 31}});
const std::vector<std::pair<int32_t, int32_t>> dUT1_dot_32({{241, 19}});
// EOP Parameters End
const std::vector<std::pair<int32_t, int32_t>> Rev_32({{260, 5}});


// Type 33 (288 bits)
const std::vector<std::pair<int32_t, int32_t>> HS_33({{31, 2}});
const std::vector<std::pair<int32_t, int32_t>> DIF_33({{33, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_33({{34, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_33({{35, 1}});
const std::vector<std::pair<int32_t, int32_t>> SISMAI_33({{36, 4}});
const std::vector<std::pair<int32_t, int32_t>> DIF_B1C_33({{40, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_B1C_33({{41, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_B1C_33({{42, 1}});
// Clock Correction Parameters (69 bits)
const std::vector<std::pair<int32_t, int32_t>> t_oc_33({{43, 11}});
const std::vector<std::pair<int32_t, int32_t>> a_0_33({{54, 25}});
const std::vector<std::pair<int32_t, int32_t>> a_1_33({{79, 22}});
const std::vector<std::pair<int32_t, int32_t>> a_2_33({{101, 11}});
// Clock Correction Parameters End
// BGTO Parameters (68 bits)
const std::vector<std::pair<int32_t, int32_t>> GNSS_ID_33({{112, 3}});
const std::vector<std::pair<int32_t, int32_t>> WN_0BGTO_33({{115, 13}});
const std::vector<std::pair<int32_t, int32_t>> t_0BGTO_33({{128, 16}});
const std::vector<std::pair<int32_t, int32_t>> A_0BGTO_33({{144, 16}});
const std::vector<std::pair<int32_t, int32_t>> A_1BGTO_33({{160, 13}});
const std::vector<std::pair<int32_t, int32_t>> A_2BGTO_33({{173, 7}});
// BGTO Parameters End
// Reduced Almanac Parameters (38 bits)
const std::vector<std::pair<int32_t, int32_t>> PRN_ALM_33({{180, 6}});
const std::vector<std::pair<int32_t, int32_t>> SatType_33({{186, 2}});
const std::vector<std::pair<int32_t, int32_t>> delta_A_33({{188, 8}});
const std::vector<std::pair<int32_t, int32_t>> Omega_0_33({{196, 7}});
const std::vector<std::pair<int32_t, int32_t>> Phi_0_33({{203, 7}});
const std::vector<std::pair<int32_t, int32_t>> Health_33({{210, 8}});
// Reduced Almanac Parameters End
const std::vector<std::pair<int32_t, int32_t>> IODC_33({{218, 10}});
const std::vector<std::pair<int32_t, int32_t>> WN_ALM_33({{228, 13}});
const std::vector<std::pair<int32_t, int32_t>> t_oa_33({{241, 8}});
const std::vector<std::pair<int32_t, int32_t>> Rev_33({{249, 16}});


// Type 34 (288 bits)
const std::vector<std::pair<int32_t, int32_t>> HS_34({{31, 2}});
const std::vector<std::pair<int32_t, int32_t>> DIF_34({{33, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_34({{34, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_34({{35, 1}});
const std::vector<std::pair<int32_t, int32_t>> SISMAI_34({{36, 4}});
const std::vector<std::pair<int32_t, int32_t>> DIF_B1C_34({{40, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_B1C_34({{41, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_B1C_34({{42, 1}});
// SISAI_OC (22 bits)
const std::vector<std::pair<int32_t, int32_t>> t_op_34({{43, 11}});
const std::vector<std::pair<int32_t, int32_t>> SISAI_ocb_34({{54, 5}});
const std::vector<std::pair<int32_t, int32_t>> SISAI_oc1_34({{59, 3}});
const std::vector<std::pair<int32_t, int32_t>> SISAI_oc2_34({{62, 3}});
// SISAI_OC End
// Clock Correction Parameters (69 bits)
const std::vector<std::pair<int32_t, int32_t>> t_oc_34({{65, 11}});
const std::vector<std::pair<int32_t, int32_t>> a_0_34({{76, 25}});
const std::vector<std::pair<int32_t, int32_t>> a_1_34({{101, 22}});
const std::vector<std::pair<int32_t, int32_t>> a_2_34({{123, 11}});
// Clock Correction Parameters End
const std::vector<std::pair<int32_t, int32_t>> IODC_34({{134, 10}});
// BDT-UTC Time Offset Parameters (97 bits)
const std::vector<std::pair<int32_t, int32_t>> A_0UTC_34({{144, 16}});
const std::vector<std::pair<int32_t, int32_t>> A_1UTC_34({{160, 13}});
const std::vector<std::pair<int32_t, int32_t>> A_2UTC_34({{173, 7}});
const std::vector<std::pair<int32_t, int32_t>> dt_LS_34({{180, 8}});
const std::vector<std::pair<int32_t, int32_t>> t_ot_34({{188, 16}});
const std::vector<std::pair<int32_t, int32_t>> WN_ot_34({{204, 13}});
const std::vector<std::pair<int32_t, int32_t>> WN_LSF_34({{217, 13}});
const std::vector<std::pair<int32_t, int32_t>> DN_34({{230, 3}});
const std::vector<std::pair<int32_t, int32_t>> dt_LSF_34({{233, 8}});
// BDT-UTC Time Offset Parameters End
const std::vector<std::pair<int32_t, int32_t>> Rev_34({{241, 24}});


// Type 40 (288 bits)
const std::vector<std::pair<int32_t, int32_t>> HS_40({{31, 2}});
const std::vector<std::pair<int32_t, int32_t>> DIF_40({{33, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_40({{34, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_40({{35, 1}});
const std::vector<std::pair<int32_t, int32_t>> SISMAI_40({{36, 4}});
const std::vector<std::pair<int32_t, int32_t>> DIF_B1C_40({{40, 1}});
const std::vector<std::pair<int32_t, int32_t>> SIF_B1C_40({{41, 1}});
const std::vector<std::pair<int32_t, int32_t>> AIF_B1C_40({{42, 1}});
const std::vector<std::pair<int32_t, int32_t>> SISAI_OE_40({{43, 5}});
// SISAI_OC (22 bits)
const std::vector<std::pair<int32_t, int32_t>> t_op_40({{48, 11}});
const std::vector<std::pair<int32_t, int32_t>> SISAI_ocb_40({{59, 5}});
const std::vector<std::pair<int32_t, int32_t>> SISAI_oc1_40({{64, 3}});
const std::vector<std::pair<int32_t, int32_t>> SISAI_oc2_40({{67, 3}});
// SISAI_OC End
// Midi Almanac Parameters (156 bits)
const std::vector<std::pair<int32_t, int32_t>> PRN_a_40({{70, 6}});
const std::vector<std::pair<int32_t, int32_t>> SatType_40({{76, 2}});
const std::vector<std::pair<int32_t, int32_t>> WN_a_40({{78, 13}});
const std::vector<std::pair<int32_t, int32_t>> t_oa_40({{91, 8}});
const std::vector<std::pair<int32_t, int32_t>> e_40({{99, 11}});
const std::vector<std::pair<int32_t, int32_t>> delta_i_40({{110, 11}});
const std::vector<std::pair<int32_t, int32_t>> sqrt_A_40({{121, 17}});
const std::vector<std::pair<int32_t, int32_t>> Omega_0_40({{138, 16}});
const std::vector<std::pair<int32_t, int32_t>> Omega_dot_40({{154, 11}});
const std::vector<std::pair<int32_t, int32_t>> omega_40({{165, 16}});
const std::vector<std::pair<int32_t, int32_t>> M_0_40({{181, 16}});
const std::vector<std::pair<int32_t, int32_t>> a_f0_40({{197, 11}});
const std::vector<std::pair<int32_t, int32_t>> a_f1_40({{208, 10}});
const std::vector<std::pair<int32_t, int32_t>> Health_40({{218, 8}});
// Midi Almanac Parameters End
const std::vector<std::pair<int32_t, int32_t>> Rev_40({{226, 39}});


#endif /* GNSS_SDR_BEIDOU_B2a_H_ */
