#include "Base.hpp"
#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	std::srand(std::time(NULL));

	for (int i = 0; i < 5; ++i) {
		Base* obj = generate();
		std::cout << "Test " << i << ": ";
		std::cout << "pointer version -> ";
		identify(obj);
		std::cout << "         reference version -> ";
		identify(*obj);
		delete obj;
	}
	return 0;
}
