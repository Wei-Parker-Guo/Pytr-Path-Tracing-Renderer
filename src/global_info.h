#ifndef GLOBAL_INFO_H
#define GLOBAL_INFO_H
/*
	GLOBAL INFO POOL FOR PYTR, DON'T EDIT
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string read_html_file(const char* file_name);

//function to read a raw html string given a file
string read_html_file(const char* file_name) {
	ifstream file(file_name);
	string content;
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			content += (line + "\n");
		}
	}
	file.close();
	return content;
}

const char* VERSION_NAME = "Malenchenko(v1.0)";
const char* INDEX_HTML = "assets/index.html";


#endif // !GLOBAL_INFO_H
