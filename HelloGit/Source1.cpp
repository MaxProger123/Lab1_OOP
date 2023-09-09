#include <vector>
#include <string>
#include <algorithm>

using namespace std;


typedef bool (*CriteriaFunction)(const string&);

// Функція для упорядкування послідовності слів за заданим критерієм
void orderWords(vector<std::string>& words, CriteriaFunction criteria) {
    // Використовуйте передану функцію criteria для порівняння слів і впорядковуйте їх
    sort(words.begin(), words.end(), [criteria](const string& a, const string& b) {
        return criteria(a) > criteria(b);
        });
}

// Функція для обчислення кількості "гарних", "поганих" і "ніяких" слів
void countWords(const vector<string>& words, int& goodCount, int& badCount, int& neutralCount, CriteriaFunction criteria) {
    goodCount = badCount = neutralCount = 0;

    for (const std::string& word : words) {
        if (criteria(word)) {
            goodCount++;
        }
        else if (!word.empty()) {
            badCount++;
        }
        else {
            neutralCount++;
        }
    }
}
