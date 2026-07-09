#ifndef	RPN_HPP
# define RPN_HPP

#include <stack>
#include <list>
#include <iostream>
#include <stdexcept>

class RPN {
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		void	set_stack(int n);
		int		get_stack(void);
		bool	isEmpty(void) const;
		bool	is_command(char command);
		void	run_command(char command);
	private:
		std::stack<int, std::list<int> > _stack;
};

#endif
