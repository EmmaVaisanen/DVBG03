#include "ui.h"
#include "io.h"
#include "analyze.h"

#include <stdbool.h>
#include <stdio.h>

//
// Private
//

static void ui_benchmark(){
    printf("size		time T(s)		T/logn		T/n		T/nlog\n");
}

static void ui_benchmark_results(){
	for(int i = 0; i < RESULT_ROWS; i++){
		printf("test		test		test		test		test \n");
	}
}

static void ui_invalid_input()
{
	printf("info> bad input\n");
}

static void ui_exit()
{
	printf("info> bye\n");
}

static char ui_get_choice()
{
	char buf[3];

	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
	while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
}

static void ui_menu_options(const char *options[], int num_options)
{
	int i;

	for (i=0; i<num_options; i++) {
		printf("    %c) %s\n", 'a'+i, options[i]);
	}
}

static void ui_menu()
{
	const char *options[] = {
		"Menu",
		"Exit\n",
		"Bubble sort best case",
		"Bubble sort worst case",
		"Bubble sort average case\n",

		"Insertion sort best case",
		"Insertion sort worst case",
		"Insertion sort average case\n",

		"Quick sort best case",
		"Quick sort worst case",
		"Quick sort average case\n",

		"Linear search best case",
		"Linear search worst case",
		"Linear search average case\n",

		"Binary search best case",
		"Binary search worst case",
		"Binary search average case\n",		
	};

	ui_line('=', MENU_WIDTH);
	ui_menu_options(options, sizeof(options) / sizeof(char *));
	ui_line('-', MENU_WIDTH);
}

//
// Public
//
void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];
	
	show_menu = true;
	running = true;
	while (running) {
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			// House keeping
			case 'a':
				show_menu = true;
				break;
			case 'b':
				running = false;
				break;
			// Bubble sort
			case 'c':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;
			case 'd':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
			break;	
			case 'e':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;

			// Insertion sort
			case 'f':
				benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;

			case 'g':
				benchmark(insertion_sort_t, worst_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;

			case 'h':
				benchmark(insertion_sort_t, average_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;

			// Quick sort
			case 'i':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;

			case 'j':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;

			case 'k':
				benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;
			
			//	Linear search
			case 'l':
				benchmark(linear_search_t, best_t, result, RESULT_ROWS);
				ui_benchmark(); 
				ui_benchmark_results();
				break;
			case 'm':
				benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;
			case 'n':
				benchmark(linear_search_t, average_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;

			//	Binary search	
			case 'o':
				benchmark(binary_search_t, best_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;
			case 'p':
				benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;
			case 'q':
				benchmark(binary_search_t, average_t, result, RESULT_ROWS);
				ui_benchmark();
				ui_benchmark_results();
				break;

			// Invalid input
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}
