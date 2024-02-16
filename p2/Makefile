CXX = g++ -Wall

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CXXFLAGS = -g -std=c++11 -Wall -Werror=return-type  -Werror=uninitialized

CATCH = test/catch/catch.o
OBJECTS = cell.o board.o ui.o 

TESTS = test-1-cell test-2-board test-3-gameplay test-4-ui

main:  main.o cell.o board.o ui.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM test/*.dSYM
	$(RM) *.o *.gc* main test/*.o $(CATCH) test/test-1-cell test/test-2-board test/test-3-gameplay test/test-4-ui

test-all: $(TESTS)

test-1-cell: cell.o test/test-1-cell.cpp
test-2-board: cell.o board.o test/test-2-board.cpp
test-3-gameplay: cell.o board.o test/test-3-gameplay.cpp
test-4-ui: cell.o board.o ui.o test/test-4-ui.cpp

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success
