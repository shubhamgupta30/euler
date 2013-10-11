print sum([int(n) for n in file("primes1M.txt", "r").readlines() if int(n) < 2000000])
