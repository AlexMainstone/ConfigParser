#ifndef CONFIGPARSER_H_
#define CONFIGPARSER_H_

#include<map>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

namespace cnfp {
	std::map<std::string, std::string> getConfig(const char *filepath) {
		std::map<std::string, std::string> tmpMap;
		std::ifstream file(filepath);
		
		std::string line;
		while(getline(file, line)) {
			std::string key, value;

			std::stringstream split(line);
			std::getline(split, key, '=');
			std::getline(split, value);

			tmpMap[key] = value;
		}
		return tmpMap;
	}

	void writeMap(std::map<std::string, std::string> map, const char *filepath) {
		std::ofstream file;
		file.open(filepath);
		for(std::map<std::string, std::string>::iterator it = map.begin(); it != map.end(); ++it) {
			file << it->first << "=" << map[it->first] << "\n";
		}
		file.close();
	}
}

#endif // CONFIGPARSER_H_
