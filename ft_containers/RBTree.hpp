#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>
# include "TreeIterator.hpp"
# include "ReverseIterator.hpp"

namespace ft
{
    template <class T, class Compare, class Alloc = std::allocator<T> >
    class RBTree
    {
        private:
            typedef RBTree												tree;
            typedef ft::RBnode<T>										node_type;
            typedef ft::RBnode<T>*										node_pointer;
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
			typedef	ft::tree_iterator<value_type>						iterator;
			typedef	ft::const_tree_iterator<value_type>					const_iterator;
			typedef	ft::reverse_iterator<iterator>						reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		private:
			value_compare	_comp;
			allocate_type	_alloc;
			node_alloc_type	_node_alloc;
			node_pointer	_meta_node;
			size_type		_size;

		public:
			RBTree(value_compare const &comp, allocate_type const &alloc, node_alloc_type const &node = node_alloc_type())
				: _comp(comp), _alloc(alloc), _node_alloc(node), _meta_node(NULL), _size(0)
			{
				_meta_node = _node_alloc.allocate(1);
				_node_alloc.construct(_meta_node, node_type());
			}

			RBTree(const RBTree &ref) : _comp(ref._comp), _alloc(ref._alloc), _node_alloc(ref._node_alloc), _meta_node(NULL), _size(0)
			{
				_meta_node = _node_alloc.allocate(1);
				_node_alloc.construct(_meta_node, node_type());
				copyTree(ref.getRoot());
			}

			RBTree& operator=(const RBTree &ref)
			{
				if (this == &ref)
					return (*this);
				this->clear();
				this->_comp = ref._comp;
				this->_alloc = ref._alloc;
				this->_node_alloc = ref._node_alloc;
				copyTree(ref.getRoot());
				this->_size = ref._size;
				return (*this);
			}

