/**
 * @file unit_test.h
 * @brief
 *
 *
 *
 *
 * @author Aleksandr Barunin
 *
 * @date Feb 2019.
 */

#ifndef _UNIT_TEST_H
#define _UNIT_TEST_H

#include "preprocessorSettings.h"

#include <stdint.h>


enum unit_test {
    UT_OK = 0,
    UT_CLOCK_ERROR = 1,
    UT_PARSER_ERROR = 2,
    UT_MATH_ERROR = 3,
    UT_2_BYTE_ENDIAN_ERROR = 4,
    UT_4_BYTE_ENDIAN_ERROR = 5,
    UT_FLASH_ERROR = 6,
    UT_CHANNEL_PARSER_ERROR = 7,
    UT_CHANNEL_FRAME_DATA_ERROR = 8,
    UT_CHANNEL_FRAME_ERROR = 9,
    UT_UART1_DMA_TX_ERROR = 10,
    UT_UART2_DMA_TX_ERROR = 11,
    UT_UART3_DMA_TX_ERROR = 12,
    UT_UART6_DMA_TX_ERROR = 13,
    UT_NO_SWK92_ACK_ERROR = 14,
    UT_RX_ERROR = 15,
    UT_TX_ERROR = 16,
    UT_SYSTICK_ERROR = 17,
    UT_TIM5_ERROR = 18,
    UT_RETX_FSM_ACK_ERROR = 19,
    UT_RETX_FSM_RETRY_ERROR = 20,
    UT_SKW92B_200MS_TIM_ERROR = 21,
    UT_TIM4_ERROR = 22,
    UT_ADC_ERROR = 23,
    UT_DSP_ERROR = 24,
    UT_TYPES_ERROR = 25,
    UT_QUEUE_ERROR = 26,
    UT_HEAP_ERROR = 27,
    UT_TX_SKW_UART_ERROR = 28,
    UT_TX_DEBUG_UART_ERROR = 29,
    UT_TX_LPSH_UART_ERROR = 30,
    UT_PARSE_IPV4_ERROR = 31,
    UT_IMPLEMENTATION_DEFINED_ERROR = 32,
    UT_CONST_CHANGE_ERROR = 33,
    UT_STACK_ADDR_ERROR,
    UT_WDPU_DATA_ERROR = 35,
    UT_WDPU_DATA1_ERROR,
    UT_WDPU_VER_ERROR,
    UT_WDPU_SRC_ERROR,
    UT_WDPU_DST_ERROR,
    UT_WDPU_LEN_ERROR = 40,
    UT_DLMS_LACK_ANSWER_ERROR,
    UT_QUEUE16_ERROR,
    UT_QUEUE15_ERROR,
    UT_QUEUE14_ERROR,
    UT_QUEUE13_ERROR,
    UT_QUEUE12_ERROR,
    UT_QUEUE11_ERROR,

    UT_QUEUE2B_ERROR,
    UT_QUEUE2A_ERROR,
    UT_QUEUE29_ERROR = 50,
    UT_QUEUE28_ERROR,
    UT_QUEUE27_ERROR,
    UT_QUEUE26_ERROR,
    UT_QUEUE25_ERROR,
    UT_QUEUE24_ERROR,
    UT_QUEUE23_ERROR,
    UT_QUEUE22_ERROR,
    UT_QUEUE21_ERROR,
    UT_QUEUE35_ERROR,
    UT_QUEUE34_ERROR = 60,
    UT_QUEUE33_ERROR,
    UT_QUEUE32_ERROR = 62,
    UT_QUEUE31_ERROR,
    UT_DLMS_TCP_ROLE_LACK_ANSWER1_ERROR,
    UT_DLMS_TCP_ROLE_LACK_ANSWER2_ERROR,

    UT_MEMORY_MANAGER_GET4_1ERROR,
    UT_MEMORY_MANAGER_GET4_2ERROR,
    UT_MEMORY_MANAGER_GET4_3ERROR,
    UT_MEMORY_MANAGER_GET4_4ERROR,

    UT_MEMORY_MANAGER_SET8_1_ERROR = 70,
    UT_MEMORY_MANAGER_UPDATE1_ERROR,
    UT_MEMORY_MANAGER_UPDATE2_ERROR,

