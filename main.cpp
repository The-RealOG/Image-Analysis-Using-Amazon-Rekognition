#include "rekognition.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	Rekognition rekognition;
	
	vector<Rekognition::LabelInfo> rekognitionLabels;
	
	bool validFile;
	string filename = "degu.jpg";

	rekognitionLabels = rekognition.getLabels(filename, validFile);

	if (!validFile) {
		cout << "invalid image file!" << endl;
		return 1;
		
	} else {
		for (const auto& labelInfo : rekognitionLabels) {
			cout << labelInfo.label << ": confidence of " << labelInfo.confidence << "%" << endl;
		        }
	}
	return 0;
};
