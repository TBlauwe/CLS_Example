#include <doctest/doctest.h>
#include <cls_example/cls_example.hpp>

TEST_CASE("Basic")
{
	CHECK(CLS_Example::success() == 1);
}