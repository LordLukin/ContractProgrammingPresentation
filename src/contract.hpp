#include <cassert.h>

#ifdef NDEBUG
#define preCondition(c)  assert(c)
#define postCondition(c) assert(c)
#else
#define preCondition(c) \
    if(!c) { \
        std::cerr << __FILE__ << ":" << __LINE__ << ": " << c; \
        throw preConditionException("preCondition c failed!"); \
    }        
#define postCondition(c) \
    if(!c) { \
        std::cerr << __FILE__ << ":" << __LINE__ << ": " << c; \
        throw postConditionException("postCondition c failed!"); \
    }
#endif