# Student Roster Manager (C++)

A C++ console application that parses student records from comma-separated strings, stores them in a roster, and generates reports. It started as a university coursework project and was later refactored to use modern C++ practices.

## Features

- Parses delimited student records into `Student` objects
- Add and remove students by ID
- Print the full roster
- Print students filtered by degree program (Security, Network, Software)
- Calculate the average days a student took to complete their courses
- Detect and report invalid email addresses
- Skips malformed records (for example, a non-numeric age) with a clear error message instead of crashing

## Concepts Used

- Object-oriented design: encapsulation with private members, getters and setters
- Enums for degree programs
- `std::vector` for storage
- String parsing with `std::istringstream` and `std::getline`
- Exception handling (`try`/`catch` around `std::stoi`)
- Input validation (email rules, degree program lookup via `std::map`)

## Project Structure

| File | Purpose |
|------|---------|
| `main.cpp` | Sample data and program flow |
| `roster.h` / `roster.cpp` | `Roster` class: add, remove, parse, and report functions |
| `student.h` / `student.cpp` | `Student` class: data and accessors |
| `degree.h` | `DegreeProgram` enum and name mapping |

## Building and Running

**Visual Studio (Windows):**
1. Open the `.sln` file in Visual Studio 2022 (with the "Desktop development with C++" workload installed).
2. Press `Ctrl + F5` to build and run.

**Command line (g++):**
```
g++ -std=c++17 main.cpp roster.cpp student.cpp -o roster
./roster
```

## Improvements Over the Original Version

- **Replaced a raw-pointer array with `std::vector<Student>`.** This removed manual `new`/`delete` and the hard 5-student limit.
- **Removing a student now preserves the roster order.** The original swapped the last element into the removed slot.
- **Added exception handling to record parsing.** A bad number in one record is reported and skipped.
- **Stricter email validation.** An email must have exactly one `@`, no spaces, and a `.` with characters on both sides after the `@`.

## Possible Future Improvements

- Read records from a file instead of hard-coded strings
- Unit tests for the parser and email validator
- A command-line menu for adding and removing students interactively
