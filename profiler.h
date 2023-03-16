
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>

class LogDuration {
public:
    explicit LogDuration(const std::string& msg = "")
        : start(std::chrono::steady_clock::now())
        , message(msg + ": ")
    {}

    ~LogDuration() {
        auto finish = std::chrono::steady_clock::now();
        auto dur = finish - start;
        std::cerr << std::setw(50) << std::left << message << " mcs: "
            << std::chrono::duration_cast<std::chrono::microseconds>(dur).count()
            << "\n";
    }
private:
    std::string message;
    std::chrono::steady_clock::time_point start;
};

#define UNIQ_ID_IMP(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMP(lineno)

#define LOG_DURATION(message) \
    LogDuration UNIQ_ID(__LINE__){message}