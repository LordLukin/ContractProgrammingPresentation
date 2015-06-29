import java.util.*;

/**
 *  @inv !isEmpty() implies top() != null
 */
public interface Stack
{
    /**
     *  @pre o != null
     *  @post !isEmpty()
     *  @post top() == o
     */
    void push(Object o);
    /**
     *  @pre !isEmpty()
     *  @post @return == top()@pre
     */
    Object pop();
    /**
     *  @pre !isEmpty()
     */
    Object top();
    boolean isEmpty();
}

/**
 *  @inv isEmpty() implies elements.size() == 0
 */
public class StackImpl implements Stack
{
    private final LinkedList elements = new LinkedList();
    public void push(Object o)
    {
        elements.add(o);
    }
    public Object pop()
    {
        final Object popped = top();
        elements.removeLast();
        return popped;
    }
    public Object top()
    {
        return elements.getLast();
    }
    public boolean isEmpty()
    {
        return elements.size() == 0;
    }
}

public  class StackTest
{
    public static void main(String[] args)
    {
        final Stack s = new StackImpl();
        s.push("one");
        s.pop();
        s.push("two");
        s.push("three");
        s.pop();
        s.pop();
        s.pop();    //  causes an assertion to fail
    }
}
