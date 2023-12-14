//
// Created by arno on 3/12/23.
//

#ifndef PC_WINKLE_CAPSTRING_HPP
#define PC_WINKLE_CAPSTRING_HPP
#include <cstring>
#include <string>
#include <stdexcept>

template<size_t Capacity>
class CapString {
public:
    CapString() : strSize(0) {
        memset(data, 0, Capacity);
    }

    CapString(const char* str) : strSize(strlen(str)) {
        if (strSize > Capacity)
            throw std::runtime_error("String too long");

        strncpy(data, str, Capacity);
    }

    CapString(const CapString<Capacity>& other) : strSize(other.strSize) {
        memcpy(data, other.data, Capacity);
    }

    CapString(const std::string& str) : strSize(str.size()) {
        if (strSize > Capacity)
            throw std::runtime_error("String too long");

        strncpy(data, str.c_str(), Capacity);
    }

    void set(const char* str) {
        if (strlen(str) > Capacity)
            throw std::runtime_error("String too long");
        strSize = strlen(str);
        strncpy(data, str, Capacity);
    }

    void set(std::string str) {
        if (str.size() > Capacity)
            throw std::runtime_error("String too long");
        strSize = str.size();
        strncpy(data, str.c_str(), Capacity);
    }

    void set(const CapString<Capacity>& other) {
        strSize = other.strSize;
        memcpy(data, other.data, Capacity);
    }

    friend std::istream& operator>>(std::istream& is, CapString<Capacity>& str) {
        std::string temp;
        is >> temp;
        str.set(temp);
        return is;
    }

    [[nodiscard]] const char* c_str() const {
        return (const char*)data;
    }

    [[nodiscard]] size_t size() const {
        return strSize;
    }

    [[nodiscard]] size_t capacity() const {
        return Capacity;
    }

    CapString& operator=(const std::string& str) {
        set(str);
        return *this;
    }

    CapString& operator=(const char* str) {
        set(str);
        return *this;
    }

    bool operator==(const CapString<Capacity>& other) const {
        if (strSize != other.strSize)
            return false;
        return strcmp(data, other.data) == 0;
    }

    bool operator==(const char* other) const {
        if (strSize != strlen(other))
            return false;
        return strcmp(data, other) == 0;
    }

    bool operator==(const std::string& other) const {
        if (strSize != other.size())
            return false;
        return strcmp(data, other.c_str()) == 0;
    }

    bool operator!=(const CapString<Capacity>& other) const {
        if (strSize != other.strSize)
            return true;
        return strcmp(data, other.data) != 0;
    }

    bool operator!=(const std::string& other) const {
        if (strSize != other.size())
            return true;
        return strcmp(data, other.c_str()) != 0;
    }

    bool operator!=(const char* other) const {
        if (strSize != strlen(other))
            return true;
        return strcmp(data, other) != 0;
    }

private:
    size_t strSize;
    char data[Capacity];
};
#endif //PC_WINKLE_CAPSTRING_HPP
