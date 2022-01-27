#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

#include "Iterator.hpp"
#include "RBnode.hpp"


namespace ft
{

    template <typename T>
	class map_const_iterator;

	template <class T>
	class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		private:
			typedef ft::RBnode<T>				node;
			typedef ft::RBnode<T>*				node_pointer;
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
				while (node->left != NULL)
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

	        node_pointer		getnode() const { return (this->_node); }

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
				return(*this);
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
				return (this->_node == lhs.getnode());
			}

			bool operator!= (const map_iterator& lhs)
			{
				return (this->_node != lhs.getnode());
			}

			bool operator== (const map_const_iterator<T>& lhs)
			{
				return (this->_node == lhs.getnode());
			}

			bool operator!= (const map_const_iterator<T>& lhs)
			{
				return (this->_node != lhs.getnode());
			}
	};

	template <class T>
	class map_const_iterator : public ft::iterator<ft::bidirectional_iterator_tag, const T>
	{
		private:
			typedef ft::RBnode<T>               node;
			typedef ft::RBnode<T>*              node_pointer;
		public:
			typedef bidirectional_iterator_tag  iterator_category;
			typedef T                           value_type;
			typedef const value_type&                 reference; 
			typedef std::ptrdiff_t              difference_type;
			typedef const T*                          pointer;

		private:
			node_pointer 	_node;
			node_pointer	minValueNode(node_pointer node)
			{
				// if (node == NULL)
				//     return (node);
				while (node->left != NULL)
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
			map_const_iterator(): _node(NULL) {}
			map_const_iterator(const map_const_iterator &ref) : _node(ref._node) {}
			map_const_iterator(node_pointer node) : _node(node) {}
			virtual ~map_const_iterator() {}
			map_const_iterator& operator=(const map_const_iterator& ref)
			{
				if (this != &ref)
					this->_node = ref._node;
				return (*this);
			}
			
			map_const_iterator(const map_iterator<T>& other) : _node(other.getnode())
			{}

	        node_pointer		getnode() const { return (this->_node); }

			map_const_iterator& operator++()
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

			map_const_iterator& operator--()
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
				return (*this);
			}

			 map_const_iterator operator++(int)
			{
				 map_const_iterator tmp;

				tmp = *this;
				++(*this);
				return (tmp);
			}

			 map_const_iterator operator--(int)
			{
				 map_const_iterator tmp;

				tmp = *this;
				--(*this);
				return (tmp);
			}

			reference operator*() const
			{
				return (_node->value);
			}

			pointer operator->() const //return 시, const 형을 반환
			{
				return (&(_node->value));
			}

			bool operator== (const  map_const_iterator& lhs)
			{
				return (this->_node == lhs.getnode());
			}

			bool operator!= (const  map_const_iterator& lhs)
			{
				return (this->_node !=lhs.getnode());
			}

			bool operator== (const map_iterator<T>& lhs)
			{
				return (this->_node == lhs.getnode());   //base로 받아오는 값이 _node랑 같은데 굳이 base 써야하나????
			}

			bool operator!= (const map_iterator<T>& lhs)
			{
				return (this->_node != lhs.getnode());
			}
	};
}
#endif
