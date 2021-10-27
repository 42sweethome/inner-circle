#include "Zombie.hpp"

int     main(void)
{
    Zombie* newzombie = newZombie("monika");

    randomChump("leejung");
    newzombie->announce();
    delete newzombie;
    return (0);
}