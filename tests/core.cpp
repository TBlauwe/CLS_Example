#include <doctest/doctest.h>
#include <cls_example/core.hpp>

TEST_CASE("Basic")
{
	CHECK(CLS_Example::success() == 1);
}