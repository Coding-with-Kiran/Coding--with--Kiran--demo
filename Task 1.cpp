#include <iostream>  // Include the input/output stream library

#include <fstream>   // Include the file stream library

int main() {
  // Create a new file named "test.txt"
  std::ofstream outputFile("test.txt");  // Open/create a file named "test.txt" for writing

  if (outputFile.is_open()) {  // Check if the file was successfully opened
    // Write some text into the file
    outputFile << "C++ is a high-level, general-purpose programming language created by Danish computer scientist Bjarne Stroustrup. \n";  // Write a line of text to the file
    outputFile << "First released in 1985 as an extension of the C programming language, it has since expanded significantly over time. \n";  // Write a line of text to the file
    outputFile << "Modern C++ currently has object-oriented, generic, and functional features, in addition to facilities for low-level memory manipulation.\n";  // Write a line of text to the file
    outputFile << "It is almost always implemented in a compiled language.\n";  // Write a line of text to the file
    outputFile << "Many vendors provide C++ compilers, including the Free Software Foundation, LLVM, Microsoft, Intel, Embarcadero, Oracle, and IBM.";  // Write a line of text to the file

    // Close the file
    outputFile.close();  // Close the file after writing

    std::cout << "Text has been written to the file." << std::endl;  // Display a success message
  } else {
    std::cout << "Failed to create the file." << std::endl;  // Display an error message if file creation failed
  }

  return 0;  // Return 0 to indicate successful execution
}
