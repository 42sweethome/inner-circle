#ifndef MAP_HPP
# define MAP_HPP

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
			//typedef ft::map_iterator<value_type>			    iterator;
			//typedef ft::map_iterator<const value_type>	        const_iterator;
			//typedef ft::reverse_map_iterator<iterator>	        reverse_iterator;
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
            {

            }

            map (const map& x)
            {
                
            }



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


    };

}

#endif