//uva 280
//Vertex

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector <vector <int> > & graph, bool * visited, int starting_vertex);

int main(void)
{
	int n = 0;
	while (1) {
		cin >> n;

		if (n == 0)
			break;

		vector < vector <int> > graph(n + 1);

		while (1) {
			int vertex1;
			cin >> vertex1;

			if (vertex1 == 0)
				break;

			while(1){
				int vertex2;
				cin >> vertex2;

				if (vertex2 == 0)
					break;

				graph[vertex1].push_back(vertex2);
			}
		}

		int count = 0;
		cin >> count;
		for (int i = 0; i < count; ++i) {
			int starting_vertex;
			cin >> starting_vertex;

			bool * visited = new bool[n + 1]();
			BFS(graph, visited, starting_vertex);


			int counter = 0;
			for (int i = 1; i < n + 1; ++i)
				if (!visited[i])
					++counter;

			cout << counter;

			for (int i = 1; i < n + 1; ++i)
				if (!visited[i])
					cout << ' ' << i;

			cout << endl;


			delete[] visited;
			visited = nullptr;
		}

	}
	return 0;
}

void BFS(vector <vector <int> > & graph, bool * visited, int starting_vertex)
{
	queue <int> Queue;
	Queue.push(starting_vertex);

	while (!Queue.empty()) {
		int front_vertex = Queue.front();
		Queue.pop();

		for (auto a : graph[front_vertex])
			if (!visited[a]){
				Queue.push(a);
				visited[a] = 1;
			}
	}

	return;
}
