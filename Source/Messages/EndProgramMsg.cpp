#include "EndProgramMsg.h"
#include "GameLoopImpl.h"
#include <iostream>
namespace HtW
{
	int EndProgramMsg::ID = -1;

	int EndProgramMsg::GetID() const
	{
		return EndProgramMsg::ID;
	}

	void EndProgramMsgHandler::Process(const Message&)
	{
		dynamic_cast<GameLoopImpl*>(m_pGameLoop)->Stop();
		std::cin.get();
	}

} // namespace HtW
