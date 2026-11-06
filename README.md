*This project has been created as part of the 42 curriculum by abdait-o.*

# ft_printf

## Description

The **ft_printf** project is part of the 42 curriculum. Its goal is to recreate the behavior of the standard C library function `printf()`.

The main purpose of this project is to understand variadic functions in C, format string parsing, and how formatted output works.

The implementation handles the following conversion specifiers:

| Specifier | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a decimal number. |
| `%i` | Prints an integer in decimal format. |
| `%u` | Prints an unsigned decimal number. |
| `%x` | Prints a number in lowercase hexadecimal format. |
| `%X` | Prints a number in uppercase hexadecimal format. |
| `%%` | Prints the percent character. |

The function returns the total number of characters printed. If a writing operation fails, it returns `-1`.

## Instructions

### Compilation

The project includes a Makefile that compiles the source files and creates a static library named `libftprintf.a`.

To compile the library, run:

```bash
make
```

Available Makefile rules:

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Recompile everything
```

### Usage

To use the library, include the header file in your C program:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc main.c libftprintf.a -o program
```

Run the executable:

```bash
./program
```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    int number = 42;

    ft_printf("Hello, %s!\n", "42 student");
    ft_printf("Number: %d\n", number);
    ft_printf("Hexadecimal: %x\n", number);
    ft_printf("Pointer: %p\n", &number);
    return (0);
}
```

## Resources

The following resources were useful during the development of this project:

- [C Programming Language - GNU Documentation](https://www.gnu.org/software/libc/manual/)
- [printf(3) - Linux Manual Page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg.h - Variadic Arguments](https://en.cppreference.com/w/c/variadic.html)
- [write(2) - Linux Manual Page](https://man7.org/linux/man-pages/man2/write.2.html)
- 42 subject documentation.
- Discussions and explanations with peers.

### AI Usage

When I encounter a problem in C or need to understand a new concept, I first ask my peers for help and try to develop a general understanding of the problem myself. After that, I may look for information online or use AI tools to get some guidance and explore possible solutions.

I do not rely entirely on AI, as understanding the code and solving problems independently are important parts of my learning process. After completing my code, and once I have already sought help from my peers, I may also use AI to review it, identify potential errors, and check whether anything could be improved. My main goal is to learn, understand my mistakes, and improve my programming skills rather than simply rely on AI-generated solutions.

## Algorithm and Data Structures

### Algorithm

The program reads the format string character by character. When it encounters a `%`, it identifies the conversion specifier and retrieves the corresponding argument using `va_arg()`. A dedicated helper function handles each conversion and prints the result using `write()`.

The number of characters printed is accumulated and returned at the end. If a writing operation fails, the function returns `-1`.

### Data Structures

- **`va_list`:** Used to access the variable arguments passed to `ft_printf()`.
- **Character arrays:** Used as temporary buffers to store digits during number conversions.
- **Pointers:** Used to handle strings and memory addresses.
- **Integer variables:** Used to track the format string position and count printed characters.

These choices keep the implementation simple, organized, and easy to maintain.