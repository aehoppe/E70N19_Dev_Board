/**
 * \file
 *
 * \brief SAM EFC
 *
 * Copyright (C) 2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 */

#ifdef _SAME70_EFC_COMPONENT_
#ifndef _HRI_EFC_E70_H_INCLUDED_
#define _HRI_EFC_E70_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_EFC_CRITICAL_SECTIONS)
#define EFC_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define EFC_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define EFC_CRITICAL_SECTION_ENTER()
#define EFC_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_efc_eefc_fcr_reg_t;
typedef uint32_t hri_efc_eefc_fmr_reg_t;
typedef uint32_t hri_efc_eefc_frr_reg_t;
typedef uint32_t hri_efc_eefc_fsr_reg_t;
typedef uint32_t hri_efc_eefc_wpmr_reg_t;

static inline void hri_efc_write_EEFC_FCR_reg(const void *const hw, hri_efc_eefc_fcr_reg_t data)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FCR = data;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_set_EEFC_FMR_FRDY_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR |= EEFC_FMR_FRDY;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_efc_get_EEFC_FMR_FRDY_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_FMR;
	tmp = (tmp & EEFC_FMR_FRDY) >> EEFC_FMR_FRDY_Pos;
	return (bool)tmp;
}

static inline void hri_efc_write_EEFC_FMR_FRDY_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	EFC_CRITICAL_SECTION_ENTER();
	tmp = ((Efc *)hw)->EEFC_FMR;
	tmp &= ~EEFC_FMR_FRDY;
	tmp |= value << EEFC_FMR_FRDY_Pos;
	((Efc *)hw)->EEFC_FMR = tmp;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_clear_EEFC_FMR_FRDY_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR &= ~EEFC_FMR_FRDY;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_toggle_EEFC_FMR_FRDY_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR ^= EEFC_FMR_FRDY;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_set_EEFC_FMR_SCOD_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR |= EEFC_FMR_SCOD;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_efc_get_EEFC_FMR_SCOD_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_FMR;
	tmp = (tmp & EEFC_FMR_SCOD) >> EEFC_FMR_SCOD_Pos;
	return (bool)tmp;
}

static inline void hri_efc_write_EEFC_FMR_SCOD_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	EFC_CRITICAL_SECTION_ENTER();
	tmp = ((Efc *)hw)->EEFC_FMR;
	tmp &= ~EEFC_FMR_SCOD;
	tmp |= value << EEFC_FMR_SCOD_Pos;
	((Efc *)hw)->EEFC_FMR = tmp;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_clear_EEFC_FMR_SCOD_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR &= ~EEFC_FMR_SCOD;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_toggle_EEFC_FMR_SCOD_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR ^= EEFC_FMR_SCOD;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_set_EEFC_FMR_CLOE_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR |= EEFC_FMR_CLOE;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_efc_get_EEFC_FMR_CLOE_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_FMR;
	tmp = (tmp & EEFC_FMR_CLOE) >> EEFC_FMR_CLOE_Pos;
	return (bool)tmp;
}

