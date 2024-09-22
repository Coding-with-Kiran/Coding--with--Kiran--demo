#include <iostream>     // Including the input/output stream library
#include <fstream>      // Including the file stream library
#include <string>       // Including the string handling library
#include <sstream>      // Including the stringstream library

int main() {
  std::ifstream inputFile("test.txt"); // Open the text file named "test.txt" for reading

  if (inputFile.is_open()) {  // Checking if the file was successfully opened
    std::string line;         // Declaring a string variable to store each line of text
    int wordCount = 0;        // Initializing a variable to count words

    while (std::getline(inputFile, line)) {  // Loop through each line in the file
      std::stringstream ss(line);  // Create a stringstream object with the current line content
      std::string word;  // Declare a string variable to store each word

      while (ss >> word) {  // Extract words from the stringstream
        wordCount++;  // Increment word count for each word extracted
      }
    }

    inputFile.close();  // Closing the file after counting words

    std::cout << "Number of words in the said file: " << wordCount << std::endl;  // Outputting the total word count
  } else {
    std::cout << "Failed to open the file." << std::endl;  // Display an error message if file opening failed
  }

  return 0;  // Return 0 to indicate successful execution
}
