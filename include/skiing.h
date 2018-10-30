const int m = 10, n = 10;
struct Pos {
	int row;
	int col;
};
class Skiing
{
public:
	void initializer(); //��ʼ��
	int compute_longest_path_by_dfs(int x, int y);  //(x,y)Ϊ��ʼλ��,����dfs�����·��
	void compute_longest_path_by_bfs(int x, int y); //(x,y)Ϊ��ʼλ��,����bfs�����·��
	int get_dp();
	int BackTrackPath();
private:
	int map[m][n]; //��ͼ
	int dp[m][n];//�洢ÿ��λ�õ��·��
	int R, C;
	Pos backPathBFS[m][n];
};
