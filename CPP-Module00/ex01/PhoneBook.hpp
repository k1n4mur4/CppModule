/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:24:40 by kinamura          #+#    #+#             */
/*   Updated: 2025/08/30 19:42:08 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>

class PhoneBook {
	private:
		Contact contacts[8];
		int		size;
		int		index;
	public:
		PhoneBook() : index(0), size(0) {}
		int		getSize(void) const;
		void	addContact(std::string data[5]);
		void	displayContact(int index) const;
		void	displayPhoneBook(void) const;
};
