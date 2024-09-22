#include <iostream>   // Including the input/output stream library
#include <fstream>    // Including the file stream library
#include <string>     // Including the string handling library

// Function to display the content of a file
void displayFileContent(const std::string & filename) {
  std::ifstream file(filename); // Open file with given filename
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

int main() {
  std::ifstream inputFile("test.txt"); // Open the input file named "test.txt" for reading
  std::ofstream outputFile("new_test.txt"); // Create or overwrite the output file named "new_test.txt" for writing

  if (inputFile.is_open() && outputFile.is_open()) { // Check if both input and output files were successfully opened
    std::string line; // Declare a string variable to store each line of text
    std::string searchWord = "C++"; // Define the word to search for
    std::string replaceWord = "CPP"; // Define the word to replace with

    std::cout << "Search word:" << searchWord << std::endl; // Display the word to search for
    std::cout << "Replace word:" << replaceWord << std::endl; // Display the word to replace with

    std::cout << "\nBefore find and replace:" << std::endl; // Display a message before find and replace
    displayFileContent("test.txt"); // Display the content of the input file before find and replace

    while (std::getline(inputFile, line)) { // Loop through each line in the input file
      size_t pos = line.find(searchWord); // Find the position of the search word in the line

      while (pos != std::string::npos) { // Repeat until all occurrences are replaced
        line.replace(pos, searchWord.length(), replaceWord); // Replace the search word with the replace word
        pos = line.find(searchWord, pos + replaceWord.length()); // Find the next occurrence of the search word
      }
      outputFile << line << "\n"; // Write the modified line to the output file
    }

    inputFile.close(); // Close the input file
    outputFile.close(); // Close the output file

    std::cout << "After find and replace:" << std::endl; // Display a message after find and replace
    displayFileContent("new_test.txt"); // Display the content of the output file after find and replace

    std::cout << "\nWord replaced successfully." << std::endl; // Display a success message
  } else {
    std::cout << "\nFailed to open the files." << std::endl; // Display an error message if file opening failed
  }

  return 0; // Return 0 to indicate successful execution
}
