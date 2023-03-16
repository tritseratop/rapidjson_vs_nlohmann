#include "values_description.h"

#include "include/json.hpp"

#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"

/* { "tws": 1945, "d": [ {"v": 1}, {"v": 2}, {"v": 3}, {"v": 4}, {"v": 5} ] } */
void convertStructValueToNlohmannJson(const std::vector<StructValue>& source) {
	nlohmann::ordered_json json;
	json["tws"] = 1000000000000000;

	// Для первого элемента нужно выделить память
	json["d"] = std::vector<nlohmann::json>(source.front().totalSize(), {{"v", 0}});

	for (const auto& dto : source) {
		// Дальше идет перезапись в одну и ту же область память
		nlohmann::ordered_json::iterator d_it = json["d"].begin();

		fillContainerOfJsonWithData(d_it, dto.int_v);
		fillContainerOfJsonWithData(d_it, dto.float_v);
		fillContainerOfJsonWithData(d_it, dto.double_v);
		fillContainerOfJsonWithData(d_it, dto.string_v);
		auto str = json.dump();
	}
}

void convertStructValueToRapidJson(const std::vector<StructValue>& source) {
	rapidjson::Document document(rapidjson::kObjectType);
	auto& allocator = document.GetAllocator();

	document.AddMember("tws", rapidjson::Value(1000000000000000), allocator);

	auto& d_value = document.FindMember("d")->value;
	d_value.Reserve(source.front().totalSize(), allocator);

	// Для первого элемента нужно выделить память
	pushBackIntoRapidJson(allocator, d_value, source.front());
	{
		rapidjson::StringBuffer buffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		document.Accept(writer);
		auto str = buffer.GetString();
	}

	// Дальше идет перезапись в одну и ту же область память
	for (size_t i = 1; i < source.size(); ++i) {
		rapidjson::Value::ValueIterator itr = d_value.Begin();
		rapidjson::Value::MemberIterator member_it = d_value.Begin()->MemberBegin();
		for (auto v : source[i].int_v) {
			itr->MemberBegin()->value.SetInt(v);
			++itr;
		}
		for (auto v : source[i].float_v) {
			itr->MemberBegin()->value.SetFloat(v);
			++itr;
		}
		for (auto v : source[i].double_v) {
			itr->MemberBegin()->value.SetDouble(v);
			++itr;
		}
		for (auto v : source[i].string_v) {
			itr->MemberBegin()->value.SetString(rapidjson::StringRef(v.c_str(), v.size()));
			++itr;
		}

		rapidjson::StringBuffer buffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		document.Accept(writer);
		auto str = buffer.GetString();

	}
}

/* { "tws": 1945, "d": {"v": [1, 2, 3, 4, 5, 6]} } */
void convertStructValueToNlohmannJsonWithVect(const std::vector<StructValue>& source) {
	nlohmann::ordered_json json;
	json["tws"] = 1000000000000000;

	// Для первого элемента нужно выделить память
	json["d"]["v"] = std::vector<nlohmann::json>(source.front().totalSize(), 0);

	for (const auto& dto : source) {
		// Дальше идет перезапись в одну и ту же область память
		nlohmann::ordered_json::iterator d_it = json["d"]["v"].begin();

		fillContainerOfJsonWithDataForVect(d_it, dto.int_v);
		fillContainerOfJsonWithDataForVect(d_it, dto.float_v);
		fillContainerOfJsonWithDataForVect(d_it, dto.double_v);
		fillContainerOfJsonWithDataForVect(d_it, dto.string_v);
		auto str = json.dump();
	}
}

void convertStructValueToRapidJsonWithVect(const std::vector<StructValue>& source) {
	rapidjson::Document document(rapidjson::kObjectType);
	auto& allocator = document.GetAllocator();

	document.AddMember("tws", rapidjson::Value(1000000000000000), allocator);

	document.AddMember("d", rapidjson::Value(rapidjson::kObjectType), allocator);
	document.FindMember("d")->value.AddMember("v", rapidjson::Value(rapidjson::kArrayType), allocator);

	auto& d_value = document.FindMember("d")->value.FindMember("v")->value;
	d_value.Reserve(source.front().totalSize(), allocator);

	// Для первого элемента нужно выделить память
	pushBackIntoRapidJsonWithVect(allocator, d_value, source.front());
	{
		rapidjson::StringBuffer buffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		document.Accept(writer);
		auto str = buffer.GetString();
	}

	// Дальше идет перезапись в одну и ту же область память
	for (size_t i = 1; i < source.size(); ++i) {
		rapidjson::Value::ValueIterator itr = d_value.Begin();
		for (auto v : source[i].int_v) {
			itr->SetInt(v);
			++itr;
		}
		for (auto v : source[i].float_v) {
			itr->SetFloat(v);
			++itr;
		}
		for (auto v : source[i].double_v) {
			itr->SetDouble(v);
			++itr;
		}
		for (auto v : source[i].string_v) {
			itr->SetString(rapidjson::StringRef(v.c_str(), v.size()));
			++itr;
		}

		rapidjson::StringBuffer buffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		document.Accept(writer);
		auto str = buffer.GetString();

	}
}

void pushBackIntoRapidJson(rapidjson::Document::AllocatorType& allocator, rapidjson::Value& dom, const StructValue& source) {
	for (auto v : source.int_v) {
		rapidjson::Value value(rapidjson::kObjectType);
		value.AddMember("v", rapidjson::Value(v), allocator);
		dom.PushBack(value, allocator);
	}
	for (auto v : source.float_v) {
		rapidjson::Value value(rapidjson::kObjectType);
		value.AddMember("v", rapidjson::Value(v), allocator);
		dom.PushBack(value, allocator);
	}
	for (auto v : source.double_v) {
		rapidjson::Value value(rapidjson::kObjectType);
		value.AddMember("v", rapidjson::Value(v), allocator);
		dom.PushBack(value, allocator);
	}
	for (auto v : source.string_v) {
		rapidjson::Value value(rapidjson::kObjectType);
		value.AddMember("v", rapidjson::StringRef(v.c_str(), v.size()), allocator);
		dom.PushBack(value, allocator);
	}
}

void pushBackIntoRapidJsonWithVect(rapidjson::Document::AllocatorType& allocator, rapidjson::Value& dom, const StructValue& source) {
	for (auto v : source.int_v) {
		dom.PushBack(v, allocator);
	}
	for (auto v : source.float_v) {
		dom.PushBack(v, allocator);
	}
	for (auto v : source.double_v) {
		dom.PushBack(v, allocator);
	}
	for (auto v : source.string_v) {
		dom.PushBack(rapidjson::StringRef(v.c_str(), v.size()), allocator);
	}
}

template<class It, class T>
void fillContainerOfJsonWithData(It& d_it, const std::vector<T>& source)
{
	for (size_t i = 0; i < source.size(); ++i)
	{
		d_it->begin().value() = source[i];
		d_it++;
	}
}

template<class It, class T>
void fillContainerOfJsonWithDataForVect(It& d_it, const std::vector<T>& source)
{
	for (size_t i = 0; i < source.size(); ++i)
	{
		*d_it = source[i];
		d_it++;
	}
}

size_t StructValue::totalSize() const {
	return int_v.size() + float_v.size() + double_v.size() + string_v.size() + char_v.size();
}

