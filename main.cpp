//imports the necessary libraries
#include "rekognition.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

int directoryExists(string& dirName, bool& validFile) {
	if (!((fs::exists(dirName)) && (fs::is_directory(dirName)))) {
		cout << "not a directory, exiting..." << endl;
			validFile = false;
			return 1;
		}
};

int analyzeJpeg(string& dirName, bool& validFile, vector<string>& results) {
	for (auto &entry : fs::directory_iterator(dirName)) {
			if (fs::is_regular_file(entry)) {
				string filename = entry.path().string();
	
				//looks out for the ".jpg" extension
				if (entry.path().extension() == ".jpg") {
					cout << filename << endl;
	
					//Initiate a rekognition object
					Rekognition rekognition;
					vector<Rekognition::LabelInfo> rekognitionLabels = rekognition.getLabels(filename, validFile);

					//Iterates through the list of structs and prints the label and confidence level/percentage
					if (!validFile) {
							cout << "invalid image file!" << endl;
							return 1;
							
						} else {
							for (const auto &labelInfo : rekognitionLabels) {
								results.push_back(labelInfo.label); //vector of labels only
							        }
						}
				}
			}
		}
		return 0;
	};

int main() {
	cout <<"** starting **" << endl;

	cout << "Enter a directory name (or '.' for current directory)" << endl;
	string dirName;
	bool validFile = true;
	cin >> dirName;
	vector<Rekognition::LabelInfo> rekognitionLabels;
	vector<string> results;
	
	
	//string filename = "degu.jpg";
	//rekognitionLabels = rekognition.getLabels(filename, validFile);

	//To confirm that the given directory actually exists
	directoryExists(dirName, validFile);
	
	//Iterate through each file in the provided directory, process and return the labels for each image.
	analyzeJpeg(dirName, validFile, results);

	//sorts the labels in alphabetical order
	sort(results.begin(), results.end());

	for (const string& label: results) {
		cout << label << endl;
	}

	
	return 0;
};
