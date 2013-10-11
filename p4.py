def is_palindrome(n):
  number_string = str(n)
  reverse = number_string[::-1]
  return number_string == reverse

print max([n1*n2 for n1 in xrange(100,999) for n2 in xrange(100, 999) if is_palindrome(n1*n2)])
