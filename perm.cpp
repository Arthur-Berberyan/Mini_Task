#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <bitset>


uint8_t generateRandomByte() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<uint8_t> dis(0, 255);
    return dis(gen);
}


uint8_t F(uint8_t x, uint8_t y) {
    uint8_t random_byte = generateRandomByte();
    uint8_t injected_byte = 0;
    for (int i = 0; i < 8; ++i) {
        if (y & (1 << i)) {  
            injected_byte |= ((random_byte >> i) & 1) << i;
        }
    }
    return x ^ injected_byte;  
}

int main() {
    std::vector<uint8_t> P1(256);
    std::vector<uint8_t> P2(256);

    for (int i = 0; i < 256; ++i) {
        P1[i] = i;
        P2[i] = i;
    }
    std::random_shuffle(P1.begin(), P1.end());
    std::random_shuffle(P2.begin(), P2.end());


    std::vector<std::vector<uint8_t>> table(256, std::vector<uint8_t>(256));
    for (int x = 0; x < 256; ++x) {
        for (int y = 0; y < 256; ++y) {
            table[x][y] = F(P1[x], P2[y]);
        }
    }

    std::cout << "First row of the table:\n";
    for (int i = 0; i < 256; ++i) {
        std::cout << std::bitset<8>(table[0][i]) << " ";
    }
    std::cout << "\n\nSecond row of the table:\n";
    for (int i = 0; i < 256; ++i) {
        std::cout << std::bitset<8>(table[1][i]) << " ";
    }
    std::cout << "\n\nPermutation P1:\n";
    for (int i = 0; i < 256; ++i) {
        std::cout << static_cast<int>(P1[i]) << " ";
    }
    std::cout << std::endl;

    return 0;
}
