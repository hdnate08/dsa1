CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -Werror=return-type  -Werror=uninitialized # --coverage

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS:%.hpp=%.o)
TESTS = test-1-node test-2-stack test-3-operand test-4-arithmetic-expression test-5-big-integer-arithmetic-1 test-5-big-integer-arithmetic-2 test-6-expression-reader
CATCH = test/catch/catch.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf main.dSYM
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM $(addprefix test/,$(TESTS)) core main ${CATCH}

test-all: $(TESTS)

test-1-node: node.o test/test-1-node.cpp
test-2-stack: node.o stack.o test/test-2-stack.cpp
test-3-operand: node.o stack.o operand.o test/test-3-operand.cpp
test-4-arithmetic-expression: node.o stack.o operand.o arithmetic-expression.o test/test-4-arithmetic-expression.cpp
test-5-big-integer-arithmetic-1: node.o stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o test/test-5-big-integer-arithmetic.cpp
test-5-big-integer-arithmetic-1: export PART=1
test-5-big-integer-arithmetic-2: node.o stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o test/test-5-big-integer-arithmetic.cpp
test-5-big-integer-arithmetic-2: export PART=2
test-6-expression-reader: node.o stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o expression-reader.o test/test-6-expression-reader.cpp

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success
