#include "InvalidRoomMsg.h"
#include <iostream>

int HtW::InvalidRoomMsg::ID = -1;

int HtW::InvalidRoomMsg::GetID() const
{
	return InvalidRoomMsg::ID;
}

void HtW::InvalidRoomMsgHandler::Process(const Message&)
{
	std::cout << "Bist du doof?" << std::endl;
}
