/*
 *
 * @file: fifo_node.h
 *
 * C implementation of FIFO
 * based on single linked list
 * Memory dynamically allocated by malloc and free
 *
 * Created on: 2019
 * Author: Aleksandr Barunin
 */
#ifndef FIFO_NODE_H_
#define FIFO_NODE_H_

#include "preprocessorSettings.h"

#if DEPLOY_FIFO_NODE

#include <stdint.h>

enum fifoNodeErrCodes {
    FIFO_NODE_OK = 0,
    FIFO_NODE_FULL_ERROR = 1,
    FIFO_NODE_INSTANCE_ERROR = 2,
    FIFO_NODE_INVALID_INSTANCE = 3,
    FIFO_NODE_ALREADY_INITED_ERROR = 4,
    FIFO_NODE_INVALID_INSTANCE_HEAD = 5,
    FIFO_NODE_INVALID_INSTANCE_TAIL = 6,
    FIFO_NODE_INVALID_INSTANCE_SIZE = 7,
    FIFO_NODE_INVALID_INSTANCE_CHAIN = 8,
    FIFO_NODE_INVALID_LIST_CHAIN = 9,
    FIFO_NODE_INVALID_LIST_HEAD = 10,
    FIFO_NODE_INVALID_LIST_NULL = 12,
    FIFO_NODE_INVALID_LIST_NEXT = 13,
    FIFO_NODE_INVALID_LIST_ERROR = 14,
    FIFO_NODE_ALLOC_MEM_ERROR = 15,
    FIFO_NODE_INVALID_MAX_SIZE_ERROR = 16,
    FIFO_NODE_TAIL_NEXT_PTR_ERROR = 17,
    FIFO_NODE_EMPTY_ERROR = 18,
    FIFO_NODE_OVERFLOWED = 20,
    FIFO_POP_TAIL_ERROR = 21,
    FIFO_NODE_DESRTOY_ERROR = 22,
    FIFO_NODE_BUSY = 23,

    FIFO_NODE_AMOUNT_ERROR
};

/*Data node*/
struct xNodeItem_t {
    uint32_t a; // anything strudture can be here
};
typedef struct xNodeItem_t NodeItem_t;

/*chain node*/
struct xFifoNode_t {
    NodeItem_t dataNode;
    struct xFifoNode_t *nextNode;
};
typedef struct xFifoNode_t FifoNode_t;

struct xFifo_t {
	uint32_t busy;
    uint16_t maxSize;
    uint16_t curSize;
    FifoNode_t *head;
    FifoNode_t *tail;
};
typedef struct xFifo_t Fifo_t;

uint16_t check_nodes (FifoNode_t *const head,
                             FifoNode_t const *const tail,
                             uint16_t const curSize);
uint16_t fifo_init (Fifo_t *const fifoInstance, uint16_t const maxSize);
uint16_t fifo_pop (Fifo_t *fifoInstance, NodeItem_t *const outDataNode);
uint16_t fifo_peek (Fifo_t const *const fifoInstance,
                    NodeItem_t *const outDataNode);
uint16_t fifo_push (Fifo_t *fifoInstance, NodeItem_t inDataNode);
uint16_t fifo_destroy (Fifo_t *const fifoInstance);
int32_t fifo_size (Fifo_t const *const fifoInstance);

#endif /*DEPLOY_FIFO_NODE*/

#endif /* FIFO_NODE_H_ */
