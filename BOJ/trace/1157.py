s = input().upper()
search = list(set(s))

count = []
for key in search:
    count.append(s.count(key))

if count.count(max(count)) > 1:
    print("?")
else:
    print(search[count.index(max(count))])