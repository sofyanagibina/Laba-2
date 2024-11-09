#include <algorithm> 

template <typename T>
class Grid final {
public:
    using value_type = T;
    using size_type = unsigned;

private:
    T* data;
    size_type const y_size, x_size;

public:
    Grid(T const& t)
        : data(new T[1]), y_size(1), x_size(1) {
        *data = t; 
    }

    // Konstruktor with two params.
    Grid(size_type y_size, size_type x_size)
        : data(new T[y_size * x_size]), y_size(y_size), x_size(x_size) {
        std::fill(data, data + (y_size * x_size), T());
    }

    // Konstruktor with three params.
    Grid(size_type y_size, size_type x_size, T const& t)
        : data(new T[y_size * x_size]), y_size(y_size), x_size(x_size) {
        std::fill(data, data + (y_size * x_size), t);
    }
//five rules of using dynamics member
    // Destruktor
    ~Grid() {
        delete[] data;
    }

    // copy konstruktor
    Grid(Grid<T> const& other)
        : data(new T[other.y_size * other.x_size]), y_size(other.y_size), x_size(other.x_size) {
        std::copy(other.data, other.data + (y_size * x_size), data);
    }

    // Translator konstruktor
    Grid(Grid<T>&& other) noexcept
        : data(other.data), y_size(other.y_size), x_size(other.x_size) {
        other.data = nullptr;
    }

    // Konstructor of assignment copy
    Grid<T>& operator=(Grid<T> const& other) {
        if (this != &other) {
            delete[] data;

            y_size = other.y_size;
            x_size = other.x_size;
            data = new T[y_size * x_size];
            std::copy(other.data, other.data + (y_size * x_size), data);
        }
        return *this;
    }

    // // Konstructor of translation copy
    Grid<T>& operator=(Grid<T>&& other) noexcept {
        if (this != &other) {
            delete[] data;

            data = other.data; 
            y_size = other.y_size;
            x_size = other.x_size;

            other.data = nullptr; 
        }
        return *this;
    }

    T operator()(size_type y_idx, size_type x_idx) const {
        return data[y_idx * x_size + x_idx];
    }

    T& operator()(size_type y_idx, size_type x_idx) {
        return data[y_idx * x_size + x_idx];
    }

    Grid<T>& operator=(T const& t) {
        for (auto it = data, end = data + x_size * y_size; it != end; ++it) {
            *it = t;
        }
        return *this;
    }

    size_type get_y_size() const { return y_size; }
    size_type

    get_x_size() const { return x_size; }
};
