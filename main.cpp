/*main.cpp*/
//This program analyzes JPG files using Rekognition, extarcts label info from each image and outputs the sorted results in a table linking
//each label to their corresponding images.

//Chibueze Anyachebelu
//Northwestern University

//imports the necessary header files for this project to compile smoothly
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

//struct to store the label and corresponding image files
struct AnalysisInfo {
	string label;
	vector<string> images;
};

//Checks if a given directory name is valid
int directoryExists(string& dirName, bool& validFile) {
	if (!((fs::exists(dirName)) && (fs::is_directory(dirName)))) {
		cout << "Not a directory, exiting..." << endl;
			validFile = false;
			return 0;
		}
};

//Analyzes the images and stores the required info
int analyzeJpeg(string dirName, bool& validFile, vector<AnalysisInfo>& results) {
	for (auto &entry : fs::directory_iterator(dirName)) {
			if (fs::is_regular_file(entry)) {
				string filename = entry.path().string();
	
				//looks out for the ".jpg" extension
				if (entry.path().extension() == ".jpg") {
					cout << "analyzing '" << filename << "'..." << endl;
	
					//Initiate a rekognition object
					Rekognition rekognition;
					vector<Rekognition::LabelInfo> rekognitionLabels = rekognition.getLabels(filename, validFile);

					cout << "# of labels identified: " << rekognitionLabels.size() << endl;

					//Iterates through the list of structs and prints the label and confidence level/percentage and file name
					if (!validFile) {
							cout << "** invalid image file! **" << endl;
							return 0;
							
						} else {
							for (const auto &labelInfo : rekognitionLabels) {
							bool found = false;
								//checks if the label is alraeady in vector of structs
								for (AnalysisInfo& info : results) {
									if (info.label == labelInfo.label) {
										if (find(info.images.begin(),info.images.end(), filename) == info.images.end()){
										info.images.push_back(filename);
										}
										found = true;
										break;
									}
								}
								
								//creates a new copy should the label not be in the results vector
								if (!found) {
									AnalysisInfo newInfo;
									newInfo.label = labelInfo.label;
									newInfo.images.push_back(filename);
									results.push_back(newInfo); //vector of labels only
								}
								
							        					}
							}
													}
	 			}
			}
			};

int main() {
	cout <<"** starting **" << endl;
	cout << "Enter a directory name (or '.' for current directory)>" << endl;

	//Prompts user to input their preferred directory name
	string dirName;
	bool validFile = true;
	cin >> dirName;

	//store the results in label-image format
	vector<Rekognition::LabelInfo> rekognitionLabels;
	vector<AnalysisInfo> results;
	
	
	//string filename = "degu.jpg";
	//rekognitionLabels = rekognition.getLabels(filename, validFile);

	//To confirm that the given directory actually exists
	directoryExists(dirName, validFile);

	//In case an invalid dir is passed, it exits the program
	if (!validFile) {
		return 0;
	}
	
	//Iterate through each file in the provided directory, process each image.
	analyzeJpeg(dirName, validFile, results);


	// Sort results by label alphabetically
	sort(results.begin(), results.end(),
	[](AnalysisInfo info1, AnalysisInfo info2) {
		return info1.label < info2.label;
	});

	
	//print the results
	cout << "\nLabel: image(s)" << endl;
	for (const AnalysisInfo& info : results) {
		cout << info.label << ": ";

		for (const string& img : info.images) {
			cout << img << " ";
		}
		cout << endl;
	}

	cout << "** done **" << endl;
	
	return 0;  //code completed
};
