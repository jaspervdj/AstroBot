/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * Cell.h
 */
#ifndef CELL_H
#define CELL_H

/** A cell in the map */
class Cell
{
    public:
        /** 
         * Constructor.
         */
        Cell(int x = 0, int y = 0);

        /**
         * Copy constructor.
         * @param cell Cell to copy.
         */
        Cell(const Cell &cell);
        
        /**
         * Destructor.
         */
        virtual ~Cell();
        
        /** 
         * Get X-coordinate
         * @return x
         */
        int getX() const;
        
        /**
         * Get Y-coordinate
         * @return y
         */
        int getY() const;
        
        /**
         * Accessible to the robot?
         * @return ok
         */
        virtual bool isAccessible() const;
        
        bool operator==(const Cell &other) const;
        bool operator>(const Cell &other) const;
        bool operator<(const Cell &other) const;
        
    private:
        /** X-coordinate */
        int x;
        
        /** Y-coordinate */
        int y;
};

#endif
