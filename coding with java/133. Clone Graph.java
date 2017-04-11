/*
@ APR 11 2017
@ by Xin Liu
*/

/************Description of the problem************/
/* 133. Clone Graph
*
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

*/


/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
       //cause label is unique.
       HashMap<Integer, UndirectedGraphNode> visited = new HashMap<Integer, UndirectedGraphNode>();
       Queue<UndirectedGraphNode> q = new LinkedList<UndirectedGraphNode>();
        //= new UndirectedGraphNode(node.label);
       q.add(node);
       if(node == null) return node;
       visited.put(node.label, new UndirectedGraphNode(node.label));
       while(!q.isEmpty() /*q.size() >0*/){
           UndirectedGraphNode head = q.poll();
           for(int i=0; i<head.neighbors.size(); i++){
               if(!visited.containsKey(head.neighbors.get(i).label)){
                   q.add(head.neighbors.get(i));
                   visited.put(head.neighbors.get(i).label, new UndirectedGraphNode(head.neighbors.get(i).label));
               }
               visited.get(head.label).neighbors.add( visited.get(head.neighbors.get(i).label));
           }
       }
       
       return visited.get(node.label);
    }
}