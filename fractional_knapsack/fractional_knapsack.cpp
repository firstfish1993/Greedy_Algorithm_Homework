#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

void merge(vector<int>&, vector<int>&, int, int, int);
void mergesort(vector<int>& a, vector<int>& b, int low, int high)
{
  int mid;
  if(low < high)
  {
    mid = (low + high) / 2;
    mergesort(a, b, low, mid);
    mergesort(a, b, mid+1, high);
    merge(a, b, low, high, mid); 
  }
  return; 
}

void merge(vector<int>& a, vector<int>& b, int low, int high, int mid)
{
  int i, j, k;
  vector<int> c(high+1); 
  vector<int> d(high+1); 
  i = low; k = low; j = mid + 1;
  while (i <= mid && j <= high)
  {
    //(NOTE) was int, but the value per weight can be less than 1
    if((double)a[i]/(double)b[i] < (double)a[j]/(double)b[j])
    {
      c[k] = a[i];
      d[k] = b[i];
      k++; i++;
    }
    else
    {
      c[k] = a[j];
      d[k] = b[j];
      k++; j++; 
    }
  }
  //if i still have not reached mid
  while (i <= mid)
  {
    c[k] = a[i];
    d[k] = b[i];
    k++; i++; 
  } 
  //if j still have not reached high
  while (j <= high)
  {
    c[k] = a[j];
    d[k] = b[j];
    k++; j++; 
  }
  for(i = low; i < k; i ++)
  {
    a[i] = c[i];
    b[i] = d[i]; 
  }  
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int index;
  double vpw; //stores value/weight
  
  index = values.size() - 1;  
  
  mergesort(values, weights, 0, index); 

  while (capacity > 0 && index >= 0)
  {
    vpw = (double )values[index] / (double)weights[index];
    if(weights[index] <= capacity)
    {
      value += vpw * (double) weights[index];
      capacity -= weights[index]; 
      index --;
    }
    else
    {
      value += vpw * (double) capacity;
      capacity = 0; 
    }
  }  
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(4);
  std::cout << std::fixed  << optimal_value << std::endl;
  return 0;
}
