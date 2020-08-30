#include "global_info.h"

//static const initialization
const char* GlobalConfig::VERSION_NAME = "Malenchenko(v1.0)";
const char* GlobalConfig::INDEX_HTML = "assets/index.html";

string GlobalConfig::read_html_file(const char* file_name) {
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

void GlobalConfig::load_config(const char* file) {

}

void GlobalConfig::save_config(const char* file) {

}
