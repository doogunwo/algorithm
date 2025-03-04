# 입력
str1 = input().strip()
str2 = input().strip()

# DP 테이블 초기화
len1, len2 = len(str1), len(str2)
dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]

# DP 점화식 적용
for i in range(1, len1 + 1):
    for j in range(1, len2 + 1):
        if str1[i - 1] == str2[j - 1]:  # 같은 문자라면
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:  # 다른 문자라면
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

# 최종 결과 출력
print(dp[len1][len2])
