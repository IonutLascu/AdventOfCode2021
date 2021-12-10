#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <numeric>
#include <vector>

int part1()
{
    int increased = 0, firstNr, anotherNr;

    std::ifstream in("day1.txt");
    in >> firstNr;

    while (!in.eof()) {
        in >> anotherNr;
        if (firstNr < anotherNr) {
            increased++;
        }
        firstNr = anotherNr;
    }

    return increased;
}

bool check(const std::vector<int>& arr)
{
    return std::accumulate(arr.begin(), std::prev(arr.end()), 0) <
        std::accumulate(arr.begin() + 1, arr.end(), 0);
}

int part2()
{
    int increased = 0;
    std::vector<int> arr(4, 0);
    std::ifstream in("day1.txt");

    for (auto& i : arr)
        in >> i;
    while (!in.eof()) {
        if (check(arr)) {
            ++increased;
        }

        std::shift_left(arr.begin(), arr.end(), 1);
        in >> arr.back();
    }

    if (check(arr)) {
        ++increased;
    }

    return increased;
}

int main()
{
    //std::cout << part1();
    std::cout << part2();
}