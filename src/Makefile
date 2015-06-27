CXX = g++
CXXFLAGS = -Wall -Werror -pedantic -O2 -std=c++11
LDFLAGS = -Wall -Werror -pedantic -O2 -std=c++11
OBJS = calculator.o
SRCS = calculator.cpp

JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

all: calculator blender

calculator: $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

CLASSES = \
	Blender.java

blender: $(CLASSES:.java=.class)

clean:
	$(RM) *.class