# 문제 사이트
BAEKJOON ONLINE JUDGE


# 문제 요약
1. 문제 난이도 : SILVER 1
2. 알고리즘 분류 : DP
3. 문제 내용 : 위 열의 행과 겹치지 않는 행들의 합 구하기

# 구현 로직
1. 고르는 경우에서 결국 마지막에도 R, G, B 중 하나를 골랐어야 했으므로 R, G, B를 저장할 변수 사용 (R - 마지막으로 R 고른 경우, G/B도 동일)
2. 첫 입력은 바로 R, G, B에 저장해주고, 다음 입력부터 입력받는 R, G, B인 SR, SG, SB에 대해 다음과 같은 논리 적용
- SR은 R을 고른 경우로 가정. 이전까지의 합 R, G, B 중 중복을 피하는 G, B 중 더 작은 값을 SR에 더해줌
- SG, SB의 경우도 동일
- SR, SG, SB를 다시 R, G, B에 저장.

# 고찰
- 백트래킹이나 DFS로 풀 수도 있었을듯 !! (아직 잘 모름ㅋㅋ)