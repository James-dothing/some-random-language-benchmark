#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

bool check(int n, vector<int>& usedF) {
    for (int primeNumber : usedF) {
        if (primeNumber * primeNumber > n) {
            return true;
        }
        if (n % primeNumber == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> used;
    int currentNumber = 3;
    int maxiumNumber = 50000000;
    auto startingTime = chrono::high_resolution_clock::now();

    while (currentNumber <= maxiumNumber) {
        if (check(currentNumber, used)) {
            // cout << currentNumber << endl;
            used.push_back(currentNumber);
        }
        currentNumber += 2;
    }
    auto finalTime = chrono::high_resolution_clock::now();
    double totalTime = chrono::duration<double>(finalTime - startingTime).count();
    cout << "total time: " << totalTime << endl;
    cout << "total prime number: " << used.size() + 1;
    return 0;
}