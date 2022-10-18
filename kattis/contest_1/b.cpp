#include <iostream>

using namespace std;

int main() {
    int n;
    string request;
    int volume = 7;

    getline(cin, request);
    n = stoi(request);
    for (int i = 0; i < n; i++) {
        getline(cin, request);
        if (request == "Skru op!") volume++;
        else volume--;
        volume = max(0, min(10, volume));
    }
    cout << volume;

    return 0;
}
