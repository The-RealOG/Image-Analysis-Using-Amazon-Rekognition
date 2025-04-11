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

int main() {
	cout <<"** starting **" << endl;

	cout << "Enter a directory name (or '.' for current directory)" << endl;
	string dirName;
	cin >> dirName;
	
	//string filename = "degu.jpg";
	//rekognitionLabels = rekognition.getLabels(filename, validFile);

	//To confirm that the given directory actually exists
	if (!filesystem::is_directory(dirName)) {
		cout << "not a directory, exiting..." << endl;
		return 0;
	}
	
	//Iterate through each file in the provided directory
	for (auto &entry : filesystem::directory_iterator(dirName)) {
		if (filesystem::is_regular_file(entry)) {
			string filename = entry.path().string();

			//looks out for the ".jpg" extension
			if (entry.path().extension()== ".jpg") {
				cout << filename << endl;

				//Initiate a rekognition object
				Rekognition rekognition;
				bool validFile;
				vector<Rekognition::LabelInfo> rekognitionLabels = rekognition.getLabels(filename, validFile);
				}
			}
		}

	if (!validFile) {
		cout << "invalid image file!" << endl;
		return 1;
		
	} else {
		for (const auto &labelInfo : rekognitionLabels) {
			cout << labelInfo.label << ": confidence of " << labelInfo.confidence << "%" << endl;
		        }
	}
	return 0;
};
