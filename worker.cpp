#include <iostream>
#include <zmq.hpp>
#include <zmq_addon.hpp>

int main() {
  std::cout << "Run worker..." << std::endl;
  zmq::message_t msg; // container to holds result
  zmq::context_t worker_ctx;
  zmq::socket_t worker_socket(worker_ctx, zmq::socket_type::pull);

  const std::string addr = "tcp://127.0.0.1:7000";
  worker_socket.connect(addr);

  for (int i = 0; i < 100; ++i) {
    // will return the number of byte of the message and
    // put the response buffer into "msg"
    auto res = worker_socket.recv(msg, zmq::recv_flags::none);
    std::cout << "[job id]: " << i << " [message length]: " << res.value()
              << " | [message body]: " << msg.to_string() << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
