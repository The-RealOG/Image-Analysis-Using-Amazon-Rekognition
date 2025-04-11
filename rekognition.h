/*rekognition.h*/

//
// Header file for Rekognition class, providing access to 
// Amazon's AI-based image recognition system.
//
// Prof. Joe Hummel
// Northwestern University
//

#pragma once

#include <string>
#include <vector>

using namespace std;

class Rekognition {
    public:
      struct LabelInfo {
        string label;
        int    confidence;
      };

      // default constructor:
      Rekognition();

      // destructor:
      ~Rekognition();

      // getLabels:
      vector<Rekognition::LabelInfo> getLabels(string image_filename, bool& validFile);
};
