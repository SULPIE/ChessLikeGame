#include "iostream"
#include "spdlog/spdlog.h"
#include "game.hpp"

#include <Windows.h>

int main()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);

	auto app = std::make_unique<Game>();
	app->start();

	std::cin.get();
}