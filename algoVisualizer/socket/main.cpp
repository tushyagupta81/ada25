#include <boost/asio.hpp>
#include <boost/asio/impl/read.hpp>
#include <boost/asio/impl/write.hpp>
#include <boost/asio/registered_buffer.hpp>
#include <boost/system/detail/error_code.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include <string>
using boost::asio::ip::tcp;

boost::asio::io_context io_context;
tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8080));
tcp::socket global_socket(io_context);

void sendData(std::string msg) {
  boost::asio::write(global_socket, boost::asio::buffer(msg));
  char buf[2];
  boost::asio::read(global_socket, boost::asio::buffer(buf));
  if ((std::string)buf != "OK") {
    std::cout << "Error in socket, from C++";
    exit(1);
  }
}

std::string stringify(std::vector<int> a) {
  std::string s = "[";
  for (int i = 0; i < a.size(); i++) {
    s += std::to_string(a[i]) + ",";
  }
  s[s.length() - 1] = ']';
  return s;
}

int partition(std::vector<int> &a, int l, int h) {
  int pivot = a[l];
  int j = h, i = l + 1;
  while (j >= i) {
    while (a[j] > pivot && j > l) {
      j--;
    }
    while (a[i] <= pivot && i <= h) {
      i++;
    }
    if (i >= j) {
      break;
    }
    std::swap(a[i], a[j]);
    sendData(stringify(a));
  }
  std::swap(a[l], a[i - 1]);
  sendData(stringify(a));
  return i - 1;
}

int main() {
  std::cout << "Server waiting for connection...\n";
  acceptor.accept(global_socket);

  std::srand(time(NULL));
  int n = 100;

  std::vector<int> a(n, 0);
  for (int j = 0; j < n; ++j) {
    a[j] = std::rand() % 100;
  }

  sendData(stringify(a));
  std::stack<int> s;
  int l = 0;
  int h = n - 1;
  s.push(h);
  s.push(l);
  do {
    l = s.top();
    s.pop();
    h = s.top();
    s.pop();

    while (l < h) {
      int j = partition(a, l, h);
      if (std::abs(l - j) < std::abs(h - j)) {
        s.push(h);
        s.push(j + 1);
        h = j - 1;
      } else {
        s.push(j - 1);
        s.push(l);
        l = j + 1;
      }
    }
  } while (!s.empty());

  std::cout << "Closing Connection";
  global_socket.close();

  return 0;
}
