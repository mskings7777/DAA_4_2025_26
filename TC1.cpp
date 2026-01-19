#include <bits/stdc++.h>
using namespace std;

void complexRec(int n, int &count, int &depth, int &maxdepth) {

    depth++;

   if (n <= 2) {
       maxdepth = max(depth, maxdepth);
       depth--;
       return ;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
        count += 1;
           temp[i] = i ^ p;
       }
       p >>= 1;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
        count += 1;
       small[i] = i * i;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2, count, depth, maxdepth);
   complexRec(n / 2, count, depth, maxdepth);
   complexRec(n / 2, count, depth, maxdepth);

   depth--;

}

int main(){
    int count = 0;
    int depth = 0;
    int maxdepth = INT_MIN;
    complexRec(8, count, depth, maxdepth);
    cout<<count<<endl;
    cout<<maxdepth<<endl;
}
