#include <iostream>
#include <vector>
#include <metis.h>

int main() {
    // Define the mesh parameters
    int numVertices = 8; // Number of vertices in the mesh
    int numEdges = 16; // Number of edges in the mesh
    int numPartitions = 2; // Desired number of partitions

    // Define the adjacency information for the mesh
    std::vector<int> vtxPtr = {0, 2, 5, 8, 11, 14, 16, 18, 20};
    std::vector<int> adjList = {1, 4, 0, 2, 5, 1, 3, 6, 2, 4, 7, 3, 5, 8, 0, 4, 1, 3, 6, 2, 5, 7, 3, 6, 4, 8, 5, 7, 9, 6, 8, 7};

    // Create arrays to store the partitioning results
    std::vector<int> partition(numVertices);

    // Set up the METIS options
    idx_t nVertices = static_cast<idx_t>(numVertices);
    idx_t nEdges = static_cast<idx_t>(numEdges);
    idx_t nParts = static_cast<idx_t>(numPartitions);
    idx_t objval; // To store the edge-cut metric

    // Call METIS to perform the graph partitioning
    METIS_PartGraphKway(&nVertices, &nEdges, vtxPtr.data(), adjList.data(), nullptr, nullptr, nullptr,
                        &nParts, nullptr, nullptr, nullptr, &objval, partition.data());

    // Print the partitioning results
    std::cout << "Vertex\tPartition\n";
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << "\t" << partition[i] << "\n";
    }

    return 0;
}