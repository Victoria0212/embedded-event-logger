#include <stdlib.h>
#include <stdio.h>
#include "eventqueue.h"
#include "event.h"


struct EventQueue {
    Event* buffer;
    int capacity;
    int count;
    int head;
    int tail;
    int writeIndex;
};
struct EventQueue* queue_create(int capacity) {
    //Skapa kön
    struct EventQueue* queue = (struct EventQueue*)malloc(sizeof(struct EventQueue));
    if (queue == NULL) {
        return NULL;
    }
    //Skapa buffern
    queue->buffer = (Event*)malloc(capacity * sizeof(Event));
    if (queue->buffer == NULL) {
        free(queue);
        return NULL;
    }
    //Sätt startvärden
    queue->capacity = capacity;
    queue->count = 0;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}
void queue_destroy(EventQueue* queue) {
    // Frigör minnet om kön finns
    if (queue != NULL) {
        free(queue->buffer);
        free(queue);  
    }
}
bool queue_isEmpty(const EventQueue* queue) {
    //Kollla att kön finns
    if (queue == NULL) {
        return true;
    }
    return queue->count == 0;
}
bool queue_isFull(const EventQueue* queue) {
    if (queue == NULL) {
        return true;
    }
    //Könär full om count är lika med capacity
    return queue->count == queue->capacity;
}
bool queue_enqueue(EventQueue* queue, Event e) {
    //Kolla att kön finns och inte är full
    if (queue == NULL) {
        return false;
    }
    if (queue->count >= queue->capacity) {
        return false;
    }
    //Lägg till eventet
    queue->buffer[queue->tail] = e;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->count++;

    return true;
}
bool queue_dequeue(EventQueue* queue, Event* out) {
    //Kolla att kön finns och inte är tom
    if (queue == NULL) {
        return false;
    }
    if (queue->count == 0) {
        return false;
    }
    //Ta ut eventet från head-platsen
    *out = queue->buffer[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->count--;

    return true;
}
