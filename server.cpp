#include <iostream>
#include <zmq.hpp>
#include <zmq_addon.hpp>

int main() {
  std::cout << "Run server..." << std::endl;
  zmq::context_t server_ctx;
  zmq::socket_t server_socket(server_ctx, zmq::socket_type::push);
  const std::string addr = "tcp://127.0.0.1:7000";
  server_socket.bind(addr);

  //  for (int i = 0; i < 100; ++i) {
  while (true) {
    server_socket.send(zmq::str_buffer("Hi from ZeroMQ!"),
                       zmq::send_flags::none);

    zmq_sleep(1);
  }

  return 0;
}
