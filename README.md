*This project has been created as part of the 42 curriculum by hhdili.*

---

## Description

`ft_printf` is a reimplementation of the standard C library function `printf()`.  
The goal is to reproduce the behaviour of the original `printf` for the mandatory conversions – `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%` – without using any external libraries other than `write`, `malloc`, `free`, and the `va_*` macros from `<stdarg.h>`.

The project teaches the use of **variadic functions** in C and demonstrates how to build an extensible formatting engine.  
The resulting `libftprintf.a` library can be linked into any C project and used exactly like the standard `printf`.

### Mandatory conversions

| Specifier | Output |
|-----------|--------|
| `%c` | A single character |
| `%s` | A string (null‑terminated) |
| `%p` | A `void *` pointer in hexadecimal format |
| `%d` / `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | A hexadecimal number (lowercase) |
| `%X` | A hexadecimal number (uppercase) |
| `%%` | A literal percent sign |

> **Note:** The bonus flags (`-0.`, `#`, ` `, `+`) were **not** implemented. Only the mandatory part is provided.

---

## Instructions

### Compilation

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + all
```

The library is created at the root of the repository and is named `libftprintf.a`.

### Usage

1. Include the header in your C source:
   ```c
   #include "ft_printf.h"
   ```
2. Link the library when compiling your program:
   ```bash
   cc your_program.c libftprintf.a -o your_program
   ```
3. Call `ft_printf` exactly as you would call the standard `printf`:
   ```c
   ft_printf("Hello, %s! The answer is %d (0x%x).\n", "world", 42, 42);
   ```

The function returns the total number of characters printed, or `-1` on error.

### Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Hello 42!");
    ft_printf("Pointer: %p\n", (void *)0x1234);
    ft_printf("Signed: %d, %i\n", -42, 42);
    ft_printf("Unsigned: %u\n", 3000000000u);
    ft_printf("Hex: %x, %X\n", 255, 255);
    ft_printf("Percent: %%\n");
    return (0);
}
```

---

## Resources

### Classic references

- **42 subject PDF** – *ft_printf* (version 12.1) – the official requirements.
- **C standard library documentation** – `printf(3)` man page (for behaviour reference).
- **Variadic functions in C** – [`<stdarg.h>` documentation](https://en.cppreference.com/w/c/variadic) (cppreference).
- **42 Norm** – the coding style guide used at 42 (available on the intranet).
- **printfTester** – the test suite included in this repository (used to validate the output against the original `printf`).

### Use of AI

AI (ChatGPT) was used **only** for the following tasks:

- **Clarifying the subject requirements** – e.g., confirming which conversions are mandatory and how the README should be structured.
- **Reviewing the code for potential issues** – pointing out missing `#include` directives and the leftover `libft.a` file.
- **Drafting the README** – generating the first version of this document, which was then verified and adapted by the author.

AI was **not** used to write the core logic of `ft_printf`. All conversion functions, the dispatcher, and the utility functions were implemented by the author as part of the learning process.

---

## Technical Choices – Algorithm and Data Structure

### Overview

The implementation follows a **dispatch‑table** pattern, which makes the code modular and easy to extend.

### Data structure

A single static array of `t_conv` structures is defined in `ft_dispatch.c`:

```c
typedef struct s_conv
{
    char spec;
    int (*f)(va_list *);
} t_conv;
```

Each entry maps a conversion specifier (`'c'`, `'s'`, `'p'`, `'d'`, `'i'`, `'u'`, `'x'`, `'X'`, `'%'`) to the corresponding handler function. The array is terminated by `{0, NULL}`, allowing a simple `while` loop to scan for the requested specifier.

### Algorithm

1. **`ft_printf`** (in `ft_printf.c`):
   - Initialises a `va_list` with `va_start`.
   - Iterates over the format string character by character.
   - When a `%` is encountered, it calls `dispatch()` with the next character and the `va_list`.
   - If `dispatch()` returns `-1` (unknown specifier), `ft_printf` returns `-1`.
   - Otherwise, the returned character count is added to the total.
   - Normal characters are printed with `ft_putchar`.
   - Finally, `va_end` is called and the total count is returned.

2. **`dispatch`** (in `ft_dispatch.c`):
   - Scans the static `t_conv` table.
   - When the specifier matches, it calls the associated function pointer with the `va_list`.
   - If no match is found, it returns `-1`.

3. **Conversion handlers** (e.g., `conv_d`, `conv_x`, …):
   - Each handler extracts the correct type from the `va_list` using `va_arg`.
   - It then uses the shared utilities (`ft_putchar`, `ft_putstr`, `ft_putnbr_base`) to produce the output.
   - For signed integers, the sign is handled explicitly before converting the magnitude to a string.
   - For pointers, the address is cast to `unsigned long` and printed in hexadecimal with a `0x` prefix.

4. **Utilities** (in `ft_utils.c`):
   - `ft_putchar` – writes a single character with `write`.
   - `ft_putstr` – writes a string character by character.
   - `ft_putnbr_base` – recursively converts an `unsigned long` to any base (2–16) and writes the digits.

### Why this design?

- **Extensibility** – Adding a new conversion (e.g., a future bonus flag) only requires a new handler function and one entry in the dispatch table.
- **Clarity** – The `ft_printf` loop stays simple; all formatting logic is delegated to specialised functions.
- **Norm compliance** – Each function is short (well under 25 lines) and has a single responsibility, making the code easy to read and verify.

---

## Conclusion

`ft_printf` is a complete, norm‑compliant implementation of the mandatory part of the 42 `ft_printf` project.  
It correctly handles all required conversions, returns the right character count, and is ready to be added to the author’s `libft` for future projects.
```
