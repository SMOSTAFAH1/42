#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string replaceAll(const std::string& str, const std::string& s1, const std::string& s2) {
	if (s1.empty())
		return str;
	
	std::string result;
	size_t pos = 0;
	size_t found = 0;
	
	while ((found = str.find(s1, pos)) != std::string::npos) {
		result.append(str, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(str, pos, str.length() - pos);
	
	return result;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	
	const std::string filename = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];
	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}
	
	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return 1;
	}
	
	std::ostringstream buffer;
	buffer << infile.rdbuf();
	if (infile.bad()) {
		std::cerr << "Error: Failed while reading file " << filename << std::endl;
		return 1;
	}
	const std::string content = buffer.str();
	
	std::string replaced = replaceAll(content, s1, s2);
	
	std::string outfilename = filename + ".replace";
	std::ofstream outfile(outfilename.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Cannot create file " << outfilename << std::endl;
		return 1;
	}
	
	if (!(outfile << replaced)) {
		std::cerr << "Error: Failed while writing file " << outfilename << std::endl;
		return 1;
	}
	
	return 0;
}
