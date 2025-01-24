from collections import deque
 
t = int(input())
 
_ch8x = [-1, -1, -1, 0, 0, 1, 1, 1]
_ch8y = [-1, 0, 1, -1, 1, -1, 0, 1]
 
for i in range(t):
    n = int(input())
    _minemap = [list(input()) for _ in range(n)]
     
    for x in range(n):
        for y in range(n):
            if _minemap[x][y] == '.':
                minecnt = 0
                for c in range(8):
                    cx = x + _ch8x[c]
                    cy = y + _ch8y[c]
                    if (0 <= cx < n) and (0 <= cy < n) and _minemap[cx][cy] == '*':
                        minecnt += 1
                _minemap[x][y] = minecnt
    attempt = 0
    for x in range(n):
        for y in range(n):
            if _minemap[x][y] == 0:
                attempt += 1
                q = [[x, y]]
                q = deque(q)
                 
                 
                while q:
                    nx, ny = q.popleft()
                    if _minemap[nx][ny] == 0:
                        for c in range(8):
                            cx = nx + _ch8x[c]
                            cy = ny + _ch8y[c]
                            if (0 <= cx < n) and (0 <= cy < n) and _minemap[cx][cy] != '*':
                                q.append([cx, cy])
                                # _minemap[cx][cy] = '*'
                    _minemap[nx][ny] = '*'
                     
    for x in range(n):
        for y in range(n):
            if _minemap[x][y] != '*':
                attempt += 1
     
    print(f'#{i+1} {attempt}')