#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include <resourcemining.h>

class PlayerInventory : public ResourceMining
{
public:
    PlayerInventory();

    void openInventory();
};

#endif // PLAYERINVENTORY_H
