#ifndef SOURCE1_H
#define SOURCE1_H

#include <vector>
#include <string>
#include <algorithm>

// Оголосимо тип функції для критерію "гарності"
typedef bool (*CriteriaFunction)(const std::string&);

// Прототип функції для упорядкування слів
void orderWords(std::vector<std::string>& words, CriteriaFunction criteria);

// Прототип функції для підрахунку кількості слів
void countWords(const std::vector<std::string>& words, int& goodCount, int& badCount, int& neutralCount, CriteriaFunction criteria);

#endif