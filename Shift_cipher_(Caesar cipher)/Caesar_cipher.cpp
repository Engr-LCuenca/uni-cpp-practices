#include <iostream>
#include <limits>
#include <string>
#include <cctype>

using namespace std;

string shiftText(const string& text, int shift, bool decrypt = false) {
    string result;
    result.reserve(text.size());

    const int effectiveShift = decrypt ? -shift : shift;

    for (char ch : text) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            const char base = isupper(static_cast<unsigned char>(ch)) ? 'A' : 'a';
            const int offset = static_cast<int>(ch - base);
            const int shifted = (offset + effectiveShift + 26) % 26;
            result.push_back(static_cast<char>(base + shifted));
        } else {
            result.push_back(ch);
        }
    }

    return result;
}

int main() {
    int choice = 0;
    string text;
    int shift = 3;

    while (true) {
        cout << "\n=== Caesar Cipher Menu ===\n";
        cout << "1. Encrypt text\n";
        cout << "2. Decrypt text\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Goodbye!\n";
            return 1;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice != 1 && choice != 2) {
            cout << "Invalid option. Please try again.\n";
            continue;
        }

        cout << "Enter the text: ";
        getline(cin, text);

        cout << "Enter the shift value: ";
        cin >> shift;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        const bool decrypt = (choice == 2);
        const string output = shiftText(text, shift, decrypt);

        if (decrypt) {
            cout << "Decrypted text: " << output << "\n";
        } else {
            cout << "Encrypted text: " << output << "\n";
        }
    }

    return 0;
}
