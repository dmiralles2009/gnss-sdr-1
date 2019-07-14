/*!
 * \file beidou_b1c_signal_processing_new.h
 * \brief This class implements signal generators for the BeiDou B1c signals
 * \author Andrew Kamble, 2019. andrewkamble88@gmail.com 
 * \note Code added as part of GSoC 2019 program
 * Detailed description of the file here if needed.
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2019 (see AUTHORS file for a list of contributors)
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
 * along with GNSS-SDR. If not, see <https://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */


#ifndef GNSS_SDR_BEIDOU_B1C_SIGNAL_PROCESSING_H_
#define GNSS_SDR_BEIDOU_B1C_SIGNAL_PROCESSING_H_

#include <complex>
#include <cstdint>

#if HAS_SPAN
#include <span>
namespace gsl = std;
#else
#include "gsl/gsl"
#endif

//! Generates BeiDou B1c Data Primary codes for the desired SV ID
void make_b1cd(gsl::span<int32_t> _dest, int32_t prn);


//! Generate a float version of the B1C Data Primary code
void beidou_b1cd_code_gen_float(gsl::span<float> _dest, uint32_t _prn);


//! Generate a complex version of the B1C Data Primary code
void beidou_b1cd_code_gen_complex(gsl::span<std::complex<float>> _dest, uint32_t _prn);


//! Generates complex BEIDOU B1C Data Primary code for the desired SV ID and sampled to specific sampling frequency
void beidou_b1cd_code_gen_complex_sampled(gsl::span<std::complex<float>> _dest, uint32_t _prn, int32_t _fs);


//! Generate the B1C Pilot Primary code
void make_b1cp(gsl::span<int32_t> _dest, int32_t prn);


//! Generate a float version of the B1C Pilot Primary code
void beidou_b1cp_code_gen_float(gsl::span<float> _dest, uint32_t _prn);


//! Generate a complex version of the B1C Pilot Primary code
void beidou_b1cp_code_gen_complex(gsl::span<std::complex<float>> _dest, uint32_t _prn);


//! Generates complex BEIDOU B1C Primary pilot code for the desired SV ID and sampled to specific sampling frequency
void beidou_b1cp_code_gen_complex_sampled(gsl::span<std::complex<float>> _dest, uint32_t _prn, int32_t _fs);


//! Generate a version of the B1C Pilot code with the secondary pilot code included
void make_b1cp_secondary(gsl::span<int32_t> _dest, int32_t prn);


//! Generate a complex version of the B1C pilot code with the secondary pilot code
void beidou_b1cp_code_gen_complex_secondary(gsl::span<std::complex<float>> _dest, uint32_t _prn);


//! Generates a float version of the B1C pilot primary code
void beidou_b1cp_code_gen_float_secondary(gsl::span<float> _dest, uint32_t _prn);


//! Generates complex BEIDOU B1C pilot code for the desired SV ID and sampled to specific sampling frequency with the secondary code implemented
void beidou_b1cp_code_gen_complex_sampled_secondary(gsl::span<std::complex<float>> _dest, uint32_t _prn, int32_t _fs);


//! Generates complex BEIDOU B1C data+pilot code for the desired SV ID and sampled to specific sampling frequency
void beidou_b1c_code_gen_complex_sampled(gsl::span<std::complex<float>> _dest, uint32_t _prn, int32_t _fs);



#endif /* GNSS_SDR_BEIDOU_B1C_SIGNAL_PROCESSING_H_ */