#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

using vector_middle = std::vector<float>;
using invalid_argument = std::invalid_argument;

#define DEBUG_MODE 0

float find_middle_index(const vector_middle& vec);