#pragma once
#include "GameLoop.h"

namespace HtW
{
class GameLoopImpl : public GameLoop
{
public:
    void Run();
    void Stop();

    void Push(Message* msg) override;

    void SetHandlerCount(int);
    void RegisterHandler(int, MessageHandler*);
    ~GameLoopImpl() override;

private:
    Message* Pop();
    void     Handle(Message*);

    bool                    m_isRunning                = false;
    static inline const int MAX_MSG_COUNT              = 8;
    Message*                m_pMessages[MAX_MSG_COUNT] = {};
    int                     m_nextFree                 = 0;
    int                     m_nextMsg                  = 0;
    MessageHandler**        m_pHandler                 = nullptr;
    int                     m_handlerCount             = 0;
};
} // namespace HtW
