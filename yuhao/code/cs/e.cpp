#include<stdio.h>
#include<math.h>

#define eps 1e-9

double PI = acos(-1.0);
double X ,Y ,L ,D;

double Fun(double du)
{
   return (-X + L * sin(du) + D / cos(du)) / tan(du);
}

bool solve()
{
   if(X < D || Y < D) return 0;
   double low ,up ,mid ,mmid;
   double dis1 ,dis2;
   low = 0;
   up = PI / 2;
   while(1)
   {
      mid = (low + up) / 2;
      mmid = (mid + up) / 2;
      dis1 = Fun(mid);
      dis2 = Fun(mmid);
      if(dis1 > dis2) up = mmid;
      else low = mid;
      if(up - low < eps) break;
   }
   return dis1 <= Y;
}

int main ()
{
   while(~scanf("%lf %lf %lf %lf" ,&X ,&Y ,&L ,&D))
   {
      solve()? printf("yes\n") : printf("no\n");
   }
   return 0;
}