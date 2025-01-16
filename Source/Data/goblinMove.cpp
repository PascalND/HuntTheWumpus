#include "goblinMove.h"

namespace HtW
{
void golbinMove(Room& currentGoblinRoom, RandomGenerator& random, Cave& cave)
{
    if (random.GenerateUnique({0, 2}) == 0)
    {
        currentGoblinRoom.content = HtW::Room::Content::EMPTY;
        doGolbinMove(currentGoblinRoom, random, cave);
    }
}

void doGolbinMove(Room& currentGoblinRoom, RandomGenerator& random, Cave& cave)
{
    int numberPossibleRooms = 0;
    int possibleRooms[3];
    for (int i = 0; i < 3; i++)
    {
        if (currentGoblinRoom.pNeighbors[i]->content == HtW::Room::Content::PLAYER || currentGoblinRoom.pNeighbors[i]->content == HtW::Room::Content::EMPTY)
        {
            possibleRooms[numberPossibleRooms] = i;
            numberPossibleRooms++;
        }
    }

    if (numberPossibleRooms > 0)
    {
        int   index                  = random.GenerateUnique({0, numberPossibleRooms - 1});
        int   targetGoblinRoomNumber = currentGoblinRoom.pNeighbors[possibleRooms[index]]->number;
        Room& targetGoblinRoom       = cave.getRoomByNumber(targetGoblinRoomNumber);
        targetGoblinRoom.content     = HtW::Room::Content::GOBLIN;
    }
}

}