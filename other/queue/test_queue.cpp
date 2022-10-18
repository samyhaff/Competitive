#include "queue.h"

using namespace std;

int main() {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;

    return 0;
}
