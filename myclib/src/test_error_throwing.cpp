#include <stdlib.h>
#include <string>
#include <iostream>

extern "C"
{

  double equivalent_to_id(double my_double)
  {
      try {
      std::cout << "equivalent_to_id test-throw 1" << std::endl;
      for (int i = 0; i < 10;i++) {
        std::cout << "." << std::endl;
        volatile int x;
        for (x = 0; x < 50000000; x++)
        {
            /*do nothing*/      
        }
      }
      throw 20;
    } catch(int my_error)
    {
      std::cout << "equivalent_to_id test-throw 1 caught " << my_error << std::endl;
    }
    try {
      std::cout << "equivalent_to_id test-throw 2" << std::endl;
      for (int i = 0; i < 10;i++) {
        std::cout << "." << std::endl;
        volatile int x;
        for (x = 0; x < 50000000; x++)
        {
            /*do nothing*/      
        }
      }
      throw std::runtime_error("Test error.");
    } catch(const std::runtime_error& my_error)
    {
      std::cout << "equivalent_to_id test-throw 2 caught " << my_error.what() << std::endl;
    }
    for (int j = 0; j < 10;j++) {
        std::cout << "." << std::endl;
        volatile int y;
        for (y = 0; y < 50000000; y++)
        {
            /*do nothing*/      
        }
      }
    return my_double;
  }
}
