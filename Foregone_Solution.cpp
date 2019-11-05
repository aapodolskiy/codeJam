#include <iostream>
#include <string>

using namespace std;

int main() {
  int T = 0;
  cin >> T;
    
  string line;
  getline(cin, line);
  
  string a[100];
  string b[100];

  for (int i = 0; i < T; ++i) {
    getline(cin, line);
    
    for (int j = 0; j < line.length(); ++j) {
      if (line[j] == '4') {
        a[i].append("2");
        b[i].append("2");
      } else {
        a[i].append(line[j]);
        b[i].append("0");
      }
    }
    
  }

  for (int i = 0; i < T; ++i) {
    cout << a[i] << " " << b[i] << endl;
  }
  
  return 0;
}
