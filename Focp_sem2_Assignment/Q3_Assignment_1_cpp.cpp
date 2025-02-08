#include <iostream>
#include <string>
using namespace std;

// Function to check if the string is a palindrome
bool isPalindrome(string str) {
    string cleanedStr = "";
    
    // Remove spaces and convert to lowercase
    for (char ch : str) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {  // Check if the character is alphabetic
            if (ch >= 'A' && ch <= 'Z') {  // Convert uppercase to lowercase
                ch = ch + ('a' - 'A');
            }
            cleanedStr += ch;
        }
    }

    int left = 0, right = cleanedStr.length() - 1;
    while (left < right) {
        if (cleanedStr[left] != cleanedStr[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to count frequency of each character (case insensitive)
void countFrequency(string str) {
    int freq[26] = {0}; // Array to store frequencies of each letter (a-z)

    // Count frequency of each alphabetic character
    for (char ch : str) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {  // Check if the character is alphabetic
            if (ch >= 'A' && ch <= 'Z') {  // Convert uppercase to lowercase
                ch = ch + ('a' - 'A');
            }
            freq[ch - 'a']++;  // Increment the corresponding frequency
        }
    }

    cout << "Character frequencies: " << endl;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            cout << char(i + 'a') << ": " << freq[i] << endl;
        }
    }
}

// Function to replace vowels with '*'
void replaceVowelsWithAsterisk(string &str) {
    for (char &ch : str) {
        char lowerCh = (ch >= 'A' && ch <= 'Z') ? (ch + ('a' - 'A')) : ch; // Convert to lowercase
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            ch = '*';
        }
    }
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input); // Accepting full line input, including spaces

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    // Count and display the frequency of each character
    countFrequency(input);

    // Replace vowels with '*' and display the modified string
    replaceVowelsWithAsterisk(input);
    cout << "String after replacing vowels with '*': " << input << endl;

    return 0;
}