#include "iostream"
#include "spdlog/spdlog.h"
#include "game.hpp"

int main()
{
	auto app = std::make_unique<Game>();
	app->start();

	std::cin.get();
}