#include "GameApp.h"
#include <random>
#include <time.h>

int main() {
	

	std::srand(time(nullptr));
	// allocation
	auto app = new GameApp();

	// initialise and loop
	app->run("AIE", 1280, 700, false);

	// deallocation
	delete app;

	return 0;
}