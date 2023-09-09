#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Source1.h"

using namespace std;


// Умови перевірки "гарності" слова тут
bool isGood(const string& word) {

    return word.length() > 5;
}

int main(int argc, char* argv[]) {
    vector<string> words;

    // Отримуємо вхідні дані з командного рядка або з діалогу з користувачем
    if (argc > 2) {
        // Зчитуємо дані з параметрів командного рядка
        for (int i = 1; i < argc-1; i++) {
            words.push_back(argv[i]);
        }
    }
    else {
        string inputFileName;
        cout << "Введіть ім'я файлу зі словами: ";
        cin >> inputFileName;

        ifstream inputFile(inputFileName);
        if (!inputFile.is_open()) {
            cerr << "Помилка: Не вдалося відкрити файл " << inputFileName << std::endl;
            return 1;
        }

        std::string word;
        while (inputFile >> word) {
            words.push_back(word);
        }
    }

    // Упорядковуємо слова
    orderWords(words, isGood);

    // Обчислюємо кількість "гарних", "поганих" і "ніяких" слів
    int goodCount, badCount, neutralCount;
    countWords(words, goodCount, badCount, neutralCount, isGood);

    // Отримуємо ім'я файлу для виведення результатів з командного рядка
    if (argc <= 1) {
        std::cerr << "Помилка: Вкажіть ім'я файлу для результатів в командному рядку." << std::endl;
        return 1;
    }

    std::string outputFileName = argv[argc - 1];

    // Записуємо результати в файл
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл " << outputFileName << std::endl;
        return 1;
    }

    outputFile << "Кількість \"гарних\" слів: " << goodCount << std::endl;
    outputFile << "Кількість \"поганих\" слів: " << badCount << std::endl;
    outputFile << "Кількість \"ніяких\" слів: " << neutralCount << std::endl;

    outputFile.close();

    return 0;

}