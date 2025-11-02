#include "Contact.hpp"

const std::string&	Contact::get_firstname() const {
	return (this->first_name);
}

const std::string&	Contact::get_lastname() const {
	return (this->last_name);
}

const std::string&	Contact::get_nickname() const {
	return (this->nickname);
}

const std::string&	Contact::get_number() const {
	return (this->number);
}

const std::string&	Contact::get_secret() const {
	return (this->secret);
}

void	Contact::set_firstname(const std::string& first_name) {
	this->first_name = first_name;
}

void	Contact::set_lastname(const std::string& last_name) {
	this->last_name = last_name;
}

void	Contact::set_nickname(const std::string& nickname) {
	this->nickname = nickname;
}

void	Contact::set_number(const std::string& number) {
	this->number = number;
}

void	Contact::set_secret(const std::string& secret) {
	this->secret = secret;
}
