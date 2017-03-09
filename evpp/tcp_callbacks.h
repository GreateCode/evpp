#pragma once

#include "evpp/inner_pre.h"

#include "evpp/timestamp.h"

namespace evpp {
class Buffer;
class TCPConn;

typedef std::shared_ptr<TCPConn> TCPConnPtr;
typedef std::function<void()> TimerCallback;

// When a connection established, broken down, connecting failed, this callback will be called.
typedef std::function<void(const TCPConnPtr&)> ConnectionCallback;


typedef std::function<void(const TCPConnPtr&)> CloseCallback;
typedef std::function<void(const TCPConnPtr&)> WriteCompleteCallback;
typedef std::function<void(const TCPConnPtr&, size_t)> HighWaterMarkCallback;

typedef std::function<void(const TCPConnPtr&, Buffer*, Timestamp)> MessageCallback;

namespace internal {
inline void DefaultConnectionCallback(const TCPConnPtr&) {}
inline void DefaultMessageCallback(const TCPConnPtr&, Buffer*, Timestamp) {}
}

}