			void swap(RBTree &other)
			{
				if (this == &other)
					return ;
				value_compare	tmp_comp = other._comp;
				allocate_type	tmp_alloc = other._alloc;
				node_alloc_type tmp_node_alloc = other._node_alloc;
				node_pointer	tmp_meta_node = other._meta_node;
				size_type 		tmp_size = other._size;

				other._comp = this->_comp;
				other._alloc = this->_alloc;
				other._node_alloc = this->_node_alloc;
				other._meta_node = this->_meta_node;
				other._size = this->_size;

				this->_comp = tmp_comp;
				this->_alloc = tmp_alloc;
				this->_node_alloc = tmp_node_alloc;
				this->_meta_node = tmp_meta_node;
				this->_size = tmp_size;
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

			iterator 					begin() { return (iterator(minValueNode(_meta_node))); }
			const_iterator				begin() const { return (const_iterator(minValueNode(_meta_node))); }
			iterator					end() { return (iterator(_meta_node)); }
			const_iterator				end() const { return ( const_iterator(_meta_node)); }
			reverse_iterator 			rbegin() { return (reverse_iterator(end())); }
			const_reverse_iterator		rbegin() const { return ( const_reverse_iterator(end())); }
			reverse_iterator			rend() { return (reverse_iterator(begin())); }
			const_reverse_iterator		rend() const { return (const_reverse_iterator(begin())); }

			bool						empty() const { return (this->_size == 0); }
			size_type					size() const { return (this->_size); }
			size_type					max_size() const { return(_node_alloc.max_size()); }

			node_pointer minValueNode(node_pointer node) const
			{
				if (node == NULL) //delete할때 쓰는 것 같음
					return (node);
				while (node->left != NULL)
					node = node->left;
				return (node);
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
				(void)position;
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

			void erase (const_iterator position) { deleteValue(*position); }
			size_type erase (const value_type &val) { return (deleteValue(val)); }
			void erase (const_iterator first, const_iterator last)
			{
				for (const_iterator it = first; it != last; )
					erase(it++);
			}

			node_pointer find (const value_type& val) const// find tester 확인 필요
			{
				node_pointer tmp;

				tmp = getRoot();
				while (tmp != NULL) // <
				{
					if (!_comp(tmp->value, val) && !_comp(val, tmp->value))
						break;
					else if (_comp(tmp->value, val))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				if (tmp == NULL)
					return (this->_meta_node);
				return (tmp);
			}

			size_type count(const value_type& val) const
			{
				iterator tmp;

				tmp = find(val);
				if (tmp == end())
					return (0);
				return (1);
			}

			iterator lower_bound (const value_type& val)
			{
				iterator it1 = this->begin();
				iterator it2 = this->end();

				while (it1 != it2)
				{
					if (_comp(*it1, val) == false)
						break;
					++it1;
				}
				return (it1);
			}

			iterator upper_bound (const value_type& val)
			{
				iterator it1 = this->begin();
				iterator it2 = this->end();

				while (it1 != it2)
				{
					if (_comp(val, *it1) == true)
						break;
					++it1;
				}
				return (it1);
			}

			const_iterator lower_bound (const value_type& val) const
			{
				const_iterator it1 = this->begin();
				const_iterator it2 = this->end();

				while (it1 != it2)
				{
					if (_comp(*it1, val) == false)
						break;
					++it1;
				}
				return (it1);
			}

			const_iterator upper_bound (const value_type& val) const
			{
				const_iterator it1 = this->begin();
				const_iterator it2 = this->end();

				while (it1 != it2)
				{
					if (_comp(val, *it1) == true)
						break;
					++it1;
				}
				return (it1);
			}

		private:
			pair<iterator, bool> insertValue(const value_type &val)
			{
				node_pointer node =	_node_alloc.allocate(1);
				_node_alloc.construct(node, node_type(val));
				pair<iterator, bool> ret = insertNode(node);

				if (ret.second == false)
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
					return (ft::make_pair(iterator(node), true));
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
						return (ft::make_pair(iterator(tmp), false));
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
				return (ft::make_pair(iterator(node), true));
			}

			Color getColor(node_pointer node)
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

			node_pointer getGrandparent(node_pointer node)
			{
				node_pointer pr = getParent(node);

				if (pr == NULL)
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
				node_pointer	grandparent;
				node_pointer	uncle;

				while (node != getRoot() && getColor(node) == RED && getColor(getParent(node)) == RED)
				{
					parent = getParent(node);
					grandparent = getGrandparent(node);
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

			void		deleteRootCase(node_pointer root)
			{
				if (root->right)
					setRoot(root->right);
				else
					setRoot(root->left);
				_node_alloc.destroy(root);
				_node_alloc.deallocate(root, 1);
				setColor(getRoot(), BLACK);
				return ;
			}

			void		deleteRedCase(node_pointer &node)
			{
				node_pointer child = node->left != NULL ? node->left : node->right;
				if (node == node->parent->left)
					node->parent->left = child;
				else
					node->parent->right = child;
				if (child != NULL)
					child->parent = node->parent;
				setColor(child, BLACK);
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}

			void		deleteCase1(node_pointer &s, node_pointer &p)
			{
				if (s == p->right)
					rotateLeft(p);
				if (s == p->left)
					rotateRight(p);
				setColor(s, BLACK);
				setColor(p, RED);
			}

			void		deleteCase2(node_pointer s, node_pointer p, node_pointer &node)
			{
				setColor(s, RED);
				if (getColor(p) == RED)
					setColor(p, BLACK); // extra black 제거
				else
					setColor(p, DBLACK); // dblack
				node = p; // 위로 올리기
			}

			void		deleteCase3(node_pointer &s, node_pointer &p)
			{
				if (s == p->right)
				{
					rotateRight(s);
					setColor(s->left, BLACK);
					setColor(s, RED);
					s = p->right; // 형제 재정의
				}
				if (s == p->left)
				{
					rotateLeft(s);
					setColor(s->right, BLACK);
					setColor(s, RED);
					s = p->left;
				}
			}

			void		deleteCase4(node_pointer &s, node_pointer &p)
			{
				if (s == p->right)
				{
					rotateLeft(p);
					setColor(s, getColor(p));
					setColor(p, BLACK);
					setColor(s->right, BLACK);
				}
				if (s == p->left)
				{
					rotateRight(p);
					setColor(s, getColor(p));
					setColor(p, BLACK);
					setColor(s->left, BLACK);
				}
			}

			void		fixAfterDelete(node_pointer node)
			{
				if (node == NULL)
					return ;
				if (node == getRoot())
				{
					deleteRootCase(node);
					return ;
				}
				if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED)
				{
					deleteRedCase(node);
					return ;
				}
				node_pointer s = NULL;
				node_pointer p = NULL;
				node_pointer tmp = node;
				setColor(tmp, DBLACK);
				while (tmp != getRoot() && getColor(tmp) == DBLACK)
				{
					p = tmp->parent;
					s = (tmp == p->left) ? p->right : p->left;
					if (getColor(s) == RED)
						deleteCase1(s, p); // 형제가 RED일 때 두발 전진을 위한 한발 후퇴
					else if (getColor(s->left) == BLACK && getColor(s->right) == BLACK)
						deleteCase2(s, p, tmp); // 형제의 자식들이 BLACK일 때
					else
					{
						if ((tmp == p->left && getColor(s->right) == BLACK)
						|| (tmp == p->right && getColor(s->left) == BLACK))
							deleteCase3(s, p);
						deleteCase4(s, p);
						break;
					}
				}
				if (node == node->parent->left)
					node->parent->left = NULL;
				else
					node->parent->right = NULL;
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
				setColor(getRoot(), BLACK);
			}

			node_pointer	deleteNode(node_pointer node, const value_type &val)
			{
				if (node == NULL)
					return (node);
				if (_comp(node->value, val)) // 삭제하고자하는 위치 찾기
					return (deleteNode(node->right, val));
				if (_comp(val, node->value))
					return (deleteNode(node->left, val));
				if (node->left == NULL || node->right == NULL)
					return (node);
				node_pointer tmp = minValueNode(node->right);
				if (tmp->parent == node) //tmp left가 null
				{
					if (node->parent && node->parent->left == node)
						node->parent->left = tmp;
					if (node->parent && node->parent->right == node)
						node->parent->right = tmp;
					tmp->left = node->left;
					node->left->parent = tmp;
					node->left = NULL; // 529번째줄로 return하기 위한 조건
					tmp->parent = node->parent;
					node->parent = tmp;
					node->right = tmp->right;
					tmp->right = node;
					std::swap(tmp->color, node->color);
				}
				else
				{
					if (node->parent && node->parent->left == node)
						node->parent->left = tmp;
					if (node->parent && node->parent->right == node)
						node->parent->right = tmp;
					if (tmp->parent->left == tmp)
						tmp->parent->left = node;
					if (tmp->parent->right == tmp)
						tmp->parent->right = node;
					node_pointer tmp2 = tmp->parent;
					node->right->parent = tmp;
					tmp->parent = node->parent;
					node->parent = tmp2;
					tmp->left = node->left;
					node->left->parent = tmp;
					node->left = NULL;
					node_pointer tmp3 = tmp->right;
					tmp->right = node->right;
					node->right = tmp3;
					std::swap(tmp->color, node->color);
				}
				return (deleteNode(tmp->right, val));
			}

			size_type	deleteValue(const value_type &val)
			{
				node_pointer target = deleteNode(getRoot(), val);
				if (target == NULL)
					return (0);
				fixAfterDelete(target);
				this->_size--;
				return (1);
			}
    };

}

#endif
