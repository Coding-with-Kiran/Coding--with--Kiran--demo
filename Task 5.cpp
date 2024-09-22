#include <iostream>   // Including the input/output stream library
#include <fstream>    // Including the file stream library
#include <string>     // Including the string handling library

int main() {
  // Open the input file
  std::ifstream inputFile("test.txt");    // Opening the file named "test.txt" for reading
  // Create or overwrite the output file
  std::ofstream outputFile("test_copy.txt");  // Creating/overwriting the file named "test_copy.txt" for writing

  if (inputFile.is_open() && outputFile.is_open()) {  // Checking if both input and output files were successfully opened
    std::string line;  // Declaring a string variable to store each line of text

    while (std::getline(inputFile, line)) {  // Loop through each line in the input file
      // Write each line to the output file
      outputFile << line << "\n";  // Writing each line to the output file with a newline character
    }

    inputFile.close();   // Closing the input file after copying
    outputFile.close();  // Closing the output file after copying

    std::cout << "File copied successfully." << std::endl;  // Displaying success message
  } else {
    std::cout << "Failed to open the files." << std::endl;  // Display an error message if file opening failed
  }

  return 0;  // Return 0 to indicate successful execution
}
