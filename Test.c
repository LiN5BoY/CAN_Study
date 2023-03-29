#include "CAN_FilterTypeDef.h"
#include "CAN_InitTypeDef.h"
#include "CAN_RxHeaderTypeDef.h"

//宏定义
#define ENABLE 1
#define DISABLE 2
//筛选器工作模式——掩码模式
#define CAN_FILTERMODE_IDMASK 1
//筛选器工作模式——列表模式
#define CAN_FILTERMODE_IDLIST 0
//筛选器尺度——32位长
#define CAN_FILTERSCALE_32BIT 1
//筛选器尺度——16位长
#define CAN_FILTERSCALE_16BIT 0
//存储到的FIFO——FIFO0
#define CAN_FILTER_FIFO0 1
//存储到的FIFO——FIFO1
#define CAN_FILTER_FIFO1 0

int hcan1 = 1;
#define BSP_CAN_OK 1
//设置Filter过滤，我们只使能FIFO0，并且不过滤任何消息
uint8_t bsp_can1_filter_config(void)
{
    CAN_FilterTypeDef filter = {0};
    filter.FilterActivation = ENABLE;
    filter.FilterMode = CAN_FILTERMODE_IDMASK;
    filter.FilterScale = CAN_FILTERSCALE_32BIT;
    filter.FilterBank = 0;
    filter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    filter.FilterIdLow = 0;
    filter.FilterIdHigh = 0;
    filter.FilterMaskIdLow = 0;
    filter.FilterMaskIdHigh = 0;
    //过滤
    HAL_CAN_ConfigFilter(&hcan1, &filter);
    return BSP_CAN_OK;
}

int CAN_RTR_DATA = 1;
//编写发送函数
uint8_t bsp_can1_send_msg(uint32_t id_type,uint32_t basic_id,uint32_t ex_id,uint8_t *data,uint32_t data_len)
{
   
    //data_len要发送的数据长度
    uint8_t index = 0;
    uint32_t *msg_box;
	uint8_t send_buf[8] = {0};
    CAN_TxHeaderTypeDef send_msg_hdr;
    //basic_id标准帧ID(在标准帧中有效)
    send_msg_hdr.StdId = basic_id;
    //ex_id扩展帧ID(在扩展帧中有效)
    send_msg_hdr.ExtId = ex_id;
     //id_type是扩展帧还是标准帧
    send_msg_hdr.IDE = id_type;
    ///* 存储 RTR 远程帧标志 */
    send_msg_hdr.RTR = CAN_RTR_DATA;
    send_msg_hdr.DLC = data_len;
	send_msg_hdr.TransmitGlobalTime = DISABLE;
	for(index = 0; index < data_len; index++)
        //data要发送的数据
        send_buf[index] = data[index];
 
    HAL_CAN_AddTxMessage(&hcan1,&send_msg_hdr,send_buf,msg_box);
    return BSP_CAN_OK;
}