// my_lab.cpp
#include "my_lab.h"
#include <fstream>
#include <iostream>

// Реализация быстрой сортировки
template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low -1;
    for(int j = low; j <= high -1; ++j){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return (i+1);
}

template <typename T>
void quickSort(std::vector<T>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi +1, high);
    }
}

// Необходимые явные инстанциации для шаблонов
template void quickSort<int>(std::vector<int>&, int, int);
template void quickSort<Person>(std::vector<Person>&, int, int);

// Функции для работы с файлами
std::vector<int> readIntArray(const std::string& filename){
    std::vector<int> arr;
    std::ifstream infile(filename);
    if(!infile){
        std::cerr << "No input file: " << filename << std::endl;
        return arr;
    }
    int num;
    while(infile >> num){
        arr.push_back(num);
    }
    infile.close();
    return arr;
}

std::vector<Person> readPersonArray(const std::string& filename){
    std::vector<Person> arr;
    std::ifstream infile(filename);
    if(!infile){
        std::cerr << "No input file: " << filename << std::endl;
        return arr;
    }
    std::string name;
    int age;
    while(infile >> name >> age){
        arr.emplace_back(name, age);
    }
    infile.close();
    return arr;
}

void writeIntArray(const std::vector<int>& arr, const std::string& filename){
    std::ofstream outfile(filename);
    if(!outfile){
        std::cerr << "No outnput file: " << filename << std::endl;
        return;
    }
    for(const auto& num : arr){
        outfile << num << " ";
    }
    outfile << std::endl;
    outfile.close();
}

void writePersonArray(const std::vector<Person>& arr, const std::string& filename){
    std::ofstream outfile(filename);
    if(!outfile){
        std::cerr << "No outnput file: " << filename << std::endl;
        return;
    }
    for(const auto& person : arr){
        outfile << person.name << " " << person.age << std::endl;
    }
    outfile.close();
}
