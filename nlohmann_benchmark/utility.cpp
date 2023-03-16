#include "utility.h"
#include "constants.h"

std::vector<StructValue> CreateInputDataWithInt(size_t number) {
	StructValue values{ {generateVector(number, 1)}, {}, {}, {} };
	return std::vector<StructValue>(NUMBER_OF_CYCLES, values);
}

std::vector<StructValue> CreateInputDataWithFloat(size_t number) {
	StructValue values{ {}, {generateVector(number, 3.0f)}, {}, {} };
	return std::vector<StructValue>(NUMBER_OF_CYCLES, values);
}

std::vector<StructValue> CreateInputDataWithDouble(size_t number) {
	StructValue values{ {}, {}, {generateVector(number, 4.0)}, {} };
	return std::vector<StructValue>(NUMBER_OF_CYCLES, values);
}

std::vector<StructValue> CreateInputDataWithString(size_t number) {
	StructValue values{ {}, {}, {}, {generateVector(number, std::string("00"))}};
	return std::vector<StructValue>(NUMBER_OF_CYCLES, values);
}

std::vector<StructValue> CreateInputDataWithNumeric(size_t number) {
	size_t number_ = number / 3;
	StructValue values{
		{generateVector(number_, 1)},
		{generateVector(number_, 3.0f)},
		{generateVector(number_, 4.0)},
		{}
	};
	return std::vector<StructValue>(NUMBER_OF_CYCLES, values);
}

std::vector<StructValue> CreateInputDataWithTotal(size_t number) {
	size_t number_ = number / 4;
	StructValue values{
		{generateVector(number_, 1)},
		{generateVector(number_, 3.0f)},
		{generateVector(number_, 4.0)},
		{generateVector(number_, std::string("00"))}
	};
	return std::vector<StructValue>(NUMBER_OF_CYCLES, values);
}