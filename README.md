# John-Crickett-Coding-Challenges

## Challenge 1: Build Your Own wc Tool

### Description:
A simple tool that takes a file name as input and returns various statistics. This tool supports the following arguments:

### Args:
- `-l <filename>` : Line count
- `-w <filename>` : Word count
- `-c <filename>` : Character count
- `-b <filename>` : Byte count
- `-uw <filename>` : Unique word count
- `-aw <filename>` : Average word length
- `-sc <filename> <char>` : Specific character count

### Example Usage:
cwctool -uw test.txt
- Returns the total number of unique word count in the file
![image](https://github.com/butterfling/John-Crickett-Coding-Challenges/assets/111627573/fa65b9bb-8738-4baf-a805-e1b3e9b376f0)

cwctool -l test.txt
- Returns the total number of lines in the file 
![image](https://github.com/butterfling/John-Crickett-Coding-Challenges/assets/111627573/ce04843b-d6d8-4d70-ae03-3750ab952369)


### How to Run:
This project uses CMake and Ninja build systems. Follow the steps below to set up and run the project:

1. **Install Dependencies:**
   - Ensure you have CMake and Ninja installed on your system.
     - For CMake, download from [cmake.org](https://cmake.org/download/).
     - For Ninja, download from [ninja-build.org](https://ninja-build.org/).

2. **Clone the Repository:**
   ```sh
   git clone https://github.com/butterfling/John-Crickett-Coding-Challenges.git
   cd John-Crickett-Coding-Challenges

3. **Create a Build Directory:**
   ```sh
   mkdir build
   cd build

 4. **Generate Build files with CMake**
    ```sh
    cmake -G "Ninja" ..

 5. **Build the project**
    ```sh
    ninja

 6. **Run the Executable**
    ```sh
    ./cwctool -l ../test.txt

### Demonstration in CLion IDE


