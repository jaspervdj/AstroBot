/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * EventProducer.cpp
 */
#include "EventProducer.h"
#include "EventListener.h"
#include "ObstacleEventListener.h"
#include "DestinationEventListener.h"

using namespace std;

EventProducer::EventProducer()
{
}

EventProducer::~EventProducer()
{
}

void EventProducer::registerListener(EventListener *listener)
{
    listeners.push_back(listener);
}

void EventProducer::fireDestinationReached(const DestinationEvent &event)
{
    for(list<EventListener*>::iterator i = listeners.begin();
            i != listeners.end(); i++) {
        DestinationEventListener *listener =
                dynamic_cast<DestinationEventListener*>(*i);
        if(listener) listener->destinationReached(event);
    }
}

void EventProducer::fireNoObstacle()
{
    for(list<EventListener*>::iterator i = listeners.begin();
            i != listeners.end(); i++) {
        ObstacleEventListener *listener =
                dynamic_cast<ObstacleEventListener*>(*i);
        if(listener) listener->noObstacle();
    }
}

void EventProducer::fireObstacleDetected(const ObstacleEvent &event)
{
    for(list<EventListener*>::iterator i = listeners.begin();
            i != listeners.end(); i++) {
        ObstacleEventListener *listener =
                dynamic_cast<ObstacleEventListener*>(*i);
        if(listener) listener->obstacleDetected(event);
    }
}
