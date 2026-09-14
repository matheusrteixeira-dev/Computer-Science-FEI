/**
 * @file    radix.cpp
 * @brief   Radix Sort (LSD) para inteiros de três dígitos usando Counting Sort estável.
 */

#include <iostream>
#include <vector>

using namespace std;

/// Retorna o dígito de posição @p dig (0 = unidades) de @p num.
int digito(int num, int dig) {
  for (int i = 0; i < dig; i++) {
    num /= 10;
  }
  return num % 10;
}

/// Counting Sort estável considerando apenas o dígito @p d.
void countingSort(vector<int> &v, int d) {
  vector<int> counting(10, 0);
  vector<int> temp(v.size());

  for (const auto &e : v) {
    counting[digito(e, d)]++;
  }

  for (size_t i = 1; i < counting.size(); i++) {
    counting[i] += counting[i - 1];
  }

  for (int i = static_cast<int>(v.size()) - 1; i >= 0; i--) {
    temp[--counting[digito(v[i], d)]] = v[i];
  }

  v = temp;
}

int main() {
  vector<int> v = {532, 243, 112, 420, 423, 999, 116};

  for (int d = 0; d < 3; d++) {
    countingSort(v, d);
  }

  for (const auto &e : v) {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}
