//CAN发送及接收结构体
#include<inttypes.h>
typedef int FunctionalState;
typedef struct
{
  uint32_t StdId;    /* 存储报文的标准标识符 11 位，0-0x7FF. */
  uint32_t ExtId;    /* 存储报文的扩展标识符 29 位，0-0x1FFFFFFF. */
  uint32_t IDE;     /* 存储 IDE 扩展标志 */
  uint32_t RTR;    /* 存储 RTR 远程帧标志 */
  uint32_t DLC;     /* 存储报文数据段的长度，0-8 */
  FunctionalState TransmitGlobalTime; 
} CAN_TxHeaderTypeDef;
typedef struct
{
  uint32_t StdId;    /* 存储报文的标准标识符 11 位，0-0x7FF. */
  uint32_t ExtId;    /* 存储报文的扩展标识符 29 位，0-0x1FFFFFFF. */
  uint32_t IDE;     /* 存储 IDE 扩展标志 */
  uint32_t RTR;      /* 存储 RTR 远程帧标志 */
  uint32_t DLC;     /* 存储报文数据段的长度，0-8 */
  uint32_t Timestamp; 
  uint32_t FilterMatchIndex; 
} CAN_RxHeaderTypeDef;