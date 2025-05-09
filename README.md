

# Student Record System

A simple terminal-based **Student Record Management System** written in C. This program allows administrators to add, view, search, modify, and delete student records. It uses file I/O to store student data persistently in a binary file (`okok.txt`).

## Features

* **Login Authentication** (hardcoded: `adminrecord` / `admin123`)
* **Add Student Records**
* **View All Records**
* **Search Records**

  * By First Name
  * By Last Name
  * By Roll Number
  * By Course
* **Modify Records**
* **Delete Records**

## Getting Started

### Prerequisites

* Windows OS (uses `<windows.h>`, `Sleep`, and `getch()`)
* C Compiler (e.g., GCC via MinGW)
* Terminal or Command Prompt


### Default Login Credentials

* **Username:** `adminrecord`
* **Password:** `admin123`

> Password is hidden behind asterisks (`*`) when typed.

## File Used

* `okok.txt` – Stores all student records in binary format.

## Data Structure

Each student record contains:

* `roll_no` (Integer)
* `first_name` (String)
* `last_name` (String)
* `course` (String)
* `gpa` (Float)

## Notes

* Make sure the program has read/write access to the working directory.
* Do **not** open or modify `okok.txt` manually to prevent data corruption.
* Uses legacy C-style programming, so avoid using with modern C++ compilers without adaptation.

## Limitations

* No encryption for data storage.
* No password change functionality.
* No support for multi-user environments.
* Platform-dependent due to use of Windows-specific headers.
