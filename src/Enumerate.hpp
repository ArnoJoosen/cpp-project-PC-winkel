//
// Created by arno on 5/12/23.
//

#ifndef PC_WINKLE_ENUMERATE_HPP
#define PC_WINKLE_ENUMERATE_HPP

#include <cstddef>

template<typename T>
struct EnumerateValue {
    size_t index;
    T value;
};

template<class Container_t>
class Enumerate {
public:
    Enumerate(const Container_t& container) : container(container) {}

    class iterator {
    public:
      iterator(typename Container_t::const_iterator it, size_t i) : it(it), index(i) {}

        EnumerateValue<typename Container_t::value_type> operator*() const {
            return {index, *it};
        }

        iterator& operator++() {
            ++it;
            ++index;
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return it != other.it;
        }

        iterator& operator--() {
            --it;
            --index;
            return *this;
        }

    private:
        size_t index;
        typename Container_t::const_iterator it;
    };

    iterator begin() const {
        return iterator(container.begin(), 0);
    }

    iterator end() const {
        return iterator(container.end(), container.size());
    }
private:
    const Container_t container;
};

#endif //PC_WINKLE_ENUMERATE_HPP
