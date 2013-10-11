lines = file("triangle.txt", "r").readlines()
lines = [[int(num) for num in line.split(" ")] for line in lines]
max_vals = lines[-1]
for i in xrange(99, 0, -1):
  for j in xrange(0, i):
    max_vals[j] = lines[i-1][j] + max(max_vals[j], max_vals[j+1])

print max_vals[0]

