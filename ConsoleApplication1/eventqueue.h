#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H
#include "event.h"
#include <stdbool.h>

typedef struct EventQueue EventQueue;

EventQueue* queue_create(int capacity);
void queue_destroy(EventQueue* q);
bool queue_isEmpty(const EventQueue* q);
bool queue_isFull(const EventQueue* q);
bool queue_enqueue(EventQueue* q, Event e);
bool queue_dequeue(EventQueue* q, Event* out);
#endif