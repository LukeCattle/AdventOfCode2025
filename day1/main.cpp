#include <fstream>
#include <string>
#include <vector>
#include <iostream>

struct Instruction {
    char direction;
    int distance;
};

int main() {
    std::ifstream file("c:\\work\\adventOfCode\\day1\\input.txt");
    std::vector<Instruction> instructions;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open input file" << std::endl;
        return 1;
    }
    
    char dir;
    int num;
    while (file >> dir >> num) {
        instructions.push_back({dir, num});
    }

    auto currentPosition = 50;
    auto zeroCount = 0;
    for (int i = 0; i < instructions.size(); ++i) {
        char direction = instructions[i].direction;
        int distance = instructions[i].distance;

        if (direction == 'L') {
            int stepsToZero = (currentPosition == 0) ? 100 : currentPosition;
            if (distance >= stepsToZero) {
                zeroCount += 1 + (distance - stepsToZero) / 100;
            }
            currentPosition = (currentPosition - distance) % 100;
            if (currentPosition < 0)
            {
                currentPosition += 100;
            }

        } else if (direction == 'R') {
            int stepsToZero = (currentPosition == 0) ? 100 : (100 - currentPosition);
            if (distance >= stepsToZero) {
                zeroCount += 1 + (distance - stepsToZero) / 100;
            }
            currentPosition = (currentPosition + distance) % 100;
            if (currentPosition < 0)
            {
                currentPosition += 100;
            }
        }

        std::cout << "Current Position: " << currentPosition << std::endl;
    }
    std::cout << "zero Count: " << zeroCount << std::endl;
    return 0;
}