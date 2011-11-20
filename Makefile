# compilation
CXX       = g++
CXXFLAGS  = -Wall -O -g -MMD

# objects
OBJECTS   = main.o RC_CubeNode.o RC_Enums.o RC_Cube.o

# outputs
DEPENDS = ${OBJECTS:.o=.d}
EXECUTABLE = rubiks.out

# build rule
$(EXECUTABLE) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# dependencies
-include $(DEPENDS)

# other targets
clean :
	rm -rf $(DEPENDS) $(OBJECTS) $(EXECUTABLE)

neat :
	rm -rf $(DEPENDS) $(OBJECTS)
