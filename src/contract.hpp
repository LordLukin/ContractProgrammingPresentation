#include <cassert>
#include <string>
#include <iostream>
#include <stdexcept>

class PreconditionException : public std::logic_error
{
public:
    explicit PreconditionException(const std::string & what_arg) 
        : logic_error(what_arg)
    {}
};

class PostconditionException : public std::logic_error
{
public:
    explicit PostconditionException(const std::string & what_arg) 
        : logic_error(what_arg)
    {}
};

#ifdef NDEBUG
#define preCondition(c)  assert(c)
#define postCondition(c) assert(c)
#else
#define preCondition(c) \
  if(!(c)) { \
    std::cerr << __FILE__ << ":" << __LINE__ << ": " << #c; \
    throw PreconditionException("preCondition " #c " failed!"); \
  }        
#define postCondition(c) \
  if(!(c)) { \
    std::cerr << __FILE__ << ":" << __LINE__ << ": " << #c; \
    throw PostconditionException("postCondition " #c " failed!"); \
  }
#endif