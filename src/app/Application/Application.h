#pragma once

#include <mutex>
#include "../../String/ConstString/ConstString.h"

class Application {
public:
    Application() noexcept = delete;

    Application(const Application& other) = delete;

    Application(Application&& other) = delete;

    Application& operator=(const Application& other) = delete;

    Application& operator=(Application&& other) = delete;

public:
    static void run();

    static void quit();

private:
    static void reRenderOnWidnowResize();

    static void readFromStdin();

private:
    static const size_t initialCapacityOfBuffer = 100;

private:
    static std::mutex renderMutex;

    static volatile bool stop;
};