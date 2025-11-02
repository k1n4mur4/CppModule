#pragma once

#include <string>

class Contact {
	private:
		std::string			first_name;
		std::string			last_name;
		std::string			nickname;
		std::string			number;
		std::string			secret;
	public:
		const std::string&	get_firstname(void) const;
		const std::string&	get_lastname(void) const;
		const std::string&	get_nickname(void) const;
		const std::string&	get_number(void) const;
		const std::string&	get_secret(void) const;
		void				set_firstname(const std::string& first_name);
		void				set_lastname(const std::string& last_name);
		void				set_nickname(const std::string& nickname);
		void				set_number(const std::string& number);
		void				set_secret(const std::string& secret);
};
