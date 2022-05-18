#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "doctest.h"
#include "sources/OrgChart.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("test")
{
    OrgChart organize1;
    CHECK_NOTHROW(organize1.add_root("boss"));
    for (int i = 0; i < 4; i++)
    {
        string s = "child" + to_string(i);
        CHECK_NOTHROW(organize1.add_sub("boss", s));
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            string s1 = "child" + to_string(i);
            string s2 = "grandchild" + to_string(i + j);
            CHECK_NOTHROW(organize1.add_sub(s1, s2));
        }
    }

    OrgChart organize2;
    CHECK_NOTHROW(organize2.add_root("boss"));
    for (int i = 0; i < 4; i++)
    {
        string s = "child" + to_string(i);
        CHECK_NOTHROW(organize1.add_sub("boss", s));
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            string s1 = "child" + to_string(i);
            string s2 = "grandchild" + to_string(i + j);
            CHECK_NOTHROW(organize1.add_sub(s1, s2));
        }
    }

    for (auto it1 = organize1.begin_level_order(), it2 = organize2.begin_level_order(); it1 != organize1.end_level_order(); ++it1, it2++)
    {
        CHECK(it1 == it2);
    }

    for (auto it1 = organize1.begin_reverse_order(), it2 = organize2.reverse_order(); it1 != organize1.reverse_order(); ++it1, it2++)
    {
        CHECK(it1 == it2);
    }

    for (auto it1 = organize1.begin_preorder(), it2 = organize2.begin_preorder(); it1 != organize1.end_preorder(); ++it1, it2++)
    {
        CHECK(it1 == it2);
    }
}