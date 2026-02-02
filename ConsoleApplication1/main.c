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

        int choice;
        int run = 1;

        while (run) {
            printf("\n1) Tick\n");
            printf("2) Print\n");
            printf("3) Sort\n");
            printf("4) Find\n");
            printf("5) Help\n");
            printf("6) Exit\n");
            printf("Val: ");
            scanf("%d", &choice);

            switch (choice) {
            case 1: {
                int n;
                printf("Antal tick: ");
                scanf("%d", &n);
                tick(n, queue, log);
                break;
            }
            case 2: {
                for (int i = 0; i < log_size(log); i++) {
                    Event e = log_get(log, i);
                    printf("Timestamp: %d, Sensor: %d, Type: %d, Value: %d\n",
                        e.timestamp, e.sensorId, e.type, e.value);
                break;
            }
            case 3: {
                printf("1) Insertion sort\n");
                int sortVal;
                scanf("%d", &sortVal);
                if (sortVal == 1) {
                    sort_insertion(log);
                }
                break;
            }
            case 4: {
                int sensorId;
                printf("SensorId: ");
                scanf("%d", &sensorId);
                // gör find här sedan
                break;
            }
            case 5: {
                  printf("1) Tick - kör n iterationer\n");
                  printf("2) Print - skriv ut loggen\n");
                  printf("3) Sort - sortera loggen\n");
                  printf("4) Find - sök efter sensorId\n");
                  printf("5) Help - visa hjälp\n");
                  printf("6) Exit - avsluta\n");
                  break;
            }
            case 6: {
                run = 0;
                break;
            }
        }

        queue_destroy(queue);
        log_destroy(log);
        return 0;
    }

    queue_destroy(queue);
    log_destroy(log);
    return 0;
        
}