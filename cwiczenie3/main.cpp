#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedImportStatement"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        std::cout << "Oczekiwano 3 argumentów, a podano tylko " << argc - 1 << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream inFile;
    std::ofstream outFile;
    std::string currentLine;
    std::string newFileName = argv[1];

    std::size_t dotPosition = newFileName.find('.');
    if (dotPosition == std::string::npos) {
        std::cout << "Żądany plik nie ma rozszerzenia" << std::endl;
        return EXIT_FAILURE;
    }
    newFileName = newFileName.replace(dotPosition, 1, "_nowy.");

    std::cout << "Otwieranie pliku: " << argv[1] << std::endl;
    inFile.open(argv[1]);
    if (!inFile.is_open()) {
        std::cout << "Błąd otwarcia pliku: " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Tworzenie pliku: " << newFileName << std::endl;
    outFile.open(newFileName.c_str());
    if (!outFile.is_open()) {
        std::cout << "Błąd podczas tworzenia pliku: " << newFileName << std::endl;
        return EXIT_FAILURE;
    }

    while (inFile.good()) {
        std::getline(inFile, currentLine);
        currentLine = currentLine;
        std::size_t position = 0;
        while ((position = currentLine.find(argv[2], position) ) != std::string::npos) {
            currentLine.replace(position, strlen(argv[2]), argv[3]);
            position += strlen(argv[2]);
        }
        outFile << currentLine << std::endl;
    }

    if (inFile.eof()) {
        std::cout << "Gotowe" << std::endl;
    } else if (inFile.fail()) {
        std::cout << "Błąd podczas wczytywania pliku" << std::endl;
        return EXIT_FAILURE;
    } else {
        std::cout << "Nieznany błąd" << std::endl;
        return EXIT_FAILURE;
    }

    inFile.close();
    outFile.close();

    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop