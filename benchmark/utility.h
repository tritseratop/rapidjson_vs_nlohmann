#pragma once

#include "values_description.h"

template<class T>
std::vector<T> generateVector(size_t size, T value) {
	return std::vector<T>(size, value);
}

std::vector<StructValue> CreateInputDataWithInt(size_t number);

std::vector<StructValue> CreateInputDataWithFloat(size_t number);

std::vector<StructValue> CreateInputDataWithDouble(size_t number);

std::vector<StructValue> CreateInputDataWithString(size_t number);

std::vector<StructValue> CreateInputDataWithNumeric(size_t number);

std::vector<StructValue> CreateInputDataWithTotal(size_t number);
