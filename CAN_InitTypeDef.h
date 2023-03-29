//CAN初始化
#include<inttypes.h>
typedef int FunctionalState;
typedef struct
{
  uint32_t Prescaler;  /* 配置 CAN 外设的时钟分频，可设置为 1-1024*/
  uint32_t Mode;       /* 配置 CAN 的工作模式，回环或正常模式 */
  uint32_t SyncJumpWidth;  /* 配置 SJW 极限值 */
  uint32_t TimeSeg1;   /* 配置 BS1 段长度 */
  uint32_t TimeSeg2;   /* 配置 BS2 段长度 */
  FunctionalState TimeTriggeredMode;   /* 是否使能 TTCM 时间触发功能 */
  FunctionalState AutoBusOff;     /* 是否使能 ABOM 自动离线管理功能 */
  FunctionalState AutoWakeUp;   /* 是否使能 AWUM 自动唤醒功能 */
  FunctionalState AutoRetransmission;  /* 是否使能 NART 自动重传功能 */
  FunctionalState ReceiveFifoLocked;   /* 是否使能 RFLM 锁定 FIFO 功能 */
  FunctionalState TransmitFifoPriority;/* 配置 TXFP 报文优先级的判定方法 */
} CAN_InitTypeDef;