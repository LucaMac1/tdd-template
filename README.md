# Test-Driven Development (TDD) - Google Test Introduction

## 1) Installing Google Test from the Repository

1. Clone the Google Test repository:
   ```bash
   git clone https://github.com/google/googletest.git -b release-1.12.1

2. Navigate to the googletest directory and build it:

    cd googletest
    mkdir build
    cd build/
    cmake .. -DBUILD_GMOCK=OFF
    make
    make install

3. After installation, you will find the static libraries libgtest.a and libgtest_main.a in the lib/ directory.

## 2) Hello World Example

1. Create a file named example.cpp with your test code.
2. Compile the file using the following command:
   g++ example.cpp /usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a -lpthread -I /usr/local/include/ -o firsttest.out
