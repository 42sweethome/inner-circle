#ifndef MAP_HPP
# define MAP_HPP

# include "RBTree.hpp"
# include <iostream>

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class map
    {
        public:
            typedef Key											key_type;
            typedef T											mapped_type;
            typedef std::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef allocator_type::reference;					reference;
			typedef allocator_type::const_reference				const_reference;
			typedef allocator_type::pointer						pointer;
			typedef allocator_type::const_pointer				const_pointer;
			typedef ft::map_iterator<value_type>			    iterator;
			typedef ft::map_iterator<const value_type>	        const_iterator;
			//typedef ft::reverse_map_iterator<iterator>	    reverse_iterator;
			//typedef ft::reverse_map_iterator<const_iterator>	const_reverse_iterator;
            typedef std::ptrdiff_t                              difference_type;
            typedef std::size_t                                 size_type;
            class value_compare : public ft::binary_function<value_type, value_type, bool>
            {
                friend class map;
                protected:
                    Compare	comp;
                    value_compare (Compare c) : comp(c) {}
                public:
                    typedef bool		result_type;
                    typedef value_type	first_argument_type;
                    typedef value_type	second_argument_type;
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };

        private:
            typedef RBTree<value_type, value_compare, allocator_type> tree_type;
            
            tree_type           _tree;
            key_compare		    _comp;
            allocator_type		_alloc;

        public:
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
                    : _tree(value_compare(comp), alloc), _comp(comp), _alloc(alloc) {};

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
                    : _tree(value_compare(comp), alloc), _comp(comp), _alloc(alloc)
            {
                this->insert(first, last);
            }

            map (const map& x) : _tree(x.tree), _alloc(x._alloc), _comp(x._comp)
            {}

            ~map () {}

            map& operator= (const map& x)
            {
                if (this == &x)
                    return (*this);
                this->_tree = x.tree;
                return (*this);
            }

            iterator begin() { return (_tree.begin()); }   

			pair<iterator,bool> insert (const value_type& val)
			{
				return (_tree.insert(val));
			}

			iterator insert (iterator position, const value_type& val)
			{
				return (_tree.insert(position, val));
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				return (_tree.insert(first, last));
			}

            iterator        find (const key_type& k) { return (_tree.find(ft::make_pair(k, mapped_type()))); }
            const_iterator  find (const key_type& k) const { return (_tree.find(ft::make_pair(k, mapped_type()))); }
            size_type       count (const key_type& k) const { return (_tree.count(ft::make_pair(k, mapped_type()))); }
            iterator        lower_bound (const key_type& k)
            {
                iterator it1 = this->begin();
                iterator it2 = this->end();

                while (it1 != it2)
                {
                    if (_comp(it1->first, k) == false)
                        break;
                    ++it1;
                }
                return (it1);
            }
            iterator        upper_bound (const key_type& k)
            {
                iterator it1 = this->begin();
                iterator it2 = this->end();

                while (it1 != it2)
                {
                    if (_comp(k, it1->first) == true)
                        break;
                    ++it1;
                }
                return (it1);
            }

            const_iterator        lower_bound (const key_type& k) const
            {
                iterator it1 = this->begin();
                iterator it2 = this->end();

                while (it1 != it2)
                {
                    if (_comp(it1->first, k) == false)
                        break;
                    ++it1;
                }
                return (it1);
            }

            const_iterator        upper_bound (const key_type& k) const
            {
                iterator it1 = this->begin();
                iterator it2 = this->end();

                while (it1 != it2)
                {
                    if (_comp(k, it1->first) == true)
                        break;
                    ++it1;
                }
                return (it1);
            }

            pair<const_iterator, const_iterator> equal_range (const key_type& k) const
            { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }

            pair<iterator, iterator> equal_range (const key_type& k)
            { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }

            allocator_type get_allocator() const
            { return (allocator_type()); }

    };

}

#endif