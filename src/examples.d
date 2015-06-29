int add_one( int i )
in
{
    assert( i > 0 );
}
out( result )
{
    assert( result == i + 1 );
}
body
{
    return i + 1;
}

class Date
{
    int day;
    int hour;
    invariant
    {
        assert( 1 <= day && day <= 31 );
        assert( 0 <= hour && hour < 24 );
    }
}