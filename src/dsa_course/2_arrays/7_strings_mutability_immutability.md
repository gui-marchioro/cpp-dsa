# Strings and Immutability

- Python, Java, Javascript, C#, Go, Ruby will handle strings as immutable data types
- This means that when we reassing a variable to another piece of text, or change it dynamically at runtime, this will allocate a new memory block containing the new string
- This characteristic should be taken into consideration when performing string manipulation, as we can have very inneficient memory handling based on such properties
- Mutable strings will let the programer to change their values inside the same memory block at runtime
- Immutable strings e.g.
    - Python
    ~~~python
    x = "DSA"
    hex(id(x)) # OUT: "0x10557a190" (sample memory address)
    x = "aaa"
    hex(id(x)) # OUT: "0x10557a910" (different memory address)
    ~~~
- In comparison, C and C++ give the programmer the ability to have mutable or immutable strings depending on how it is declared
- Mutable e.g
    - C
    ~~~C
    char str[] = "hello";      // mutable
    const char* str = "hello"; // immutable
    ~~~
    - C++
    ~~~C++
    std::string s = "hello";   // mutable
    const char* str = "hello"; // immutable
    ~~~

