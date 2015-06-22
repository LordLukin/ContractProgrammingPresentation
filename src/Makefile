CXX = g++
CXXFLAGS = -Wall -Werror -pedantic -O2
LDFLAGS = -Wall -Werror -pedantic -O2
OBJS = calculator.o
SRCS = calculator.cpp

calculator: $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
