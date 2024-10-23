/*
 * Inic.h
 *
 *  Created on: 23 oct. 2024
 *      Author: Pablo Pierabella
 */

#ifndef INIC_H_
#define INIC_H_



#define LED_ROJO_OFF PTE->PSOR |= 1<<29;
#define LED_ROJO_ON PTE->PCOR |= 1<<29;
#define LED_ROJO_T PTE->PTOR |= 1<<29;

#define LED_VERDE_OFF PTD->PSOR |= 1<<5;
#define LED_VERDE_ON PTD->PCOR |= 1<<5;
#define LED_VERDE_T PTD->PTOR |= 1<<5;

#define SW1 !(PTC->PDIR & (1<<3))
#define SW3 !(PTC->PDIR & (1<<12))



void inicializa(){
	/*--------------LED verde-----------------*/
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	PORTD->PCR[5] |= PORT_PCR_MUX(1);
	PTD->PCOR |= 1<<5;
	PTD->PDDR |= 1<<5;

	/*--------------LED rojo------------------*/
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	PORTE->PCR[29] |= PORT_PCR_MUX(1);
	PTE->PCOR |= 1<<29;
	PTE->PDDR |= 1<<29;

	/*-------------SW1--------------*/
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	PORTC->PCR[3] |=PORT_PCR_MUX(1);
	PTC->PDDR &= ~(1<<3);
	PORTC->PCR[3] |= 0x3;

	/*-------------SW3--------------*/
	//Ya se dio clock al puerto C en la configuración de SW1
	PORTC->PCR[12] |= PORT_PCR_MUX(1);
	PTC->PDDR &= ~(1<<12);
	PORTC->PCR[12] |= 0x3;
}







#endif /* INIC_H_ */
