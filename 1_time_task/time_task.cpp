#include <chrono>
#include <fmt/chrono.h>
#include <fmt/format.h>
#include <iostream>

namespace {
const std::chrono::seconds max_seconds{std::chrono::days{1}};

struct Timer {
  std::chrono::seconds store{};

  friend auto &operator>>(std::istream &cin, Timer &timer) {
    int hour, minute, second;
    cin >> hour >> minute >> second;
    timer.store += std::chrono::hours(hour) + std::chrono::minutes(minute) +
                   std::chrono::seconds(second);
    return cin;
  }

  friend auto &operator<<(std::ostream &cout, const Timer &timer) {
    cout << fmt::format("{:%T}", timer.store);
    return cout;
  }

  Timer operator+(int span) { return {store + std::chrono::seconds(span)}; }

  auto operator>(const Timer &other) const { return store > other.store; }

  Timer operator++(int) {
    Timer newtimer{};
    newtimer.store = store;
    store += std::chrono::seconds(1);
    if (store == max_seconds) {
      store -= std::chrono::seconds(max_seconds);
    }
    return newtimer;
  }

  Timer operator--(int) {
    Timer newtimer{};
    newtimer.store = store;
    store -= std::chrono::seconds(1);
    if (store.count() == -1) {
      store += std::chrono::seconds(max_seconds);
    }
    return newtimer;
  }

  auto operator-(const Timer &other) const {
    return (store - other.store).count();
  }
};

} // namespace

int main() {
  Timer t1, t2, t3, t4, t5;
  int span;
  std::cin >> t1;
  t3 = t1++;
  std::cout << t1 << '\n';
  std::cout << t3 << '\n';
  std::cin >> t2;
  t4 = t2--;
  std::cout << t2 << '\n';
  std::cout << t4 << '\n';
  if (t1 > t2) {
    std::cout << t1 - t2 << '\n';
  } else {
    std::cout << t2 - t1 << '\n';
  }
  std::cin >> span;
  t5 = t1 + span;
  std::cout << t5 << '\n';
}
