/*
 * File:   cadc_stm32f4.h
 * Author: eLimones <limonesu.me@gmail.com>
 *
 * Created on December 5, 2015, 5:36 PM
 */

#ifndef CADC_STM32F4_H
#define	CADC_STM32F4_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

	void cadc_init(void);
	uint16_t cadc_getDataInjected1(void);


#ifdef	__cplusplus
}
#endif

#endif	/* CADC_STM32F4_H */

