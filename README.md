# MLbase

MLbase is a collection of basic machine learning algorithms implemented in C++ and Python. The project provides fundamental implementations of classification and clustering algorithms, making it a useful resource for learning and experimenting with machine learning concepts.

## Features

- **Classification Algorithms**
- **Clustering Algorithms (including K-Means)**
- **Implementations in both C++ and Python**

## Repository Structure

The repository is organized as follows:

```
MLbase/
│── C++/         # C++ implementations of ML algorithms
│── Py/          # Python implementations of ML algorithms
│   ├── KmeansC/ # K-means clustering implementation in Python
```

## Getting Started

### Clone the Repository

```bash
git clone https://github.com/Ol3hhh/MLbase.git
```

### Navigate to the Desired Directory

```bash
cd MLbase/C++   # For C++ implementations
cd MLbase/Py    # For Python implementations
```

### Running C++ Implementations

1. Compile the C++ source file:

   ```bash
   g++ -o algorithm algorithm.cpp
   ```

2. Run the compiled program:

   ```bash
   ./algorithm
   ```

### Running Python Implementations

1. Ensure Python 3.x is installed.
2. Run the script:

   ```bash
   python algorithm.py
   ```

# Requirements

For running MLbase, ensure you have the following dependencies installed.

## C++ Requirements
- C++11 or later
- A C++ compiler (e.g., GCC, Clang, MSVC)
- ncurses library
## Python Requirements
- Python 3.x
- Required Python packages:

  ```
  numpy
  matplotlib
  ```

### Installing Python Dependencies
To install the required Python libraries, run:

```bash
pip install numpy
pip install matplotlib 
```










