CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -I/usr/local/include/cairo -I/usr/local/include/eigen3 `pkg-config gtk+-3.0 --cflags` `pkg-config --cflags cairo`
LDFLAGS = -L/usr/local/lib/ `pkg-config gtk+-3.0 --libs` `pkg-config --libs cairo`
EXEC = draw
FILES = $(wildcard ./src/*.cc)
OBJECTS = ${FILES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${LDFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm -r ${OBJECTS} ${DEPENDS} ${EXEC}
