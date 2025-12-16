#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	protected:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		void setIdea(int idx, const std::string& idea);
		std::string getIdea(int idx) const;
};

#endif
