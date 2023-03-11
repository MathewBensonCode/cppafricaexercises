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

template <std::integral... Ts>
std::ostream &operator<<(std::ostream &stream,
                         const box_of_values<Ts...> &boxed_values) {
  std::vector<std::string> data_store(sizeof...(Ts));
  auto get_data = []<std::size_t... idx>(std::index_sequence<idx...>,
                                         const auto &data, auto &store) {
    std::ostringstream output{};
    (void)std::initializer_list<int>{
        (output.str(""), output << fmt::format("{}", std::get<idx>(data)),
         store.at(idx) = (output.str()), 0)...};
  };

  get_data(std::make_index_sequence<sizeof...(Ts)>{}, boxed_values.data,
           data_store);

  std::size_t largest_element{0};

  for (const auto &data : data_store) {
    if (data.size() > largest_element) {
      largest_element = data.size();
    }
  }

  fmt::print("{:*^{}}\n", '*', largest_element + 2);

  for (const auto &data : data_store) {
    fmt::print("*{: >{}}*\n", data, largest_element);
  }

  fmt::print("{:*^{}}\n\n", '*', largest_element + 2);
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
