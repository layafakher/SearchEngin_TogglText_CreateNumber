

#include <iostream>
using namespace std;
#include <sstream>
#include <cstring>
#include <string>

// Function to search for words starting with a specific character
void searchEngine(const std::string& text, char ch) {
    std::string word;
    std::istringstream iss(text);

    while (iss >> word) {
        if (word[0] == ch)
            std::cout << word << "\n";
    }
}

// Function to toggle case of characters in a string
std::string toggleCase(const std::string& text) {
    std::string result;
    for (char ch : text) {
        if ('a' <= ch && ch <= 'z')
            result += ch - 'a' + 'A';
        else if ('A' <= ch && ch <= 'Z')
            result += ch - 'A' + 'a';
        else
            result += ch;
    }
    return result;
}

// تابعی برای استخراج اعداد از یک رشته و اعمال شرایط خاص
std::string createNumber(const std::string& text) {
    std::string result;
    size_t i = 0;

    while (i < text.size()) {// تا زمانی که به انتهای رشته نرسیم
        if (std::isdigit(text[i])) { // اگر کاراکتر فعلی یک عدد باشد
            int num = text[i] - '0';
            size_t num_start = i;// شاخص شروع عدد را ذخیره می‌کنیم
            while (i + 1 < text.size() && std::isdigit(text[i + 1])) {
                num = num * 10 + (text[i + 1] - '0');
                ++i;
            }
            
            result += std::to_string(num);
        }
        ++i;
    }
    // cout<<strlen(result);
    const char* str = result.c_str();
    int data = (unsigned)strlen(str);
    int convertdata = (int)(data);
    std::string n = result.substr(1, convertdata-2);
    return n;
}

int main() {
    std::string text;
    int choice;

    std::cout << "Enter an English text: ";
    std::getline(std::cin, text);

    std::cout << "Enter a choice:\n";
    std::cout << "1. Search Engine\n";
    std::cout << "2. Toggle Case\n";
    std::cout << "3. Create Number\n";
    std::cin >> choice;

    if (choice == 1) {
        char ch;
        std::cout << "Enter a character: ";
        std::cin >> ch;
        searchEngine(text, ch);
    } else if (choice == 2) {
        std::string toggledText = toggleCase(text);
        std::cout << "Toggled Case Text: " << toggledText << "\n";
    } else if (choice == 3) {
        std::string modifiedNumber = createNumber(text);
        std::cout << "Modified Number: " << modifiedNumber << "\n";
    } else {
        std::cout << "Invalid choice!\n";
    }

    return 0;
}

