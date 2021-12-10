#include <fstream>
#include <iostream>
#include <sstream>

enum class Operation {
    eForward,
    eDown,
    eUp,
    eNone
};

Operation getOperation(const std::string& op) 
{
    if (op == "forward")
        return Operation::eForward;
    else if (op == "up")
        return Operation::eUp;
    else if (op == "down")
        return Operation::eDown;
    return Operation::eNone;
}


int part1() 
{
    auto coordinates = std::make_pair<int, int>(0, 0);

    std::ifstream in("Day2.txt");

    std::string op;
    int value;

    while (!in.eof()) {
        in >> op >> value;
        switch (getOperation(op))
        {
        case Operation::eForward:
            coordinates.first += value;
            break;
        case Operation::eDown:
            coordinates.second += value;
            break;
        case Operation::eUp:
            coordinates.second -= value;
            break;
        }
    }
    return coordinates.first * coordinates.second;
}

int part2()
{
    int horiz = 0, aim = 0, depth = 0;

    std::ifstream in("Day2.txt");

    std::string op;
    int value;

    while (!in.eof()) {
        in >> op >> value;
        switch (getOperation(op))
        {
        case Operation::eForward:
            horiz += value;
            depth += (aim * value);
            break;
        case Operation::eDown:
            aim += value;
            break;
        case Operation::eUp:
            aim -= value;
            break;
        }
    }
    return horiz * depth;

}

int main()
{
    //std::cout << part1();
    std::cout << part2();
}