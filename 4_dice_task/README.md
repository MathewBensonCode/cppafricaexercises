# Dice Task

This Task was submitted by @kraator on the cppafrica discord server [here](https://discord.com/channels/1064965358567559270/1065315641076236329/1083383612126281769)

This exercise consists of seven subtasks and is about non-standard six-sided dice. The numbers on each side are limited to one through six, as usual, and the sum of all numbers must be equal to 21. However, each number may occur multiple times or not at all, as long as the sum is correct (e.g. {1, 6, 1, 6, 1, 6}).

a) (beginner) Given the datatype for such dice using die_t = std::array<std::uint8_t, 6>, implement a way to print it.
A simple list like "{a, b, c, d, e, f}" is fine, but you may also go wild here ;-). (edited)

b) (beginner) Given any two dice A and B, calculate the probability in % (rounded and without decimal places) that die A will win against die B.
```cpp
std::uint8_t odds(const die_t& a, const die_t& b)
{
  /// Your code here. Return values in percent between 0 and 100 (e.g. 50 for equal dice).
}
```

c) (moderate) Compute and return the number of unique six-sided dice that meet above criteria.
Two dice are considered equal if each of the possible numbers on both dice occurs the same number of times.
The order or position of the numbers is therefore irrelevant and equivalent dice may not be counted more than once.

Take the following scaffold as a starting point (you are free to change it):
```cpp
#include <cstddef>
#include <iostream>

std::size_t compute_unique_dice()
{
  /// Your code here.
}

int main(int, char*[])
{
  std::cout << "a) Total number of unique six-sided dice: " << compute_unique_dice() << ".\n";
  return EXIT_SUCCESS;
}
```

Note: skipped use of std::format to reduce requirements.

d) (moderate) Given any valid die as defined above (e.g. {1, 4, 4, 4, 4, 4}),
write a function that attempts to find a different valid die that would win in more than 50% of the cases (e.g. {2, 5, 1, 6, 1, 6}),
or return an error otherwise. Print both dice and the chance the second one wins against the first one.

Take the following scaffold as a starting point (you are free to change it):
```cpp
#include <cstddef>
#include <iostream>

bool find_better_die(const die_t& input, die_t& output)
{
  /// Your code here.
}

int main(int, char*[])
{
  const die_t input = {1, 4, 4, 4, 4, 4};
  die_t output;
  if (find_better_die(input, output))
    std::cout << "b) The given die " << input << " is beaten by the die " << output << ".\n"
  else
    std::cout << "b) There is no die that is better than " << input << ".\n";
  return EXIT_SUCCESS;
}
```

e) (moderate) Find any set of three valid dice A, B, and C as defined above, where A wins against B, B wins against C, and C wins against A.
With such a solution you can challenge a colleague to a dice game. Let him choose first the dice that he thinks is the strongest and then take the one that beats it!

f) (moderate) Find all unique sets of dice that fulfill requirements from e). How many are there?

g) (advanced) If this was too easy, generalize your code for N-sided dice (with numbers one through N) and arbitrary sums (with default being sum=N*(N+1)/2), and allow computation at compile-time!
