/***********************************************************/
/***      ______  ____  ______                 _         ***/
/***     / ___\ \/ /\ \/ / ___|_ __ __ _ _ __ | |__	     ***/
/***    | |    \  /  \  / |  _| '__/ _` | '_ \| '_ \	 ***/
/***    | |___ /  \  /  \ |_| | | | (_| | |_) | | | |    ***/
/***     \____/_/\_\/_/\_\____|_|  \__,_| .__/|_| |_|    ***/
/***                                    |_|			     ***/
/***********************************************************/
/***     Header-Only C++ Library for Graph			     ***/
/***	 Representation and Algorithms				     ***/
/***********************************************************/
/***     Author: ZigRazor			     			     ***/
/***	 E-Mail: zigrazor@gmail.com 				     ***/
/***********************************************************/
/***	 Collaboration: ----------- 				     ***/
/***********************************************************/
/***	 License: AGPL v3.0							     ***/
/***********************************************************/

#ifndef __PARTITIONINGSTATS_H__
#define __PARTITIONINGSTATS_H__

#include <iostream>
#include "Utility/Typedef.hpp"
namespace CXXGRAPH
{
    namespace PARTITIONING
    {
        class PartitioningStats
        {
        public:
            unsigned int numberOfPartitions;   // The number of Partitions
            unsigned int numberOfNodes;        // The number of Nodes
            unsigned int replicatedNodesCount; // The number of Nodes that are replicated
            unsigned int numberOfEdges;        // The number of edges
            unsigned int replicatedEdgesCount; // The number of edges that are replicated
            unsigned int maxEdgesLoad;         // Maximum edges load of the partitions
            unsigned int minEdgesLoad;         // Minimun edges load of the partitions
            unsigned int maxNodesLoad;         // Maximum nodes load of the partitions
            unsigned int minNodesLoad;         // Minimun nodes load of the partitions
            double balanceEdgesFactor;         // The balance edges factor of the partitions (maxEdgesLoad - minEdgesLoad) / (maxEdgesLoad), 0 is the optimal partitioning
            double balanceNodesFactor;         // The balance edges factor of the partitions (maxNodesLoad - minNodesLoad) / (maxNodesLoad), 0 is the optimal partitioning
            double nodesReplicationFactor;     // The replication factor of the Nodes (replicatedNodesCount / numberOfNodes), 1 is the optimal partitioning
            double edgesReplicationFactor;     // The replication factor of the edges (replicatedEdgesCount / numberOfEdges), 1 is the optimal partitioning

            friend std::ostream &operator<<(std::ostream &os, const PartitioningStats &partitionStats)
            {
                os << "Partitioning Stats:\n";
                os << "\tNumber of Partitions: " << partitionStats.numberOfPartitions << "\n";
                os << "\tNumber of Nodes: " << partitionStats.numberOfNodes << "\n";
                os << "\tNumber of Edges: " << partitionStats.numberOfEdges << "\n";
                os << "\tNumber of Nodes Replica: " << partitionStats.replicatedNodesCount << "\n";
                os << "\tNumber of Edges Replica: " << partitionStats.replicatedEdgesCount << "\n";
                os << "\tNodes Replication Factor: " << partitionStats.nodesReplicationFactor << "\n";
                os << "\tEdges Replication Factor: " << partitionStats.edgesReplicationFactor << "\n";
                os << "\tMax Edges Load: " << partitionStats.maxEdgesLoad << "\n";
                os << "\tMin Edges Load: " << partitionStats.minEdgesLoad << "\n";
                os << "\tBalance Edges Factor: " << partitionStats.balanceEdgesFactor << "\n";
                os << "\tMax Nodes Load: " << partitionStats.maxNodesLoad << "\n";
                os << "\tMin Nodes Load: " << partitionStats.minNodesLoad << "\n";
                os << "\tBalance Nodes Factor: " << partitionStats.balanceNodesFactor << "\n";
                return os;
            }
        };
    }

}

#endif // __PARTITIONINGSTATS_H__