CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = dictionary.o gameboard.o die.o word-find.o game.o
TESTS = test-1-dictionary test-2-gameboard test-3-dice-roll test-4-word-find test-5-game
CATCH = test/catch/catch.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf main.dSYM
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM $(addprefix test/,$(TESTS)) core main ${CATCH}

test-all: $(TESTS)

test-1-dictionary: dictionary.o test/test-1-dictionary.cpp
test-2-gameboard: gameboard.o test/test-2-gameboard.cpp
test-3-dice-roll: die.o test/test-3-dice-roll.cpp
test-4-word-find: gameboard.o dictionary.o word-find.o  test/test-4-word-find.cpp
test-5-game: $(OBJECTS) test/test-5-game.cpp

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success
