#include <concepts>
#include <cstddef>
#include <cstdint>
#include <fmt/format.h>
#include <initializer_list>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

template <std::integral... Ts> struct box_of_values {
  explicit constexpr box_of_values(Ts... values) : data(values...) {}

  std::tuple<std::remove_cv_t<Ts>...> data;
};

// Returns the length in characters of the passed integer's string
// representation.
template <std::integral T>
constexpr std::size_t length_as_string(T value) noexcept {
  // Start with 1 for negative numbers to compensate for the sign.
  std::size_t length = (value >= 0 ? 0 : 1);
  do {
    value /= 10;
    ++length;
  } while (value != 0);
  return length;
}
// A couple of compile-time tests of the above helper function.
static_assert(length_as_string(-10) == 3);
static_assert(length_as_string(-9) == 2);
static_assert(length_as_string(0) == 1);
static_assert(length_as_string(9) == 1);
static_assert(length_as_string(10) == 2);

template <std::integral... Ts>
std::ostream &operator<<(std::ostream &stream,
                         const box_of_values<Ts...> &boxed_values) {
  []<std::size_t... Indices>(std::ostream & ostream, const auto &values,
                             std::index_sequence<Indices...>) {
    // Get the maximum length of all values when represented as strings.
    std::size_t max_width = 0;
    ((max_width =
          std::max(max_width, length_as_string(std::get<Indices>(values)))),
     ...);
    // Compute top and bottom edge once.
    const auto top_and_bottom_edge =
        fmt::format("{:*^{}}\n", '*', max_width + 2);
    // Write everything.
    ((ostream << top_and_bottom_edge) << ...
            << fmt::format("*{: >{}}*\n", std::get<Indices>(values),
                           max_width))
        << top_and_bottom_edge;
  }
  (stream, boxed_values.data, std::make_index_sequence<sizeof...(Ts)>{});
  return stream;
}

template <typename T>
inline constexpr T min_value = std::numeric_limits<T>::min();
template <typename T>
inline constexpr T max_value = std::numeric_limits<T>::max();

int main(int, char *[]) {
  // Empty box shall print:
  // **
  // **
  std::cout << box_of_values();

  // Shall print:
  // ****
  // *-1*
  // ****
  std::cout << box_of_values(-1);

  // Shall print:
  // *****
  // *  1*
  // * 12*
  // *123*
  // *****
  std::cout << box_of_values(1, 12, 123);

  // Shall print:
  // *****
  // *321*
  // * 21*
  // *  1*
  // *****
  std::cout << box_of_values(321, 21, 1);

  // Shall print:
  // ********
  // *    42*
  // * 12345*
  // *     0*
  // *-12345*
  // *     1*
  // ********
  std::cout << box_of_values(42l, 12345u, 0ull, -12345, 1);

  // Shall print:
  // **********************
  // *                -128*
  // *                 255*
  // *              -32768*
  // *               65535*
  // *         -2147483648*
  // *          4294967295*
  // *-9223372036854775808*
  // *18446744073709551615*
  // **********************
  std::cout << box_of_values(min_value<std::int8_t>, max_value<std::uint8_t>,
                             min_value<std::int16_t>, max_value<std::uint16_t>,
                             min_value<std::int32_t>, max_value<std::uint32_t>,
                             min_value<std::int64_t>, max_value<std::uint64_t>);

  return EXIT_SUCCESS;
}
