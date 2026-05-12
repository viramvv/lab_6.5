#include <iostream>
#include <list>
#include <string>
#include <stdexcept>

// Шаблонний клас Deque (двостороння черга)
template <typename T>
class Deque {
private:
    std::list<T> container; // Серверний клас (Table 2, Variant 14)

public:
    // Додати в кінець
    void push_back(const T& value) {
        container.push_back(value);
    }

    // Додати в початок
    void push_front(const T& value) {
        container.push_front(value);
    }

    // Видалити з початку
    void pop_front() {
        if (container.empty()) {
            throw std::runtime_error("Deque Error: Спроба видалити елемент з порожньої черги (pop_front)!");
        }
        container.pop_front();
    }

    // Видалити з кінця
    void pop_back() {
        if (container.empty()) {
            throw std::runtime_error("Deque Error: Спроба видалити елемент з порожньої черги (pop_back)!");
        }
        container.pop_back();
    }

    // Отримати перший елемент
    T& front() {
        if (container.empty()) {
            throw std::logic_error("Deque Error: Черга порожня, неможливо отримати фронтальний елемент!");
        }
        return container.front();
    }

    // Отримати останній елемент
    T& back() {
        if (container.empty()) {
            throw std::logic_error("Deque Error: Черга порожня, неможливо отримати останній елемент!");
        }
        return container.back();
    }

    bool empty() const {
        return container.empty();
    }

    size_t size() const {
        return container.size();
    }

    void clear() {
        container.clear();
    }
};

// Функція для демонстрації роботи з різними типами
template <typename T>
void testDeque(const std::string& typeName, T val1, T val2) {
    std::cout << "--- Тестування Deque для типу: " << typeName << " ---" << std::endl;
    Deque<T> d;

    try {
        d.push_back(val1);
        d.push_front(val2);
        std::cout << "Елементи додано. Front: " << d.front() << ", Back: " << d.back() << std::endl;

        d.pop_front();
        d.pop_back();
        std::cout << "Елементи видалено. Поточний розмір: " << d.size() << std::endl;

        // Виклик винятку
        std::cout << "Спроба видалення з порожнього дека..." << std::endl;
        d.pop_front();
    }
    catch (const std::exception& e) {
        std::cerr << "Перехоплено виняток: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

