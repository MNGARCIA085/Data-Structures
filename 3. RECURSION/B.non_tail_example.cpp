#include <cstdio>

void nonTailRecursiveFunction(int n) {
    if (n <= 0) {
        printf("Base case reached with n = %d\n", n);
        return; // Base case
    } else {
        printf("Calling nonTailRecursiveFunction(%d)\n", n - 1);
        nonTailRecursiveFunction(n - 1); // Recursive call
        printf("Returning from nonTailRecursiveFunction(%d) with additional work\n", n);
    }
}


int nonTailRecursiveFunction2(int n) {
    if (n <= 0) {
        return 0; // Base case
    } else {
        // Non-tail recursive call
        int result = nonTailRecursiveFunction2(n - 1);
        return n + result; // After the recursive call, we do more work
    }
}



// ahora una que no devuelva siempre 0 sino que su resultado cambie
int nonTailRecursiveFunction3(int n) {
    if (n <= 0) {
        return 0; // Base case
    } else {
        // Non-tail recursive call
        int result = nonTailRecursiveFunction2(n - 1);
        return n + result; // After the recursive call, we do more work
    }
}


// simple non tail recursion
int simple(int n){
   if(n == 0)
       return 1;
   int res =  simple(n-1);
   return n + res;
 }




//
int fib(int n){
    if(n < 2)
        return n;
    int res =  fib(n-1) + fib(n-2);
    return n + res;
  }


int main() {
    int n = 3;
    nonTailRecursiveFunction(n);

    printf("\n");


    printf("%d\n", nonTailRecursiveFunction2(n)); // la recursiva devuelve siempre 0 y le sumo n
                    // en las que quedaban, (3+0) + (2+0) + (1+0)

    printf("\n");
    printf("Simple es: %d\n", simple(3));



    printf("\n");    

    printf("%d\n", fib(3));


    return 0;
}


// g++ B.non_tail_example.cpp -o non_tail