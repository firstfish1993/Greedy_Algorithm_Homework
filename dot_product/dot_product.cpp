#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
void merge(vector<int>&, int, int, int);
void mergesort(vector<int>& a, int low, int high)
{
  int mid;
  if(low < high)
  {
    mid = low + (high-low)/2; //prevent overflow
    mergesort(a, low, mid);
    mergesort(a, mid+1, high);
    merge(a, low, high, mid); 
  }
  return; 
}

void merge(vector<int>& a, int low, int high, int mid)
{
  int i, j, k;
  vector<int> c(high+1);
  
  i = low;
  k = low;
  j = mid+1;
  
  while(i <= mid && j <= high)
  {
    if(a[i] <= a[j])
    {
      c[k] = a[i];
      k++; i++; 
    } 
    else
    {
      c[k] = a[j];
      k++; j++; 
    }
  }

  while(i <= mid)
  {
    c[k] = a[i];
    k++; i++; 
  }
  
  while(j <= high)
  {
    c[k] = a[j];
    k++; j++; 
  }
  
  for(i = low; i < k; i ++)
  {
    a[i] = c[i]; 
  }
  
  return; 
}


long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;
  mergesort(a, 0, a.size()-1);  
  mergesort(b, 0, b.size()-1);  

  for (size_t i = a.size(); i --;) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
