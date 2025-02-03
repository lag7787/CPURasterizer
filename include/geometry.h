#include <cstdint>

template<typename T>
class Vec2 {
    private:
        T x, y;
    public:
        Vec2();
        Vec2(T, T);
        T& operator[](uint8_t);
        void print();
};