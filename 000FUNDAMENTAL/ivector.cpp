#include <iostream>
#include <cassert>
#include <cstdint>

template <typename T>
class ivector {
private:
    T *ptr;
    size_t capacity, used;

    void enlarge() {
        capacity <<= 1;
        T *new_ptr = new T[capacity]();
        for (int i = 0; i < used; i++) {
            new_ptr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = new_ptr;
    }

public:
    ivector(size_t default_cap) : capacity(default_cap) {
        assert(default_cap > 0);
        used = 0;
        ptr = new T[default_cap]();
    }

    ivector() : ivector(8) {}
    ~ivector() { delete[] ptr; }

    void push_back(T value) {
        if (used == capacity) enlarge();
        ptr[used++] = value;
    }
    
    T back() {
        assert(used > 0);
        return ptr[used - 1];
    }

    T at(int idx) {
        assert(idx >= 0 && idx < used);
        return ptr[idx];
    }

    size_t size() {
        return used;
    }

    void pop_back() {
        assert(used > 0);
        --used;
    }
};

int main(void) {
    ivector<int64_t> vec;
    vec.push_back(1LL);
    vec.push_back(1LL);
    for (int i = 0; i < 7; i++) {
        int sz = vec.size();
        vec.push_back(vec.at(sz - 1) + vec.at(sz - 2));
    }

    std::cout << vec.at(vec.size() - 1) << std::endl;
}