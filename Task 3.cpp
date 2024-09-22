#include <iostream>   // Including the input/output stream library

#include <fstream>    // Including the file stream library

#include <string>     // Including the string handling library

int main() {
  // Open the text file
  std::ifstream inputFile("test.txt");  // Opening the file named "test.txt" for reading

  if (inputFile.is_open()) {  // Checking if the file was successfully opened
    std::string line;  // Declaring a string variable to store each line of text
    int lineCount = 0;  // Initializing a variable to count lines

    while (std::getline(inputFile, line)) {  // Loop through each line in the file
      lineCount++;  // Incrementing line count for each line read
    }

    inputFile.close();  // Closing the file after counting lines

    std::cout << "Number of lines in the file: " << lineCount << std::endl;  // Outputting the total line count
  } else {
    std::cout << "Failed to open the file." << std::endl;  // Display an error message if file opening failed
  }

  return 0;  // Return 0 to indicate successful execution
}
