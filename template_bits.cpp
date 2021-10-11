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

// There was a 1 @5th place in ch, i bought that damn One @rightmost point and
// then took AND,
// note that, ((ch & (1 << 5))) wont work, cauz how will it will be equal to 1
bool isLower(char ch) { return ((ch >> 5 & 1) == 1); }
char toLower(char ch) { return (ch | (1 << 5)); }
char toUpper(char ch) { return (ch & (~(1 << 5))); }
bool isUpper(char ch) { return (ch >> 5 & 1) == 0; }
int clearLSB(const int &n, const int &i) {
  /*
   * Given 111011
   * we wish to clear LSB until 4th
   * we picked 1
   * moved to 5th place
   * 10000
   * 10000 being power of 2
   * minus 1 -> 1111
   * or 00001111
   * negate it
   * 11110000
   * and take the &
   */
  return (n & (~((1 << (i + 1)) - 1)));
}

