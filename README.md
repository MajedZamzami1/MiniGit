# MiniGit – A Simplified Version Control System in C++

## Overview

**MiniGit** is a lightweight, console-based version control system implemented from scratch in **C++**.  
It recreates the core ideas behind Git—tracking files, committing changes, and checking out previous versions—without relying on external libraries or existing VCS tools.

This project was built to demonstrate a deep understanding of **data structures, file systems, and system-level programming concepts** by implementing version control logic manually.

---

## Key Features

- Initialize a local repository (`.minigit`) to store file versions
- Add files to version tracking
- Remove files from tracking
- Commit snapshots of tracked files
- Automatically detect file changes and version them
- Checkout (restore) any previous commit
- Maintain a full commit history in memory

---

## Technologies Used

- **Language:** C++ (C++17)
- **Standard Libraries:**
  - `<filesystem>` for directory and file management
  - `<fstream>` for file I/O
  - `<iostream>` for console interaction
- **Data Structures:**
  - Doubly Linked List (commit history)
  - Singly Linked List (files per commit)

---

## How the System Works

### Repository Structure

When initialized, MiniGit creates a hidden directory called `.minigit`.  
This directory stores all historical versions of tracked files using versioned filenames.

Example:
```
.minigit/
├── 00example.txt
├── 01example.txt
├── 00notes.md
```

Each version prefix (`00`, `01`, `02`, etc.) represents a new version of the file.

---

### Data Structures

- **Commit History:**  
  Implemented as a **doubly linked list**, where each node represents a commit.
  - Stores:
    - Commit number
    - Pointer to a list of tracked files
    - Pointers to previous and next commits

- **Tracked Files:**  
  Each commit contains a **singly linked list** of file records.
  - Each node stores:
    - Original file name
    - Versioned file name (stored in `.minigit`)

---

### Adding Files

- Validates that the file exists in the working directory
- Prevents duplicate tracking of the same file
- Assigns an initial version number (`00`)
- Adds the file to the current commit’s file list

---

### Committing Changes

When committing:
1. Each tracked file is compared against its last saved version
2. If the file is **new**, it is copied to `.minigit` with version `00`
3. If the file **changed**, a new version number is generated and stored
4. If unchanged, the previous version is reused
5. A new commit node is created with a deep copy of the file list

---

### Checkout (Restore a Commit)

- Removes current working files if needed
- Retrieves the correct versions from `.minigit`
- Restores the project directory to match the selected commit exactly

---

## Why This Project Matters

This project demonstrates:

- Strong C++ fundamentals
- Practical use of data structures
- System-level design thinking
- Understanding how real tools like Git work internally

---

## How to Run

```bash
g++ -std=c++17 main.cpp -o minigit
./minigit
```

---

## Author

**Majed Zamzami**  
Computer Science Graduate
