# ZeroMQ C++ Simple Queue

1. To create servers and workers, first we need define a **context**, a "thread" like but it's safe.
2. We define the socket by using `zmq::socket_t` and give the context and also the socket type.
3. Notice the socket connection by looking at these!
    - **Server**: use `socket.bind(addr)`
    - **Client**: use `socket.connect(addr)`
4. Infinite loop the server, and client/worker
5. Inside server's loop:
    - Call `socket.send()` to send the message buffer
6. Inside worker's loop:
    - Call `socket.recv()` to receive the byte size and message buffer
    - The byte size will go as the result of `socket.recv()` while,
    - The message buffer will go to the `msg` buffer container

[Nice Reference](https://brettviren.github.io/cppzmq-tour/index.html)
