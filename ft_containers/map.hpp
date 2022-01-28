#ifndef MAP_HPP
# define MAP_HPP

# include "RBTree.hpp"
# include <iostream>
# include <memory>
# include <functional>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair< const Key, T> > >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			poiner;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::tree_iterator<value_type>				iterator;
			typedef ft::const_tree_iterator<value_type>			const_iterator; //const_tree_iterator와 tree_iterator<const> 차이????
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;   //typename 안해도되나??????????
			typedef std::size_t									size_type;
			class value_compare : public std::binary_function<value_type, value_type, bool>
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

		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _tree(value_compare(comp), alloc) {};

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
				: _tree(value_compare(comp), alloc)
			{
				this->insert(first, last);
			}

			map (const map& other) : _tree(other._tree)
			{}

			~map () {}

			map& operator= (const map& other)
			{
				if (this == &other)
					return (*this);
				this->_tree = other._tree;
				return (*this);
			}

			iterator 				begin() { return (_tree.begin()); }
			const_iterator 			begin() const { return (_tree.begin()); }
			iterator 				end() {  return (_tree.end()); }
			const_iterator	 		end() const {  return (_tree.end()); }
			reverse_iterator		rbegin() { return (_tree.rbegin()); }
			const_reverse_iterator 	rbegin() const { return (_tree.rbegin()); }
			reverse_iterator 		rend() {  return (_tree.rend()); }
			const_reverse_iterator 	rend() const {  return (_tree.rend()); }


			bool 					empty() const { return (this->_tree.empty()); }
			size_type 				size() const { return (this->_tree.size()); }
			size_type 				max_size() const { return (_tree.max_size()); }

			mapped_type& operator[] (const key_type& key)
			{
				return (insert(ft::make_pair(key, mapped_type())).first->second);
			}

			pair<iterator,bool> 	insert (const value_type& val) { return (_tree.insert(val)); }
			iterator 				insert (iterator position, const value_type& val) { return (_tree.insert(position, val)); }
			template <class InputIterator>
			void 					insert (InputIterator first, InputIterator last) {	return (_tree.insert(first, last));	}
			void 					erase (iterator position) { return (_tree.erase(position)); }
			size_type 				erase (const key_type& key)	{ return (_tree.erase(ft::make_pair(key, mapped_type()))); }
			void 					erase (iterator first, iterator last)	{ return (_tree.erase(first, last)); }

			void            		swap (map& x) { return (_tree.swap(x._tree)); }
			void           			clear() { return (_tree.clear()); }

			key_compare				key_comp() const { return (key_compare()); }
			value_compare			value_comp() const { return (value_compare(key_compare())); }

			iterator				find (const key_type& key) { return (iterator(_tree.find(ft::make_pair(key, mapped_type())))); }
			const_iterator			find (const key_type& key) const { return (const_iterator(_tree.find(ft::make_pair(key, mapped_type())))); }
			size_type				count (const key_type& key) const { return (_tree.count(ft::make_pair(key, mapped_type()))); }

			iterator        		lower_bound (const key_type& key) {	return (iterator(_tree.lower_bound(ft::make_pair(key, mapped_type())))); }
			iterator        		upper_bound (const key_type& key) {	return (iterator(_tree.upper_bound(ft::make_pair(key, mapped_type())))); }
			const_iterator			lower_bound (const key_type& key) const {	return (const_iterator(_tree.lower_bound(ft::make_pair(key, mapped_type())))); }
			const_iterator			upper_bound (const key_type& key) const {	return (const_iterator(_tree.upper_bound(ft::make_pair(key, mapped_type())))); }

			pair<const_iterator, const_iterator> equal_range (const key_type& key) const
			{ return (ft::make_pair(this->lower_bound(key), this->upper_bound(key))); }

			pair<iterator, iterator> equal_range (const key_type& key)
			{ return (ft::make_pair(this->lower_bound(key), this->upper_bound(key))); }

			allocator_type get_allocator() const
			{ return (allocator_type()); }

			friend bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
				const ft::map<Key,T,Compare,Alloc>& rhs )
			{
				if (lhs.size() != rhs.size())
					return (false);
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

			friend bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
				const ft::map<Key,T,Compare,Alloc>& rhs )
			{
				return (!(lhs == rhs));
			}

			friend bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
							const ft::map<Key,T,Compare,Alloc>& rhs )
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

			friend bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
							const ft::map<Key,T,Compare,Alloc>& rhs )
			{
				return(!(rhs < lhs));
			}

			friend bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
							const ft::map<Key,T,Compare,Alloc>& rhs )
			{
				return (rhs < lhs);
			}

			friend bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
							const ft::map<Key,T,Compare,Alloc>& rhs )
			{
				return (!(lhs < rhs));
			}
	};

}

#endif
