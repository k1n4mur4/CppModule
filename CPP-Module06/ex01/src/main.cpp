#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data original;
	original.id = 42;
	original.name = "Hello";

	Data* originalPtr = &original;

	uintptr_t raw = Serializer::serialize(originalPtr);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original address:  " << originalPtr << std::endl;
	std::cout << "Serialized value:  " << raw << std::endl;
	std::cout << "Restored address:  " << restored << std::endl;

	if (originalPtr == restored) {
		std::cout << "OK: pointers match" << std::endl;
		std::cout << "id=" << restored->id 
				<< ", name=" << restored->name << std::endl;
	} else {
		std::cout << "FAIL: pointers differ" << std::endl;
	}
	return 0;
}
