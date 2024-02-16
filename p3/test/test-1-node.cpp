#include "catch/catch.hpp"
#include "../node.hpp"

TEST_CASE("class Node")
{
	Node n(50);
	CHECK(50 == n.GetValue());
	CHECK(nullptr == n.GetNext());
}
