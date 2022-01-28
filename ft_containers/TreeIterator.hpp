#ifndef TREEITERATOR_HPP
# define TREEITERATOR_HPP

# include "Iterator.hpp"
# include "RBnode.hpp"

namespace ft
{
    template <typename T>
	class const_tree_iterator;

	template <class T>
	class tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
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
				while (node->left != NULL)
					node = node->left;
				return (node);
			}

			node_pointer	maxValueNode(node_pointer node)
			{
				while (node->right != NULL)
					node = node->right;
				return (node);
			}

		public:
			tree_iterator(): _node(NULL) {}
			tree_iterator(const tree_iterator &ref) : _node(ref._node) {}
			tree_iterator(node_pointer node) : _node(node) {}
			virtual ~tree_iterator() {}

			tree_iterator& operator=(const tree_iterator& ref)
			{
				if (this != &ref)
					this->_node = ref._node;
				return (*this);
			}

	        node_pointer getnode() const { return (this->_node); }

			tree_iterator& operator++()
			{
				if (_node->parent == NULL)
					_node = NULL;
				if (_node->right != NULL)
				{
					_node = minValueNode(_node->right);
					return (*this);
				}
				while (_node->parent && _node->parent->right == _node)
					_node = _node->parent;
				if (_node->parent)
					_node = _node->parent;
				return (*this);
			}

			tree_iterator& operator--()
			{
				if (_node->left != NULL)
				{
					_node = maxValueNode(_node->left);
					return (*this);
				}
				while (_node->parent && _node->parent->left == _node)
					_node = _node->parent;
				if (_node->parent)
					_node = _node->parent;
				else
					_node = NULL;
				return(*this);
			}

			tree_iterator operator++(int)
			{
				tree_iterator tmp;

				tmp = *this;
				++(*this);
				return (tmp);
			}

			tree_iterator operator--(int)
			{
				tree_iterator tmp;

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

			bool operator== (const tree_iterator& lhs)
			{
				return (this->_node == lhs.getnode());
			}

			bool operator!= (const tree_iterator& lhs)
			{
				return (this->_node != lhs.getnode());
			}

			bool operator== (const const_tree_iterator<T>& lhs)
			{
				return (this->_node == lhs.getnode());
			}

			bool operator!= (const const_tree_iterator<T>& lhs)
			{
				return (this->_node != lhs.getnode());
			}
	};

	template <class T>
	class const_tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, const T>
	{
		private:
			typedef ft::RBnode<T>               node;
			typedef ft::RBnode<T>*              node_pointer;

		public:
			typedef bidirectional_iterator_tag  iterator_category;
			typedef T                           value_type;
			typedef const value_type&           reference;
			typedef std::ptrdiff_t              difference_type;
			typedef const T*                    pointer;

		private:
			node_pointer 	_node;

			node_pointer	minValueNode(node_pointer node)
			{
				while (node->left != NULL)
					node = node->left;
				return (node);
			}

			node_pointer	maxValueNode(node_pointer node)
			{
				while (node->right != NULL)
					node = node->right;
				return (node);
			}

		public:
			const_tree_iterator(): _node(NULL) {}
			const_tree_iterator(const const_tree_iterator &ref) : _node(ref._node) {}
			const_tree_iterator(node_pointer node) : _node(node) {}
			virtual ~const_tree_iterator() {}

			const_tree_iterator& operator=(const const_tree_iterator& ref)
			{
				if (this != &ref)
					this->_node = ref._node;
				return (*this);
			}

			const_tree_iterator(const tree_iterator<T>& other) : _node(other.getnode()) {}

	        node_pointer getnode() const { return (this->_node); }

			const_tree_iterator& operator++()
			{
				if (_node->parent == NULL)
					_node = NULL;
				if (_node->right != NULL)
				{
					_node = minValueNode(_node->right);
					return (*this);
				}
				while (_node->parent && _node->parent->right == _node)
					_node = _node->parent;
				if (_node->parent)
					_node = _node->parent;
				return (*this);
			}

			const_tree_iterator& operator--()
			{
				if (_node->left != NULL)
				{
					_node = maxValueNode(_node->left);
					return (*this);
				}
				while (_node->parent && _node->parent->left == _node)
					_node = _node->parent;
				if (_node->parent)
					_node = _node->parent;
				else
					_node = NULL;
				return (*this);
			}

			const_tree_iterator operator++(int)
			{
				 const_tree_iterator tmp;

				tmp = *this;
				++(*this);
				return (tmp);
			}

			 const_tree_iterator operator--(int)
			{
				 const_tree_iterator tmp;

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

			bool operator== (const  const_tree_iterator& lhs)
			{
				return (this->_node == lhs.getnode());
			}

			bool operator!= (const  const_tree_iterator& lhs)
			{
				return (this->_node !=lhs.getnode());
			}

			bool operator== (const tree_iterator<T>& lhs)
			{
				return (this->_node == lhs.getnode());
			}

			bool operator!= (const tree_iterator<T>& lhs)
			{
				return (this->_node != lhs.getnode());
			}
	};
}
#endif
