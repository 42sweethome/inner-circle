#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>

namespace ft
{

	enum Color
	{
		RED,
		BLACK,
		DBLACK
	};

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

		// bool operator== (const RBnode &other)
		// {
		// 	if (this->value == other.value)
		// 		return (true);
		// 	return (false);
		// }

		// bool operator!= (const RBnode &other)
		// {
		// 	if (this->value != other.value)
		// 		return (true);
		// 	return (false);
		// }

	};



    template <class T, class Compare, class Alloc = std::allocator<T> >
    class RBTree
    {
        private:
            typedef RBTree												tree;
            typedef ft::RBnode<T>										node_type;
            typedef ft::RBnode<T>*										node_pointer;
            //typedef typename Alloc::template rebind<node_type>::other	node_alloc_type;
			typedef std::allocator<node_type>							node_alloc_type;

        public:
			typedef	T													value_type;
			typedef	Compare												value_compare;
			typedef	Alloc												allocate_type;
			typedef	std::size_t											size_type;
			typedef	std::ptrdiff_t										difference_type;
			typedef	typename allocate_type::reference					reference;
			typedef	typename allocate_type::const_reference				const_reference;
			typedef	typename allocate_type::pointer						pointer;
			typedef	typename allocate_type::const_pointer				const_pointer;
			// typedef	ft::tree_iterator<value_type>						iterator;
			// typedef	ft::tree_const_iterator<value_type>					const_iterator;
			// typedef	ft::reverse_iterator<iterator>						reverse_iterator;
			// typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		private:
			value_compare	_comp;
			allocate_type	_alloc;
			node_alloc_type	_node_alloc;
			node_pointer	_meta_node;
			size_type		_size;

		public:
			RBtree(value_compare const &comp, allocate_type const &alloc, node_alloc const &node = node_alloc_type())
				: _comp(comp), _alloc(alloc), _node_alloc(node_alloc), _meta_node(NULL), _size(0)
			{
				_meta_node = _node_alloc.allocate(1);
				_node_alloc.construct(_meta_node, node_type());
			}

			RBtree(const RBnode &ref) : _comp(ref._comp), _alloc(ref._alloc), _node_alloc(ref._node_alloc), _meta_node(NULL), _size(0)
			{
				_meta_node = _node_alloc.allocate(1);
				_node_alloc.construct(_meta_node, node_type());
				if (ref.getRoot() != NULL)
					copyTree(ref.getRoot());
			}

			node_pointer getRoot(void) const
			{
				return (_meta_node->left);
			}

			void	setRoot(node_pointer node) const
			{
				this->_meta_node->left = node;
				this->_meta_node->right = node; //???? right는 필요한가????
				if (node != NULL)
					node->parent = _meta_node;
			}


			pair<iterator,bool> insert (const value_type& val)
			{
				return (insertValue(val));
			}

			iterator insert (iterator position, const value_type& val)
			{
				
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				
			}


			pair<iterator, bool> insertValue(const value_type &val)
			{
				node_pointer node =	_node_alloc.allocate(1);
				_node_alloc.construct(node, node_type(val));
				pair<iterator, bool> ret = insertNode(node);

				if (ret.seconde == false)
				{
					_node_alloc.destroy(node);
					_node_alloc.deallocate(node, 1);
				}
				else
				{
					this->_size++;
					fixAfterInsert(node);
				}
				return (ret);
			}

			pair<iterator, bool> insertNode(node_pointer node)
			{
				node_pointer tmp = getRoot();
				node_pointer parent;

				if (tmp == NULL)
				{
					setRoot(node);
					return (make_pair(iterator(node), true));
				}
				while (tmp)
				{
					if (_comp(tmp->value, node->value))
					{
						parent = tmp;
						tmp = tmp->right;
					}
					else if (_comp(node->value, tmp->value))
					{
						parent = tmp;
						tmp = tmp->left;
					}
					else
						return (make_pair(iterator(tmp), false));
				}
				if (_comp(parent->value, node->value))
				{
					parent->right = node;
					node->parent = parent;
				}
				else
				{
					parent->left = node;
					node->parent = parent;
				}
				return (make_pair(iterator(node), true));
			}

			Color getColor(node_pointer node) //????
			{
				if (node == NULL)
					return (BLACK);
				return (node->color);
			}

			void setColor(node_pointer node, Color color)
			{
				if (node == NULL)
					return ;
				node->color = color;
			}

			node_pointer getParent(node_pointer node) const
			{
				if (node == NULL)
					return (NULL);
				if (node->parent == this->_meta_node)
					return (NULL);
				return (node->parent);
			}

			node_pointer getGrandparent(node_pointer node) // const????
			{
				node_pointer pr = getParent(node);
				
				if (pr = NULL)
					return (NULL);
				return (getParent(pr));
			}

			node_pointer getSibling(node_pointer node)
			{
				node_pointer pr = getParent(node);

				if (pr == NULL)
					return (NULL);
				if (node == pr->left)
					return (pr->right);
				return (pr->left);
			}

			node_pointer getUncle(node_pointer node)
			{
				node_pointer pr = getParent(node);

				if (pr == NULL)
					return (NULL);
				return (getSibling(pr));
			}

			void insertCase1(node_pointer& node)
			{
				setColor(getParent(node), BLACK);
				setColor(getUncle(node), BLACK);
				setColor(getGrandparent(node), RED);
				node = getGrandparent(node);
			}

			void fixAfterInsert(node_pointer node)
			{
				node_pointer	parent;
				node_pointer	grandParent;
				node_pointer	uncle;

				while (node != getRoot() && getColor(node) == RED && getColor(getParent) == RED))
				{
					parent = getParent(node);
					grandparent = getGrandparent(node)

					if (grandparent == NULL)
						break;
					
					uncle = getUncle(node);

					if(getColor(uncle) == RED)
					{ // recoloring
						insertCase1(node);
					}
					else if ()
					{

					}
					else if ()
					{

					}

				}
			}
    };

}

#endif