#include "exceptions.h"
#include <stdexcept>
#include <string>

void throwInvalidArgumentError(int size) {
  throw std::invalid_argument(
      "Number of octects in provided IP address should be " +
      std::to_string(size) + ".");
}

void throwCannotConvertToIp() {
  throw std::invalid_argument(
      "Provided string cannot be converted to IP address.");
}