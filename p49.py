from sets import Set
import itertools

primes = Set([int(l) for l in file("primes10000.txt", "r")])
print list(primes)[:10], len(primes)

f = lambda (x,y,z,w) : 1000*x+100*y+10*z+w
perms = [list(Set([f(p) for p in itertools.permutations([int(d) for d in str(i)]) if f(p) > 1000 and f(p) in primes])) for i in xrange(1000, 10000)]
perms = [sorted(pe) for pe in perms if len(pe) >= 3]

valid = [str(x) + str(y) + str(z) for (x,y,z) in list(Set([(a,b,2*b-a) for p in perms for a in p for b in p if a < b and 2*b-a in p]))]
print valid
