# Bytes Table Generator

This C++ program generates a table of bytes based on permutations and a function `F` that injects random bits into the bytes based on specified positions.

## Description

The program consists of the following components:

- **Permutation Generation**: Two permutations (`P1` and `P2`) of length 256 are generated randomly using the `generate_permutation` function.
- **Function F**: The `F` function takes a byte and a set of positions as input and injects random bits into the byte at the specified positions.
- **Table Generation**: A 256x256 table of bytes is generated, where each row alternates between using permutation `P1` and `P2` to determine the bits to be injected using function `F`.
- **Output**: The generated permutations (`P1` and `P2`) and the first few rows of the generated table are printed to the console.

## Usage

1. Clone the repository or copy the code into a C++ file.
2. Compile the code using a C++ compiler (e.g., g++).
3. Run the compiled executable.
4. View the output in the console, which includes the generated permutations and the first few rows of the generated table.

## Dependencies

- C++ standard libraries (`iostream`, `vector`, `algorithm`, `random`)
- Compiler with C++11 support

## Example Output

```plaintext
Permutation P1: 10 55 87 ... (256 values)
Permutation P2: 198 76 32 ... (256 values)
First few rows of the table:
132 77 245 64 213 32 145 199 255 10
34 89 43 192 76 201 155 200 0 55
...

