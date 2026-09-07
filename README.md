# COS214-Practical-4-FilmProduction

Film Production Management System for COS214 Practical 4.

## Overview

TaskForge is a film production management system developed in C++11. The system models a film production as a hierarchy of production phases, scenes and production tasks.

The implementation makes use of several object-oriented design patterns, including:

- Composite Pattern
- State Pattern
- Iterator Pattern
- Decorator Pattern

## Project Structure

```text
COS214-Practical-4-FilmProduction/
|-- include/        Header files
|-- docs/           UML diagrams and design documentation
|-- *.cpp           C++ implementation files
|-- main.cpp        Testing and demonstration program
|-- Makefile        Build configuration
|-- Dockerfile      Docker development environment
|-- .gitignore      Ignored build files
`-- README.md       Project documentation
```

## Requirements

The project uses C++11 and requires:

- g++
- make
- gdb
- valgrind
- Docker

These tools are also provided inside the Docker development environment.

## Building the Project

To build the project using the Makefile:

```bash
make clean
make
```

The executable produced is:

```bash
./taskforge
```

## Running the Program

After building:

```bash
./taskforge
```

## Cleaning the Build

To remove generated object files and the executable:

```bash
make clean
```

## Running with Docker

Build the Docker image:

```bash
docker build -t taskforge .
```

Run the program:

```bash
docker run --rm taskforge
```

## Valgrind

To check the program for memory leaks:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./taskforge
```

Using Docker:

```bash
docker run --rm taskforge valgrind --leak-check=full --show-leak-kinds=all ./taskforge
```

```markdown
## GDB

To debug the program locally:

```bash
gdb ./taskforge
```

Example GDB commands:

```text
break ProductionTask::start
run
print name
print priority
print state
next
print state
continue
```

To run GDB through Docker:

```bash
docker run --rm -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined taskforge gdb ./taskforge
```

## Design Patterns

### Composite Pattern

The Composite pattern represents the film production as a hierarchical structure. `WorkItem` provides the common interface while `WorkGroup`, `ProductionPhase` and `Scene` represent composite elements that can contain other work items.

### State Pattern

The State pattern controls the lifecycle of a `ProductionTask`. Tasks can transition between states such as Planned, In Progress, Blocked, Completed and Cancelled.

### Iterator Pattern

The Iterator pattern provides different ways of traversing the production structure. `ProductionOrderIterator` traverses work items in production order, while `PriorityIterator` allows tasks to be traversed according to priority.

### Decorator Pattern

The Decorator pattern allows additional requirements to be attached to work items dynamically. The implemented decorators include equipment checks, safety checks and insurance requirements.

## Documentation

The `docs/` directory contains the UML diagrams and other design documentation for the system.

## Team Members

- Mueez Gani - u24983439
- Nisiha Osman - u25110188
- Kiara Ajodhaparsadh - u25395344
