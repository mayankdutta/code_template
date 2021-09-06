class Bignum {
public:
  Bignum(int value) {
    assert(value >= 0 && value <= 999999999);
    parts.push_back(value);
  }

  Bignum &operator*=(int rhs) {
    assert(rhs >= 0 && rhs <= 999999999);
    uint32_t carry = 0;
    for (size_t i = 0; i < parts.size(); i++) {
      uint64_t product = (uint64_t)parts[i] * (uint64_t)rhs + carry;
      parts[i] = (uint32_t)(product % 1000000000LL);
      carry = (uint32_t)(product / 1000000000LL);
    }
    if (carry != 0)
      parts.push_back(carry);
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &stream, const Bignum &num);

private:
  std::vector<uint32_t> parts;
};

inline std::ostream &operator<<(std::ostream &stream, const Bignum &num) {
  char oldfill = stream.fill('0');
  for (std::vector<uint32_t>::const_reverse_iterator it = num.parts.rbegin();
       it != num.parts.rend(); it++)
    stream << *it << std::setw(9);
  stream.fill(oldfill);
  stream.width(0);
  return stream;
}

Bignum factorial(int n) {
  Bignum fac = 1;
  for (int i = 2; i <= n; i++)
    fac *= i;
  return fac;
}
