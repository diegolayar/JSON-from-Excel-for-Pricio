#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main() {
	fstream file( "./porfa.csv");
	vector<string> codes;
	string line;
	char val;
	while(getline(file, line))
	{
		stringstream ss(line);
		string helper = "";
		while(ss.get(val)) {
			helper.push_back(val);
			if(ss.peek() == ',' || ss.peek() == '.') {
				cout << helper << endl;
				codes.push_back(helper);
				helper = "";
				ss.ignore();
			}
		}
	}

	file.close();
	ofstream newFile;
	newFile.open("casadiego.json");
	newFile << "{";
	for(int i = 0; i < codes.size(); i+=3) {
		string namehelper = codes[i + 1];
		string pricehelper = codes[i + 2];
		newFile << "\n\t\"" << codes[i] << "\" : {\n\t\t";
		newFile << "\"foto\" : \"\",\n\t\t";
		newFile << "\"name\" : \""<< namehelper << "\",\n\t\t";
		newFile << "\"price\" : \""<< pricehelper << "\"\n\t},";
	}
	newFile.close();
}
