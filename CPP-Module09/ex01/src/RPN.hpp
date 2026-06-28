#ifndef	RPN_HPP
# define RPN_HPP

#include <stack>

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
		std::stack<int> _stack;
};

#endif
