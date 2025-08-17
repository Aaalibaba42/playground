#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <ranges>
#include <utility>

namespace vw = std::views;
namespace rg = std::ranges;

template <typename T>
int part1(std::pair<std::uint32_t, std::uint32_t> r,
          std::initializer_list<T> list)
{
    auto rng = vw::enumerate(list) | vw::filter([r](auto const& t) {
                   std::uint32_t idx =
                       static_cast<std::uint32_t>(std::get<0>(t));
                   return r.first <= idx && idx <= r.second;
               })
        | vw::transform([](auto const& p) { return std::get<1>(p); });

    return rg::fold_left(rng, 0, std::plus{});
}

int part2(std::pair<std::uint32_t, std::uint32_t> point,
          std::initializer_list<std::pair<std::uint32_t, std::uint32_t>> coords)
{
    auto rng =
        vw::enumerate(coords) | vw::filter([point](auto const& icoord) {
            auto const& [i, coord] = icoord;
            return point.first == coord.first || point.second == coord.second;
        })
        | vw::transform([point](auto const& icoord) {
              auto const& [i, coord] = icoord;
              return std::pair{ std::abs(static_cast<int64_t>(coord.first)
                                         - static_cast<int64_t>(point.first))
                                    + std::abs(
                                        static_cast<int64_t>(coord.second)
                                        - static_cast<int64_t>(point.second)),
                                i };
          });

    return rg::min(rng).second;
}

int main()
{
    std::cout << part1({ 0, 2 }, { -2, 0, 3, -5, 2, -1 }) << std::endl;
    std::cout << part1({ 1, 3 }, { 1, -2, 3, -4, 5 }) << std::endl;

    std::cout << part2({ 3, 4 }, { { 1, 2 }, { 3, 1 }, { 2, 4 }, { 2, 3 } })
              << std::endl;
    std::cout << part2({ 2, 5 }, { { 3, 4 }, { 2, 3 }, { 1, 5 }, { 2, 5 } })
              << std::endl;

    return 0;
}
