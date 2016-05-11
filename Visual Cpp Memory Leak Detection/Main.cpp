// ************ MUST INCLUDE FOR MEMORY DETECTION ************ //
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
// ************ MUST INCLUDE FOR MEMORY DETECTION ************ //

#include <memory>
using namespace std;

// these are some of the many ways that can cause memory leaks
void memoryLeak() {
	int *m = (int*)malloc(sizeof(int));

	int *n = new int;

	int **pp = new int*[4];
	for (int i = 0; i < 4; i++) {
		pp[i] = new int;
	}
	delete pp;
}

// these are the ways to safely clear heap memory allocations
void noMemoryLeak() {
	int *m = (int*)malloc(sizeof(int));
	free(m);

	int *n = new int;
	delete n;

	int **pp = new int*[4];
	for (int i = 0; i < 4; i++) {
		pp[i] = new int;
	}
	for (int i = 0; i < 4; i++) {
		delete pp[i];
	}
	delete pp;

	unique_ptr<int> u(new int);
	shared_ptr<int> s(new int);
	weak_ptr<int> w = s;
	auto_ptr<int> a(new int);
}

int main() {
	// ************ MUST INCLUDE FOR MEMORY DETECTION ************ //
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	// ************ MUST INCLUDE FOR MEMORY DETECTION ************ //

	// call this function to cause memory leaks
	//memoryLeak();

	// call this function to create and delete dynamic objects
	noMemoryLeak();

	return 0;
}