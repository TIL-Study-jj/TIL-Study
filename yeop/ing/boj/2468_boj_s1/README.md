# 문제 사이트
BAEKJOON ONLINE JUDGE


# 문제 요약
1. 문제 난이도 : SILVER 1
2. 알고리즘 분류 : BFS, 완전탐색(Brute Force)
3. 문제 내용 : 변화하는 조건에 따른 영역의 개수 찾기

# 구현 로직
1. 입력 받으며 반복 조건(최소 높이, 최대 높이) 찾기
2. BFS를 통해 영역의 개수 찾아 vector에 넣기
3. sorting 후 가장 큰 영역의 개수 찾기

# 고찰
- 2차원 boolean 배열 초기화는 memset !! memo ..
- vector sorting 말고 priority queue 사용해봐도 됐을듯 ?? (아님말고)