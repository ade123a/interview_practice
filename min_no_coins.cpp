// min_no_coins.cpp : determines the minimum number of coins required to reach a value
// Done using recursive programming with dynamic programming technique

#include "stdafx.h"
#include <iostream>

using namespace std;

int change(int *coins, int value, int size);
int changeHelper(int *coins, int value, int *cache, int size);

int change(int *coins, int value, int size)
{
  int *cache = new int[value];
  for (int i = 0; i < value; i++)
  {
    cache[i] = -1;
  }
  int noCoins = changeHelper(coins, value, cache, size);
  delete[] cache;

  return noCoins;
}

int changeHelper(int *coins, int value, int *cache, int size)
{
  if (value == 0)
  {
    return 0;
  }
  int min = value;
  for (int i = 0; i < size; i++)
  {
    if (value - coins[i] >= 0)
    {
      int c;
      if (cache[value - coins[i]] > 0)
      {
        c = cache[value - coins[i]];
      }
      else
      {
        c = changeHelper(coins, value - coins[i], cache, size);
        cache[value - coins[i]] = c;
      }
      if (c + 1 < min)
      {
        min = c + 1;
      }
    }
  }
  return min;
}

int main()
{

  int coins[] = {25, 10, 5, 1};
  int value = 0;
  cout << "determines the minimum number of coins required to reach a value" << endl;
  cout << "................Uses the American coin system..................." << endl;
  cout << "................................................................" << endl;

  cout << "Value: ";
  cin >> value;
  while (cin.fail())
  {
    cout << "Only accepts number" << endl;
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Value: ";
    cin >> value;
  }

  cout << "The minimum number of coins for " << value << " is: " << change(coins, value, 4) << endl;

  return 0;
}