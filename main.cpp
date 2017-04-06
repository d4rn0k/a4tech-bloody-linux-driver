#include <iostream>
#include <cstdlib>
#include "Mouse.h"

void changeBacklightLevel(Mouse myMouse);

int main() {
	Mouse myMouse;
	int address, level;
	myMouse.init();

	if (myMouse.getDevicesCount() == 1) {
		changeBacklightLevel(myMouse);
		std::exit(EXIT_SUCCESS);
	}

	do {
		myMouse.listDevices();
		std::cout << "Enter device address: ";
		std::cin >> address;
	} while (!myMouse.selectDevice(address));

	changeBacklightLevel(myMouse);

	std::exit(EXIT_SUCCESS);
}

void changeBacklightLevel(Mouse myMouse) {
	int level;

	std::cout << "Current backlight level: "
			<< (int) myMouse.getBackLightLevel() << std::endl;

	do {
		std::cout << "Select backlight level(0-3):";
		std::cin >> level;
	} while (myMouse.setBackLightLevel(level) < 0);
}
