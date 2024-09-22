#include <iostream>   // Including the input/output stream library
#include <fstream>    // Including the file stream library
#include <vector>     // Including the vector container
#include <algorithm>  // Including algorithms like 'sort'
#include <iterator>   // Including iterator operations

// Function to display the content of a file
void displayFileContent(const std::string & filename) {
  std::ifstream file(filename);  // Open file with given filename for reading
  std::string line;  // Declare a string to store each line of text

  if (file.is_open()) {  // Check if the file was successfully opened
    std::cout << "File content:" << std::endl;  // Displaying a message indicating file content
    while (std::getline(file, line)) {  // Read each line from the file
      std::cout << line << std::endl;  // Display each line of the file
    }
    file.close();  // Close the file
  } else {
    std::cout << "Failed to open the file." << std::endl;  // Display an error message if file opening failed
  }
}

int main() {
  std::ifstream inputFile("test1.txt");  // Open the input file named "test1.txt" for reading
  displayFileContent("test1.txt");  // Display content of "test1.txt"
  std::ofstream outputFile("sorted_test1.txt");  // Create or overwrite the output file named "sorted_test1.txt" for writing

  if (inputFile.is_open() && outputFile.is_open()) {  // Check if both input and output files were successfully opened
    std::vector<std::string> lines;  // Vector to store the lines of the file
    std::string line;  // Declare a string variable to store each line of text

    while (std::getline(inputFile, line)) {  // Read each line from the input file and store it in the vector
      lines.push_back(line);  // Push each line to the vector
    }

    std::sort(lines.begin(), lines.end());  // Sort the lines in alphabetical order

    std::copy(lines.begin(), lines.end(), std::ostream_iterator<std::string>(outputFile, "\n"));  // Write the sorted lines to the output file

    inputFile.close();  // Close the input file
    outputFile.close();  // Close the output file

    std::cout << "\nLines sorted successfully.\n" << std::endl;  // Display a success message
    displayFileContent("sorted_test1.txt");  // Display content of "sorted_test1.txt"
  } else {
    std::cout << "\nFailed to open the files." << std::endl;  // Display an error message if file opening failed
  }

  return 0;  // Return 0 to indicate successful execution
}
