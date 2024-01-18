# MONTY: Bridging the Gap Between Scripting and Programming

## Overview

MONTY is a dynamic programming language designed to bridge the gap between scripting languages and traditional programming languages. It combines the ease of use and flexibility of scripting languages with the power and structure of traditional programming languages. MONTY is suitable for a wide range of applications, from simple scripting tasks to complex software development projects.

## Learning Objectives

MONTY is designed with the following learning objectives in mind:

1. **Ease of Learning:** MONTY aims to be accessible to beginners with a syntax that is easy to understand and learn.

2. **Versatility:** Users should be able to use MONTY for a variety of tasks, from simple scripting to more complex software development.

3. **Readability:** The language encourages clean and readable code, making it easier for developers to collaborate and maintain codebases.

4. **Flexibility:** MONTY is designed to be flexible, allowing developers to choose their programming paradigm (procedural, object-oriented, functional) based on their preferences and the requirements of the project.

## Usage / Installation

### Installation

#### $ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty


### Usage

#### Running MONTY Scripts

Once MONTY is installed, you can execute MONTY scripts using the following command:

```bash
monty script.mty
```

Replace `script.mty` with the path to your MONTY script.

#### Interactive Mode

MONTY also provides an interactive mode, allowing you to execute code snippets directly. Simply run:

```bash
monty
```

This will open an interactive MONTY shell where you can enter and execute MONTY code interactively.

## Command Required

# MONTY Language - Command Reference

## Command Required

### `push <int>`
Pushes an integer onto the stack.

- **Usage:**
  ```bash
  push 42
  ```
  Pushes the integer `42` onto the stack.

### `pall`
Prints all integers on the stack, starting at the top.

- **Usage:**
  ```bash
  pall
  ```
  Prints all integers present on the stack.

### `pint`
Prints the integer at the top of the stack.

- **Usage:**
  ```bash
  pint
  ```
  Prints the integer at the top of the stack.

### `pop`
Removes the top element of the stack.

- **Usage:**
  ```bash
  pop
  ```
  Removes the integer at the top of the stack.

### `swap`
Swaps the top two elements of the stack.

- **Usage:**
  ```bash
  swap
  ```
  Swaps the positions of the top two integers on the stack.

### `add`
Adds the top two elements of the stack, removes them, and pushes the result onto the stack.

- **Usage:**
  ```bash
  add
  ```
  Adds the top two integers on the stack and pushes the result onto the stack.

### `sub`
Subtracts the top two elements of the stack, removes them, and pushes the result onto the stack.

- **Usage:**
  ```bash
  sub
  ```
  Subtracts the top integer from the second-top integer on the stack and pushes the result.

### `div`
Integer divides the top two elements of the stack, removes them, and pushes the result onto the stack.

- **Usage:**
  ```bash
  div
  ```
  Divides the second-top integer by the top integer on the stack and pushes the result.

### `mul`
Multiplies the top two elements of the stack, removes them, and pushes the result onto the stack.

- **Usage:**
  ```bash
  mul
  ```
  Multiplies the top two integers on the stack and pushes the result.

### `mod`
Integer division remainder of the top two elements, removes them, and pushes the result onto the stack.

- **Usage:**
  ```bash
  mod
  ```
  Computes the remainder of the integer division of the second-top integer by the top integer and pushes the result.

### `pchar`
Prints the ASCII character based on the top integer in the stack.

- **Usage:**
  ```bash
  pchar
  ```
  Prints the ASCII character corresponding to the top integer on the stack.

### `pstr`
Prints the ASCII characters related to integers in the stack until 0 or >255.

- **Usage:**
  ```bash
  pstr
  ```
  Prints the ASCII characters corresponding to integers on the stack until a `0` or an integer greater than `255` is encountered.

### `rotl`
Rotates the stack. The top element becomes the last, and the second from the top becomes the new top.

- **Usage:**
  ```bash
  rotl
  ```
  Rotates the stack to the left.

### `rotr`
Rotates the stack. The last element becomes the top, and the top element becomes the second from the top.

- **Usage:**
  ```bash
  rotr
  ```
  Rotates the stack to the right.

### `stack`
Changes the mode to first in, first out (FIFO) - the default behavior. The front of the queue becomes the top of the stack.

- **Usage:**
  ```bash
  stack
  ```
  Changes the mode to stack (LIFO).

### `queue`
Changes the mode to last in, first out (LIFO). The top of the stack becomes the front of the queue.

- **Usage:**
  ```bash
  queue
  ```
  Changes the mode to queue (FIFO).