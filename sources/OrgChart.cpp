#include <iostream>
#include <sstream>
using namespace std;
#include "OrgChart.hpp"
using namespace ariel;

namespace ariel
{
    OrgChart &OrgChart::add_root(string s)
    {
        return *this;
    }

    OrgChart &OrgChart::add_sub(string parent, string son)
    {
        return *this;
    }

    OrgChart::iterator OrgChart::begin_level_order()
    {
        return OrgChart::iterator(1);
    }

    OrgChart::iterator OrgChart::end_level_order()
    {
        return OrgChart::iterator(1);
    }

    OrgChart::iterator OrgChart::begin_reverse_order()
    {
        return OrgChart::iterator(1);
    }

    OrgChart::iterator OrgChart::reverse_order()
    {
        return OrgChart::iterator(1);
    }

    OrgChart::iterator OrgChart::begin_preorder()
    {
        return OrgChart::iterator(1);
    }

    OrgChart::iterator OrgChart::end_preorder()
    {
        return OrgChart::iterator(1);
    }

    OrgChart::iterator OrgChart::begin()
    {
        return OrgChart::iterator(1);
    }

    OrgChart::iterator OrgChart::end()
    {
        return OrgChart::iterator(1);
    }

    ostream &operator<<(ostream &os, OrgChart &org)
    {
        os << org.root;
        return os;
    }
}
