#ifndef SET_HPP
# define SET_HPP

# include "RBTree.hpp"
# include <iostream>
# include <memory>
# include <functional>

namespace ft
{
	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		public:
			typedef T											key_type;
			typedef T											value_type;
			typedef Compare										key_compare;
			typedef Compare										value_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			poiner;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::tree_iterator<value_type>				iterator;
			typedef ft::const_tree_iterator<value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

		private:
			typedef RBTree<value_type, value_compare, allocator_type> tree_type;

			tree_type           _tree;

		public:
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _tree(value_compare(comp), alloc) {};

			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
				: _tree(value_compare(comp), alloc)
			{
				this->insert(first, last);
			}

			set (const set& other) : _tree(other._tree)
			{}

			~set () {}

			set& operator= (const set& other)
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

			pair<iterator,bool> 	insert (const value_type& val) { return (_tree.insert(val)); }
			iterator 				insert (iterator position, const value_type& val) { return (_tree.insert(position, val)); }
			template <class InputIterator>
			void 					insert (InputIterator first, InputIterator last) {	return (_tree.insert(first, last));	}
			void 					erase (iterator position) { return (_tree.erase(position)); }
			size_type 				erase (const value_type& val)	{ return (_tree.erase(val)); }
			void 					erase (iterator first, iterator last)	{ return (_tree.erase(first, last)); }

			void            		swap (set& x) { return (_tree.swap(x._tree)); }
			void           			clear() { return (_tree.clear()); }

			key_compare				key_comp() const { return (key_compare()); }
			value_compare			value_comp() const { return (value_compare()); }

			iterator				find (const value_type& val) { return (_tree.find(val)); }
			size_type				count (const value_type& val) const { return (_tree.count(val)); }

			iterator				lower_bound (const value_type& val) const {	return (iterator(_tree.lower_bound(val))); }
			iterator				upper_bound (const value_type& val) const {	return (iterator(_tree.upper_bound(val))); }

			pair<iterator, iterator> equal_range (const value_type& val) const
			{ return (ft::make_pair(this->lower_bound(val), this->upper_bound(val))); }

			allocator_type get_allocator() const
			{ return (allocator_type()); }

			friend bool operator==( const ft::set<T,Compare,Alloc>& lhs,
				const ft::set<T,Compare,Alloc>& rhs )
			{
				if (lhs.size() != rhs.size())
					return (false);
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

			friend bool operator!=( const ft::set<T,Compare,Alloc>& lhs,
				const ft::set<T,Compare,Alloc>& rhs )
			{
				return (!(lhs == rhs));
			}

			friend bool operator<( const ft::set<T,Compare,Alloc>& lhs,
							const ft::set<T,Compare,Alloc>& rhs )
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

			friend bool operator<=( const ft::set<T,Compare,Alloc>& lhs,
							const ft::set<T,Compare,Alloc>& rhs )
			{
				return(!(rhs < lhs));
			}

			friend bool operator>( const ft::set<T,Compare,Alloc>& lhs,
							const ft::set<T,Compare,Alloc>& rhs )
			{
				return (rhs < lhs);
			}

			friend bool operator>=( const ft::set<T,Compare,Alloc>& lhs,
							const ft::set<T,Compare,Alloc>& rhs )
			{
				return (!(lhs < rhs));
			}
	};

}

#endif
