# Kruskal's Algorithm

<p align="justify">
The Kruskal’s algorithm finds minimum spanning tree (MST) of an undirected weighted graph.
Kruskal’s algorithm can find minimum spanning forest (spanning tree of each component) of a
disconnected graph in a single run as compare to Prim’s algorithm which requires a separate run
for each component of a disconnected graph. Kruskal’s algorithm belongs to a special category of 
algorithms called greedy algorithms.

Algorithm has $O(E \space log \space V)$ time complexity and $O(E + V)$ space complexity, assuming Union-Find data structure 
is used to detect the cycles. Here $E$ is number of edges $|E|$ and $V$ is number of vertices $|V|$.
</p>

## Tutorial Document

<p align="justify">
Tutorial document 
<a href="https://github.com/vikasawadhiya/Kruskal-Algorithm/blob/main/Kruskal’sAlgorithm.pdf">Kruskal’sAlgorithm.pdf</a> 
explains algorithm in detail. The tutorial document begins with introduction then explains few graph-theory concepts required
to understand for Kruskal's algorithm. Document lists all steps of algorithm and then considers an undirected simple weighted 
graph to explain these steps.

The tutorial document then explains time and space complexities of Kruskal’s algorithm. It also discusses about the directed 
graph constraint and why Kruskal’s algorithm doesn’t work with a directed graph.

This document doesn't require any programming background to understand.
</p>

## Usage

<p align="justify">
Implementation can be used to find minimum spanning tree of a graph by passing it to <code>graphLibrary::kruskalAlgorithm</code> 
function.
</p>

#### Graph Initialization

<p align="justify">
It is a simple undirected weighted graph with three vertices and it can be considered as a triangle where 
three corners of the triangle represent three vertices. The left side of the triangle has one vertex and it is labeled 
as vertex 0 and the opposite side of it there are two vertices labeled 1 and 2 in clockwise direction respectively.
</p>

```cpp
std::vector< std::vector< std::pair<std::size_t, std::size_t> > >  graph { { {1, 1}, {2, 2} }, 
																		   { {0, 1}, {2, 1} },
																		   { {0, 2}, {1, 1} } };
```

<p align="justify">
An edge is represented by a <code>std::pair&lt;std::size_t, std::ptrdiff_t&gt;</code> here <code>std::size_t</code> represents the vertex 
and <code>std::ptrdiff_t</code> represents the weight.
</p>

#### Function Invocation

```cpp
vector< vector< pair<size_t, ptrdiff_t> > > minimumSpanningTree = graphLibrary::kruskalAlgorithm(graph);
```
<p align="justify">
It return minimum spanning tree as an acyclic graph.
</p>

## Example

<p align="justify">
A simple undirected weighted graph as shown in figure below on the left and minimum spanning tree of graph is 
shown in fig below on the right.
</p>

<p align="center">
<img src="https://github.com/vikasawadhiya/Kruskal-Algorithm/blob/main/graphAndMST.svg" alt="Graph and Minimum spanning tree.">
</p>

## License

The code is licensed under the [MIT License](https://github.com/vikasawadhiya/Kruskal-Algorithm/blob/main/LICENSE).</br>
The tutorial document [Kruskal’sAlgorithm.pdf](https://github.com/vikasawadhiya/Kruskal-Algorithm/blob/main/Kruskal’sAlgorithm.pdf) and 
[graphAndMST.svg](https://github.com/vikasawadhiya/Kruskal-Algorithm/blob/main/graphAndMST.svg) 
are licensed under the [CC-BY 4.0](https://creativecommons.org/licenses/by/4.0/).