#include <benchmark/benchmark.h>
#include <cls_example/core.hpp>

// Define another benchmark
static void BM_Success(benchmark::State& state) {
	for (auto _ : state)
		CLS_Example::success();
}
BENCHMARK(BM_Success);

BENCHMARK_MAIN();