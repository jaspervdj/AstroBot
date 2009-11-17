#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "Event.h"

/** Abstract event listener class. */
class EventListener
{
    public:
        /**
         * Constructor.
         */
        EventListener();

        /**
         * Destructor.
         */
        virtual ~EventListener();
};

#endif
