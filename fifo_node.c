
/*
 * fifo_node.c
 *
 * C implementation of FIFO
 * based on single linked list
 * Memory dynamically allocated by malloc and free
 *
 * Created on: 2019
 * Author: Aleksandr Barunin
 */

#include "preprocessorSettings.h"

#if DEPLOY_FIFO_NODE


#include "fifo_node.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint16_t check_nodes (FifoNode_t *const head,
		              FifoNode_t const *const tail,
                      uint16_t const curSize) {
    FifoNode_t *curNode = NULL;
    curNode = head;

    if (0 == curSize) {
        if (head) {
            return FIFO_NODE_INVALID_LIST_HEAD;
        }
        if (tail) {
            return FIFO_NODE_INVALID_LIST_HEAD;
        }
        return FIFO_NODE_OK;
    }
    int32_t i;
    for ( i = 0; i < (curSize - 1); i++) {
        if (!curNode) {
            return FIFO_NODE_INVALID_LIST_NULL;
        }
        if (curNode->nextNode) {
            curNode = curNode->nextNode;
        }
    }
    if (curNode == tail) {
        if (curNode->nextNode) {
            return FIFO_NODE_TAIL_NEXT_PTR_ERROR;
        }
        return FIFO_NODE_OK;
    }
    return FIFO_NODE_INVALID_LIST_ERROR;
}
/*
 * 1 not valid fifo instance
 * 0 valid fifo instance
 *
 */
static uint16_t is_fifo (Fifo_t const *const fifoInstance) {

    if (0 < (fifoInstance->curSize)) {
        if (!fifoInstance->head) {
            return FIFO_NODE_INVALID_INSTANCE_HEAD;
        }
        if (!fifoInstance->tail) {
            return FIFO_NODE_INVALID_INSTANCE_TAIL;
        }
    }

    if ((fifoInstance->maxSize) < (fifoInstance->curSize)) {
        return FIFO_NODE_INVALID_INSTANCE_SIZE;
    }

    if (0 == (fifoInstance->curSize)) {
        if (fifoInstance->head) {
            return FIFO_NODE_INVALID_INSTANCE_HEAD;
        }
        if (fifoInstance->tail) {
            return FIFO_NODE_INVALID_INSTANCE_TAIL;
        }
    }

    if (fifoInstance->maxSize <= 0) {
        return FIFO_NODE_INVALID_MAX_SIZE_ERROR;
    }

    uint16_t ret = check_nodes (fifoInstance->head, fifoInstance->tail,
                                fifoInstance->curSize);
    if (ret) {
        return FIFO_NODE_INVALID_INSTANCE_CHAIN;
    }

    return FIFO_NODE_OK;
}

uint16_t fifo_init (Fifo_t *const fifoInstance, uint16_t const maxSize) {
    // check whether list is valid
    uint16_t ret = is_fifo (fifoInstance);
    if (!ret) {
        return FIFO_NODE_ALREADY_INITED_ERROR;
    }
    if(fifoInstance->busy){
		return FIFO_NODE_BUSY;
	}
	fifoInstance->busy = 1;
    fifoInstance->head = NULL;
    fifoInstance->tail = NULL;
    fifoInstance->curSize = 0;
    fifoInstance->maxSize = maxSize;
    fifoInstance->busy = 0;
    return FIFO_NODE_OK;
}

/*
 *
 * extract node from the fifo
 *
 * */
uint16_t fifo_pop (Fifo_t *fifoInstance, NodeItem_t *const outDataNode) {

    uint16_t ret = is_fifo (fifoInstance);
    if (ret) {
        return FIFO_NODE_INSTANCE_ERROR;
    }
    if(fifoInstance->busy){
		return FIFO_NODE_BUSY;
	}
	fifoInstance->busy = 1;
	
	int32_t amountOfElements=0;
    amountOfElements = fifo_size (fifoInstance);
    if (0 == amountOfElements) {
		fifoInstance->busy = 0;
        return FIFO_NODE_EMPTY_ERROR;
    }

    if (fifoInstance->head) {
        FifoNode_t *tempNode = fifoInstance->head;
        /* return data item to user */
        *outDataNode = tempNode->dataNode;
        /*is the last element in linked list*/
        if (tempNode->nextNode) {
            /*several elements in linked list*/
            /*assigne a new head of fifo*/
            fifoInstance->head = tempNode->nextNode; // check
        } else {
            /*single element in linked list*/
            /*assigne a new head and tail of fifo*/
            fifoInstance->head = NULL;
            fifoInstance->tail = NULL;
        }
        free (tempNode);
        tempNode = NULL;
        fifoInstance->curSize--;
    } else {
		fifoInstance->busy = 0;
        return FIFO_NODE_EMPTY_ERROR;
    }
    fifoInstance->busy = 0;
    return FIFO_NODE_OK;
}

