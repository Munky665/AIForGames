#include "AgentTutorialApp.h"
#include <time.h>

int main() {
	
	srand(time(nullptr));
	// allocation
	auto app = new AgentTutorialApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);
	// deallocation
	delete app;

	return 0;
}