#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "eventlog.h"
#include "eventqueue.h"


int timestamp = 0;

Event create_event() {
    Event e; //Skapa ett nytt event med slumpade värden
    e.timestamp = timestamp++;
    e.sensorId = rand() % 5;
    e.type = rand() % 3;
    e.value = rand() % 100;
    return e;
}
void process_event(EventQueue* queue, EventLog* log) {
    Event e;
    if (queue_dequeue(queue, &e)) {
        log_append(log, e);
    }
}
void tick(int n, EventQueue* queue, EventLog* log) {
    for (int i = 0; i < n; i++) {
        queue_enqueue(queue, create_event());
        process_event(queue, log);
    }
}
int main() {
    EventQueue* queue = queue_create(10);
    EventLog* log = log_create(10);

    //Menyn saknas här!

    queue_destroy(queue);
    log_destroy(log);
    return 0;
}