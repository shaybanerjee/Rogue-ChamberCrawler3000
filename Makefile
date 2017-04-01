CXX=g++-5
CXXFLAGS=-std=c++14 -Wall -MMD
OBJECTS= main.o cell.o grid.o subject.o textdisplay.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}
clean:
	rm *.o cc3k *.d
.PHONY: clean