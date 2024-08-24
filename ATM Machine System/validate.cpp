#include "validate.h"

#include <iostream>
#include <limits>


void ignoreline() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}