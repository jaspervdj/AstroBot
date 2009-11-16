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
         * Destructor.
         */
        virtual ~Cell();
        
        /** 
         * Get X-coordinate
         * @return x
         */
        const int &getX() const;
        
        /**
         * Get Y-coordinate
         * @return y
         */
        const int &getY() const;
        
        /**
         * Accessible to the robot?
         * @return ok
         */
        virtual bool isAccessible() const = 0;
        
        bool operator== (const Cell &other) const;
        bool operator> (const Cell &other) const;
        bool operator< (const Cell &other) const;
        
    private:
        /** X-coordinate */
        int x;
        
        /** Y-coordinate */
        int y;
    
};

#endif
