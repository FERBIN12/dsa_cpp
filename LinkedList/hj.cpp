#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> s = {1, 2, 3};

    if (s.contains(2)) {
        std::cout << "2 is in the set!\n";
    } else {
        std::cout << "2 is not in the set!\n";
    }

    return 0;
}
