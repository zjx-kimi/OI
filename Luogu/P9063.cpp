#include <iostream>

int main() {
  int T;
  for (std::cin >> T; T; --T) {
    long long n; std::cin >> n;
    std::cout << ((n & 1) ? "Yes" : "No") << std::endl;
  }
}