#include <benchmark/benchmark.h>

#include "../conv2D.hpp"

namespace {

static void BM_Conv2D(benchmark::State& state) {
	const int size = static_cast<int>(state.range(0));

	Matrix input = Matrix::Random(size, size);
	Matrix kernel = Matrix::Random(3, 3);

	for (auto _ : state) {
		benchmark::DoNotOptimize(conv2D(input, kernel));
	}
}

static void BM_Conv2DPadded(benchmark::State& state) {
	const int size = static_cast<int>(state.range(0));

	Matrix input = Matrix::Random(size, size);
	Matrix kernel = Matrix::Random(3, 3);

	for (auto _ : state) {
		benchmark::DoNotOptimize(conv2D_Padded(input, kernel, 1));
	}
}

static void BM_Conv2DOptimized(benchmark::State& state) {
	const int size = static_cast<int>(state.range(0));

	Matrix input = Matrix::Random(size, size);
	Matrix kernel = Matrix::Random(3, 3);

	for (auto _ : state) {
		benchmark::DoNotOptimize(conv2D_Optimizer(input, kernel, 1));
	}
}

}  // namespace

BENCHMARK(BM_Conv2D)->Arg(64)->Arg(128)->Arg(256);
BENCHMARK(BM_Conv2DPadded)->Arg(64)->Arg(128)->Arg(256);
BENCHMARK(BM_Conv2DOptimized)->Arg(64)->Arg(128)->Arg(256);