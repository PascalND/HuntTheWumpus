#pragma once
#include "Room.h"

namespace HtW
{
	class Cave
	{
	public:
		Cave() = default;
		Cave(const Cave&) = delete;
		Cave& operator=(const Cave&) = delete;

		// Die Cave besteht aus 20 Raeumen die in einem Dodekaeder angeordnet sind (siehe Print)
		static inline const int NUMBER_ROOMS = 20;
		Room rooms[NUMBER_ROOMS] = {};
        Room&                   getRoomByNumber(int roomNumber);
        Room&                   getRoomByContent(Room::Content content);
        
		
	};

	void Print(const Cave& c);
} // namespace HtW
