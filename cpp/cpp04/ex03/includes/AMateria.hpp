#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public :
		AMateria();
		AMateria(const AMateria& src);
		AMateria(std::string const &type);
		AMateria & operator=(const AMateria& src);
		virtual ~AMateria();

		std::string const &getType() const; // Returns the materia type
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

class Ice : public AMateria
{
	public :
		Ice();
		Ice(const Ice& src);
		Ice & operator=(const Ice& src);
		virtual ~Ice();

		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);
};

class Cure : public AMateria
{
	public :
		Cure();
		Cure(std::string const &type);
		Cure & operator=(const Cure& src);
		virtual ~Cure();
		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);
};

#endif
