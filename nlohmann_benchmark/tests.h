#pragma once

#include "utility.h"
#include "constants.h"

#include "profiler.h"

void TestStructValueToNlohmannJson(std::string_view message, const std::vector<StructValue>& inputs) {
	LOG_DURATION(message.data());
	convertStructValueToNlohmannJson(inputs);
}

void TestStructValueToRapidJson(std::string_view message, const std::vector<StructValue>& inputs) {
	LOG_DURATION(message.data());
	convertStructValueToRapidJson(inputs);
}

void TestStructValueToNlohmannJsonWithVect(std::string_view message, const std::vector<StructValue>& inputs) {
	LOG_DURATION(message.data());
	convertStructValueToNlohmannJsonWithVect(inputs);
}

void TestStructValueToRapidJsonWithVect(std::string_view message, const std::vector<StructValue>& inputs) {
	LOG_DURATION(message.data());
	convertStructValueToRapidJsonWithVect(inputs);
}

void TestIntNlohmann(const std::vector<size_t>& numbers) {
	for (auto number : numbers) {
		auto inputs = CreateInputDataWithInt(number);
		TestStructValueToNlohmannJson("Convert dto (" + std::to_string(number) + " int) to nlohmann_json", inputs);
	}
}

void TestIntRapid(const std::vector<size_t>& numbers) {
	for (auto number : numbers) {
		auto inputs = CreateInputDataWithInt(number);
		TestStructValueToRapidJson("Convert dto (" + std::to_string(number) + " int) to rapid_json", inputs);
	}
}

void TestNumericNlohmann(const std::vector<size_t>& numbers) {
	for (auto number : numbers) {
		auto inputs = CreateInputDataWithNumeric(number);
		TestStructValueToNlohmannJson("Convert dto (" + std::to_string(number) + " Numeric) to nlohmann_json", inputs);
	}
}

void TestNumericRapid(const std::vector<size_t>& numbers) {
	for (auto number : numbers) {
		auto inputs = CreateInputDataWithNumeric(number);
		TestStructValueToRapidJson("Convert dto (" + std::to_string(number) + " Numeric) to rapid_json", inputs);
	}
}

void TestNumericNlohmannWithVect(const std::vector<size_t>& numbers) {
	for (auto number : numbers) {
		auto inputs = CreateInputDataWithNumeric(number);
		TestStructValueToNlohmannJsonWithVect("Convert dto (" + std::to_string(number) + " Numeric) to nlohmann_json", inputs);
	}
}

void TestNumericRapidWithVect(const std::vector<size_t>& numbers) {
	for (auto number : numbers) {
		auto inputs = CreateInputDataWithNumeric(number);
		TestStructValueToRapidJsonWithVect("Convert dto (" + std::to_string(number) + " Numeric) to rapid_json", inputs);
	}
}

void TestStringNlohmann(const std::vector<size_t>& numbers) {
	for (auto number : numbers) {
		auto inputs = CreateInputDataWithString(number);
		TestStructValueToNlohmannJson("Convert dto (" + std::to_string(number) + " String) to nlohmann_json", inputs);
	}
}

void TestStringRapid(const std::vector<size_t>& numbers) {
	for (auto number : numbers) {
		auto inputs = CreateInputDataWithString(number);
		TestStructValueToRapidJson("Convert dto (" + std::to_string(number) + " String) to rapid_json", inputs);
	}
}

void TestTotalNlohmann(const std::vector<size_t>& numbers) {
	for (auto number : numbers) {
		auto inputs = CreateInputDataWithTotal(number);
		TestStructValueToNlohmannJson("Convert dto (" + std::to_string(number) + " Total) to nlohmann_json", inputs);
	}
}

void TestTotalRapid(const std::vector<size_t>& numbers) {
	for (auto number : numbers) {
		auto inputs = CreateInputDataWithTotal(number);
		TestStructValueToRapidJson("Convert dto (" + std::to_string(number) + " Total) to rapid_json", inputs);
	}
}