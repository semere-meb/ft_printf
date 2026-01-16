*This project has been created as part of the 42 curriculum by semebrah.*

## Description

ft_printf is a custom implementation of the standard C library function `printf(3)`. The goal of this project is to recreate a subset of printf's functionality, handling formatted output conversion and providing a deeper understanding of variadic functions, format string parsing, and type-specific output formatting in C.

### Supported Features

**Format Specifiers:**
| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address (hexadecimal) |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal (lowercase) |
| `%X` | Unsigned hexadecimal (uppercase) |
| `%%` | Literal percent sign |

**Flags:**
| Flag | Description |
|------|-------------|
| `-` | Left-align output within field width |
| `+` | Force sign display for signed numbers |
| ` ` | Prefix positive numbers with space |
| `#` | Alternate form (0x/0X prefix for hex) |
| `0` | Zero-pad numbers instead of space-pad |

**Width and Precision:**
- Minimum field width (e.g., `%10d`)
- Precision specifier (e.g., `%.5d`, `%.3s`)

## Instructions

### Prerequisites

- GCC or compatible C compiler
- GNU Make
- The project includes a `libft` dependency (included in the repository)

### Compilation

Build the static library:

```bash
make
```

This produces `libftprintf.a`, a static library containing ft_printf and all libft functions.

Other make targets:
```bash
make clean    # Remove object files
make fclean   # Remove object files and library
make re       # Rebuild from scratch
```

### Usage

1. Include the header in your source file:
```c
#include "ft_printf.h"
```

2. Compile your program by linking with the library:
```bash
cc -Wall -Wextra -Werror your_program.c -L. -lftprintf -o your_program
```

### Usage Examples

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    // Basic string and character
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Character: %c\n", 'A');

    // Numbers with formatting
    ft_printf("Decimal: %d, Unsigned: %u\n", -42, 42);
    ft_printf("Hex: %x, HEX: %X\n", 255, 255);

    // Width and precision
    ft_printf("Width: [%10d]\n", 42);
    ft_printf("Left-align: [%-10d]\n", 42);
    ft_printf("Precision: [%.5d]\n", 42);

    // Flags
    ft_printf("Sign: [%+d] [%+d]\n", 42, -42);
    ft_printf("Space: [% d] [% d]\n", 42, -42);
    ft_printf("Zero-pad: [%010d]\n", 42);
    ft_printf("Alternate hex: [%#x]\n", 255);

    // Pointer
    count = 0;
    ft_printf("Pointer: %p\n", &count);

    // Return value (character count)
    count = ft_printf("This line has %d characters\n", 27);
    ft_printf("Printed %d characters\n", count);

    return (0);
}
```

## Algorithm and Data Structure

### Core Data Structure

The implementation uses a single struct to encapsulate all format specification data:

```c
typedef struct s_template
{
    size_t  start;      // Position of '%' in format string
    size_t  end;        // Position after format specifier

    size_t  len;        // Total output length accumulated

    int     left;       // '-' flag (left-align)
    int     sign;       // '+' flag (force sign)
    int     space;      // ' ' flag (space for positive)
    int     alt;        // '#' flag (alternate form)
    int     zero;       // '0' flag (zero-padding)

    int     width;      // Minimum field width
    int     precision;  // Precision (-1 if not specified)

    char    specifier;  // Format specifier character
}   t_template;
```

**Justification:** A single struct consolidates all parsing state and formatting parameters, simplifying parameter passing between functions and avoiding global state. This approach makes the code modular and maintainable, as each handler function receives all necessary context through a single pointer.

### Parsing Algorithm

The parser implements a linear state machine that processes the format string in one pass:

```
1. SEARCH  → Find '%' character
2. RESET   → Initialize template fields
3. FLAGS   → Parse flag characters (-, +, space, #, 0)
4. WIDTH   → Parse numeric width value
5. PRECISION → Check for '.' and parse precision digits
6. SPECIFIER → Validate and store the type specifier
```

**Justification:** Linear parsing (O(n) complexity) is efficient for format strings, which are typically short. The state machine approach handles flag ordering flexibility (flags can appear in any order) while maintaining clear separation of parsing stages.

### Number Conversion Algorithm

The converter uses a universal base-conversion algorithm:

```c
char *convert(unsigned long long val, char *base)
```

- Extracts digits via repeated modulo operations
- Supports any radix through character-set strings (`"0123456789"`, `"0123456789abcdef"`)
- Builds the result string in reverse, then reverses it

**Justification:** A single parameterized converter eliminates code duplication between decimal, hexadecimal lowercase, and hexadecimal uppercase conversions. The base is passed as a string (e.g., `"0123456789abcdef"`), making the function flexible and reusable.

### Handler Pipeline Architecture

Formatting is applied through a modular handler pipeline:

```
Input Value
    │
    ▼
┌─────────────────┐
│  convert()      │  Number → String
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│handle_precision │  Apply minimum digits / truncation
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│handle_sign/space│  Add +/- or space prefix
│handle_alt       │  Add 0x/0X prefix
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│handle_width     │  Generate padding string
│handle_left      │  Apply alignment
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│    print()      │  Output to stdout
└─────────────────┘
```

**Justification:** The pipeline pattern isolates each formatting concern into dedicated functions, following the single-responsibility principle. This makes the code easier to test, debug, and extend. Each handler transforms the output string independently, and their composition produces the final formatted result.

### Memory Management Strategy

- Each conversion/handler allocates its result string
- The `append()` utility combines strings and frees the inputs
- The `print()` function outputs and frees the final string

**Justification:** Allocating intermediate strings provides clear ownership semantics and prevents buffer overflow issues. While this approach has allocation overhead, it prioritizes correctness and simplicity over raw performance—appropriate for a learning project focused on understanding printf internals.

### File Organization

| File | Responsibility |
|------|----------------|
| `ft_printf.c` | Entry point, main loop, dispatcher |
| `parser.c` | Format string parsing |
| `converter.c` | Base conversion |
| `printers1.c` | Handlers for c, s, p, d/i |
| `printers2.c` | Handlers for x, X, % |
| `handlers1.c` | Precision, width, alignment, alt, sign |
| `handlers2.c` | Space, zero-padding |
| `utils.c` | String utilities |

## Resources

### Documentation and References

- **printf(3) man page** - The authoritative reference for printf behavior and format specifications
- **cplusplus.com** - https://cplusplus.com/reference/cstdio/printf/
- **42 ft_printf subject** - Project requirements and constraints

### AI Usage Disclosure

AI assistance was used in the following capacity:

- **Documentation**: AI was used moderately in creating this README file, including structuring the algorithm explanation and formatting the technical documentation
- **Explaning Edge cases**: AI provided a baseline understanding of how printf behaves in specific edge cases

The core implementation (source code) was developed independently without AI-generated code.
