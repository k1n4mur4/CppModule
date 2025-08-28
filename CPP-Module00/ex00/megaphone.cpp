/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:19:37 by kinamura          #+#    #+#             */
/*   Updated: 2025/08/29 00:26:20 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			for (int j = 0; argv[i][j]; ++j)
			{
				unsigned char c = static_cast<unsigned char>(argv[i][j]);
				std::cout << static_cast<char>(std::toupper(c));
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
