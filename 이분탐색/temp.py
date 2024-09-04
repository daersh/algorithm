n = int(input("입력할 구간 개수: "))

# arr의 크기를 적당한 범위로 설정
MAX_RANGE = 1000002  # 최대 범위를 설정합니다. 필요에 맞게 조정하세요.
arr = [0] * (MAX_RANGE)

# 구간 입력
for i in range(n):
    s, e = map(int, input().split())
    arr[s] += 1
    arr[e + 1] -= 1

# 누적 합 계산
for i in range(1, len(arr)):
    arr[i] += arr[i - 1]

# 테스트할 시간 입력
test_time = int(input())
query = list(map(int, input()).split())

# 결과 출력
for i in range(test_time):
    print(arr[query[i]])
