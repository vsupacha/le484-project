#include "cmd.h"

typedef enum {
  IDLE_STATE,
  BUFFERING_STATE
} Command_State_t;

Command_State_t Command_State = IDLE_STATE;

char Buffer[10];
int Buffer_Idx = 0;

void Cmd_Handler(uint8_t ch)
{
  switch(Command_State) {
    case IDLE_STATE:
      // ! or ? to change state
      if ((ch == '!') || (ch == '?')) {
        Command_State = BUFFERING_STATE; 
        Buffer_Idx = 0;
        Buffer[Buffer_Idx++] = ch;
      }
      break;
    case BUFFERING_STATE:
      // character or numeric -> buffer
      if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= '0') && (ch <= '9')) || (ch == '-') || (ch == ' ')) {
        Buffer[Buffer_Idx++] = ch;
      } else if (ch == '\n') {    // '\n' -> parse command
        Buffer[Buffer_Idx] = 0;
        Cmd_Parse(Buffer);
        Command_State = IDLE_STATE; 
      } else {
        Command_State = IDLE_STATE;   
      }   
      break;
    default:
      Command_State = IDLE_STATE; 
  }      
}


void Cmd_Parse(const char *Buffer)
{
  int position_value; 
  if (sscanf(Buffer, "!POS %d", &position_value) > 0) {
    Position_Target = position_value;  
  } else {
      
  }
}
