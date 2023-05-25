#include<iostream>
#include<vector>
using namespace std;

int div_sum(int num)
{
  int sum{ 0 }, k;
  while (num!=0)
  {
    k = num % 10;
    num /= 10;
    sum += k;
  }
  return sum;
}

int main()
{
  int arr[]= {1, 5 , 14,23, 22, 3, 23, 14,41, 50}, c;
  cout << "Enter number: "; 
  cin >> c;
  int sum{ 0 }, k{ 0 }, len{ 0 }, last_len{ 0 }, pos{ 0 }, best_pos{ 0 }, end_pos{ 0 };
 
  for (int i = 0; i < 10; i++)
  {
    while (div_sum(arr[i+k]) == c)
    {
      k++;
      len = i;
    }
    if (k>best_pos)
    {
      best_pos = k;
      pos = len;
      last_len = i + k;
    }
    k = 0;
  }

  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  end_pos = best_pos + pos - 1;
  cout << "Start index: " << pos << " " << "Last index: " << end_pos << endl;
  for (int i = pos; i < end_pos; i++)
  {
      cout << arr[i] << " ";
  }
  cout << endl;
  cout << "Ñount of elements: " << best_pos << endl;
  return 0;
}