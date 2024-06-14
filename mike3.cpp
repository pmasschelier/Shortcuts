#include <climits>
#include <deque>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> shortcuts(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> shortcuts[i];
  }

  std::vector<int> distances(n + 1, INT_MAX);
  distances[1] = 0;
  std::deque<int> queue;
  queue.push_back(1);

  while (!queue.empty()) {
    int node = queue.front();
    queue.pop_front();

    if (distances[node] + 1 < distances[shortcuts[node]]) {
      distances[shortcuts[node]] = distances[node] + 1;
      queue.push_back(shortcuts[node]);
    }
    if (node + 1 <= n && distances[node] + 1 < distances[node + 1]) {
      distances[node + 1] = distances[node] + 1;
      queue.push_back(node + 1);
    }
    if (node - 1 >= 1 && distances[node] + 1 < distances[node - 1]) {
      distances[node - 1] = distances[node] + 1;
      queue.push_back(node - 1);
    }
  }

  for (int i = 1; i <= n; i++) {
    std::cout << distances[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
