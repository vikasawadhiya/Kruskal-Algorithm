/*********************************************************************************
** MIT License
**
** Copyright (c) 2025 Vikas Awadhiya
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:

** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.

** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
*********************************************************************************/

#include "kruskal_algorithm.hpp"
#include "disjoint_set.hpp"

#include <tuple>
#include <algorithm>

using namespace std;

namespace graphLibrary{

	namespace {

		/// @brief It is a custom function used in std::sort to sort the edges in ascending order.
		/// @param edge1 It represents an edge where both std::size_t represents vertices of the edge and std::ptrdiff 
		/// represents the weight of the edge.
		/// 
		/// @param edge2 It represents another edge.
		/// @return True if weight of edge1 is small than the weight of edge2.
		/// 
		bool edgesLessThanComparator(const tuple<size_t, size_t, ptrdiff_t>& edge1, 
									 const tuple<size_t, size_t, ptrdiff_t>& edge2) {

			return get<2>(edge1) < get<2>(edge2);
		}

		/// @brief The edges represented in adjacency-list form of a graph can't be used directly to sort.
		/// In undirected graph an edge has two entries, so if there is an edge from vertices u to v then 
		/// undirected graph has entries of it adjacency-list of both vertices.
		/// 
		/// This function creates an unique entry of an edge as a tuple contains {u, v, w} where u and v 
		/// are vertices and w is weight of the edge.
		/// 
		/// @param graph It represents a graph of which the edges are required.
		/// 
		/// @return It returns all edges of the graph passed as a parameter.
		/// 
		vector< tuple<size_t, size_t, ptrdiff_t> > edges(const vector< vector< pair<size_t, ptrdiff_t> > >& graph) {

			vector< tuple<size_t, size_t, ptrdiff_t> > allEdges;

			for (size_t i = 0; i < graph.size(); ++i) {

				for (const pair<size_t, ptrdiff_t>& edge : graph[i]) {

					if (i < edge.first) {

						allEdges.emplace_back(i, edge.first, edge.second);
					}
				}
			}

			return allEdges;
		}
	}

	vector< vector< pair<size_t, ptrdiff_t> > > kruskalAlgorithm(const vector< vector< pair<size_t, ptrdiff_t> > >& graph) {

		vector< tuple<size_t, size_t, ptrdiff_t> > allEdges = edges(graph);

		sort(allEdges.begin(), allEdges.end(), edgesLessThanComparator);

		DisjointSet unionFind( graph.size() );

		size_t u;
		size_t v;
		ptrdiff_t w;

		vector< vector< pair<size_t, ptrdiff_t> > > miniumSpanningTree( graph.size() );
		
		for (auto it = allEdges.cbegin(); allEdges.cend() != it; ++it) {

			std::tie(u, v, w) = *it;

			if ( unionFind.merge(u, v) ) {

				miniumSpanningTree[u].emplace_back(v, w);
			}
		}

		return miniumSpanningTree;
	}
}
