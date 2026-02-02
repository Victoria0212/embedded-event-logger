#ifndef EVENT_H
#define EVENT_H

typedef enum EventType {
    TEMP,
    BUTTON,
    MOTION
} EventType;

typedef struct Event {
    int timestamp;
    int sensorId;
    EventType type;
    int value;
} Event;

extern int global_timestamp;


#endif EVENT_H