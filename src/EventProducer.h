/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * EventProducer.h
 */
#ifndef EVENTPRODUCER_H
#define EVENTPRODUCER_H

#include <list>
#include "DestinationEvent.h"
#include "ObstacleEvent.h"
class EventListener;

class EventProducer
{
    public:
        /**
         * Constructor.
         */
        EventProducer();

        /**
         * Destructor.
         */
        virtual ~EventProducer();

        /**
         * Add an eventlistener.
         * @param listener EventListener to add.
         */
        void registerListener(EventListener *listener);

    protected:
        /**
         * Fire a destinationReached event.
         * @param event Event containing more information.
         */
        void fireDestinationReached(const DestinationEvent &event);

        /**
         * Fire a noObstacle event.
         */
        void fireNoObstacle();

        /**
         * Fire an obstacleDetected event.
         * @param event ObstacleEvent to pass.
         */
        void fireObstacleDetected(const ObstacleEvent &event);

    private:
        /** EventListeners */
        std::list<EventListener*> listeners;
};

#endif
