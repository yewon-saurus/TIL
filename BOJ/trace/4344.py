c = int(input())

for _ in range(c) :
  data = list(map(int, input().split()))
  avg = sum(data[1:]) / data[0]
  count = 0

  for i in range(1, len(data)) :
    if data[i] > avg :
      count += 1

  result = count / data[0] * 100
  print('%.3f'% result+'%')