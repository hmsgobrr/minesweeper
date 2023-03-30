#include "pt/plankton.h"

#define SCREEN_WIDTH  800
#define SCREEE_HEIGHT 450

int main() {
	pt::initWindow(SCREEN_WIDTH, SCREEE_HEIGHT, "Hello World!");

	while (!pt::windowShouldClose()) {
		pt::prepareFrame();

		pt::clearFrame({ 1.0f, 1.0f, 1.0f, 1.0f });

		// Drawing code goes here

		pt::display();
	}

	pt::shutdown();
	
	return 0;
}
