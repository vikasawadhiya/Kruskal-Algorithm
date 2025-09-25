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

#ifndef DISJOINT_SET
#define DISJOINT_SET

#include <vector>

namespace graphLibrary {

	/// @brief Implements Union-Find / Disjoint-Set data structure.
	/// It is rank based implementation assumes that the number of elements are know in advance.
	/// 
	class DisjointSet {

		mutable std::vector<std::size_t> parent;
		mutable std::vector<std::size_t> rank;

	public:
		/// @brief Parameterized constructor 
		/// @param elementCount It represents initial number of sets or the total possible elements.
		/// 
		explicit DisjointSet(std::size_t elementCount);

		/// @brief Perfomrs union or set merge of two sets.
		/// @param element1 It may be the representative element of a set or any element belong to a set.
		/// @param element2 It may be the representative element of a set or any element belong to a set.
		/// @return True if merge operation succeed.
		/// 
		bool merge(std::size_t element1, std::size_t element2);

		/// @brief Find the set an elements belongs to.
		/// @param element Represents an element and disjoint-set finds the set it belongs to.
		/// @return Representative element or root element of a set the element passed as parameter belongs to.
		/// 
		std::size_t find(std::size_t element) const;
	};
}

#endif // !DISJOINT_SET

