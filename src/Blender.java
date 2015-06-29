import java.io.*;

/**
 * @invariant getSpeed() > 0 implies isFull()    // don't run empty blender
 * @invariant getSpeed() >= 0 && getSpeed() < 10 // verify range
 */
public interface Blender
{
    int getSpeed();
    boolean isFull();

    /**
     * @pre Math.abs(getSpeed() - x) <= 1 // change only by 1
     * @pre x >= 0 && x < 10 	          // verify range
     * @post getSpeed() == x
     */
    void setSpeed(final int x);
        
    /**
     * @pre !isFull()
     * @post isFull()
     */
    void fill();
    
    /**
     * @pre isFull()
     * @post !isFull()
     */
    void empty();    
}