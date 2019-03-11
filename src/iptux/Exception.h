#ifndef IPTUX_EXCEPTION_H
#define IPTUX_EXCEPTION_H

#include <stdexcept>

namespace iptux {

enum class ErrorCode {
  INVALID_IP_ADDRESS,
};

class Exception : public std::runtime_error {
 public:
  explicit Exception(ErrorCode ec);
  Exception(ErrorCode ec, const std::string& reason);
  Exception(ErrorCode ec, std::exception* causedBy);
  Exception(ErrorCode ec, const std::string& reason, std::exception* causedBy);

  ErrorCode getErrorCode() const;
 private:
  ErrorCode ec;
};

}

#endif //IPTUX_EXCEPTION_H
