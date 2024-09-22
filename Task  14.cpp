#include <iostream>   // Including the input/output stream library
#include <fstream>    // Including the file stream library
#include <string>     // Including the string handling library
#include <vector>     // Including the vector container library
#include <sstream>    // Including the string stream library

// Function to split a string into tokens based on a delimiter
std::vector<std::string> splitString(const std::string &str, char delimiter) {
  std::vector<std::string> tokens; // Vector to store the split tokens
  std::stringstream ss(str); // Creating a string stream from the input string
  std::string token; // String to store each token

  // Extract tokens using the specified delimiter
  while (std::getline(ss, token, delimiter)) {
    tokens.push_back(token); // Store each token in the vector
  }

  return tokens; // Return the vector of tokens
}

// Function to display the CSV file contents in tabular form
void displayCSVContents(const std::string &filename) {
  std::ifstream file(filename); // Open file with given filename for reading
  std::string line; // String to store each line of the file

  if (file.is_open()) { // Check if the file was successfully opened
    while (std::getline(file, line)) { // Read each line from the file
      std::vector<std::string> tokens = splitString(line, ','); // Split the line into tokens based on comma delimiter
      for (const std::string &token : tokens) { // Loop through each token in the line
        std::cout << token << "\t"; // Display each token followed by a tab
      }
      std::cout << std::endl; // Output a newline after displaying all tokens in a line
    }

    file.close(); // Close the file
  } else {
    std::cout << "Failed to open the file." << std::endl; // Display an error message if file opening failed
  }
}

int main() {
  std::string filename = "test.csv"; // CSV file to read

  displayCSVContents(filename); // Display contents of the CSV file in tabular form

  return 0; // Return 0 to indicate successful execution
}
