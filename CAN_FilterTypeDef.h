
//CAN筛选器结构体
#include<inttypes.h>
typedef struct
{
  uint32_t FilterIdHigh;         /*CAN_FxR1 寄存器的高 16 位 */
  uint32_t FilterIdLow;         /*CAN_FxR1 寄存器的低 16 位 */
  uint32_t FilterMaskIdHigh;   /*CAN_FxR2 寄存器的高 16 位 */
  uint32_t FilterMaskIdLow;    /*CAN_FxR2 寄存器的低 16 位 */
  uint32_t FilterFIFOAssignment;  /* 设置经过筛选后数据存储到哪个接收 FIFO */
  uint32_t FilterBank;            /* 筛选器编号，范围 0-27，数据手册上说0-27是CAN1/CAN2共享，但是实测发现并不是这样，CAN1是0-13，CAN2是14-27 */
  uint32_t FilterMode;            /* 筛选器模式 */
  uint32_t FilterScale;           /* 设置筛选器的尺度 */
  uint32_t FilterActivation;      /* 是否使能本筛选器 */
  uint32_t SlaveStartFilterBank;  
} CAN_FilterTypeDef;
