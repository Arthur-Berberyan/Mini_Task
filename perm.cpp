#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> generate_permutation() {
    std::vector<int> perm(256);
    for (int i = 0; i < 256; ++i) {
        perm[i] = i;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(perm.begin(), perm.end(), g);
    return perm;
}

unsigned char F(unsigned char byte, unsigned char positions) {
    unsigned char random_byte = rand() % 256;
    unsigned char result = byte;
    for (int i = 0; i < 8; ++i) {
        if (positions & (1 << i)) {
            result |= (random_byte & (1 << i));
        }
    }
    return result;
}

int main() {
    srand(time(NULL));

    std::vector<int> perm_P1 = generate_permutation();
    std::vector<int> perm_P2 = generate_permutation();

    std::vector<std::vector<unsigned char>> table(256, std::vector<unsigned char>(256));

    for (int row = 0; row < 256; ++row) {
        for (int col = 0; col < 256; ++col) {
            const std::vector<int>& permutation = (row % 2 == 0) ? perm_P1 : perm_P2;
            table[row][col] = F(0, permutation[col]);
        }
    }

    std::cout << "Permutation P1: ";
    for (int i = 0; i < 256; ++i) {
        std::cout << perm_P1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Permutation P2: ";
    for (int i = 0; i < 256; ++i) {
        std::cout << perm_P2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "First few rows of the table:" << std::endl;
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 10; ++col) {
            std::cout << static_cast<int>(table[row][col]) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

