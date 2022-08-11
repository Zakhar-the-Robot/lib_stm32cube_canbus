// *************************************************************************
//
// Copyright (c) 2022 Andrei Gramakov. All rights reserved.
//
// site:    https://agramakov.me
// e-mail:  mail@agramakov.me
//
// *************************************************************************

#include "qcan.h"
#include "CANSPI.h"
#include "FreeRTOS.h"
#include "registers.h"
#include "task.h"

static uint8_t device_id = 0;

static void taskPresence() {
    uCAN_MSG txMessage;
    txMessage.frame.idType = 0;
    txMessage.frame.id     = device_id << 8;
    txMessage.frame.dlc    = 3;
    txMessage.frame.data0  = 0;
    txMessage.frame.data1  = 2;
    txMessage.frame.data2  = 0;
    txMessage.frame.data3  = 0;
    txMessage.frame.data4  = 0;
    txMessage.frame.data5  = 0;
    txMessage.frame.data6  = 0;
    txMessage.frame.data7  = 0;
    while (1) {
        qcan_transmit(&txMessage);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


uint8_t qcan_transmit(uCAN_MSG *tempCanMsg){
    return CANSPI_Transmit(tempCanMsg);
}

bool qcan_start(uint8_t device_address) {
    device_id = device_address;
    if (device_id > 7){
        return false;
    }
    CANSPI_Initialize();
    xTaskCreate(taskPresence, "qCanPresence", 1024, NULL, 5, NULL);
    return true;
}
