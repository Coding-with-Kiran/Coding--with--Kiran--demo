#include <iostream>   // Including the input/output stream library
#include <fstream>    // Including the file stream library
#include <string>     // Including the string handling library
#include <vector>     // Including the vector container

// Function to display the content of a file
void displayFileContent(const std::string & filename) {
  std::ifstream file(filename); // Open file with given filename for reading
  std::string line; // Declare a string to store each line of text

  if (file.is_open()) { // Check if the file was successfully opened
    std::cout << "File content:" << std::endl; // Displaying a message indicating file content
    while (std::getline(file, line)) { // Read each line from the file
      std::cout << line << std::endl; // Display each line of the file
    }
    file.close(); // Close the file
  } else {
    std::cout << "Failed to open the file." << std::endl; // Display an error message if file opening failed
  }
}

// Function to search for a string in a file and display line numbers where it is found
void searchAndDisplayLineNumbers(const std::string & filename, const std::string & searchStr) {
  std::ifstream file(filename); // Open file with given filename for reading
  std::string line; // Declare a string to store each line of text
  std::vector<int> lineNumbers; // Vector to store line numbers where the search string is found
  int lineNumber = 1; // Variable to track the current line number

  while (std::getline(file, line)) { // Read each line from the file
    if (line.find(searchStr) != std::string::npos) { // Check if the search string is found in the line
      lineNumbers.push_back(lineNumber); // Store the line number where the search string is found
    }
    lineNumber++; // Increment the line number counter
  }

  file.close(); // Close the file after reading

  if (!lineNumbers.empty()) { // Check if any line numbers were stored
    std::cout << "String \"" << searchStr << "\" found at line number(s): "; // Display a message indicating the search string was found

    for (int i = 0; i < lineNumbers.size(); ++i) { // Loop through the stored line numbers
      std::cout << lineNumbers[i]; // Display each line number

      if (i != lineNumbers.size() - 1) {
        std::cout << ", "; // Display a comma between line numbers, except for the last one
      }
    }

    std::cout << std::endl; // Move to the next line after displaying line numbers
  } else {
    std::cout << "String \"" << searchStr << "\" not found in the file." << std::endl; // Display a message indicating the search string was not found
  }
}

int main() {
  std::string filename = "test.txt"; // File to search
  displayFileContent("new_test.txt"); // Display content of "new_test.txt"
  std::cout << std::endl; // Output a newline for formatting

  std::string searchStr = "currently"; // String to search
  searchAndDisplayLineNumbers(filename, searchStr); // Search for the string in the file and display line numbers where it's found

  return 0; // Return 0 to indicate successful execution
}
