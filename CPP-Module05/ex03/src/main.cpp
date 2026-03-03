#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	srand(time(0));

	Intern someIntern;
	AForm* rrf;

	// 正常なケース
	rrf = someIntern.makeForm("robotomy request", "Bender");
	delete rrf;

	rrf = someIntern.makeForm("shrubbery creation", "home");
	delete rrf;

	rrf = someIntern.makeForm("presidential pardon", "Marvin");
	delete rrf;

	// 存在しないフォーム
	rrf = someIntern.makeForm("unknown form", "nobody");
	if (rrf)
		delete rrf;

	return 0;
}
