# include "functions.h"
// add any includes

using std::cout, std::cin, std::endl, std::string;

void deobfuscate() {
    // TODO
    char string[100];
    char length[50];
    int count = 0;

    cout << "Please enter obfuscated sentence: ";
    cin >> string;
    cout << "Please enter deobfuscation details: ";
    cin >> length;

    cout << "Deobfuscated sentence: ";
    for (int i = 0; length[i] != '\0'; ++i) {
        char c = length[i];
        int number = (int)c - 48;

        for (int j = 0; j < number; ++j) {
            cout << string[count+j];
        }
        cout << " ";
        count = count + number;

    }
    cout << endl;
}

void wordFilter() {
    // TODO
    string input_sent;
    string filter_word;
    string filter = "#";
    unsigned int i;

    cout << "Please enter the sentence: ";
    getline(cin, input_sent);
    cout << "Please enter the filter word: ";
    cin >> filter_word;

    for (i = 1; i < filter_word.size(); ++i) {
        filter.push_back('#');
    }

    while (input_sent.find(filter_word) != string::npos) {
        input_sent.replace((input_sent.find(filter_word)), (filter_word.size()), filter);
    }
    
    cout << "Filtered sentence: " << input_sent << endl;
}

void passwordConverter() {
    // TODO
    string pwd;
    int i;

    cout << "Please enter your text input: ";
    cin >> pwd;
    cout << "input: " << pwd;

    for (i = 0; i < pwd.size(); ++i) {
        if (pwd.at(i) == 'a') {
            pwd.replace(i, 1, "@");
        }
        else if (pwd.at(i) == 'e') {
            pwd.replace(i, 1, "3");
        }
        else if (pwd.at(i) == 'i') {
            pwd.replace(i, 1, "!");
        }
        else if (pwd.at(i) == 'o') {
            pwd.replace(i, 1, "0");
        }
        else if (pwd.at(i) == 'u') {
            pwd.replace(i, 1, "^");
        }
    }

    cout << endl << "output: " << pwd;

    for (i = pwd.length() - 1; i >= 0; --i) {
        cout << pwd[i];
    } 
    cout << endl;
}

void wordCalculator() {
    // TODO
}

void palindromeCounter() {
    // TODO
}