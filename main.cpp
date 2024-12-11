// main.cpp
#include "my_lab.h"
#include <iostream>

int main(){
    setlocale('LC_ALL', "Russian");
    // Сортировка массива целых чисел
    std::vector<int> intArray = readIntArray("../input.txt");
    if(intArray.empty()){
        std::cerr << "No input file" << std::endl;
    } else {
        quickSort(intArray, 0, intArray.size() -1);
        writeIntArray(intArray, "../output_int.txt");
        std::cout << "Result in output_int.txt" << std::endl;
    }

    // Сортировка массива объектов Person
    std::vector<Person> personArray = readPersonArray("../input_person.txt");
    if(personArray.empty()){
        std::cerr << "No Person input file" << std::endl;
    } else {
        quickSort(personArray, 0, personArray.size() -1);
        writePersonArray(personArray, "../output_person.txt");
        std::cout << "Result Person in output_person.txt" << std::endl;
    }

    return 0;
}
