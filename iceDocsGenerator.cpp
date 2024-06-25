#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <vector>

using namespace std;

int getLastThing(string token, char lookFor) {
	for (int c = token.length() - 1; c >= 0; c--) {
		if (token[c] == lookFor) {
			return c;
		}
	}
	return 0;
}

// FIXME: pairs break the system because of ", "
void processFile(const string& filePath, ofstream& outFile) {
	ifstream file(filePath);
	string line;
	string currentComment = "";
	bool comment = false;
	string returnsStr = "N/A";

	vector<pair<string, string>> params;

	while (getline(file, line)) {
		// NOT MY FILE
		if (line.substr(0, 70) == "/*********************************************************************") {
			return;
		}
		// cout << line << " [Comment: " << comment << "]\n";
		if (comment) {
			if (line.length() < 3) {
				comment = false;
				currentComment = "";
				returnsStr = "N/A";
				params.clear();
				continue;
			}
			string trueLine = line.substr(3);
			int param = trueLine.find("@param");
			int returns = trueLine.find("@return");
			if (param != string::npos) {
				string paramStr = trueLine.substr(6);
				int paramStart = paramStr.find("{");
				int paramEnd = paramStr.find("}");
				params.push_back({paramStr.substr(paramStart + 1, paramEnd - paramStart - 1), paramStr.substr(paramEnd + 2)});
			}
			else if (returns != string::npos) {
				returnsStr = trueLine.substr(7);
			}
			else {
				currentComment += trueLine;
			}
		}
		if (line.length() >= 3 && line.substr(0, 3) == "/**") {
			comment = true;
		}
		if (line.length() >= 3 && line.substr(0, 3) == " */") {
			comment = false;
		}

		int colon = getLastThing(line, ':');
		int doubleColon = line.find("::");

		if (colon != string::npos && colon != doubleColon + 1) {
			line = line.substr(0, colon);
		}

		int argStart = line.find("(");
		int argEnd = getLastThing(line, ')');

		if (line.length() >= 1 && line.at(0) != '\t' && argStart != string::npos && argEnd != string::npos) {
			string start = line.substr(0, argStart);
			int lastSpace = getLastThing(start, ' ');
			string returnType = line.substr(0, lastSpace);

			int titleStart = (lastSpace == 0) ? lastSpace : lastSpace + 1;

			string functionName = line.substr(titleStart, argStart - titleStart);
			
			if (functionName != "") {
				outFile << "### " << functionName << endl;

				string args = line.substr(argStart + 1, argEnd - argStart - 1);

				outFile << "| **Type** | **Variable Name** | **Description** | \n";
				outFile << "| :------: | :---------------: | :-------------: | \n";
				while (args != "") {
					int pos = args.find(", ");
					if (pos == string::npos) {
						pos = args.length();
					}
					string token = args.substr(0, pos);
					lastSpace = getLastThing(token, ' ');

					string type = token.substr(0, lastSpace);
					string varName = token.substr(lastSpace + 1);

					string description = "N/A";

					for (pair<string, string> pss : params) {
						if (pss.first == varName) {
							description = pss.second;
						}
					}

					// For a function that is passed in as an argument
					int where = varName.find("(*");
					if (where != string::npos) {
						varName = varName.substr(0, where) + "(\\*" + varName.substr(where + 2);
					}

					outFile << "| " << type << " | " << varName << " | " << description << " |\n";

					args.erase(0, pos + 2);
				}

				outFile << "\n**Return Type:** " << returnType << " (" << returnsStr << ")\n\n\n";
			}

			currentComment = "";
			returnsStr = "N/A";
			params.clear();
		}
	}
}

void processDirectory(const string& dirPath, ofstream& outFile) {
	DIR* dir = opendir(dirPath.c_str());
	if (!dir) {
		cerr << "Failed to open directory: " << dirPath << endl;
		return;
	}

	struct dirent* entry;
	while ((entry = readdir(dir)) != nullptr) {
		string fileName = entry->d_name;
		if (fileName == "." || fileName == "..") {
			continue;
		}
		string filePath = dirPath + "/" + fileName;
		if (fileName.size() > 4 && fileName.substr(fileName.size() - 4) == ".cpp") {
			cout << "Processing " << filePath << endl;
			outFile << "## " << filePath << endl;
			processFile(filePath, outFile);
		}
	}
	closedir(dir);
}

int main() {
	ofstream outFile("README.md");
	if (!outFile) {
		cerr << "Failed to open output file." << endl;
		return 1;
	}
	
	outFile << "# Project Documentation\n\n";

	processDirectory("src", outFile);

	outFile.close();
	cout << "Documentation generated in README.md" << endl;

	return 0;
}
