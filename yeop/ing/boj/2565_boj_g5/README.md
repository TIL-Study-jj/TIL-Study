# 문제 사이트
BAEKJOON ONLINE JUDGE

# 문제 요약
1. 문제 난이도 : GOLD 5
2. 알고리즘 분류 : DP
3. 문제 내용 : 주어진 pair대로 이었을 때, 선이 겹치지 않도록 하기 위해 제거해야 하는 선 수 찾기

# 구현 로직
1. 선들을 pair로 받아 first를 기준으로 정렬해주고, second에 대해 LIS를 구한다.

# 고찰
- NlogN LIS도 공부해야되는데