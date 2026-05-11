# C++ Module 00

This module contains three exercises implementing basic C++ concepts following the C++98 standard.

## Exercises

### ex00 - Megaphone
A simple program that converts command-line arguments to uppercase.

**Usage:**
```bash
./megaphone "hello world"  # Outputs: HELLO WORLD
./megaphone                # Outputs: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

**Compilation:**
```bash
cd ex00 && make
```

### ex01 - PhoneBook
A simple phonebook application with contact management functionality.

**Features:**
- Store up to 8 contacts in a static array
- Circular replacement: 9th contact replaces the 1st
- Commands: ADD, SEARCH, EXIT
- Formatted table display (10 chars, right-aligned, truncated with dot)

**Usage:**
```bash
cd ex01 && make
./phonebook
> ADD           # Add a new contact
> SEARCH        # Search and display contacts
> EXIT          # Exit the program
```

**Classes:**
- `Contact`: Stores contact information (first name, last name, nickname, phone number, darkest secret)
- `PhoneBook`: Manages the array of contacts with ADD and SEARCH operations

### ex02 - Account
Implementation of the Account class to match the expected output from a bank account test program.

**Compilation:**
```bash
cd ex02 && make
./account       # Runs the test program
```

**Features:**
- Static member variables for tracking accounts
- Deposit and withdrawal operations
- Display functions with timestamp formatting
- Output matches provided .log file (ignoring timestamps)
