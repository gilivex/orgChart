#pragma once
#include <iostream>
#include <sstream>
#include <queue>
#include <fstream>
#include <stdexcept>
using namespace std;

namespace ariel
{

    class OrgChart
    {
    private:
        struct Node
        {
            string data;
            queue<Node *> children;
            explicit Node(string val)
            {
                this->data = val;
            }
        };

        Node *root;

    public:
        OrgChart()
        {
            this->root = nullptr;
        }
        ~OrgChart(){};

        OrgChart &add_root(string s);

        OrgChart &add_sub(string parent, string son);

        class iterator
        {
        private:
            Node *curr;
            queue<Node *> byOrder;

        public:
            explicit iterator(int type, Node *start = nullptr){
                curr = start;
            };

            iterator &operator++() // prefix
            {
                byOrder.pop();
                if (byOrder.empty())
                {
                    curr = nullptr;
                }
                else
                {
                    curr = byOrder.front();
                }
                return *this;
            };

            iterator operator++(int)
            { // postfix
                iterator temp = *this;
                // this way we saving codelines
                ++(*this);
                return temp;
            };
            bool operator==(const iterator &itr) const
            {
                return curr == itr.curr;
            };

            bool operator!=(const iterator &itr) const
            {
                return curr != itr.curr;
            };
            string &operator*()
            {
                return this->curr->data;
            };
            string *operator->()
            {
                return &(this->curr->data);
            };
            friend ostream &operator<<(ostream &os, const iterator &itr)
            {
                os << itr.curr->data;
                return os;
            };
        };

        

        OrgChart::iterator begin();
        OrgChart::iterator end();
        OrgChart::iterator begin_level_order();
        OrgChart::iterator end_level_order();
        OrgChart::iterator begin_reverse_order();
        OrgChart::iterator reverse_order();
        OrgChart::iterator begin_preorder();
        OrgChart::iterator end_preorder();
        friend ostream& operator<<(ostream& os, OrgChart& org);
    };

}