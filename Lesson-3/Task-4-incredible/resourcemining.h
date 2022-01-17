#ifndef RESOURCEMINING_H
#define RESOURCEMINING_H


class ResourceMining
{
public:
    ResourceMining();

    void mineResource();

    void setSticksCount(int fStick) { sticks = fStick; }
    void setWoodCount(int fWood) { wood = fWood; }
    void setStoneCount(int fStone) { stone = fStone; }

    int getSticksCount() { return sticks; }
    int getWoodCount() { return wood; }
    int getStoneCount() { return stone; }

private:
    int sticks;
    int wood;
    int stone;
};

#endif // RESOURCEMINING_H
