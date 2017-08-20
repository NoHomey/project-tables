#pragma once

#include <condition_variable>
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

private:
    static bool waitForAction();

    static void reRenderOnWidnowResize();

    static void readFromStdin();

    static void takeAction();

private:
    static ConstString quitString;

    static const size_t initialCapacityOfBuffer = 100;

private:
    static std::mutex commandMutex;

    static std::condition_variable condition;

    static bool readCommand;

    static ImmutableString command;

    static volatile bool stop;
};