#ifndef RBNODE_HPP
# define RBNODE_HPP

#include "Utils.hpp"

namespace ft
{
    template<class T>
    struct RBnode
    {
        typedef T		value_type;
        typedef Color	color_type;

        value_type	value;
        RBnode*		parent;
        RBnode*		left;
        RBnode*		right;
        color_type	color;

        RBnode() : value(), parent(NULL), left(NULL), right(NULL), color(RED) {}; // NULL?? nullptr????

        RBnode(const value_type& val, RBnode *parent = NULL, RBnode *left = NULL, RBnode *right = NULL, color_type color = RED)
            : value(val), parent(parent), left(left), right(right), color(color) {};

        RBnode(const RBnode &other) : value(other.value), parent(other.parent), left(other.left), right(other.right), color(other.color) {};

        virtual ~RBnode() {}; // ???? 

        RBnode& operator= (const RBnode &other)
        {
            if(this == &other)
                return (*this);
            this->value = other.value;
            this->parent = other.parent;
            this->left = other.left;
            this->right = other.right;
            this->color = other.color;
            return (*this);
        }

        bool operator== (const RBnode &other)
        {
            if (this->value == other.value)
                return (true);
            return (false);
        }

        // bool operator!= (const RBnode &other)
        // {
        // 	if (this->value != other.value)
        // 		return (true);
        // 	return (false);
        // }

    };
}


#endif