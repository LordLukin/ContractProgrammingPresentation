/** 
 * @pre f >= 0.0
 * @post Math.abs((return * return) - f) < 0.001 
 */ 
public float sqrt(float f)
{
    ...
} 

/**
 *  Append an element to a collection.
 *
 *  @post c.size() == c@pre.size() + 1
 *  @post c.contains(o)
 */
public void append(Collection c, Object o)
{
    ...
}

/**
 *  A PositiveInteger is an Integer that is guaranteed to be positive.
 *
 *  @inv intValue() > 0
 */
class PositiveInteger extends Integer
{
    ...
}

/**
 * @invariant forall IEmployee e in getEmployees() |
 *              getRooms().contains(e.getOffice())
 */
 
/**
 * @post exists IRoom r in getRooms() | r.isAvailable()
 */
 
/**
 * @invariant getRooms().isEmpty() implies
 *            getEmployees().isEmpty() // no rooms, no employees
 */
 
/**
 * @invariant forall IEmployee e1 in getEmployees() |
 *            forall IEmployee e2 in getEmployees() |
 *            (e1 != e2) implies e1.getOffice() != e2.getOffice()
 *            // a single office per employee
 */
 