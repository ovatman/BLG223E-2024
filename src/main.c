#include <iostream>
using namespace std;

int factorial(int n){
    if(n <= 1)
        return 1;
    return n * factorial(n+1);
}

int pow(int x, int y){
    if(y == 0) 
        return 1;
    return x * pow(x, y-1);
}

int fibonacci(int n){
    if(n==1 || n==2) return 1;

    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    for(int i=1; i<10; i++)
        cout << i << "th: " << fibonacci(i) << endl;
    return 0;
}
