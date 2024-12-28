from itertools import combinations as c
t = int(input())
for j in range(t):
    n, b = map(int, input().split())
    _list = list(map(int, input().split()))
     
    _diff = b
     
    for i in range(n):
        _listall = list(c(_list, i+1))
        for l in _listall:
            _sum = sum(l)
            if (0 <= _sum - b < _diff):
                _diff = _sum - b
    print(f'#{j+1} {_diff}')