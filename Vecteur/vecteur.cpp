#include <iostream>

class Vector {
private:
    int* data;
    int size;
public:
    Vector() {
        data = new int[1];
        size = 0;
    }

    void push_back(int element) {
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        temp[size] = element;
        size++;
        delete[] data;
        data = temp;
    }

    void pop_back() {
        int* temp = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            temp[i] = data[i];
        }
        size--;
        delete[] data;
        data = temp;
    }

    int at(int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of bounds" << std::endl;
            exit(1);
        }
        return data[index];
    }

    int get_size() {
        return size;
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::cout << "Size of vector: " << v.get_size() << std::endl;
    std::cout << "Element at index 1: " << v.at(1) << std::endl;
    v.pop_back();
    std::cout << "Size of vector after pop_back: " << v.get_size() << std::endl;
    std::cout << "Is vector empty? " << v.empty() << std::endl;
    return 0;
}