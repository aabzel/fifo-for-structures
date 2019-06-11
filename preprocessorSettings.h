/**
* @file  preprocessorSettings.h
* @brief
*
* That macros allow us to deploy separately all parts of firmware if needed.
*
* @author  Alexander Barunin
*
* @date  April 2019.
*/

#ifndef PREPROCCESSOR_SETUPS_H
#define PREPROCCESSOR_SETUPS_H

#define DEPLOY_UNIT_TESTS 1
#define DEPLOY_SELF_TESTS 0
#define DEPLOY_HEARTBEAT_TASK 1
#define DEPLOY_ERASE_MEMMAN_FLASH 0

#define TEST_RETX_FSM 0
#define DEPLOY_FIFO_NODE_TEST 1
#define DEPLOY_FIFO_NODE 1

#define DEPLOY_HW_TIMERS_UNIT_TESTS 1
#define DEPLOY_TEST_DLMS_STACK 1

#define DEPLOY_WPSU_TEST 1

#define DEPLOY_UART6_DMA 0
#define DEPLOY_UNIT_TEST_LPSH2 0

#define DEBUG_TIM3 0
#define DEBUG_TIM4 0


#endif /* PREPROCCESSOR_SETUPS_H */
