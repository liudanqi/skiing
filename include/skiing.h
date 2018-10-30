const int m = 10, n = 10;
struct Pos {
	int row;
	int col;
};
class Skiing
{
public:
	void initializer(); //初始化
	int compute_longest_path_by_dfs(int x, int y);  //(x,y)为起始位置,利用dfs计算最长路径
	void compute_longest_path_by_bfs(int x, int y); //(x,y)为起始位置,利用bfs计算最长路径
	int get_dp();
	int BackTrackPath();
private:
	int map[m][n]; //地图
	int dp[m][n];//存储每个位置的最长路径
	int R, C;
	Pos backPathBFS[m][n];
};
