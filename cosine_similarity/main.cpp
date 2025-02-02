#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
using namespace std;

bool is_stop_word(vector<string> stop_words, string word) {
  vector<string>::iterator it = find(stop_words.begin(), stop_words.end(), word);

  if (it != stop_words.end()) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char **argv) {
  if (argc < 3) {
    cout << "Usage: main <file1> <file2>";
    return 1;
  }
  map<string, int> a, b;
  ifstream a_file(argv[1]), b_file(argv[2]), stop_words_file("stop_words.txt");
  vector<string> stop_words(1000);
  string word;

  int i = 0;
  while (getline(stop_words_file, word)) {
    stop_words[i++] = word;
  }

  while (getline(a_file, word, ' ')) {
    if (!is_stop_word(stop_words, word)) {
      if (a.find(word) == a.end()) {
        a[word] = 1;
        b[word] = 0;
      } else {
        a[word] += 1;
      }
    }
  }
  while (getline(b_file, word, ' ')) {
    if (!is_stop_word(stop_words, word)) {
      if (b.find(word) == b.end()) {
        b[word] = 1;
        a[word] = 0;
      } else {
        b[word] += 1;
      }
    }
  }

  float a_mag = 0, b_mag = 0, a_dot_b = 0;
  map<string, int>::iterator a_iter = a.begin(), b_iter = b.begin();
  while (a_iter != a.end() && b_iter != b.end()) {
    a_dot_b += a_iter->second * b_iter->second;
    a_mag += a_iter->second * a_iter->second;
    b_mag += b_iter->second * b_iter->second;
    a_iter++;
    b_iter++;
  }
  a_mag = sqrt(a_mag);
  b_mag = sqrt(b_mag);

  // cout << "Length of a = " << a.size() << endl;
  // cout << "Length of b = " << b.size() << endl;
  //
  // map<string, int>::iterator a_iter_new = a.begin(), b_iter_new = b.begin();
  // while (a_iter_new != a.end() && b_iter_new != b.end()) {
  //   cout << a_iter_new->first << " = " << a_iter_new->second << ", "
  //        << b_iter_new->first << " = " << b_iter_new->second << endl;
  //   a_iter_new++;
  //   b_iter_new++;
  // }

  float cosine = a_dot_b / (a_mag * b_mag);
  cout << "Similarity: " << cosine * 100 << "%\n";

  a_file.close();
  b_file.close();
  return 0;
}
