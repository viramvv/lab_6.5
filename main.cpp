#include <iostream>
#include <string>
#include "Deque.h"

int main() {
    // Встановлення локалі для коректного відображення символів (якщо потрібно)
    setlocale(LC_ALL, "Ukrainian");

    // --- 1. ТЕСТУВАННЯ З ТИПОМ INT ---
    std::cout << "=== Тестування Deque <int> ===" << std::endl;
    try {
        Deque<int> dInt;
        dInt.push_back(10);
        dInt.push_front(20);
        std::cout << "Додано 10 (back) та 20 (front). Front: " << dInt.front() << ", Back: " << dInt.back() << std::endl;

        dInt.pop_back();
        std::cout << "Видалено з кінця. Новий Back: " << dInt.back() << std::endl;

        dInt.clear();
        std::cout << "Контейнер очищено. Спроба доступу..." << std::endl;
        dInt.pop_front(); // Це викличе виняток
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка (int): " << e.what() << "\n" << std::endl;
    }


    // --- 2. ТЕСТУВАННЯ З ТИПОМ DOUBLE ---
    std::cout << "=== Тестування Deque <double> ===" << std::endl;
    try {
        Deque<double> dDouble;
        dDouble.push_back(5.55);
        dDouble.push_front(1.23);
        std::cout << "Front: " << dDouble.front() << ", Back: " << dDouble.back() << std::endl;

        dDouble.pop_front();
        dDouble.pop_front();
        std::cout << "Видалено всі елементи. Спроба отримати front..." << std::endl;
        std::cout << dDouble.front() << std::endl; // Це викличе виняток
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка (double): " << e.what() << "\n" << std::endl;
    }


    // --- 3. ТЕСТУВАННЯ З ТИПОМ STD::STRING ---
    std::cout << "=== Тестування Deque <std::string> ===" << std::endl;
    try {
        Deque<std::string> dStr;
        dStr.push_back("World");
        dStr.push_front("Hello");
        std::cout << "Вміст: " << dStr.front() << " " << dStr.back() << std::endl;

        dStr.pop_back();
        dStr.pop_back();
        std::cout << "Черга порожня: " << (dStr.empty() ? "Так" : "Ні") << std::endl;

        std::cout << "Спроба видалення з порожнього списку (pop_back)..." << std::endl;
        dStr.pop_back(); // Це викличе виняток
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка (string): " << e.what() << "\n" << std::endl;
    }

    std::cout << "Програма завершила роботу." << std::endl;
    return 0;
}