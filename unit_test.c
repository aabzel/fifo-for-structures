/**
 * @file unit_test.c
 * @brief
 *
 * @author Aleksandr Barunin
 *
 * @date  2019.
 */
#include "preprocessorSettings.h"

#include "unit_test.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#if DEPLOY_FIFO_NODE_TEST
#include "fifo_node.h"
#endif
uint32_t g_MaxStackAddr = 0;
uint32_t g_MinStackAddr = 0;

uint32_t g_unit_test_result = 0;
uint32_t g_ut_status;

uint32_t run_unit_test (void) {
	printf("\n run_unit_test");
    g_ut_status = 0;
    g_ut_status = run_platforn_independent_unit_test ();
    if (g_ut_status) {
        return g_ut_status;
    }

 

    return UT_OK;
}

uint32_t run_platforn_independent_unit_test (void) {

#if DEPLOY_FIFO_NODE_TEST
    g_ut_status = test_fifo_node ();
    if (g_ut_status) {
        return g_ut_status;
    }
#endif

    return UT_OK;
}

#if DEPLOY_FIFO_NODE_TEST
uint32_t test_fifo_node (void) {
    uint32_t ret = 0;
    ret = test_fifo_node_case4 ();
    if (ret) {
        return ret;
    }
    ret = test_fifo_node_case1 ();
    if (ret) {
        return ret;
    }
    ret = test_fifo_node_case3 ();
    if (ret) {
        return ret;
    }
    ret = test_fifo_node_case2 ();
    if (ret) {
        return ret;
    }
    ret = test_fifo_node_case5 ();
    if (ret) {
        return ret;
    }
    return UT_OK;
}
#endif /*DEPLOY_FIFO_NODE_TEST*/

#if DEPLOY_FIFO_NODE_TEST
uint32_t test_fifo_node_case1 (void) {
    Fifo_t fifo1 = {0};
    uint16_t ret = 0;
    ret = fifo_init (&fifo1, 5);
    if (ret) {
        return UT_NODE_FIFO_INIT_ERROR;
    }

    NodeItem_t dataNode;
    dataNode.a = 1;
    ret = fifo_push (&fifo1, dataNode);
    if (ret) {
        return UT_NODE_FIFO_PUSH1_ERROR;
    }

    NodeItem_t outDataNode;
    ret = fifo_pop (&fifo1, &outDataNode);
    if (ret) {
        return UT_NODE_FIFO_POP_ERROR;
    }

    if (outDataNode.a != dataNode.a) {
        if (ret) {
            return UT_NODE_FIFO_COMPARE_ERROR;
        }
    }
    return 0;
}
#endif /*DEPLOY_FIFO_NODE_TEST*/

#if DEPLOY_FIFO_NODE_TEST
uint32_t test_fifo_node_case2 (void) {
    Fifo_t fifo1 = {0};
    uint16_t ret;
    uint16_t maxSizeOfFifo = 5;
    ret = fifo_init (&fifo1, maxSizeOfFifo);
    if (ret) {
        return UT_NODE_FIFO_INIT_ERROR;
    }
    
    uint32_t i=0;
    for ( i = 1; i <= maxSizeOfFifo; i++) {
        NodeItem_t dataNode;
        dataNode.a = i;
        ret = fifo_push (&fifo1, dataNode);
        if (ret) {
            return UT_NODE_FIFO_PUSH_ERROR;
        }
    }

    for ( i = 1; i <= maxSizeOfFifo; i++) {
        NodeItem_t outDataNode;
        ret = fifo_pop (&fifo1, &outDataNode);
        if (ret) {
            return UT_NODE_FIFO_POP_ERROR;
        }
        if (outDataNode.a != i) {
            return UT_NODE_FIFO_COMPARE_ERROR;
        }
    }

    return UT_OK;
}
#endif /*DEPLOY_FIFO_NODE_TEST*/

#if DEPLOY_FIFO_NODE_TEST
uint32_t test_fifo_node_case3 (void) {
    Fifo_t fifo1 = {0};
    uint16_t ret = 0;
    ret = fifo_init (&fifo1, 5);
    if (ret) {
        return UT_NODE_FIFO_INIT_ERROR;
    }

    ret = fifo_init (&fifo1, 5);
    if (ret != FIFO_NODE_ALREADY_INITED_ERROR) {
        return UT_NODE_FIFO_DOUBLE_INIT_ERROR;
    }

    return UT_OK;
}
#endif /*DEPLOY_FIFO_NODE_TEST*/

#if DEPLOY_FIFO_NODE_TEST
uint32_t test_fifo_node_case4 (void) {
    uint16_t ret;
    Fifo_t fifo1 = {0};
    fifo1.curSize = 0;
    fifo1.maxSize = 10;
    fifo1.head = NULL;
    fifo1.tail = NULL;
    ret = check_nodes (fifo1.head, fifo1.tail, fifo1.curSize);
    if (ret) {
        return UT_NODE_FIFO_CHECK_ERROR;
    }

    return UT_OK;
}
#endif /*DEPLOY_FIFO_NODE_TEST*/

#if DEPLOY_FIFO_NODE_TEST
uint32_t test_fifo_node_case5 (void) {
    Fifo_t fifo1 = {0};
    NodeItem_t dataNode = {0};
    dataNode.a = 1;
    uint16_t ret = 0;
    int32_t amountOfElements = 0;

    ret = fifo_init (&fifo1, 10);
    if (ret) {
        return UT_NODE_FIFO_INIT_ERROR;
    }

    ret = fifo_push (&fifo1, dataNode);
    if (ret) {
        return UT_NODE_FIFO_PUSH_ERROR;
    }
    ret = fifo_push (&fifo1, dataNode);
    if (ret) {
        return UT_NODE_FIFO_PUSH_ERROR;
    }
    ret = fifo_push (&fifo1, dataNode);
    if (ret) {
        return UT_NODE_FIFO_PUSH_ERROR;
    }

    amountOfElements = fifo_size (&fifo1);
    if (amountOfElements < 0) {
        return UT_NODE_CALC_SIZE_ERROR;
    }

    if (3 != amountOfElements) {
        return UT_NODE_GET_SIZE_ERROR;
    }
    ret = fifo_destroy (&fifo1);
    if (ret) {
        return UT_NODE_FIFO_DESTROY_ERROR;
    }

    ret = fifo_push (&fifo1, dataNode);
    if (ret) {
        return UT_NODE_FIFO_PUSH_ERROR;
    }
    ret = fifo_push (&fifo1, dataNode);
    if (ret) {
        return UT_NODE_FIFO_PUSH_ERROR;
    }
    ret = fifo_push (&fifo1, dataNode);
    if (ret) {
        return UT_NODE_FIFO_PUSH_ERROR;
    }
    ret = fifo_destroy (&fifo1);
    if (ret) {
        return UT_NODE_FIFO_DESTROY_ERROR;
    }

    return UT_OK;
}
#endif /*DEPLOY_FIFO_NODE_TEST*/


 

 
 
