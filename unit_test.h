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
   
    UT_NODE_FIFO_INIT_ERROR,
    UT_NODE_FIFO_PUSH_ERROR,
    UT_NODE_FIFO_POP_ERROR ,
    UT_NODE_FIFO_COMPARE_ERROR,
    UT_NODE_FIFO_PUSH1_ERROR,
    UT_NODE_FIFO_DOUBLE_INIT_ERROR ,
    UT_NODE_FIFO_CHECK_ERROR,
    UT_NODE_CALC_SIZE_ERROR,
    UT_NODE_GET_SIZE_ERROR,
    UT_NODE_FIFO_DESTROY_ERROR,

    UT_NUM_OF_ERRORS
};




extern uint32_t g_unit_test_result;
extern uint32_t g_ut_status;

uint32_t run_unit_test (void);

#if DEPLOY_FIFO_NODE_TEST
uint32_t test_fifo_node (void);
uint32_t test_fifo_node_case1 (void);
uint32_t test_fifo_node_case2 (void);
uint32_t test_fifo_node_case3 (void);
uint32_t test_fifo_node_case4 (void);
uint32_t test_fifo_node_case5 (void);
#endif /*DEPLOY_FIFO_NODE_TEST*/


#endif /* _UNIT_TEST_H */
