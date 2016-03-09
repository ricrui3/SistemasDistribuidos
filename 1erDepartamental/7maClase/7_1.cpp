#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  string n;
  string line;
  //cin >> n;
  //std::cout << "n: " << n << std::endl;
  getline(cin, line);
  std::cout << "line: " << line << std::endl;
  return 0;
}
