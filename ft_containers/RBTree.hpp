#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>
# include "MapIterator.hpp"

namespace ft
{
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
				//if (ref.getRoot() != NULL)
				copyTree(ref.getRoot()); //
			}

			RBtree& operator=(const red_black_tree &ref)
			{
				if (this == &ref)
					return (*this);
				this->clear();
				this->_comp = ref._comp;
				this->_alloc = ref._alloc;
				this->_node_alloc = ref._node_alloc;
				copyTree(ref.getRoot());
				this->size = ref._size;
				return (*this);
			}

			void clear()
			{
				deleteTree(getRoot());
				setRoot(NULL);
				this->_size = 0;
			}

			void deleteTree(node_pointer node)
			{
				if (node != NULL)
				{
					deleteTree(node->left);
					deleteTree(node->right);
					_node_alloc.destroy(node);
					_node_alloc.deallocate(node, 1);
				}	
			}

			void copyTree(node_pointer node)
			{
				if (node != NULL) //base con
				{
					insertValue(node->value);
					copyTree(node->left);
					copyTree(node->right);
				}
			}

			iterator 			begin() { return (iterator(minValueNode(_meta_node))); }
			const_iterator		begin() const { return (const_iterator(minValueNode(_meta_node))); }
			iterator			end() { return (iterator(_meta_node)); }
			const_iterator		end() const { return ( const_iterator(_meta_node)); }
			
			bool				empty() const { return (this->_size == 0); }
			size_type			size() const { return (this->_size); }
			size_type			max_size() const { return(_node_alloc.max_size()); }

			node_pointer minValueNode(node_pointer node) const
			{
				// if (node == NULL) //delete할때 쓰는 것 같음
				// 	return (node);
				while (node->left != NULL)
					node = node->left;
				return (node);
			}

			//node_pointer maxValueNode() 없네?

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
				(void)positon;
				return (insertValue(val).first);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					this->insert(*first);
					++first;
				}
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

			iterator find (const value_type& k) const
			{
				node_pointer tmp;

				tmp = getRoot();
				while (tmp != NULL) // <
				{
					if (!_comp(tmp->value, k) && !_comp(k, tmp->value))
						break;
					else if (_comp(tmp->value, k))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				if (tmp == NULL)
					return (iterator(this->_meta_node));
				return (iterator(tmp));
			}

			size_type count(const value_type& k) const
			{
				iterator tmp;

				tmp = find(k);
				if (tmp == end())
					return (0);
				return (1);
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

			void rotateLeft(node_pointer node)
			{
				node_pointer rightChild;
				
				rightChild = node->right; //부모의 오른쪽 자식
				if (rightChild == NULL) // ????
					return ;
				node->right = rightChild->left;
				if (node->right != NULL)
					node->right->parent = node;
				rightChild->parent = node->parent;
				if (getParent(node) == NULL)
					setRoot(rightChild);
				else if (node == node->parent->left)
					node->parent->left = rightChild;
				else
					node->parent->right = rightChild;
				rightChild->left = node;
				node->parent = rightChild;
			}
		
			void rotateRight(node_pointer node)
			{
				node_pointer leftChild;

				leftChild = node->left;
				if (leftChild == NULL)
					return ;
				node->left = leftChild->right;
				if (node->left != NULL)
					node->left->parent = node;
				leftChild->parent = node->parent;
				if (getParent(node) == NULL)
					setRoot(leftChild);
				else if (node == node->parent->left)
					node->parent->left = leftChild;
				else
					node->parent->right = leftChild;
				leftChild->right = node;
				node->parent = leftChild;
			}

			void insertCase1(node_pointer& node)
			{
				setColor(getParent(node), BLACK);
				setColor(getUncle(node), BLACK);
				setColor(getGrandparent(node), RED);
				node = getGrandparent(node);
			}

			void insertCase2(node_pointer& node, node_pointer &p)
			{
				if (p == getGrandparent(node)->left)
				{
					rotateLeft(p);
					node = p;
					p = getParent(node);
				}
				else if (p == getGrandparent(node)->right)
				{
					rotateRight(p);
					node = p;
					p = getParent(node);
				}
			}

			void insertCase3(node_pointer& node, node_pointer p, node_pointer g)
			{
				if (p == g->left)
					rotateRight(g);
				else if (p == g->right)
					rotateLeft(g);
				std::swap(p->color, g->color);
				node = p;		
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
					else if (parent == grandparent->left) //부모 left
					{
						if (node == parent->right)//lr
							insertCase2(node, parent);
						insertCase3(node, parent, grandparent); //ll
					}
					else if (parent == grandparent->right) //부모 right
					{
						if (node == parent->left) //rl
							insertCase2(node, parent);
						insertCase3(node, parent, grandparent); //rr
					}
				}
				setColor(getRoot(), BLACK);
			}
    };

}

#endif