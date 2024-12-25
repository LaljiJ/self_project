/*--------------------------------------------------*/
//  Name : Lalji J
//  File : own_string_datatype.c
//  Desciption : Write own string dataytype in c++ which has work as a same string datatype which are predefine function in C++ language.
/*--------------------------------------------------*/



#include <iostream>
#include <cstring>
#include <cctype>

class Own_string {
private:
    char* data; // Pointer to the actual string data
    size_t length; // Length of the string

public:
    // Default constructor
    Own_string() : data(nullptr), length(0) {}

    // Parameterized constructor
    Own_string(const char* str) {
        length = own_strlen(str);
        data = new char[length + 1]; // +1 for null terminator
        own_strcpy(data, str);
    }

    // Copy constructor
    Own_string(const Own_string& other) {
        length = other.length;
        data = new char[length + 1]; // +1 for null terminator
        own_strcpy(data, other.data);
    }

    // Destructor
    ~Own_string() {
        delete[] data;
    }

    // Assignment operator
    Own_string& operator=(const Own_string& other) {
        if (this != &other) {
            delete[] data; // Free existing memory
            length = other.length;
            data = new char[length + 1]; // +1 for null terminator
            own_strcpy(data, other.data);
        }
        return *this;
    }

    // << operator overload for output
    friend std::ostream& operator<<(std::ostream& os, const Own_string& str) {
        os << str.data;
        return os;
    }

    // >> operator overload for input
    friend std::istream& operator>>(std::istream& is, Own_string& str) {
        char buffer[1024];
        is >> buffer;
        str = Own_string(buffer);
        return is;
    }

    // + operator overload for concatenation
    Own_string operator+(const Own_string& other) const {
        Own_string result;
        result.length = length + other.length;
        result.data = new char[result.length + 1]; // +1 for null terminator
        own_strcpy(result.data, data);
        own_strcat(result.data, other.data);
        return result;
    }

    // [] operator overload for accessing individual characters
    char& operator[](size_t index) {
        return data[index];
    }

    // Comparison operators
    bool operator>(const Own_string& other) const {
        return own_strcmp(data, other.data) > 0;
    }

    bool operator<(const Own_string& other) const {
        return own_strcmp(data, other.data) < 0;
    }

    bool operator>=(const Own_string& other) const {
        return own_strcmp(data, other.data) >= 0;
    }

    bool operator<=(const Own_string& other) const {
        return own_strcmp(data, other.data) <= 0;
    }

    bool operator==(const Own_string& other) const {
        return own_strcmp(data, other.data) == 0;
    }

    bool operator!=(const Own_string& other) const {
        return own_strcmp(data, other.data) != 0;
    }

    // Custom string functions

    // Implementation of strcpy
    static char* own_strcpy(char* dest, const char* src) {
        char* ptr = dest;
        while ((*ptr++ = *src++) != '\0');
        return dest;
    }

    // Implementation of strcmp
    static int own_strcmp(const char* str1, const char* str2) {
        while (*str1 && (*str1 == *str2)) {
            str1++;
            str2++;
        }
        return *(const unsigned char*)str1 - *(const unsigned char*)str2;
    }

    // Implementation of strlen
    static size_t own_strlen(const char* str) {
        size_t len = 0;
        while (*str++) {
            len++;
        }
        return len;
    }

    // Implementation of strcat
    static char* own_strcat(char* dest, const char* src) {
        own_strcpy(dest + own_strlen(dest), src);
        return dest;
    }

    // Implementation of strchr
    static char* own_strchr(const char* str, int c) {
        while (*str && *str != c) {
            str++;
        }
        return (*str == c) ? const_cast<char*>(str) : nullptr;
    }

    // Implementation of strrchr
    static char* own_strrchr(const char* str, int c) {
        const char* last_occurrence = nullptr;
        while (*str) {
            if (*str == c) {
                last_occurrence = str;
            }
            str++;
        }
        return const_cast<char*>(last_occurrence);
    }

    // Implementation of strrevers
    static void own_strrevers(char* str) {
        if (!str) return;
        char* end = str + own_strlen(str) - 1;
        while (str < end) {
            char temp = *str;
            *str++ = *end;
            *end-- = temp;
        }
    }

    // Implementation of strstr
    static char* own_strstr(const char* haystack, const char* needle) {
        size_t needle_length = own_strlen(needle);
        while (*haystack) {
            if (own_strncmp(haystack, needle, needle_length) == 0) {
                return const_cast<char*>(haystack);
            }
            haystack++;
        }
        return nullptr;
    }

    // Implementation of strncat
    static char* own_strncat(char* dest, const char* src, size_t n) {
        size_t dest_len = own_strlen(dest);
        size_t i;
        for (i = 0; i < n && src[i] != '\0'; i++) {
            dest[dest_len + i] = src[i];
        }
        dest[dest_len + i] = '\0';
        return dest;
    }

    // Implementation of strncmp
    static int own_strncmp(const char* str1, const char* str2, size_t n) {
        for (size_t i = 0; i < n; i++) {
            if (str1[i] != str2[i]) {
                return (str1[i] - str2[i]);
            }
        }
        return 0;
    }

    // Implementation of strncpy
    static char* own_strncpy(char* dest, const char* src, size_t n) {
        size_t i;
        for (i = 0; i < n && src[i] != '\0'; i++) {
            dest[i] = src[i];
        }
        for (; i < n; i++) {
            dest[i] = '\0';
        }
        return dest;
    }

    // Convert string to uppercase
    void own_struppercase() {
        for (size_t i = 0; i < length; i++) {
            data[i] = std::toupper(data[i]);
        }
    }

    // Convert string to lowercase
    void own_strlowercase() {
        for (size_t i = 0; i < length; i++) {
            data[i] = std::tolower(data[i]);
        }
    }
};

int main() {
    Own_string str1("Hello");
    Own_string str2("World");

    // Testing custom functions
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    // Test concatenation
    Own_string concatenated = str1 + " " + str2;
    std::cout << "Concatenated: " << concatenated << std::endl;

    // Test comparison operators
    std::cout << "Comparison: " << (str1 > str2) << std::endl;

    // Test custom string functions
    concatenated.own_struppercase();
    std::cout << "Uppercase: " << concatenated << std::endl;

    concatenated.own_strlowercase();
    std::cout << "Lowercase: " << concatenated << std::endl;

    return 0;
}