static inline void hri_efc_write_EEFC_FMR_CLOE_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	EFC_CRITICAL_SECTION_ENTER();
	tmp = ((Efc *)hw)->EEFC_FMR;
	tmp &= ~EEFC_FMR_CLOE;
	tmp |= value << EEFC_FMR_CLOE_Pos;
	((Efc *)hw)->EEFC_FMR = tmp;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_clear_EEFC_FMR_CLOE_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR &= ~EEFC_FMR_CLOE;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_toggle_EEFC_FMR_CLOE_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR ^= EEFC_FMR_CLOE;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_set_EEFC_FMR_FWS_bf(const void *const hw, hri_efc_eefc_fmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR |= EEFC_FMR_FWS(mask);
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline hri_efc_eefc_fmr_reg_t hri_efc_get_EEFC_FMR_FWS_bf(const void *const hw, hri_efc_eefc_fmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_FMR;
	tmp = (tmp & EEFC_FMR_FWS(mask)) >> EEFC_FMR_FWS_Pos;
	return tmp;
}

static inline void hri_efc_write_EEFC_FMR_FWS_bf(const void *const hw, hri_efc_eefc_fmr_reg_t data)
{
	uint32_t tmp;
	EFC_CRITICAL_SECTION_ENTER();
	tmp = ((Efc *)hw)->EEFC_FMR;
	tmp &= ~EEFC_FMR_FWS_Msk;
	tmp |= EEFC_FMR_FWS(data);
	((Efc *)hw)->EEFC_FMR = tmp;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_clear_EEFC_FMR_FWS_bf(const void *const hw, hri_efc_eefc_fmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR &= ~EEFC_FMR_FWS(mask);
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_toggle_EEFC_FMR_FWS_bf(const void *const hw, hri_efc_eefc_fmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR ^= EEFC_FMR_FWS(mask);
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline hri_efc_eefc_fmr_reg_t hri_efc_read_EEFC_FMR_FWS_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_FMR;
	tmp = (tmp & EEFC_FMR_FWS_Msk) >> EEFC_FMR_FWS_Pos;
	return tmp;
}

static inline void hri_efc_set_EEFC_FMR_reg(const void *const hw, hri_efc_eefc_fmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR |= mask;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline hri_efc_eefc_fmr_reg_t hri_efc_get_EEFC_FMR_reg(const void *const hw, hri_efc_eefc_fmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_FMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_efc_write_EEFC_FMR_reg(const void *const hw, hri_efc_eefc_fmr_reg_t data)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR = data;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_clear_EEFC_FMR_reg(const void *const hw, hri_efc_eefc_fmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR &= ~mask;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_toggle_EEFC_FMR_reg(const void *const hw, hri_efc_eefc_fmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_FMR ^= mask;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline hri_efc_eefc_fmr_reg_t hri_efc_read_EEFC_FMR_reg(const void *const hw)
{
	return ((Efc *)hw)->EEFC_FMR;
}

static inline void hri_efc_set_EEFC_WPMR_WPEN_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_WPMR |= EEFC_WPMR_WPEN;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_efc_get_EEFC_WPMR_WPEN_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_WPMR;
	tmp = (tmp & EEFC_WPMR_WPEN) >> EEFC_WPMR_WPEN_Pos;
	return (bool)tmp;
}

static inline void hri_efc_write_EEFC_WPMR_WPEN_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	EFC_CRITICAL_SECTION_ENTER();
	tmp = ((Efc *)hw)->EEFC_WPMR;
	tmp &= ~EEFC_WPMR_WPEN;
	tmp |= value << EEFC_WPMR_WPEN_Pos;
	((Efc *)hw)->EEFC_WPMR = tmp;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_clear_EEFC_WPMR_WPEN_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_WPMR &= ~EEFC_WPMR_WPEN;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_toggle_EEFC_WPMR_WPEN_bit(const void *const hw)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_WPMR ^= EEFC_WPMR_WPEN;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_set_EEFC_WPMR_WPKEY_bf(const void *const hw, hri_efc_eefc_wpmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_WPMR |= EEFC_WPMR_WPKEY(mask);
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline hri_efc_eefc_wpmr_reg_t hri_efc_get_EEFC_WPMR_WPKEY_bf(const void *const hw, hri_efc_eefc_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_WPMR;
	tmp = (tmp & EEFC_WPMR_WPKEY(mask)) >> EEFC_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_efc_write_EEFC_WPMR_WPKEY_bf(const void *const hw, hri_efc_eefc_wpmr_reg_t data)
{
	uint32_t tmp;
	EFC_CRITICAL_SECTION_ENTER();
	tmp = ((Efc *)hw)->EEFC_WPMR;
	tmp &= ~EEFC_WPMR_WPKEY_Msk;
	tmp |= EEFC_WPMR_WPKEY(data);
	((Efc *)hw)->EEFC_WPMR = tmp;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_clear_EEFC_WPMR_WPKEY_bf(const void *const hw, hri_efc_eefc_wpmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_WPMR &= ~EEFC_WPMR_WPKEY(mask);
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_toggle_EEFC_WPMR_WPKEY_bf(const void *const hw, hri_efc_eefc_wpmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_WPMR ^= EEFC_WPMR_WPKEY(mask);
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline hri_efc_eefc_wpmr_reg_t hri_efc_read_EEFC_WPMR_WPKEY_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_WPMR;
	tmp = (tmp & EEFC_WPMR_WPKEY_Msk) >> EEFC_WPMR_WPKEY_Pos;
	return tmp;
}

static inline void hri_efc_set_EEFC_WPMR_reg(const void *const hw, hri_efc_eefc_wpmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_WPMR |= mask;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline hri_efc_eefc_wpmr_reg_t hri_efc_get_EEFC_WPMR_reg(const void *const hw, hri_efc_eefc_wpmr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_WPMR;
	tmp &= mask;
	return tmp;
}

static inline void hri_efc_write_EEFC_WPMR_reg(const void *const hw, hri_efc_eefc_wpmr_reg_t data)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_WPMR = data;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_clear_EEFC_WPMR_reg(const void *const hw, hri_efc_eefc_wpmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_WPMR &= ~mask;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_efc_toggle_EEFC_WPMR_reg(const void *const hw, hri_efc_eefc_wpmr_reg_t mask)
{
	EFC_CRITICAL_SECTION_ENTER();
	((Efc *)hw)->EEFC_WPMR ^= mask;
	EFC_CRITICAL_SECTION_LEAVE();
}

static inline hri_efc_eefc_wpmr_reg_t hri_efc_read_EEFC_WPMR_reg(const void *const hw)
{
	return ((Efc *)hw)->EEFC_WPMR;
}

static inline bool hri_efc_get_EEFC_FSR_FRDY_bit(const void *const hw)
{
	return (((Efc *)hw)->EEFC_FSR & EEFC_FSR_FRDY) > 0;
}

static inline bool hri_efc_get_EEFC_FSR_FCMDE_bit(const void *const hw)
{
	return (((Efc *)hw)->EEFC_FSR & EEFC_FSR_FCMDE) > 0;
}

static inline bool hri_efc_get_EEFC_FSR_FLOCKE_bit(const void *const hw)
{
	return (((Efc *)hw)->EEFC_FSR & EEFC_FSR_FLOCKE) > 0;
}

static inline bool hri_efc_get_EEFC_FSR_FLERR_bit(const void *const hw)
{
	return (((Efc *)hw)->EEFC_FSR & EEFC_FSR_FLERR) > 0;
}

static inline bool hri_efc_get_EEFC_FSR_UECCELSB_bit(const void *const hw)
{
	return (((Efc *)hw)->EEFC_FSR & EEFC_FSR_UECCELSB) > 0;
}

static inline bool hri_efc_get_EEFC_FSR_MECCELSB_bit(const void *const hw)
{
	return (((Efc *)hw)->EEFC_FSR & EEFC_FSR_MECCELSB) > 0;
}

static inline bool hri_efc_get_EEFC_FSR_UECCEMSB_bit(const void *const hw)
{
	return (((Efc *)hw)->EEFC_FSR & EEFC_FSR_UECCEMSB) > 0;
}

static inline bool hri_efc_get_EEFC_FSR_MECCEMSB_bit(const void *const hw)
{
	return (((Efc *)hw)->EEFC_FSR & EEFC_FSR_MECCEMSB) > 0;
}

static inline hri_efc_eefc_fsr_reg_t hri_efc_get_EEFC_FSR_reg(const void *const hw, hri_efc_eefc_fsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_FSR;
	tmp &= mask;
	return tmp;
}

static inline hri_efc_eefc_fsr_reg_t hri_efc_read_EEFC_FSR_reg(const void *const hw)
{
	return ((Efc *)hw)->EEFC_FSR;
}

static inline hri_efc_eefc_frr_reg_t hri_efc_get_EEFC_FRR_FVALUE_bf(const void *const hw, hri_efc_eefc_frr_reg_t mask)
{
	return (((Efc *)hw)->EEFC_FRR & EEFC_FRR_FVALUE(mask)) >> EEFC_FRR_FVALUE_Pos;
}

static inline hri_efc_eefc_frr_reg_t hri_efc_read_EEFC_FRR_FVALUE_bf(const void *const hw)
{
	return (((Efc *)hw)->EEFC_FRR & EEFC_FRR_FVALUE_Msk) >> EEFC_FRR_FVALUE_Pos;
}

static inline hri_efc_eefc_frr_reg_t hri_efc_get_EEFC_FRR_reg(const void *const hw, hri_efc_eefc_frr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Efc *)hw)->EEFC_FRR;
	tmp &= mask;
	return tmp;
}

static inline hri_efc_eefc_frr_reg_t hri_efc_read_EEFC_FRR_reg(const void *const hw)
{
	return ((Efc *)hw)->EEFC_FRR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_EFC_E70_H_INCLUDED */
#endif /* _SAME70_EFC_COMPONENT_ */
