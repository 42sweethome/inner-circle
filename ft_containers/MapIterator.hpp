#ifndef MAPTERATOR_HPP
# define MAPITERATOR_HPP

#include "Iterator.hpp"
#include "RBnode.hpp"

namespace ft
{

//     template <typename T>
// class tree_const_iterator;

    template <class T>
    class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        private:
            typedef ft::RBnode<T>            node;
            typedef ft::RBnode<T>*           node_pointer;
        public:
            typedef bidirectional_iterator_tag  iterator_category;
            typedef T                           value_type;
            typedef value_type&                 reference;
            typedef std::ptrdiff_t              difference_type;
            typedef T*                          pointer;

        private:
            node_pointer _node;
            node_pointer	minValueNode(node_pointer node)
            {
                // if (node == NULL)
                //     return (node);
                while (node->left != my_nullptr)
                    node = node->left;
                return (node);
            }

            node_pointer	maxValueNode(node_pointer node)
            {
                // if (node == NULL)
                //     return (node);
                while (node->right != NULL)
                    node = node->right;
                return (node);
            }

        public:
            map_iterator(): _node(NULL) {}
            map_iterator(const map_iterator &ref) : _node(ref._node) {}
            map_iterator(node_pointer node) : _node(node) {}
            virtual ~map_iterator() {}
            map_iterator& operator=(const map_iterator& ref)
            {
                if (this != &ref)
                    this->_node = ref._node;
                return (*this);
            }

//	        node_pointer		base() const { return (this->_node); }

            map_iterator& operator++()
            {
                if (_node->parent == NULL)
                    _node = NULL;
                if (_node->right != NULL)
                {
                    _node = minValueNode(_node->right);
                    return (*this);
                }
                while (_node->parent && _node->parent->left != _node)
                    _node = _node->parent;
                if (_node->parent)
                    _node = _node->parent;
                return (*this);
            }

            map_iterator& operator--()
            {
                if (_node->left != NULL)
                {
                    _node = maxValueNode(_node->left);
                    return (*this);
                }
                while (_node->parent && _node->parent->right != _node)
                    _node = _node->parent;
                if (_node->parent)
                    _node = _node->parent;
                else
                    _node = NULL;
            }

            map_iterator operator++(int)
            {
                map_iterator tmp;
                
                tmp = *this;
                ++(*this);
                return (tmp);
            }

            map_iterator operator--(int)
            {
                map_iterator tmp;
                
                tmp = *this;
                --(*this);
                return (tmp);
            }
            
            reference operator*() const
            {
                return (_node->value);
            }

            pointer operator->() const
            {
                return (&(_node->value));
            }

            bool operator== (const map_iterator& lhs)
            {
                return (this->_node == lhs._node);
            }
            
            bool operator!= (const map_iterator& lhs)
            {
                return (this->_node != lhs._node);
            }

            // bool operator== (const map_const_iterator<T>& lhs)
            // {
            //     return (this->base() == lhs.base());
            // }

            // bool operator!= (const map_const_iterator<T>& lhs)
            // {
            //     return (this->base() != lhs.base());
            // }
    };
}
#endif
