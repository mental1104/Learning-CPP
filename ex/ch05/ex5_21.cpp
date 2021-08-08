#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

int main() {
  string curr, prev;
  bool no_twice = false;

  while (cin >> curr) {
    if (!isupper(curr[0])) {
      prev = "";
      continue;
    }
    if (prev == curr) {
      cout << curr << " occurs twice in succession." << endl;
      no_twice = true;
      break;
    }
    prev = curr;
  }

  if (!no_twice) cout << "no word was repeated." << endl;
}