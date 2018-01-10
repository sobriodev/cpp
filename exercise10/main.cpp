#include <iostream>
#include <random>
#include <chrono>
#include "TestClass.h"
#include "templates.h"
#include "SpecialClass.h"

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1568);

    int elemNum;
    std::cout << "Enter numbers of elements: ";
    std::cin >> elemNum;
    if (!std::cin || elemNum <= 0) {
        std::cout << "Sorry, entered value ha illegal format. Aborting!";
        return EXIT_FAILURE;
    }

    //auto *vector1 = new int[elemNum];
    //auto *vector2 = new int[elemNum];
    //auto *vector1 = new SpecialClass[elemNum];
    //auto *vector2 = new SpecialClass[elemNum];
    auto *vector1 = new TestClass[elemNum];
    auto *vector2 = new TestClass[elemNum];

    for (int i = 0; i < elemNum; ++i) {
        //vector1[i] = dis(gen);
        //vector1[i] = SpecialClass("test");
        vector1[i] = TestClass(dis(gen));
        vector2[i] = vector1[i];
    }

    auto start = std::chrono::system_clock::now();
    std::cout << "Performing selection sort...";
    selectionSort(vector1, elemNum);
    std::cout << "Done!" << std::endl;
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> selectionSortElapsedTime = end - start;

    start = std::chrono::system_clock::now();
    std::cout << "Performing quick sort...";
    quickSort(vector1, 0, elemNum - 1);
    std::cout << "Done!" << std::endl;
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> quickSortElapsedTime = end - start;

    std::cout << "Sorted elements after selection sort: ";
    for (int i = 0; i < elemNum; ++i) {
        std::cout << vector1[i] << " ";
    }
    std::cout << std::endl << "Total elapsed time: " << selectionSortElapsedTime.count() << "s" << std::endl;

    std::cout << "Sorted elements after quick sort: ";
    for (int i = 0; i < elemNum; ++i) {
        std::cout << vector1[i] << " ";
    }
    std::cout << std::endl << "Total elapsed time: " << quickSortElapsedTime.count() << "s" << std::endl;

    return 0;
}