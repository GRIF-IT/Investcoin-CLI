// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include <future>
#include <INode.h>

namespace Tests {

class NodeCallback {
public:
  CryptoNote::INode::Callback callback() {
    prom = std::promise<std::error_code>(); // reset std::promise
    result = prom.get_future();
    return [this](std::error_code ec) {
      std::promise<std::error_code> localPromise(std::move(prom));
      localPromise.set_value(ec);
    };
  }

  std::error_code get() {
    return result.get();
  }

private:
  std::promise<std::error_code> prom;
  std::future<std::error_code> result;
};

}
