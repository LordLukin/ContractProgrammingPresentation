CXX = g++
CXXFLAGS = -Wall -Werror -pedantic -O2 -std=c++11
LDFLAGS = -Wall -Werror -pedantic -O2 -std=c++11

JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

all: calculator blender ownMechanism

calculator: calculator.o
	$(CXX) $(LDFLAGS) $^ -o $@

ownMechanism: ownMechanism.o
	$(CXX) $(LDFLAGS) $^ -o $@

ownMechanism.o: ownMechanism.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

calculator.o: calculator.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
CLASSES = \
	Blender.java

blender: $(CLASSES:.java=.class)

clean:
	$(RM) *.class