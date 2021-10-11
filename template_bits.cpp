std::string dec_to_bin(int n) {
  std::string binary = std::bitset<8>(n).to_string();
  return binary;
}

unsigned long bin_to_dec(std::string s) {
  unsigned long decimal = std::bitset<8>(s).to_ulong();
  return decimal;
}

unsigned int next_power_of_2(unsigned int v) {
  //    unsigned int v; // compute the next highest power of 2 of 32-bit v
  v--;
  v |= v >> 1;  // v >> 2 means, v/4, shifting rightward twice, 1000100 -> 10001
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v++;
  return v;
}

template <typename INT> bool oppositeSigns(INT x, INT y) {
  return ((x ^ y) < 0); // True if x and y have opposite signs.
  // source :: http://graphics.stanford.edu/~seander/bithacks.html
}

bool isPowerOfTwo(int n) {
  return (((n) & (n - 1)) ==
          0); // note that 0 is considered incorrectly as power of 2
}

void printBinary(int n) {
  for (int i = 10; i >= 0; i--) { // to set the limit of bit size you want on screen.
    printf("%d", ((n >> i) & 1));
  }
  printf("\n");
}

  
