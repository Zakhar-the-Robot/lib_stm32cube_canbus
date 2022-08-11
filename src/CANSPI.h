// Based on https://github.com/eziya/STM32_SPI_MCP2515
// Copyright (c) 2022 Andrei Gramakov. All rights reserved.

#ifndef __CAN_SPI_H
#define	__CAN_SPI_H

#include <stdio.h>
#include <stdbool.h>
#include "qcan.h"

#define dSTANDARD_CAN_MSG_ID_2_0B 1
#define dEXTENDED_CAN_MSG_ID_2_0B 2

bool CANSPI_Initialize(void);
void CANSPI_Sleep(void);
uint8_t CANSPI_Transmit(uCAN_MSG *tempCanMsg);
uint8_t CANSPI_Receive(uCAN_MSG *tempCanMsg);
uint8_t CANSPI_messagesInBuffer(void);
uint8_t CANSPI_isBussOff(void);
uint8_t CANSPI_isRxErrorPassive(void);
uint8_t CANSPI_isTxErrorPassive(void);

#endif	/* __CAN_SPI_H */
