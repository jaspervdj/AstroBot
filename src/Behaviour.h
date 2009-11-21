#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

class Robot;

/** Abstract class defining a certain Robot behaviour. */
class Behaviour
{
    public:
        /**
         * Constructor.
         */
        Behaviour();

        /**
         * Destructor.
         */
        virtual ~Behaviour();

        /**
         * Check if this Robot behaviour wants focus.
         * @return If this robot behaviour wants focus.
         */
        virtual bool isActive() = 0;

        /**
         * Execute the behaviour action.
         */
        virtual void action() = 0;

        /**
         * Get the controlled robot.
         * @return The robot this behaviour belongs to.
         */
        Robot *getRobot() const; 

        /**
         * Set the robot to which this behaviour belongs.
         * @param robot Robot to control.
         */
        void setRobot(Robot *robot);

    private:
        /** Robot this behaviour controls. */
        Robot *robot;
};

#endif
