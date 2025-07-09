#define _CRTDBG_MAP_ALLOC

#include <iostream>

int main()
{
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  std::cout << "Hello World" << std::endl;

  return 0;
}