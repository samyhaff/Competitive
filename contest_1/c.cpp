#include <iostream>

using namespace std;

int main() {
    string line;
    char c;
    int length, count = 0;

    getline(cin, line);
    length = line.length();
    for (int i = 0; i < length; i++) {
        c = tolower(line[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')count++;
    }
    cout << count;

    return 0;
}
