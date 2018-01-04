#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int do_main(const std::vector<std::string>& args)
{
  if (args.size() != 2) return 1;
  try
  {
    const int i = std::stoi(args[1]);
    if (i < 2)
    {
      std::cout << "false\n"; return 0;
    }
    if (i == 2)
    {
      std::cout << "true\n"; return 0;
    }
    for (int j=2; j!=i-1; ++j)
    {
      if (i % j == 0)
      {
        std::cout << "false\n";
        return 0;
      }
    }
    std::cout << "true\n";
  }
  catch (const std::exception&)
  {
    return 1;
  }
  return 0;
}

int main(int argc, char* argv[]) 
{
  assert(do_main( { "is_prime" } ) == 1);
  assert(do_main( { "is_prime", "6" } ) == 0);
  assert(do_main( { "is_prime", "17" } ) == 0);
  assert(do_main( { "is_prime", "nonsense" } ) == 1);
  assert(do_main( { "is_prime", "7", "42" } ) == 1);

  const std::vector<std::string> args(argv, argv + argc);
  return do_main(args);
}
