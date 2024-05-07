#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int gcd1(int m,int n)
{
   int r;
  r=m%n;
 if(r==0)
     return n;
else
    return gcd1(n,r);
 }
int gcd2(int m,int n)
{
    int r;
    while(n!=0){

    r=m%n;
    m=n;
    n=r;
}
return m;

}
int gcd3(int m,int n )
{
     int t;
     if(m>n)
    {
     t=n;
    }
    else
    {
       t=m;
    }
   while( m%t!=0 || n%t!=0 )
   {
    t--;
   }
return t;
}

int gcd4(int m,int n)\
{
    while(n!=0){
        int temp=n;
            n=m%n;
m=temp;}

return m;

}

int main(){
clock_t start,end;
double time_taken,time_taken1,time_taken2,time_taken3;

start=clock();

 int m;
 int n;
 printf("enter the number 1\n");
 scanf("%d",&m);
 printf("enter the number 2\n");
 scanf("%d",&n);
 int y=gcd1(m,n);
 printf("Euclid's Algorithem recursive:%d\n",y);

end=clock();
time_taken=((double)(end -start)) /CLOCKS_PER_SEC;
printf("The time taken by the function is %f\n",time_taken);

start=clock();
int y1=gcd2(m,n);
printf("Euclid's Algorithem:%d\n",y1);
end=clock();
time_taken1=((double)(end -start)) /CLOCKS_PER_SEC;
printf("The time taken by the function is %f\n",time_taken1);

start=clock();
int y2=gcd3(m,n);
printf("Consecutive Integer Checking:%d\n",y2);
end=clock();
time_taken2=((double)(end -start)) /CLOCKS_PER_SEC;
printf("The time taken by the function is %f\n",time_taken2);

start=clock();
int y3=gcd4(m,n);
printf("Middle-school:%d\n",y1);
end=clock();
time_taken3=((double)(end -start)) /CLOCKS_PER_SEC;
printf("The time taken by the function is %f\n",time_taken3);
                                                                                                                                    
}
