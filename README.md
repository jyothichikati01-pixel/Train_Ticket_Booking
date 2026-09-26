# 🚆 Train Ticket Booking App

A **console-based Train Ticket Booking System developed in C**.
This project provides basic railway ticket management features such as user registration, login, train management, ticket reservation, ticket cancellation, booking details, and waiting-list handling.

The project demonstrates the practical use of **C programming, structures, pointers, linked lists, file handling, dynamic memory allocation, and modular programming**.

---

## 📌 Project Overview

The Train Ticket Booking System is designed to simulate a simple railway reservation system through a command-line interface.

Users can:

* Sign up and create an account
* Sign in to the system
* View available trains
* Reserve train tickets
* Cancel tickets
* View booking details
* Get a waiting-list status when seats are unavailable

An administrator can:

* Log in through administrator credentials
* View available trains
* Add new trains
* Manage train information

---

## ✨ Features

### 👤 User Features

* User Sign Up
* User Sign In
* Password validation
* Username duplication checking
* Login attempt limitation
* View available trains
* Reserve tickets
* Cancel tickets
* View booking details
* Waiting-list support
* Journey-date validation

### 🔐 Admin Features

* Administrator authentication
* Display train information
* Add new trains
* Duplicate train number/name checking
* Manage train seat information

### 💾 Data Management

The project uses files to store persistent information:

* `login_info` – stores user login information
* `train_info` – stores train information and seat availability
* `Passenger_info.txt` – stores passenger booking information

---

## 🛠️ Technologies Used

| Technology                    | Usage                                      |
| ----------------------------- | ------------------------------------------ |
| **C Programming**             | Application development                    |
| **Structures**                | User, train, seat, passenger and date data |
| **Linked Lists**              | Dynamic train and passenger management     |
| **Pointers**                  | Dynamic data structures                    |
| **Dynamic Memory Allocation** | `calloc()` for creating nodes              |
| **File Handling**             | Reading and writing application data       |
| **Makefile**                  | Compilation and build automation           |
| **GCC/CC Compiler**           | Compiling the C source files               |
| **Linux/Unix Environment**    | Development and execution                  |

---

## 🧠 C Concepts Demonstrated

This project provides hands-on implementation of several important C concepts:

* Structures
* Nested structures
* Pointers
* Linked lists
* Dynamic memory allocation
* Functions
* Header files
* File handling
* String handling
* Conditional statements
* Loops
* `switch` statements
* Preprocessor directives
* Modular programming
* Makefile-based compilation

---

## 🏗️ Project Structure

```text
Cmini/
│
├── AppTest.c
├── myheaders.h
│
├── AddPassenger.c
├── AddTrain.c
├── ReserveTickets.c
├── CancelTicket.c
├── BookingDetails.c
├── PrintTrain.c
├── AdminMenu.c
│
├── SaveSyncPassenger.c
├── SaveSyncTrain.c
├── signTest.c
│
├── makefile
│
├── login_info
├── train_info
└── Passenger_info.txt
```

---

## 🚀 Future Enhancements

Possible improvements include:

* Improved input validation
* Secure password storage
* Better date validation using the system date
* Automatic waiting-list confirmation after cancellation
* User-friendly terminal interface
* Search trains by source and destination
* Multiple travel classes
* PNR generation
* Improved error handling
* Database integration
* GUI or web-based interface

---

## Project Summary

**Train Ticket Booking System** is a console-based application developed using **C programming** to automate basic railway ticket reservation activities. The system allows users to register and log in, view available trains, reserve and cancel tickets, check booking details, and manage waiting-list passengers. An admin module is provided to add and manage train information.

The project uses **structures, pointers, linked lists, dynamic memory allocation, and file handling** to manage train, passenger, login, and booking data. A **Makefile** is used to compile the modular C source files. This project provided hands-on experience in developing a real-world, menu-driven application using core C programming concepts.


