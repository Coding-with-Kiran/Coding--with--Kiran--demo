#include <iostream>   // Including the input/output stream library
#include <fstream>    // Including the file stream library
#include <string>     // Including the string handling library

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

int main() {
  displayFileContent("new_test.txt"); // Display content of "new_test.txt" before any modification
  std::cout << std::endl;

  std::ofstream outputFile; // Declare an output file stream object
  // Open the file in append mode
  outputFile.open("new_test.txt", std::ios::app); // Open "new_test.txt" in append mode

  displayFileContent("new_test.txt"); // Display content of "new_test.txt" after opening in append mode
  std::cout << std::endl;

  if (outputFile.is_open()) { // Check if the file was successfully opened
    std::string newData; // Declare a string to store new data entered by the user

    std::cout << "Enter the data to append: "; // Prompt the user to enter data
    // Read the new data from the user
    std::getline(std::cin, newData); // Get user input for new data

    // Append the new data to the file
    outputFile << newData << std::endl; // Write the new data to the file
    outputFile.close(); // Close the file

    std::cout << "Data appended successfully." << std::endl; // Display a success message
    displayFileContent("new_test.txt"); // Display content of "new_test.txt" after appending data
    std::cout << std::endl;
  } else {
    std::cout << "Failed to open the file." << std::endl; // Display an error message if file opening failed
  }

  return 0; // Return 0 to indicate successful execution
}
