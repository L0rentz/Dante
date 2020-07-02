# Usage

./generator width height [perfect]
./solver maze

# Dante

- **Binary name:** solver/generator
- **Repository name:** Dante
- **Language:** C
- **Group Size:** 1
- **Compilation:** via Makefile, including re, clean and fclean rules

## Goal

Dante must journey through Hell, a thoroughly maze-like place. Here we’re going to generate mazes, find
the exit path and try to do this as fast as possible.
The project is divided into nine sections, which represent the nine circles of Hell that Dante must pass
through in order to reach purgatory.
The goal of this project is to generate mazes (in a reasonable amount of time), solve them (in a reasonable
amount of time), and print the solution.

## Authorized functions

- System functions and libC are allowed, but no external libraries.

## Perfect mazes

First, generate a perfect maze.
A perfect maze is a maze that has no loops and no clusters; therefore, following a wall makes us cross the
entire maze.
The generation method is up to you, but it must work in an acceptable amount of time.
Input: maze size (width/height).
Output: a maze with the required size on the standard output.

## Imperfect mazes

An imperfect maze must contain clusters.
The requirements are the same as for perfect mazes.
The generation method is up to you, but it must work in an acceptable amount of time.
Input: maze size
Output: a maze with the required size on the standard output.

## Examples

![ScreenShot](https://raw.github.com/L0rentz/Dante/master/examples/example.png)
