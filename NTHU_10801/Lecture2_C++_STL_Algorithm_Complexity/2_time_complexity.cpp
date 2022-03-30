#include <time.h>
#include <iostream>

int main () {
    // use clock
    clock_t start_c = clock();
    clock_t stop_c = clock();
    double duration = ((double) (stop_c-start_c))/ CLOCKS_PER_SEC;
    std:: cout << duration;

    // use time
    time_t start_t = time(NULL);
    time_t stop_t = time(NULL);
    duration = (double) difftime(stop_t, start_t);
    std:: cout << duration;
   return 0;
}