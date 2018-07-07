#include<iostream>
using namespace std;
int main()
{
   int num;
   int even=0;
   int odd=1;
   int i=0;
   while(i<=10)
   {
      if(i%2==0)
      {
         even+=i;
      }else if(i%2==1)
      {
         odd*=i;
      }
      i++;
   }
   cout<<"Â¦¼öÀÇ ÇÕ : "<<even<<endl;
   cout<<"È¦¼öÀÇ °ö : "<<odd<<endl;
}