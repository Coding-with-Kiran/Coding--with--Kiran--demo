#include <iostream>   // Including the input/output stream library
#include <fstream>    // Including the file stream library
#include <string>     // Including the string handling library

// Function to display the content of a file
void displayFileContent(const std::string &filename) {
  std::ifstream file(filename); // Open file with given filename for reading
  std::string line; // String to store each line of the file

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

// Function to calculate the average of numbers from a file
double calculateAverage(const std::string &filename) {
  std::ifstream file(filename); // Open file with given filename for reading
  double sum = 0.0; // Variable to store the sum of numbers
  double count = 0.0; // Variable to count the numbers

  if (file.is_open()) { // Check if the file was successfully opened
    double number; // Variable to store each number read from the file

    while (file >> number) { // Read each number from the file
      sum += number; // Add the number to the sum
      count++; // Increment the count of numbers
    }

    file.close(); // Close the file
  } else {
    std::cout << "Failed to open the file." << std::endl; // Display an error message if file opening failed
    return 0.0; // Return 0.0 if file opening failed
  }

  if (count > 0) { // Check if numbers were found in the file
    return sum / count; // Return the average of the numbers
  } else {
    std::cout << "No numbers found in the file." << std::endl; // Display a message if no numbers were found
    return 0.0; // Return 0.0 if no numbers were found
  }
}

int main() {
  std::string filename = "sample.txt"; // File containing numbers
  displayFileContent("sample.txt"); // Display content of "sample.txt"
  std::cout << std::endl; // Output a newline for formatting

  double average = calculateAverage(filename); // Calculate the average of numbers in the file
  std::cout << "Average: " << average << std::endl; // Display the calculated average
  return 0; // Return 0 to indicate successful execution
}
