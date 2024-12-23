def tetromino(arr, n, m):
    _tet = []
    for i in range(n):
        for j in range(m):
            # case I
            # 1-1
            # st 0 0 0
            if (0 <= i < n) and (0 <= j < m) and (0 <= i < n) and (0 <= j + 3 < m):
                _tet.append(arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3])
            # 1-2
            # st
            # 0
            # 0
            # 0
            if (0 <= i < n) and (0 <= j < m) and (0 <= i + 3 < n) and (0 <= j < m):
                _tet.append(arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j])
            # case sq
            # 2-1
            # st 0
            # 0  0
            if (0 <= i < n) and (0 <= j < m) and (0 <= i + 1 < n) and (0 <= j + 1 < m):
                _tet.append(arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1])
            # case L
            # 3-1
            # st
            # 0
            # 0 0
            if (0 <= i < n) and (0 <= j < m) and (0 <= i + 2 < n) and (0 <= j + 1 < m):
                _tet.append(arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1])
            # 3-2
            #   st
            #   0
            # 0 0
            if (0 <= i < n) and (0 <= j - 1 < m) and (0 <= i + 2 < n) and (0 <= j < m):
                _tet.append(arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j-1])
            # 3-3
            # 0 0 st
            # 0
            if (0 <= i < n) and (0 <= j - 2 < m) and (0 <= i + 1 < n) and (0 <= j < m):
                _tet.append(arr[i][j] + arr[i][j-1] + arr[i][j-2] + arr[i+1][j-2])
            # 3-4
            # st 0 0
            #      0
            if (0 <= i < n) and (0 <= j < m) and (0 <= i + 1 < n) and (0 <= j + 2 < m):
                _tet.append(arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+2])
            # 3-5
            # st 0
            #    0
            #    0
            if (0 <= i < n) and (0 <= j < m) and (0 <= i + 2 < n) and (0 <= j + 1< m):
                _tet.append(arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1])
            # 3-6
            # 0 st 
            # 0
            # 0
            if (0 <= i < n) and (0 <= j - 1< m) and (0 <= i + 2 < n) and (0 <= j < m):
                _tet.append(arr[i][j] + arr[i][j-1] + arr[i+1][j-1] + arr[i+2][j-1])
            # 3-7
            #     st 
            # 0 0 0
            if (0 <= i < n) and (0 <= j - 2 < m) and (0 <= i + 1 < n) and (0 <= j < m):
                _tet.append(arr[i][j] + arr[i+1][j] + arr[i+1][j-1] + arr[i+1][j-2])
            # 3-8
            # st
            #  0 0 0
            if (0 <= i < n) and (0 <= j < m) and (0 <= i + 1 < n) and (0 <= j + 2 < m):
                _tet.append(arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2])
            # 4-1
            # st
            #  0 0
            #    0
            if (0 <= i < n) and (0 <= j < m) and (0 <= i + 2 < n) and (0 <= j + 1 < m):
                _tet.append(arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1])
            # 4-2
            #   st
            # 0 0
            # 0
            if (0 <= i < n) and (0 <= j - 1 < m) and (0 <= i + 2 < n) and (0 <= j < m):
                _tet.append(arr[i][j] + arr[i+1][j] + arr[i+1][j-1] + arr[i+2][j-1])
            # 4-3
            #    0 0
            # st 0 
            if (0 <= i - 1 < n) and (0 <= j < m) and (0 <= i < n) and (0 <= j + 2 < m):
                _tet.append(arr[i][j] + arr[i][j+1] + arr[i-1][j+1] + arr[i-1][j+2])
            # 4-4
            # st 0
            #    0 0
            if (0 <= i < n) and (0 <= j < m) and (0 <= i + 1 < n) and (0 <= j + 2 < m):
                _tet.append(arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2])
            # 5-1
            #   st 
            # 0 0  0
            if (0 <= i < n) and (0 <= j - 1 < m) and (0 <= i + 1 < n) and (0 <= j + 1 < m):
                _tet.append(arr[i][j] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1])  
            # 5-2
            #    0
            # st 0
            #    0
            if (0 <= i - 1 < n) and (0 <= j < m) and (0 <= i + 1 < n) and (0 <= j + 1 < m):
                _tet.append(arr[i][j] + arr[i-1][j+1] + arr[i][j+1] + arr[i+1][j+1])
            # 5-3
            # 0  0  0
            #    st
            if (0 <= i < n) and (0 <= j - 1 < m) and (0 <= i - 1 < n) and (0 <= j + 1 < m):
                _tet.append(arr[i][j] + arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1])
            # 5-4
            # 0
            # 0 st
            # 0
            if (0 <= i - 1 < n) and (0 <= j - 1 < m) and (0 <= i + 1 < n) and (0 <= j < m):
                _tet.append(arr[i][j] + arr[i-1][j-1] + arr[i][j-1] + arr[i+1][j-1])
              
    return max(_tet)

_n, _m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(_n)]
print(tetromino(a, _n, _m))
