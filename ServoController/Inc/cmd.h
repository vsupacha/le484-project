#ifndef _CMD_H
#define _CMD_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stm32f4xx.h>
#include <stdio.h>
#include "main.h"


void Cmd_Handler(uint8_t ch);
void Cmd_Parse(const char *Buffer);    
    
#ifdef __cplusplus
}
#endif

#endif // _CMD_H
