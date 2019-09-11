#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> A)
{
  int totalSum = 0;
  int arr[100002] = {0};
  
  for (int i = 0; i < A.size(); i++) totalSum += A[i];
  
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j <= 100000; j++) {
      if (arr[i] == 1 && i + A[i] < 100000) {
        arr[i+A[i]] = 1;
      }
    }
  
    arr[A[i]] = 1;      
  }
  
  int ans = totalSum;
  for (int i = 0; i <= 100000; i++) {
    if (arr[i] == 1 && ans > abs(i*2 - totalSum)) {
      ans = abs(i*2 - totalSum);
    }
  }
  return ans; 
}

vector<int> toIntVector(string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string AS;
  cin >> AS;
  cout << solution(toIntVector(AS));
}
