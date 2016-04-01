#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
Following structures could very well be used to create a tree, but considering that adding new edges can destroy
the structure I decided to build something, that resembles a usual directed graph

Also, from specifics of the task, I won't do destructors this time
*/

class edge
{
public:
	int value;
	int from_id;
	int to_id;

	edge(int input_value, int input_from_id, int input_to_id): value(input_value), from_id(input_from_id), to_id(input_to_id){};
};

class graph_node
{
public:
	int node_id;

	int value;		//for generality, but here is not needed, still used
	vector<edge> adjacent_edges;

	graph_node(int input_node_id, int input_value): node_id(input_node_id), value(input_value){};

	vector<edge> outgoing_edges() //neded here
	{
		vector<edge> result;
		for (int i = 0; i < adjacent_edges.size(); i++)
			if (adjacent_edges[i].from_id == this->node_id)
				result.push_back(adjacent_edges[i]);
		return result;
	}
};

class d_graph
{
public:
	int d_graph_id;

	vector<graph_node> nodes;
	//vector<edge> all_edges; Outlining the possibilities

	d_graph(int input_d_graph_id): d_graph_id(input_d_graph_id){}

	void add_node(int input_value)
	{
		nodes.push_back(graph_node(nodes.size(), input_value));
	}

	void add_edge(int from_id, int to_id, int input_value)	//Working not for consumer
	{
		nodes[from_id].adjacent_edges.push_back(edge(input_value, from_id, to_id));
		nodes[to_id].adjacent_edges.push_back(edge(input_value, from_id, to_id));
	}

	//No deletion
};

void main()
{
	int wait;

	int temp_value;

	d_graph triangle(0);

	ifstream input("data.txt");

	//Initialization of the graph with values from the file

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			input >> temp_value;
			triangle.add_node(temp_value);
		}

		for (int k = 0; k < i; k++)
		{
			triangle.add_edge(i * (i - 1) / 2 + k, i * (i - 1) / 2 + k + i, triangle.nodes[i * (i - 1) / 2 + k + i].value);
			triangle.add_edge(i * (i - 1) / 2 + k, i * (i - 1) / 2 + k + i + 1, triangle.nodes[i * (i - 1) / 2 + k + i + 1].value);
		}
	}

	//Now we have our triangle with all nodes and edges(ideally)
	int max_sum = triangle.nodes[0].value;

	for (int i = 0; i < 14; i++)
		for (int j = 0; j < i + 1; j++)
		{
			if ((triangle.nodes[(i + 1) * i / 2 + j].value + triangle.nodes[(i + 1) * i / 2 + j].outgoing_edges()[0].value) > triangle.nodes[(i + 1) * i / 2 + j + i + 1].value)
			{
				triangle.nodes[(i + 1) * i / 2 + j + i + 1].value = triangle.nodes[(i + 1) * i / 2 + j].value + triangle.nodes[(i + 1) * i / 2 + j].outgoing_edges()[0].value;
				if (max_sum < triangle.nodes[(i + 1) * i / 2 + j + i + 1].value)
					max_sum = triangle.nodes[(i + 1) * i / 2 + j + i + 1].value;
			}

			if ((triangle.nodes[(i + 1) * i / 2 + j].value + triangle.nodes[(i + 1) * i / 2 + j].outgoing_edges()[1].value) > triangle.nodes[(i + 1) * i / 2 + j + i + 2].value)
			{
				triangle.nodes[(i + 1) * i / 2 + j + i + 2].value = triangle.nodes[(i + 1) * i / 2 + j].value + triangle.nodes[(i + 1) * i / 2 + j].outgoing_edges()[1].value;
				if (max_sum < triangle.nodes[(i + 1) * i / 2 + j + i + 2].value)
					max_sum = triangle.nodes[(i + 1) * i / 2 + j + i + 2].value;
			}
		}

	cout << max_sum << '\n';
	cin >> wait;
}