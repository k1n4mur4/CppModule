/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:24:42 by kinamura          #+#    #+#             */
/*   Updated: 2025/08/29 01:24:43 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Contact {
	private:
		std::string			firstName;
		std::string			lastName;
		std::string			nickName;
		std::string			phoneNumber;
		std::string			secret;
	public:
		const	std::string&	getFirstName(void) const;
		const	std::string&	getLastName(void) const;
		const	std::string&	getNickName(void) const;
		const	std::string&	getPhoneNumber(void) const;
		const	std::string&	getSecret(void) const;
		void					setFirstName(const std::string& firstName);
		void					setLastName(const std::string& lastName);
		void					setNickName(const std::string& nickName);
		void					setPhoneNumber(const std::string& phoneNumber);
		void					setSecret(const std::string& secret);
};
