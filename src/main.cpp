#include "iostream"
#include "application.hpp"
#include "spdlog/spdlog.h"

class Game : public Application
{
	virtual void on_update() override
	{
		spdlog::info("test");
	}
};

int main()
{
	std::cout << "hello world" << std::endl;
	spdlog::info("hello world!");

	auto app = std::make_unique<Game>();
	app->start();

	std::cin.get();
}