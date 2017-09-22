CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD -lX11 -L/opt/X11/lib -I/opt/X11/include
OBJECTS=window.o subject.o cell.o grid.o textdisplay.o graphicsdisplay.o main.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=lightout.exe
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}
clean:
	rm *.o main
.PHONY: clean
