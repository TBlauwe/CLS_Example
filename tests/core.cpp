#include <catch2/catch_test_macros.hpp>
#include <cls_example/core.hpp>

TEST_CASE("Basic")
{
	CHECK(CLS_Example::success() == 1);
}