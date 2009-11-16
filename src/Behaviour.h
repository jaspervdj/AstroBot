#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

/** Abstract class defining a certain Robot behaviour. */
class Behaviour
{
    public:
        /**
         * Check if this Robot behaviour wants focus.
         * @return If this robot behaviour wants focus.
         */
        virtual bool isActive() = 0;

        /**
         * Execute the behaviour action.
         */
        virtual void action() = 0;
};

#endif
