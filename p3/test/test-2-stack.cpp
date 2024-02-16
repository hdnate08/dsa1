#include "catch/catch.hpp"
#include <limits>
#include "../node.hpp"
#include "../stack.hpp"

TEST_CASE("class Stack")
{
	Stack s;
	s.Push(50);
	CHECK(!s.IsEmpty());
	CHECK(50 == s.Pop());
	CHECK(s.IsEmpty()); // only element was just popped, should be empty

	// Safe to pop from empty stack??
	// Should return minimum possible integer if stack is empty
	CHECK(std::numeric_limits<int>::min() == s.Pop());
}
