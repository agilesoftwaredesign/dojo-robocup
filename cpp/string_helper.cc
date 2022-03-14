#include "string_helper.h"

#include <list>
#include <sstream>

// explicit template instantiation
template std::string join<std::list<std::string>::iterator>(
    const std::list<std::string>::iterator begin,
    const std::list<std::string>::iterator end, std::string separator);

template std::string
join<std::list<int>::const_iterator>(const std::list<int>::const_iterator begin,
                                     const std::list<int>::const_iterator end,
                                     std::string separator);

template std::string
join<std::list<int>::iterator>(const std::list<int>::iterator begin,
                               const std::list<int>::iterator end,
                               std::string separator);

template <typename T>
std::string join(const T begin, const T end, std::string separator) {
  const auto length = static_cast<size_t>(std::distance(begin, end));
  std::stringstream ss;
  size_t count = 0;

  for (T iter = begin; iter != end; ++iter, ++count) {
    ss << *iter;

    if (count < length - 1) {
      ss << separator;
    }
  }

  return ss.str();
}