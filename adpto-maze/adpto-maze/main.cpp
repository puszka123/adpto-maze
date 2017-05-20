#include "DFS.h"
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

//char** maze; todo
int height = 10;
int width = 20;
int mirrorNumber = 9;

int** connections;
int** vertexLocation;
int specialVertices[3];

string maze[10][1] = {
	{"####################"},
	{"      ###          #"},
	{"####  #     *  ### #"},
	{"#  #  #  # #  # ## #"},
	{"#  * #    #   # *# #"},
	{"#  ##      #     # #"},
	{"#     *   ## # #   #"},
	{"# ## ### #  ## ## ##"},
	{"#        #  #   #  #"},
	{"####################"}
};

void initArray(int** &array, int size1, int size2)
{
	array = new int*[size1];
	for (int i = 0; i < size1; i++) array[i] = new int[size2];
	
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			array[i][j] = 0;
		}
	}
}

void setVertexLocation()
{
	int vertex = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < maze[i][0].size(); j++)
		{
			if (maze[i][0][j] != '#')
			{
				vertexLocation[i][j] = vertex++;
			}
			else vertexLocation[i][j] = -1;
		}
	}
}

void setConnections()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (vertexLocation[i][j] == -1) continue;
			int v = vertexLocation[i][j];
			//right
			for (int next = j + 1; next < width && vertexLocation[i][next] != -1; next++)
			{
				int neigh = vertexLocation[i][next];
				connections[v][neigh] = 1;
				connections[neigh][v] = 1;
			}
			//down
			for (int next = i + 1; next < height && vertexLocation[next][j] != -1; next++)
			{
				int neigh = vertexLocation[next][j];
				connections[v][neigh] = 1;
				connections[neigh][v] = 1;
			}
		}
	}
}

int countVert()
{
	int countVertices = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < maze[i][0].size(); j++)
		{
			if (maze[i][0][j] != '#') ++countVertices;
		}
	}
	return countVertices;
}

void printArray(int** array, int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		cout << endl;
		cout <<"vertex: "<<i<< "-------------------------------------------------------------------------------" << endl;
		for (int j = 0; j < size2; j++)
		{
			cout << array[i][j];
		}
	}
}

void main(int argc, char* args[])
{
	//read xD todo

	int countVertices = countVert();
	initArray(connections, countVertices, countVertices);
	initArray(vertexLocation, height, width);
	setVertexLocation();
	setConnections();
	

	

	getchar();
}