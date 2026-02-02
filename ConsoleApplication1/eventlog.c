#include <stdlib.h>
#include <stdio.h>
#include "eventlog.h"
#include "event.h"

struct EventLog {
    Event* events;
    int size;
    int capacity;
};

EventLog* log_create(int capacity) {
    //Allokera minne för själva loggen
    EventLog* log = (EventLog*)malloc(sizeof(EventLog));
    if (log == NULL) {
        printf("Fel: Kunde inte allokera minne för loggen\n");
        return NULL;
    }

    //Allokera minne för event-arrayen
    log->events = (Event*)malloc(capacity * sizeof(Event));
    if (log->events == NULL) {
        printf("Fel: Kunde inte allokera minne för events\n");
        free(log);
        return NULL;
    }

    //Sätt startvärden
    log->size = 0;
    log->capacity = capacity;

    return log;
}

int log_size(const EventLog* log) {
    //Kolla att log finns
    if (log == NULL) {
        return 0;
    }
    return log->size;
}

int log_capacity(const EventLog* log) {
    //Kolla att log finns
    if (log == NULL) {
        return 0;
    }
    return log->capacity;
}

void log_destroy(EventLog* log) {
    //Frigör minnet om log finns
    if (log != NULL) {
        free(log->events);  //Frigör event-arrayen först
        free(log);          //Sedan själva loggen
    }
}

void log_append(EventLog* log, Event e) {
    //Kolla att log finns
    if (log == NULL) {
        return;
    }

    //Om loggen är full, dubbla kapaciteten
    if (log->size >= log->capacity) {
        int newCapacity = log->capacity * 2;
        Event* newEvents = realloc(log->events, newCapacity * sizeof(Event));

        if (newEvents == NULL) {
            printf("Fel: Kunde inte utöka loggen\n");
            return;
        }

        log->events = newEvents;
        log->capacity = newCapacity;
    }

    //Lägg till eventet på rätt plats och öka size
    log->events[log->size] = e;
    log->size++;
}

Event log_get(const EventLog* log, int index) {
    //Kolla att log finns och att index är giltigt
    if (log == NULL || index < 0 || index >= log->size) {
        //Returnera ett tomt event om något är fel
        Event empty = { -1, -1, TEMP, -1 };
        return empty;
    }

    return log->events[index];
}

void log_set(EventLog* log, int index, Event e) {
    //Kolla att log finns
    if (log == NULL) {
        return;
    }

    //Kolla att index är giltigt
    if (index < 0 || index >= log->size) {
        return;
    }

    //Sätt eventet på rätt plats
    log->events[index] = e;
}
	

	//öka size

	//om size är större än capacity, allokera mer minne och öka capacity

	//lägg till eventet på "events listan"



