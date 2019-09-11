#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> A)
{
  int rows = 1;
  multiset<int> heights;
  
  heights.insert(A[0]);
              
  for (int i = 1; i < A.size(); i++) {
    auto upper = heights.upper_bound(A[i]);
    if (upper != heights.end()) {
      heights.erase(upper);
    } else {
      rows++;
    }
    heights.insert(A[i]);
  }
  return rows; 
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
  vector<int> A = toIntVector(AS);
  cout << solution(A);
}
