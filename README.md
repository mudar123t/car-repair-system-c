# Car Repair Management System (C Project)

A C-based system for managing a car repair shop. It allows users to store and update customer information, car records, and repair logs. Built using modular C programming and file I/O techniques.

## Project Context
- Language: C
- Platform: Windows (tested)
- Year: 2024–2025
- Purpose: Academic project for learning structured C and file handling

## Features
- Add/Edit/Delete customer data
- Manage car records
- Track repair history
- Save and load data from `.txt` files
- Modular source files with header files

## Tech Stack
- C (compiled with GCC)
- File I/O
- Console-based interface

## How to Compile
Use a C compiler like GCC:
bash
gcc main.c car.c main_func_testing.c -o car_repair_system
./car_repair_system

## Files & Structure
.
├── main.c
├── car.c / car.h
├── car_repair_library.h
├── main_func_testing.c
├── customers.txt / cars.txt / repair_records.txt
├── CarSystem.exe         # Windows binary
├── Project documentation.pdf
└── .vscode/settings.json

Notes
This is a terminal/console app, no GUI

File data is stored in plain text

Functions are separated by responsibility (data, logic, testing)




