# Image-Analysis-Using-Amazon-Rekognition
This project, developed as part of CS 211: Fundamentals of Computer Programming II, demonstrates foundational C++ skills through an AI-powered image analysis application.

Using Amazon's Rekognition service, the program analyzes a set of images and extracts high-confidence object labels (≥ 80% confidence). For each label, the program also tracks which images were associated with it.

🛠️ Key Features
* Reads and processes .jpg images from a user-specified directory

* Leverages a provided Rekognition C++ library to return image labels

* Stores and displays the confidence score for each detected label

* Tabulates and reports label-to-image associations

* Filters results based on a minimum 80% confidence threshold

🔧 Technologies Used:
* C++17

* Amazon Rekognition (via provided C++ wrapper)

* Standard Template Library (STL): vectors, strings, file I/O

* Git for version control

📌 Concepts used in this project:

* Image processing

* Structs & vectors

* Basic file system traversal

* API interaction via libraries

