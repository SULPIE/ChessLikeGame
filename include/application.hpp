#pragma once

#include "utils.hpp"
#include <SFML/Graphics.hpp>

class Application
{
public:
    Application();
    virtual ~Application();

    Application(const Application&) = delete;
    Application(Application&&) = delete;
    Application& operator = (const Application&) = delete;
    Application& operator = (Application&&) = delete;

    virtual void start();
    virtual void on_update();
};