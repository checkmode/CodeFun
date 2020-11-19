#include <iostream>
#include "sortfunctions.h"

void printfMaster()
{
	printf("printf master haha");
}

int sayHello()
{
	printf("in sayHello\n");
	printfMaster();
	return 0;
}

int main(int, char**) {
  int aa[] = {1, 3, 45, 10, 34, 30, 4, 8, 33};
  sort_bubble(aa, sizeof(aa) / sizeof(aa[0]));
  std::cout << "Hello, world! dev branch, also change\n";
  std::cout << "change from master again, dev\n";
  return 0;
}


