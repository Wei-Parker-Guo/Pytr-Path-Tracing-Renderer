#ifndef GLOBAL_INFO_H
#define GLOBAL_INFO_H
/*
	GLOBAL INFO POOL FOR PYTR, DON'T EDIT
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//class to store settings for the entire renderer
class GlobalConfig {
public:
	//parameters
	static const char* VERSION_NAME;
	static const char* INDEX_HTML;
	vector<string>* shader_list;

	//function to read a raw html string given a file
	string read_html_file(const char* file_name);
	//method to load config from an arbitrary file, a fallback path will be provided as default
	void load_config(const char* file);
	//method to save config into an arbitrary file
	void save_config(const char* file);
};


#endif // !GLOBAL_INFO_H
