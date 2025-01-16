#pragma once

namespace HtW
{
	class Room
	{
	public:
		enum class Content
		{
			EMPTY = 0,
			SUPER_BAT = 1,
			WUMPUS = 2,
			DEEP_PIT = 4,
			PLAYER = 8,
			ARROW = 16,
			GOBLIN = 32
		};

		int number = 0;
		Content content = Content::EMPTY;
		const Room* pNeighbors[3] = {};
	};
} // namespace HtW