    UT_MEMORY_MANAGER_ERROR,
    UT_MEMORY_MANAGER_SET1_ERROR,
    UT_MEMORY_MANAGER_GET1_ERROR,
    UT_MEMORY_MANAGER_SET2_ERROR,
    UT_MEMORY_MANAGER_GET2_ERROR,
    UT_MEMORY_MANAGER_SET4_ERROR,
    UT_MEMORY_MANAGER_GET4_ERROR,
    UT_MEMORY_MANAGER_SET8_ERROR = 80,
    UT_MEMORY_MANAGER_GET8_ERROR,
    UT_MEMORY_MANAGER_NOT_FOUND_ERROR,
    UT_MEMORY_MANAGER_RETURN_LEN_ERROR,
    UT_MEMORY_MANAGER_RET_LEN_ERROR,
    UT_MEM_MANG_STRING_STORE1_ERROR,
    UT_MEM_MANG_STRING_STORE2_ERROR,
    UT_MEM_MANG_STRING_STORE3_ERROR,
    UT_MEM_MANG_STRING_STORE4_ERROR,

    UT_MEMORY_MANAGER_CMOMPARE1_ERROR,
    UT_MEMORY_MANAGER_CMOMPARE2_ERROR = 90,
    UT_MEMORY_MANAGER_CMOMPARE3_ERROR,
    UT_MEMORY_MANAGER_CMOMPARE4_ERROR,
    UT_MEMORY_MANAGER_CMOMPARE5_ERROR,

    UT_MEMORY_MANAGER_GET_IP_PORT_ERROR = 94,
    UT_MEMORY_MANAGER_SET_IP_PORT_ERROR,

    UT_MEMORY_MANAGER_RETURN_IP_PORT_LEN_ERROR,
    UT_MEMORY_MANAGER_CMOMPARE_IP_PORT_ERROR,
    UT_STRUCT_PACKED_ERROR,
    UT_STRUCT_PTR_SIZE_ERROR,
    UT_STACK_EVAL_ERROR,
    UT_RAM_ERROR,
    UT_MALLOCK_ERROR = 102,
    UT_WDPU_WRAPER_ERROR = 103,
    UT_WDPU_WRAPER_LEN_ERROR,
    UT_UNSPEC_BEHAVIOR1_ERROR,
    UT_STRNCPY_ERROR,
    UT_STRLCPY_ERROR = 107,

    UT_TIM2_1_ERROR,
    UT_TIM2_2_ERROR = 109,
    UT_TIM2_3_ERROR,
    UT_TIM2_4_ERROR,

    UT_TIM3_1_ERROR,
    UT_TIM3_2_ERROR = 113,
    UT_TIM3_3_ERROR,
    UT_TIM3_4_ERROR = 115,

    UT_TIM4_1_ERROR,
    UT_TIM4_2_ERROR,
    UT_TIM4_3_ERROR,
    UT_TIM4_4_ERROR = 119,

    UT_TIM5_1_ERROR,
    UT_TIM5_2_ERROR,
    UT_TIM5_3_ERROR,
    UT_TIM5_4_ERROR = 123,
    UT_UART6_IT_TX_ERROR,
    UT_NODE_FIFO_INIT_ERROR,
    UT_NODE_FIFO_PUSH_ERROR,
    UT_NODE_FIFO_POP_ERROR = 127,
    UT_NODE_FIFO_COMPARE_ERROR,
    UT_NODE_FIFO_PUSH1_ERROR,
    UT_NODE_FIFO_DOUBLE_INIT_ERROR = 130,
    UT_NODE_FIFO_CHECK_ERROR,
    UT_NODE_CALC_SIZE_ERROR,
    UT_NODE_GET_SIZE_ERROR,
    UT_NODE_FIFO_DESTROY_ERROR,

    UT_NUM_OF_ERRORS
};

#define MIN_DLMS_PKT_SIZE (4 * 2)
#define WDPU_HEADER_SIZE (4 * 2)



extern uint32_t g_unit_test_result;
extern uint32_t g_ut_status;

uint32_t run_unit_test (void);
uint32_t test_channel_protocol (void);

// hardware independent tests
uint32_t test_types (void);

uint32_t test_byte_endians (void);
uint32_t test_utility_func (void);
uint32_t test_heap (void);
uint32_t test_queue (void);
uint32_t test_queue1 (void);
uint32_t test_queue2 (void);
uint32_t test_queue3 (void);
uint32_t test_queue4 (void);
uint32_t test_undefined_behavior (void);
uint32_t witch_address_first_in_stack (void);
uint32_t run_platforn_independent_unit_test (void);
uint32_t test_unspecified_behavior (void);
uint32_t test_implementation_defined_behaviour (void);


#if DEPLOY_FIFO_NODE_TEST
uint32_t test_fifo_node (void);
uint32_t test_fifo_node_case1 (void);
uint32_t test_fifo_node_case2 (void);
uint32_t test_fifo_node_case3 (void);
uint32_t test_fifo_node_case4 (void);
uint32_t test_fifo_node_case5 (void);
#endif /*DEPLOY_FIFO_NODE_TEST*/



uint32_t test_malloc_heap (void);


#endif /* _UNIT_TEST_H */
