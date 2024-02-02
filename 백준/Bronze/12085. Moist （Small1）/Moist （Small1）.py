def calculate_sorting_cost(test_cases):
    results = []
    for index, names in enumerate(test_cases, start=1):
        cost = 0
        for i in range(1, len(names)):
            if names[i] < names[i - 1]:  # If current name is lexicographically smaller
                cost += 1
                names[:i + 1] = sorted(names[:i + 1])  # Sort the sublist to place the current name correctly
        results.append(f"Case #{index}: {cost}")
    return results

# Test cases from the problem statement
test_cases = []


T = int(input())

for i in range(T):

    n= int(input())
    case = [ input() for _ in range(n)]
    test_cases.append(case)


# Calculate sorting cost
results = calculate_sorting_cost(test_cases)

# Print the results
for result in results:
    print(result)
