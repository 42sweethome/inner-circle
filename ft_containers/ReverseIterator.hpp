#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

# include "MapIterator.hpp"

namespace	ft{
	template<class Iterator>
	class reverse_iterator
	{
		public:
			typedef	Iterator	iterator_type;
			typedef	typename	ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef	typename	ft::iterator_traits<Iterator>::value_type			value_type;
			typedef	typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef	typename	ft::iterator_traits<Iterator>::pointer				pointer;
			typedef	typename	ft::iterator_traits<Iterator>::reference			reference;

		private:
			iterator_type		_iter;

		public:
			reverse_iterator() : _iter() {};
			explicit reverse_iterator (iterator_type it) : _iter(it) {};
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& other) : _iter(other.base()) {};
			template< class Iter >
			reverse_iterator& operator=( const reverse_iterator<Iter>& other )
			{
				_iter = other.base();
				return (*this);
			}
			iterator_type		base() const { return (_iter); }
			reference 			operator*() const
			{
				iterator_type tmp;

				tmp = base();
				return (*(--tmp));
			}
			pointer 			operator->() const
			{
				iterator_type tmp;

				tmp = base();
				return (--tmp);
			}
			//reverse_iterator	operator+ (difference_type n) const ;
			reverse_iterator&	operator++() { return (--_iter); }
			reverse_iterator  	operator++(int)
			{
				reverse_iterator	tmp;

				tmp = *this;
				--_iter;
				return (tmp);
			}
			//reverse_iterator 	operator- (difference_type n) const;
			reverse_iterator& 	operator--() { return (++_iter); }
			reverse_iterator  	operator--(int)
			{
				reverse_iterator	tmp;

				tmp = *this;
				++_iter;
				return (tmp);
			}
			//reverse_iterator& 	operator+= (difference_type n);
			//reverse_iterator& 	operator-= (difference_type n);
			//reference 			operator[] (difference_type n) const;



			friend bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
			{
				retrun (lhs._iter == rhs._iter);
			}

			friend bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
			{
				retrun (lhs._iter != rhs._iter);
			}

			friend bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
			{
				retrun (lhs._iter > rhs._iter);
			}

			friend bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
			{
				retrun (lhs._iter >= rhs._iter);
			}

			friend bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
			{
				retrun (lhs._iter < rhs._iter);
			}

			friend bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
			{
				retrun (lhs._iter <= rhs._iter);
			}

			// template <class Iterator>
  			// reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);

			// template <class Iterator>
  			// typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs);
	};
}

#endif
