#include "board.h"


typedef enum
{
	TEMP_CHN,
	HUM_CHN
}CHN;


extern void app_init(void);
extern void app_task(void);
extern UINT8 APP_comCallBack( UINT8 *rxPacket, UINT8* txCode, UINT8** txPacket);

#define CMD_GET_STATUS (0X80)
#define CMD_SET_LIMIT  (0X81)
#define CMD_GET_LIMIT  (0X82)

