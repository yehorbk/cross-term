#include "error.hpp"

Error::Error(ErrorCase errorCase) {
    this->errorCase = errorCase;
}

string Error::getMessage() {
    return this->errorMessages[this->errorCase];
}
