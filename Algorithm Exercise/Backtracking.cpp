#include <iostream>
#include <vector>
using namespace std;

typedef int element;

vector <int> tree;
// left node = index *2
// right node = index *2 +1

vector<bool> useless;
// not valid node -> true

int N;
int maxLength;
int length = 2;		// Default sequence length

void dfs(int cur) {

	// total repeat
	int start_index = 1;
	pair<int, int> subSequence = { 0,0 };

	// data save
	subSequence.first += tree[start_index] * pow(10, length-1);

	// left traversal
	dfs();

	// right traversal





	//visited[cur] = true;
	cout << cur << ' ';
	for (int i = 0; i < tree[cur].size(); i++) {
		int there = tree[cur][i];
		if (visited[there]) continue;
		dfs(there);
	}
}


// cur == index
void makeTree(int cur)
{
	// child node's index
	int left, right;

	left = cur * 2;
	right = cur * 2 + 1;

	if (left >= tree.size())
		return;

	if (tree[cur] == 1)
	{
		tree[left] = 2;
		tree[right] = 3;
	}

	else if (tree[cur] == 2)
	{
		tree[left] = 1;
		tree[right] = 3;
	}

	else
	{
		tree[left] = 1;
		tree[right] = 2;
	}
	
	makeTree(left);
	makeTree(right);

}

int main() {

	// Init
	cin >> N;

	if (N = 1)
	{
		cout << 1;
		return;
	}

	tree.resize(pow(2,N));
	useless.resize(pow(2, N));

	tree[1] = 1;
	makeTree(1);
	maxLength = N / 2;
	
	
	//cout << tree.size() << endl;	

	/*for (int i = 1, level = 1; i < tree.size(); i++)
	{
		cout << tree[i] << " ";
		if (i % 2 == 1 && i + 1 == pow(2, level))
		{
			cout << endl;
			level++;
		}
	}*/

	cout << endl;
	

	//dfs(1);
}