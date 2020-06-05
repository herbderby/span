//
// Created by Herb Derby on 5/23/20.
//

#include "gtest/gtest.h"
#include "Span.h"

#include <array>
#include <vector>

static int second(Span<const int> s) { return s[1]; }

TEST(Span, Basic) {
    int a[] = {1, 2, 3};
    Span s{a};
    std::vector<int> v = {1, 2, 3};
    Span t{v};
    std::array aa{1, 2, 3};
    Span saa{aa};
    std::initializer_list<int>i{1, 2, 3};
    Span si{i};

    second(a);
    second(s);
    second(v);
    second(t);
    second(aa);
    second(saa);
    second(i);
    second(si);
}

