// my_lab.h
#ifndef MY_LAB_H
#define MY_LAB_H

#include <vector>
#include <string>

// Класс Person
class Person {
public:
    std::string name;
    int age;

    Person() : name(""), age(0) {}
    Person(const std::string& n, int a) : name(n), age(a) {}

    // Оператор сравнения по возрасту
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

// Шаблон быстрой сортировки
template <typename T>
void quickSort(std::vector<T>& arr, int low, int high);

// Функции для чтения и записи данных
std::vector<int> readIntArray(const std::string& filename);
std::vector<Person> readPersonArray(const std::string& filename);
void writeIntArray(const std::vector<int>& arr, const std::string& filename);
void writePersonArray(const std::vector<Person>& arr, const std::string& filename);

#endif // MY_LAB_H