/*
 * look at the first node in the fifo
 *
 * */
uint16_t fifo_peek (Fifo_t const *const fifoInstance,
                    NodeItem_t *const outDataNode) {
    uint16_t ret = is_fifo (fifoInstance);
    if (ret) {
        return FIFO_NODE_INSTANCE_ERROR;
    }
    if (!fifoInstance->head) {
        return FIFO_NODE_EMPTY_ERROR;
    }
    *outDataNode = fifoInstance->head->dataNode;
    return 0;
}

/*
 *
 * put a node to the fifo
 *
 * */
uint16_t fifo_push (Fifo_t *fifoInstance, NodeItem_t inDataNode) {
    uint16_t ret = is_fifo (fifoInstance);
    if (ret) {
        return ret;
    }
    if(fifoInstance->busy){
		return FIFO_NODE_BUSY;
	}
	fifoInstance->busy = 1;
	
    if (fifoInstance->maxSize <= fifoInstance->curSize) {
		fifoInstance->busy = 0;
        return FIFO_NODE_OVERFLOWED;
    }
    FifoNode_t *newNode = NULL;
    newNode = (FifoNode_t *)((void *)malloc (sizeof (FifoNode_t)));
    if (!newNode) {
		fifoInstance->busy = 0;
        return FIFO_NODE_ALLOC_MEM_ERROR;
    }
    newNode->dataNode = inDataNode;
    newNode->nextNode = NULL;
    if (fifoInstance->tail) {
        // fifo is not empty
        fifoInstance->tail->nextNode = newNode;
        fifoInstance->tail = newNode;
    } else {
        // fifo is empty
        fifoInstance->tail = newNode;
        fifoInstance->head = newNode;
    }
    fifoInstance->curSize++;
    fifoInstance->busy = 0;
    return FIFO_NODE_OK;
}

/*
 * calculate the size of the fifo
 * */
static uint16_t fifo_calc_size (Fifo_t const *const fifoInstance,
                                int32_t *const outSize) {
    uint16_t ret = is_fifo (fifoInstance);
    if (ret) {
        return ret;
    }
    uint16_t size = 0;
    FifoNode_t *curNode = NULL;
    curNode = fifoInstance->head;
    uint32_t i;
    for ( i = 0; i < fifoInstance->maxSize; i++) {
        if (curNode) {
            size++;
            curNode = curNode->nextNode;
        } else {
            break;
        }
    }
    *outSize = size;
    return FIFO_NODE_OK;
}

uint16_t fifo_destroy (Fifo_t *const fifoInstance) {
    uint16_t loop = 1;
    uint16_t ret = 0;
    NodeItem_t dataNode = {0};
    int32_t cnt = 0;
    int32_t iter = 0;
    cnt = fifo_size (fifoInstance);
    while (loop) {
        ret = fifo_pop (fifoInstance, &dataNode);
        if (FIFO_NODE_EMPTY_ERROR == ret) {
            loop = 0;
        } else {
            loop = 0;
            return ret;
        }
        iter++;
    }
    if (iter != cnt) {
        return FIFO_NODE_DESRTOY_ERROR;
    }
    return FIFO_NODE_OK;
}

int32_t fifo_size (Fifo_t const *const fifoInstance) {
    int32_t outSize = 0;
    uint16_t ret = 0;
    ret = fifo_calc_size (fifoInstance, &outSize);
    if (ret) {
        return -2;
    }
    if (outSize == (fifoInstance->curSize)) {
        return fifoInstance->curSize;
    }
    return -1;
}

#endif /*DEPLOY_FIFO_NODE*/
