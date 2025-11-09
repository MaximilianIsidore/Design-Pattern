#include <stdlib.h>

#include <vector>

#include "benchmark/benchmark.h"

void BM_new_delete(benchmark::State& state) {
    const size_t S = state.range(0);
    for (auto _ : state) {
        auto* p = new char[S];
        benchmark::DoNotOptimize(p);
        delete[] p;
    }
}
BENCHMARK(BM_new_delete)->RangeMultiplier(2)->Range(32, 256);
BENCHMARK_MAIN();