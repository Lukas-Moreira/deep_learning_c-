#pragma once 

#include <cmath>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <stdexcept>

#include "./chi_squared_test.hpp"

using vector = std::vector<int>;
using chrono = std::chrono::system_clock;
using rand_t = std::default_random_engine;
using uniform_dist = std::normal_distribution<float>;

float sigmoid(float z);
int find_middle(vector & arr);

std::vector<float> glorot_initializer(int fan_in, int fan_out);