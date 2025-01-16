#include "Cave.h"
#include <exception>
#include <iomanip>
#include <iostream>

namespace HtW
{
std::ostream& operator<<(std::ostream& out, Room::Content c)
{
    switch (c)
    {
    case Room::Content::DEEP_PIT:
        out << 'O';
        break;
    case Room::Content::PLAYER:
        out << 'P';
        break;
    case Room::Content::WUMPUS:
        out << 'W';
        break;
    case Room::Content::SUPER_BAT:
        out << 'B';
        break;
    case Room::Content::ARROW:
        out << 'A';
        break;
    case Room::Content::GOBLIN:
        out << 'G';
        break;
    default:
        out << ' ';
        break;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Room& r)
{
    out << std::setw(3) << r.number << ' ' << r.content;
    return out;
}

void Print(const Cave& c)
{
    ::system("cls");
    const auto r = c.rooms;
    // clang-format off
		std::cout << R"#(                         -----                      
                       -|)#" << r[0] << R"#(|-
                     /   -----   \
                   -       |       -
                 /       -----       \
               -       /|)#" << r[7] << R"#(|\       -
             /       -   -----   -       \
           -       /               \       -
         /      -----             -----      \
       -       |)#" << r[6] << R"#(|           |)#" << r[8] << R"#(|       -
     /        / ----- \         / ----- \        \
   -         /         \       /         \         -
 -----    -----      -----   -----      -----    -----
|)#" << r[4] << "|--|" << r[5] << "|    |" << r[16] << "|-|" << r[17] << "|    |" << r[9] << "|--|" << r[1] << R"#(|
 -----    -----      -----   -----      -----    -----
  \         |         /         \         |        /
   |        |      -----       -----      |       |
   \      -----  -|)#" << r[15] << "|     |" << r[18] << R"#(|-  -----     /
    |    |)#" << r[14]<< "|/  -----       -----  \\|" << r[10] << R"#(|   | 
    \     -----       \         /       -----    /
     |       \         \       /         /      | 
     \        \          -----          /       /
      |      -----      |)#" << r[19] << R"#(|     -----      | 
      \     |)#" << r[13] << "|      -----     |" << r[11] << R"#(|     /
       |     ----- \       |      / -----     | 
       \      /      -     |    -      \      /
        |     |        \ ----- /        |    | 
        \    /          |)#" << r[12] << R"#(|         \    / 
         -----           -----          -----
        |)#" << r[3] << "|------------------------|" << r[2] << R"#(|
         -----                          -----)#" << std::endl;
    // clang-format on
}

Room& Cave::getRoomByNumber(int roomNumber)
{
    for (int i = 0; i < Cave::NUMBER_ROOMS; i++)
    {
        if (rooms[i].number == roomNumber)
        {
            return rooms[i];
        }
    }
    static Room invalidRoom;
    invalidRoom.number = -1;
    return invalidRoom;
}

Room& Cave::getRoomByContent(Room::Content content)
{
    for (int i = 0; i < Cave::NUMBER_ROOMS; i++)
    {
        if (rooms[i].content == content)
        {
            return rooms[i];
        }
    }
    static Room invalidRoom;
    invalidRoom.number = -1;
    return invalidRoom;
}

} // namespace HtW
