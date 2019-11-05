#include <iostream>
#include <string>

using namespace std;

int main() {
  int T = 0;
  cin >> T;

  string lines[100];

  getline(cin, lines[0]);
  
  for (int i = 0; i < T; ++i) {
    getline(cin, lines[i]);
  }

  string a[100];
  string b[100];

  for (int i = 0; i< T; ++i) {
    a[i] = b[i] = "";

    for (int j = 0; j < lines[i].length(); ++j) {
      if (lines[i][j] == '4') {
        a[i] += "2";
        b[i] += "2";
      } else {
        a[i] += lines[i][j];
        if (b[i].length() > 0) {
          b[i] += "0";
        }
      }
    }
  }

  for (int i = 0; i < T; ++i) {
    cout << "Case #"<< i+1 << ": " << a[i] << " " << b[i] << endl;
  }
  
  return 0;
}
