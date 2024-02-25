#include <algorithm>
#include <iostream>
#include <numeric>
#include <bitset>
#include <vector>
#include <random>

void printRow(const std::vector<std::vector<uint8_t>>& table, int row) noexcept {
    constexpr int colSize = 256;
    constexpr int byteSize = 8;
    for (int i = 0; i < colSize; ++i) {
        std::cout << std::bitset<byteSize>(table[row][i]) << ' ';
    }
    std::cout << std::endl;
}

void printPermutation(const std::vector<uint8_t>& perm) {
    constexpr int size = 256;
    for (int i = 0; i < size; ++i) {
        std::cout << static_cast<int>(perm[i]) << ' ';
    }
    std::cout << std::endl;
}

uint8_t generateRandomByte() {
    constexpr int maxPermutation = 256;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<uint8_t> dis(0, maxPermutation);
    return dis(gen);
}

uint8_t F(uint8_t x, uint8_t y) {
    const uint8_t random_byte = generateRandomByte();
    uint8_t injected_byte = 0;
    constexpr int byteSize = 8;
    for (int i = 0; i < byteSize; ++i) {
        if (y & (1 << i)) {
            injected_byte |= ((random_byte >> i) & 1) << i;
        }
    }
    return x ^ injected_byte;
}

int main() {
    constexpr int tableSize = 256;
    std::vector<uint8_t> P1(tableSize);
    std::vector<uint8_t> P2(tableSize);
    std::iota(P1.begin(), P1.end(), 0);
    std::iota(P2.begin(), P2.end(), 0);
    std::random_shuffle(P1.begin(), P1.end());
    std::random_shuffle(P2.begin(), P2.end());
    std::vector<std::vector<uint8_t>> table(tableSize, std::vector<uint8_t>(tableSize));
    for (int x = 0; x < tableSize; ++x) {
        for (int y = 0; y < tableSize; ++y) {
            table[x][y] = F(P1[x], P2[y]);
        }
    }
    std::cout << "First row of the table:\n";
    printRow(table, 0);
    std::cout << "\nSecond row of the table:\n";
    printRow(table, 1);
    std::cout << "\nPermutation P1:\n";
    printPermutation(P1);
}
