#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

Queue newQueue(size_t capacity) {
  Queue q = (Queue) malloc(sizeof(struct queue));
  if (q == NULL) {
    return NULL;
  }

  q -> capacity = (size_t) capacity + 1;
  q -> head = (size_t) 0;
  q -> tail = (size_t) 0;
  q -> queue = (void **) malloc(q -> capacity * (sizeof(void *)));

  if (q -> queue == NULL) {
    freeQueue(q);
    return NULL;
  }

  return q;
}

bool isQueueEmpty(Queue q) {
  return q -> head == q -> tail;
}

void enQueue(Queue q, void *elem) {
  if ((q -> tail + 1) % q -> capacity != q->head) {
    q -> queue[q -> tail] = elem;
    q -> tail = (q -> tail + 1) % q -> capacity;
  }
}

void *deQueue(Queue q) {
  void *elem = q -> queue[q -> head];
  if (q -> head != q -> tail) {
    q -> head = (q -> head + 1) % q -> capacity;
  }

  return elem;
}

void freeQueue(Queue q) {
  if (q -> queue != NULL) {
    free(q -> queue);
  }

  free(q);
  q = NULL;
}
