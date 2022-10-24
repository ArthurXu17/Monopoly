CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla #-fsanitize=address
BUILD = bin
OBJECTS = main.o game.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = monopoly

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
	mv ${DEPENDS} bin/.
	mv ${OBJECTS} bin/.

clean :
	rm ${DEPENDS} ${OBJECTS}

-include ${DEPENDS} # reads the .d files and reruns dependencies
