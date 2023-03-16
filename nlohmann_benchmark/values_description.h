#pragma once

#include <vector>
#include <string>

#include "include/rapidjson/document.h"

struct StructValue {
	std::vector<int32_t> int_v;
	std::vector<float> float_v;
	std::vector<double> double_v;
	std::vector<std::string> string_v;

	std::vector<char> char_v;

	size_t totalSize() const;
};

/* { "tws": 1945, "d": [ {"v": 1}, {"v": 2}, {"v": 3}, {"v": 4}, {"v": 5} ] } */
void convertStructValueToNlohmannJson(const std::vector<StructValue>& source);
void convertStructValueToRapidJson(const std::vector<StructValue>& source);

/* { "tws": 1945, "d": {"v": [1, 2, 3, 4, 5, 6]} } */
void convertStructValueToNlohmannJsonWithVect(const std::vector<StructValue>& source);
void convertStructValueToRapidJsonWithVect(const std::vector<StructValue>& source);

void pushBackIntoRapidJson(rapidjson::Document::AllocatorType& allocator, rapidjson::Value& dom, const StructValue& source);
void pushBackIntoRapidJsonWithVect(rapidjson::Document::AllocatorType& allocator, rapidjson::Value& dom, const StructValue& source);

template<class It, class T>
void fillContainerOfJsonWithData(It& d_it, const std::vector<T>& source);

template<class It, class T>
void fillContainerOfJsonWithDataForVect(It& d_it, const std::vector<T>& source);