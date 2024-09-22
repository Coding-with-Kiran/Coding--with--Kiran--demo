#include <iostream>   // Including the input/output stream library
#include <fstream>    // Including the file stream library
#include <string>     // Including the string handling library
#include <vector>     // Including the vector container

// Function to split a file into smaller chunks
void splitFile(const std::string & inputFile, const std::string & outputPrefix, int chunkSize) {
  // Open the input file in binary mode
  std::ifstream input(inputFile, std::ios::binary); // Open the input file in binary mode

  if (input.is_open()) { // Check if the input file was successfully opened
    // Get the file size
    input.seekg(0, std::ios::end); // Move the file pointer to the end of the file
    std::streampos fileSize = input.tellg(); // Get the current position of the file pointer, indicating the file size
    input.seekg(0, std::ios::beg); // Move the file pointer back to the beginning of the file

    // Calculate the number of chunks
    int numChunks = (fileSize + chunkSize - 1) / chunkSize; // Calculate the number of chunks based on file size and chunk size

    // Read and write each chunk
    for (int i = 0; i < numChunks; ++i) { // Iterate through each chunk
      // Create or overwrite the output file with an incremental suffix
      std::ofstream output(outputPrefix + std::to_string(i + 1) + ".txt", std::ios::binary); // Create or overwrite the output file

      if (output.is_open()) { // Check if the output file was successfully opened
        std::vector<char> buffer(chunkSize); // Create a buffer to hold the chunk data

        // Read a chunk of data from the input file
        input.read(buffer.data(), chunkSize); // Read chunkSize number of bytes into the buffer

        // Write the chunk to the output file
        output.write(buffer.data(), input.gcount()); // Write the read data from the buffer to the output file

        output.close(); // Close the output file
      } else {
        std::cout << "Failed to open output file: " << outputPrefix + std::to_string(i + 1) + ".txt" << std::endl; // Display an error message if output file opening failed
      }
    }

    input.close(); // Close the input file

    std::cout << "File split successfully." << std::endl; // Display a success message after splitting
  } else {
    std::cout << "Failed to open the input file." << std::endl; // Display an error message if input file opening failed
  }
}

int main() {
  std::string inputFile = "merged_test_file.txt"; // Input file
  std::string outputPrefix = "part_"; // Prefix for output files
  int chunkSize = 400; // Chunk size in bytes
  splitFile(inputFile, outputPrefix, chunkSize); // Call the function to split the file
  return 0; // Return 0 to indicate successful execution
}
