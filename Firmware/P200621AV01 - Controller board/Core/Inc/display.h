/*
 * display.h
 *
 *  Created on: 19 sep. 2020
 *      Author: Admin
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_



extern uint8_t nextion_uart_transmit(uint8_t* buffer);
extern uint8_t nextion_uart_receive(uint8_t* buffer, uint8_t buffSize);

uint8_t nextion_setText(const char* id, const char* val);
char* temp2string(float val);
uint8_t nextion_getPage(void);
uint8_t nextion_setPage(uint8_t pageNr);
uint8_t nextion_add2wave(uint8_t id, uint8_t ch, float val);
uint8_t nextionWakeup(void);

#endif /* INC_DISPLAY_H_ */






