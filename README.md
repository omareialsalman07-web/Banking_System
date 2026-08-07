# Banking System

A C++ desktop application that simulates a small banking system. It lets you manage clients, users, balances, money transfers, and currency exchange — all through a modern GUI built with **Dear ImGui**, **GLFW**, and **OpenGL**.

This project was made for learning purposes and is a great example of a **student-level C++ project** that combines object-oriented design, file I/O, and a GUI framework.

---

## Features

- **Login System** — username + password login with encrypted passwords and a limit of 3 attempts.
- **Permissions / User Roles** — users have permissions (as a bitmask) that control what they can do (list clients, add clients, transactions, manage users, etc.).
- **Client Management**
  - View the list of all clients
  - Add new clients
  - Find a client by account number
  - Update client data
  - Delete clients
- **Transactions**
  - Deposit money into an account
  - Withdraw money from an account
  - Transfer money between two accounts
- **Currency Exchange**
  - Browse a list of world currencies with exchange rates
  - Currency exchange screen
  - Currency calculator to convert amounts between currencies
- **Logging**
  - User login register (who logged in and when)
  - Money transfer register (history of transfers)
- **Manage Users** — add, update, list, and delete bank users.
- **Dockable GUI** — docking layout with multiple windows you can arrange freely.
- **Data Persistence** — all data is saved to plain text files inside the `data/` folder.

---

## Tech Stack

| Technology | Purpose |
|-----------|---------|
| C++20 | Programming language |
| Dear ImGui | GUI framework |
| GLFW | Window / input handling |
| OpenGL | Rendering backend for ImGui |
| MSVC (Visual Studio 2022) | Compiler / build system |

---

## Requirements

- **Windows 10/11**
- **Visual Studio 2022** with the **Desktop development with C++** workload
- A graphics driver that supports OpenGL

The project is configured to use:

- C++20 standard (`stdcpp20`)
- Platform toolset `v143`
- GLFW library (already included under `Dependencies/`)

---

## How to Build and Run

1. Clone or download the repository.
2. Open the solution file `Banking_System.slnx` in **Visual Studio 2022**.
3. Set the build configuration to `Debug` / `x64`.
4. Press `Ctrl + F5` to build and run (or `F5` to run with the debugger).

The executable is produced in `build/x64/Debug/`.

> **Note:** the program reads and writes its data files from a `data/` folder relative to the working directory, so run it from the solution folder (the default in Visual Studio).

### Default Login

| Field | Value |
|-------|-------|
| Username | `admin` |
| Password | `5678` |

You can find the default admin account in `data/USERS.txt`.

---

## Project Structure

```
Banking_System/
│
├── src/
│   ├── main.cpp              # Entry point
│   ├── App/                  # Application core (singleton, main loop, console)
│   ├── Core/                 # Business logic: BankClient, BankUser, BankCurrency, logs
│   ├── BaseLib/              # Reusable utilities: String, Date/Time, encrypt/decrypt helpers
│   └── GUI_Layer/            # All ImGui screens/windows (login, main menu, lists, ...)
│
├── data/                     # Stored data (text files)
│   ├── CLIENTS.txt           # All bank clients
│   ├── USERS.txt             # All system users (passwords are encrypted)
│   ├── Currencies.txt        # Currencies and their exchange rates
│   ├── LogRegisters.txt      # Login history
│   └── RegisterTransferLog.txt  # Transfer history
│
├── Dependencies/             # External libraries (GLFW)
├── build/                    # Build output (git-ignored)
└── Banking_System.slnx       # Visual Studio solution
```

### Data Storage

The app does **not** use a database. Instead, it uses simple text files where each line represents one record, and fields are separated by `#//#`. The generic `Repository<T>` template class (in `src/Core/Repository.h`) handles loading, saving, finding, adding, updating, and deleting records for any persistable type.

---

## Concepts You Can Learn From This Project

- **Singleton pattern** — the `Application` class exposes a single global instance.
- **Polymorphism & interfaces** — `IPersistable` lets any class be saved to / loaded from a file.
- **Templates** — `Repository<T>` is a generic data-access layer reused for clients, users, currencies, and logs.
- **Object-Oriented Design** — inheritance (`Person`, `BankClient`, `BankUser`) and encapsulation.
- **Bitmask permissions** — user permissions stored as bits and checked with bitwise operators.
- **File I/O** — reading and writing structured text files.
- **GUI programming** — building an interactive desktop UI with ImGui.

---

## Possible Improvements

- Use a real database (e.g., SQLite) instead of text files.
- Add interest calculations and loan features.
- Add a search filter to client/currency lists.
- Write unit tests with a framework like GoogleTest.
- Improve input validation and error handling.

---

## License

This project is for **educational purposes only** and is not intended for production use.
