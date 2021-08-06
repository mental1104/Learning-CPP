decltype(odd)& arrPtr(int i){
    return (i%2)? &odd : &even;
}

auto arrPtr(int i) -> int &[10];
