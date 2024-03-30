#ifndef QUEUES_H
#define QUEUES_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

/* Queue Structure */
typedef struct queue_s {
    struct binary_tree_s *node;
    struct queue_s *next;
} queue_t;

queue_t *push_to_queue(queue_t **rear, binary_tree_t *node);
binary_tree_t *pop_from_queue(queue_t **front);

#endif /* QUEUES_H */
