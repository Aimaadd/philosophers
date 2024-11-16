
# Philosophers

An implementation of the classic **Dining Philosophers Problem**, created as part of the [42 School](https://www.42.fr/) curriculum. This project explores concepts in concurrency, multithreading, and synchronization, adhering to rigorous constraints to emulate real-world systems.

## Table of Contents
- [About the Project](#about-the-project)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Technologies Used](#technologies-used)
- [Acknowledgments](#acknowledgments)

---

## About the Project

The **Dining Philosophers Problem** is a classic computer science problem that illustrates synchronization issues and solutions. The goal of this project is to simulate philosophers dining at a table while sharing limited resources (forks) without causing deadlocks or race conditions.

This project focuses on:
- Proper thread management.
- Using mutexes or semaphores for resource sharing.
- Avoiding deadlocks and achieving proper synchronization.

---

## Features

- Implements the dining philosophers problem using multithreading.
- Ensures no deadlocks or race conditions occur.
- Simulates realistic philosopher behaviors:
  - Eating
  - Thinking
  - Waiting for forks
- Customizable parameters:
  - Number of philosophers
  - Time to eat, think, and die
- Highly efficient and adheres to the constraints of the project.

---

## Installation

### Prerequisites
Ensure the following are installed on your system:
- **GCC** (or any compatible C compiler)
- **Make**

### Clone the Repository
```bash
git clone https://github.com/Aimaadd/philosophers.git
cd philosophers
```

### Build the Project
Run the following command to compile the program:
```bash
make
```

This will generate the executable files in the project directory.

---

## Usage

### Run the Program
```bash
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_meals (optional)]
```

#### Example:
```bash
./philosophers 5 800 200 200
```

This simulates 5 philosophers, where:
- Each philosopher dies after 800ms if they don't eat.
- Eating takes 200ms, and sleeping takes 200ms.

---

## Technologies Used

- **C Programming Language**
- POSIX Threads (pthreads)
- Mutexes and Semaphores

---

## Acknowledgments

This project is part of the **42 School** curriculum. It serves as a practical exercise to understand and solve concurrency issues in multithreaded systems. Special thanks to the 42 community for their support and resources.

---
