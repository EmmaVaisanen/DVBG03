#include "analyze.h"
#include "algorithm.h"

//
// Private
//
static void run_algorithm(algorithm_t a, int *data, int n, int v){
    switch (a)
    {
    case bubble_sort_t:
        bubble_sort(data, n);
        break;
    case insertion_sort_t:
        insertion_sort(data, n);
        break;
    case quick_sort_t:
        quick_sort(data, n);
        break;
    case linear_search_t:
        linear_search(data, n, v);
        break;
    case binary_search_t:
        binary_search(data, n, v);
        break;

    default:
        break;
    }
}

static void run_cases(case_t c, int *data, int n){
    switch (c)
    {
    case best_t:
        
        break;
    
    case worst_t:

        break;

    case average_t:

        break;
    
    default:
        break;
    }
}

//
// Public
//
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
}
