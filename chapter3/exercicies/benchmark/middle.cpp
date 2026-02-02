#include "../headers/utils.hpp"
#include <benchmark/benchmark.h>
#include "../../headers/myfunctions.hpp"

static void BM_find_middle_index(benchmark::State& state) {

    const int fan_int = state.range(0);

    auto base = glorot_initializer(fan_int, 10);
    for (auto _ : state) {
        auto vec = base;
        benchmark::DoNotOptimize(find_middle_index(vec));
    }
}

static void BM_glorot_initializer(benchmark::State& state) {

    const int fan_int = state.range(0);

    for (auto _ : state) {
        benchmark::DoNotOptimize(glorot_initializer(fan_int, 10));
    }
}

BENCHMARK(BM_find_middle_index)->Range(8, 8<<10);
BENCHMARK(BM_glorot_initializer)->Range(8, 8<<10);

BENCHMARK_MAIN();