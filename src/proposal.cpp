int factorial( int n )
precondition
{
    0 <= n && n <= 12;
}
postcondition( result )
{
    result >= 1;
}
{
    if ( n < 2 )
        return 1;
    else
        return n * factorial( n - 1 );
}

double sqrt( double r )
in // start a block with preconditions
{
    r > 0.0: throw bad_input();
}
do // normal function body
{
    ...
}

int foo( int& i )
out // start block with postconditions
{
    i == in i + 1;
    return % 2 == 0;
}
do // normal function body
{
    i++;
    return 4;
}

class container
{
    // ...
    invariant
    {
        size() >= 0;
        size() <= max_size();
        is_empty() implies size() == 0;
        is_full() implies size() == max_size();
        distance( begin(), end() ) == size();
    }
};