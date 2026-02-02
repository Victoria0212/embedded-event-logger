#ifndef EVENTLOG_H
#define EVENTLOG_H
#include "event.h"

typedef struct EventLog EventLog;

EventLog* log_create(int capacity);
int log_size(const EventLog* log);
int log_capacity(const EventLog* log);
void log_destroy(EventLog* log);
void log_append(EventLog* log, Event e);
Event log_get(const EventLog* log, int index);
void log_set(EventLog* log, int index, Event e);

#endif