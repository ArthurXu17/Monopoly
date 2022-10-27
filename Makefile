CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla #-fsanitize=address
BUILD = bin
OBJECTS = main.o game.o control.o player.o property.o railroad.o street_property.o tile.o utility.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = monopoly

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
	mv ${DEPENDS} bin/.
	mv ${OBJECTS} bin/.

clean :
	rm ${DEPENDS} ${OBJECTS}

-include ${DEPENDS} # reads the .d files and reruns dependencies
