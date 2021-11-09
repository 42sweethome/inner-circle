#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria *createMateria(std::string const &type) = 0;
};

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materia[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		MateriaSource & operator=(const MateriaSource& src);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria *);
		virtual AMateria *createMateria(std::string const &type);
};

#endif
