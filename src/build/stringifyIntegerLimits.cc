#include <iostream>
#include <climits>

unsigned int digitsCountOfMin() {
	long min = LONG_MIN;
	unsigned long digits = 0;
	while(min != 0) {
		++digits;
		min /= 10;
	}
	return digits;
}

int main() {

	std::cout << "#pragma once" << std::endl << std::endl;
	std::cout << "#include \"../../String/ConstString/ConstString.h\"" << std::endl << std::endl;
	std::cout << "namespace StringifiedIntegerLimits {" << std::endl;
	std::cout << "\tConstString Max = {\"" << LONG_MAX << "\"};" << std::endl << std::endl;
	std::cout << "\tConstString Min = {\"" << LONG_MIN << "\"};" << std::endl << std::endl;
	std::cout << "\tconst unsigned int DigitsCountOfMin = " << digitsCountOfMin() << ";" << std::endl;
	std::cout << "}" << std::endl;

	return 0;
}