*This project has been created as part of the 42 curriculum by vgurginy.

============================================================================
# libftprintf
============================================================================

## Description

The libftprintf project is a reimplementation of the standard C library
function printf.

The goal of this project is to gain a deeper understanding of variadic
functions, formatted output, and low-level data handling in C.

This custom implementation reproduces the behavior of printf for a defined
set of format specifiers while respecting the constraints and coding
standards of the 42 curriculum.

============================================================================
## Instructions
============================================================================

### Compilation
-----------
The project is compiled using a Makefile.

To compile the library:
    make

This will generate a static library:
    libftprintf.a

To remove object files:
    make clean

To remove object files and the library:
    make fclean

To recompile everything:
    make re

============================================================================
### Usage
============================================================================

Include the header file in your source code:

    #include "ft_printf.h"

Compile your program with the library:

    cc main.c libftprintf.a

Example usage:

    ft_printf("Hello %s, number: %d\n", "world", 42);

============================================================================
## Supported Conversions
============================================================================

The following format specifiers are supported:

    %c   character
    %s   string
    %p   pointer address
    %d   signed decimal integer
    %i   signed decimal integer
    %u   unsigned decimal integer
    %x   lowercase hexadecimal
    %X   uppercase hexadecimal
    %%   percent sign

============================================================================
Resources
============================================================================

Technical References
--------------------
- man printf
- man stdarg
- The C Programming Language
- GNU C Library Documentation

AI Usage Disclosure
------------------
AI tools were used as learning aids to:
- Understand variadic functions (va_list, va_start, va_arg, va_end)
- Clarify printf behavior and edge cases
- Improve documentation clarity

No code was generated or copied without manual implementation and full understanding.

============================================================================
Algorithm and Data Structures
============================================================================

Algorithm
---------
The ft_printf function processes the format string character by character.

When a '%' character is encountered, the algorithm:
1. Advances to the next character to identify the conversion specifier.
2. Retrieves the corresponding argument using va_arg.
3. Dispatches the formatting task to a dedicated handler function.
4. Writes the formatted output to the standard output.
5. Updates and returns the total number of printed characters.

For non-format characters, the algorithm directly writes them to the output.

This approach ensures a linear traversal of the format string, resulting in
O(n) time complexity, where n is the length of the format string.

Justification:
- Linear parsing is efficient and simple.
- It closely mirrors the behavior of the original printf implementation.
- It avoids unnecessary backtracking or complex state machines.

Data Structures
---------------
The project primarily relies on the following data structures:

- va_list:
  Used to access a variable number of arguments passed to ft_printf.
  This is required for handling variadic functions in C.

- Primitive data types (int, unsigned int, char, char ):
  Used to represent and format different conversion specifiers.

- Strings (char ):
  Used for handling format strings and string arguments.
