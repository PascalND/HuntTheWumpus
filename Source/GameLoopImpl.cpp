#include "GameLoopImpl.h"
#include "UserInputMsg.h"

namespace HtW
{
	void GameLoopImpl::Run()
	{
		m_isRunning = true;
		while(m_isRunning)
		{
			if(m_nextFree == m_nextMsg)
				Push(new UserInputMsg);
			auto msg = Pop();
			Handle(msg);
		}
	}

	void GameLoopImpl::Stop()
	{
		m_isRunning = false;
	}

	void GameLoopImpl::SetHandlerCount(int c)
	{
		m_handlerCount = c;
		m_pHandler = new MessageHandler* [c] {};
	}

	void GameLoopImpl::RegisterHandler(int id, MessageHandler* handler)
	{
		m_pHandler[id] = handler;
	}

	void GameLoopImpl::Push(Message* msg)
	{
		m_pMessages[m_nextFree] = msg;
		m_nextFree = (m_nextFree + 1) % MAX_MSG_COUNT;
	}

	Message* GameLoopImpl::Pop()
	{
		auto msg = m_pMessages[m_nextMsg];
		m_pMessages[m_nextMsg] = nullptr;
		m_nextMsg = (m_nextMsg + 1) % MAX_MSG_COUNT;
		return msg;
	}

	void GameLoopImpl::Handle(Message* msg)
	{
		auto handler = m_pHandler[msg->GetID()];
		handler->Process(*msg);
		delete msg;
	}

	GameLoopImpl::~GameLoopImpl()
	{
		for(int i = 0; i < m_handlerCount; ++i)
			delete m_pHandler[i];
		delete[] m_pHandler;
		for(auto m : m_pMessages)
			delete m;
	}

} // namespace HtW
