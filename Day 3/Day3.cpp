#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int part1()
{
    std::vector<int> arr(12, 0);
    std::string gamma, epsilon;
    std::string value;
    std::ifstream in("Day3.txt");

    while (!in.eof()) {
        in >> value;
        for (int i = 0; i < value.size(); ++i) {
            if (value[i] == '0') {
                arr[i]--;
            }
            else if (value[i] == '1') {
                arr[i]++;
            }
        }
    }

    for (const auto i : arr) {
        if (i < 0) {
            gamma.push_back('0');
            epsilon.push_back('1');
        }
        else {
            gamma.push_back('1');
            epsilon.push_back('0');
        }
    }

    return std::stoi(gamma, 0, 2) *
        std::stoi(epsilon, 0, 2);
}

int loop(std::vector<std::string> arr, int pos, bool lower = false)
{
    std::vector<std::string> newArr{};

    const int noElements = std::count_if(arr.cbegin(), arr.cend(),
        [=](const std::string& value) { return value[pos] == '0'; });

    if (!lower) {
        if (noElements > arr.size() - noElements) {
            newArr = std::vector<std::string>(noElements);
            std::copy_if(arr.begin(), arr.end(), newArr.begin(),
                [=](const std::string& value) { return value[pos] == '0'; });
        }
        else {
            newArr = std::vector<std::string>(arr.size() - noElements);
            std::copy_if(arr.begin(), arr.end(), newArr.begin(),
                [=](const std::string& value) { return value[pos] == '1'; });
        }
    }
    else {
        if (noElements <= arr.size() - noElements) {
            newArr = std::vector<std::string>(noElements);
            std::copy_if(arr.begin(), arr.end(), newArr.begin(),
                [=](const std::string& value) { return value[pos] == '0'; });
        }
        else {
            newArr = std::vector<std::string>(arr.size() - noElements);
            std::copy_if(arr.begin(), arr.end(), newArr.begin(),
                [=](const std::string& value) { return value[pos] == '1'; });
        }
    }
    
    if (newArr.size() == 1) {
        return std::stoi(newArr.front(), 0, 2);
    }

    return loop(newArr, ++pos, lower);
}

int part2()
{
    std::vector<std::string> arr;
    int co2Scrubber, generator;
    std::string value;
    std::ifstream in("Day3.txt");
    
    while (!in.eof()) {
        in >> value;
        arr.push_back(value);
    }
    
    return loop(arr, 0) * loop(arr, 0, true);
}


int main()
{
    //std::cout << part1();
    std::cout << part2();
}