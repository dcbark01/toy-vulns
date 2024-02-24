// file: main.cpp
#include <iostream>
#include <cstring>
#include <climits>

void stackBufferOverflow(const char* input) {
    // CWE-121: Stack-based Buffer Overflow
    char buffer[10];
    strcpy(buffer, input); // No bounds checking
    std::cout << "Stack Buffer content: " << buffer << std::endl;
}

void heapBufferOverflow(const char* input) {
    // CWE-122: Heap-based Buffer Overflow
    char* buffer = new char[10];
    strcpy(buffer, input); // No bounds checking
    std::cout << "Heap Buffer content: " << buffer << std::endl;
    delete[] buffer;
}

void integerOverflow() {
    // CWE-190: Integer Overflow or Wraparound
    unsigned int uint_max = UINT_MAX;
    std::cout << "Unsigned int max: " << uint_max << std::endl;
    uint_max += 1; // This will wrap around to 0
    std::cout << "Unsigned int max + 1: " << uint_max << std::endl;
}

void integerUnderflow() {
    // CWE-191: Integer Underflow or Wraparound
    unsigned int uint_min = 0;
    std::cout << "Unsigned int min: " << uint_min << std::endl;
    uint_min -= 1; // This will wrap around to UINT_MAX
    std::cout << "Unsigned int min - 1: " << uint_min << std::endl;
}

void doubleFree() {
    // CWE-415: Double Free
    char* buffer = new char[10];
    strcpy(buffer, "double free");
    delete[] buffer;
    // Improper attempt to delete the same buffer again
    delete[] buffer; // This can lead to a double free vulnerability
}

void useAfterFree() {
    // CWE-416: Use After Free
    char* buffer = new char[10];
    strcpy(buffer, "use after free");
    delete[] buffer;
    // Use after free
    std::cout << "Use After Free content: " << buffer << std::endl; // This can lead to undefined behavior
}

int main(int argc, char** argv) {
    if (argc > 1) {
        stackBufferOverflow(argv[1]);
        heapBufferOverflow(argv[1]);
    } else {
        std::cout << "Usage: " << argv[0] << " <input_string>" << std::endl;
    }

    integerOverflow();
    integerUnderflow();
    doubleFree();
    useAfterFree();

    return 0;
}
