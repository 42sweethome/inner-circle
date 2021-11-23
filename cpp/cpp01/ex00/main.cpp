#include "Zombie.hpp"

int     main(void)
{
    Zombie* newzombie;
    
    newzombie = newZombie("monika");
    newzombie->announce();
    randomChump("leejung");
    delete newzombie;
    return (0);
}