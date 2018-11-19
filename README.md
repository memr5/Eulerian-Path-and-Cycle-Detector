# EULERIAN PATH & CYCLE DETECTION

**THEORY**

An Euler path, in a graph or multigraph, is a walk through the graph which uses every edge exactly once. It starts and ends at different vertices.
Suppose that a graph has an Euler path P. For every vertex v other than the starting and ending vertices, the path P enters v the same number of times that it leaves v (say n times). Therefore, there are 2n edges having v as an endpoint. 
Therefore, all vertices other than the two endpoints of P must be even vertices. Therefore, if a graph G has an Euler path, then it must have exactly two odd vertices.
![theory1](https://user-images.githubusercontent.com/35303672/48727417-28c3d500-ec58-11e8-9715-33b168a50b7c.png)


An Euler circuit is a circuit that uses every edge of a graph exactly once. It starts and ends at the same vertex.
Suppose that a graph G has an Euler circuit C. For every vertex v in G, each edge having v as an endpoint shows up exactly once in C. The circuit C enters v the same number of times that it leaves v (say n times), so v has degree 2n. That is, v must be an even vertex. 
Therefore, if a graph G has an Euler circuit, then all of its vertices must be even vertices.


![theory2](https://user-images.githubusercontent.com/35303672/48727444-3da06880-ec58-11e8-9df5-821c5c1e3b1c.png)



***














EXAMPLE 1

GRAPH:
![cycle](https://user-images.githubusercontent.com/35303672/48727461-47c26700-ec58-11e8-801f-d78aa5de4943.png)
                                          
All vertices of non-zero degree in graph-1 are “Connected” & total number of vertices with odd degrees are “Zero” hence the given graph-1 is “Eulerian Cycle”.
3 -> 1 -> 2 -> 4 -> 3

Similar for the graph-2 all the vertices with non-zero degrees are connected and vertices with odd degrees are “Zero” hence graph-2 is also    “Eulerian Cycle”.
2 -> 1 -> 3 -> 4 -> 5 -> 6 -> 3 -> 2



***


EXAMPLE 2

GRAPH:

<img width="316" alt="path" src="https://user-images.githubusercontent.com/35303672/48727493-5c9efa80-ec58-11e8-8505-c999840fc344.png">


All the vertices with non-zero degrees are connected and total number of vertices with odd degrees are “Two” hence the graph is “Eulerian Path”
Path: 
4 -> 3 -> 0 -> 1 -> 2 -> 0



***

ALGORITHM

BASIC IDEA

Eulerian or Eulerian Cycle

•	First step is to check if all the Vertices with “Non-Zero” Degree are “Connected” or not  (Vertices with zero degrees doesn`t belong to Eulerian Cycle)

•	Second step is to count the number of vertices with “ODD” degree. If the count is “Zero” then the graph is “EULERIAN OR EULERIAN CYCLE”.

Semi-Eulerian or Eulerian Path

•	First step is similar to Eulerian.

•	Second step is to count the number of vertices with “ODD” degree. If the count is “Two” then the graph is “SEMI-EULERIAN OR EULERIAN PATH”.


***



EXPLAINATION

![explaination](https://user-images.githubusercontent.com/35303672/48727227-aaffc980-ec57-11e8-935a-bd95b19a0fa7.jpg)

INPUT
1.	Number of Vertices (4)
2.	Edges (Ex. 1  2)


STEP BY STEP EXPLAINATION OF CODE
1.	Creating Adjacency list of all vertices in graph.
(Ex. Head[1]- > 2 -> 4 
         Head[2]-> 1 -> 4 -> 3
         Head[3]-> 2 -> 4
         Head[4]-> 1 -> 2 -> 3 )

2.	Finding first vertex with “Non-Zero” to start traversal. (Here 1 is first non-zero degree vertex)
(To Visit every Vertex which is connected to this Vertex, by this we can check if all vertices with non-zero degree are connected or not)
(Corner Case: If graph does not contain any edges in it then it will be “Eulerian”-Because there are no edges to traverse)

3.	After traversing through graph, check if all vertices with non-zero degree are visited.
If not then the given graph will not be “Eulerian or Semi-Eulerian” And Code will end here. (Here in given example all vertices with non-zero degree are visited hence moving further).

4.	After passing step 3 correctly -> Counting vertices with “ODD” degree.
If count is “ZERO” then the graph is “Eulerian or Eulerian Cycle”.
If count is “TWO” then the graph is “Semi-Eulerian or Eulerian Path” .
If count is “More than Two” then the graph is “Not-Eulerian”.


OUTPUT

For the given Example output will be -> “Eulerian Path” (Odd degree vertices are two 2&4).



