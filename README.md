# Mini Task - Permutation Generator

This C++ program generates random permutations `P1` and `P2` and utilizes function `F` to modify bytes in a 256x256 table based on these permutations.

## Table of Contents
- [Introduction](#introduction)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Example Output](#example-output)

## Introduction

This program is a mini task aimed at generating a 256x256 table with modified bytes. It utilizes random permutations `P1` and `P2` and a function `F` to achieve this. The generated table can be used for various applications such as cryptographic operations, data manipulation, or simulation purposes.

## Usage

Follow these steps to compile and run the program:

1. Clone the repository:
'''
git clone https://github.com/Arthur-Berberyan/Mini_Task.git
'''
2. Navigate to the project directory:
cd Mini_Task

3. Compile the program:
g++ -o perm perm.cpp

4. Run the program:
/perm


## How It Works

The program begins by generating two random permutations `P1` and `P2`, where each permutation maps numbers from 0 to 255 to other numbers in the same range. Function `F` takes two arguments, `P1(x)` and `P2(y)`, and generates a random byte. It injects the bits of this random byte into some positions of the byte represented by `P1(x)`, based on the bits set in the byte represented by `P2(y)`.

The program then constructs a 256x256 table, with each element being a byte. It fills the table by applying function `F` to every combination of `x` and `y`.

## Example Output

Here's an example output of the program:
First row of the table:
[ 10, 20, 30, ... ]
Second row of the table:
[ 50, 60, 70, ... ]
Permutation P1: [ 2, 5, 0, ... ]



