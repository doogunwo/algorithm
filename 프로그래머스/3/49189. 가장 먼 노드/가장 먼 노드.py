from collections import deque

def bfs(graph, start):
    visited = set()
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    queue = deque([start])

    while queue:
        current_node = queue.popleft()
        if current_node not in visited:
            visited.add(current_node)
            for neighbor in graph[current_node]:
                if distances[current_node] + 1 < distances[neighbor]:
                    distances[neighbor] = distances[current_node] + 1
                    queue.append(neighbor)

    return distances

def solution(n, edge):
    # 그래프 생성
    graph = {node: [] for node in range(1, n + 1)}
    for edge_info in edge:
        graph[edge_info[0]].append(edge_info[1])
        graph[edge_info[1]].append(edge_info[0])

    # BFS를 사용하여 각 노드까지의 최단 경로 길이 계산
    distances = bfs(graph, 1)

    # 가장 먼 노드 찾기
    max_distance = max(distances.values())
    farthest_nodes = [node for node, distance in distances.items() if distance == max_distance]

    answer = len(farthest_nodes)
    return answer