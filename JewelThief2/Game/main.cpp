#include "GameApp.h"
#include <random>
#include <time.h>

int main() {
	

	std::srand(time(nullptr));
	// allocation
	auto app = new GameApp();

	// initialise and loop
	app->run("Jewel Thief", 1480, 900, false);

	// deallocation
	delete app;

	return 0;
}