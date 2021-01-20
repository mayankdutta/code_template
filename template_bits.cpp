string dec_to_bin (int n) { 
    string binary = std::bitset <8> ( n ).to_string ( ); 
    return binary; 
}

unsigned long bin_to_dec (string s) { 
    unsigned long decimal = std::bitset <8> ( s ).to_ulong ( ); 
    return decimal;
}

unsigned int next_power_of2 (unsigned int v) { 
    //    unsigned int v; // compute the next highest power of 2 of 32-bit v
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v; 
}