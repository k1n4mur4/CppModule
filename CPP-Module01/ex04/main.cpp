#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>

std::string	ft_replace(std::string buffer, const std::string old_value, const std::string new_value) {
	size_t	old_length = old_value.length();
	size_t	new_length = new_value.length();
	size_t	i = 0;

	i = buffer.find(old_value);
	while (i != std::string::npos) {
		buffer.erase(i, old_length);
		buffer.insert(i, new_value);
		i = buffer.find(old_value, i + new_length);
	}
	return buffer;
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Invalid arguments" << std::endl;
		return EXIT_FAILURE;
	}
	const std::string	filename = argv[1];
	const std::string	s1 = argv[2];
	const std::string	s2 = argv[3];

	if (s1.empty()) {
		std::cout << "Invalid arguments" << std::endl;
		return EXIT_FAILURE;
	}
	std::string		buf;
	std::ifstream	infile;
	std::ofstream	outfile;

	infile.open(argv[1]);
	if (infile.is_open() != true) {
		std::perror("infile Error");
		std::cout << "Outfile not created or truncated." << std::endl;
		return EXIT_FAILURE;
	}

	outfile.open(filename + ".replace", std::ios::out | std::ios::trunc );
	if (outfile.is_open() != true) {
		std::perror("outfile Error");
		infile.close();
		std::cout << "Infile not created or truncated." << std::endl;
		return EXIT_FAILURE;
	}

	while (std::getline(infile, buf)) {
		buf = ft_replace(buf, s1, s2);
		outfile << buf;
		if (infile.peek() != EOF)
			outfile << std::endl;
	}
	infile.close();
	outfile.close();

	return EXIT_SUCCESS;
}