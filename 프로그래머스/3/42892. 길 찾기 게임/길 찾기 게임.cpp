#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using pa = pair<int, int>;

const int inf = -1;


struct Node
{
    Node(Node* cst_p_left = nullptr, Node* cst_p_right = nullptr) : p_left{ cst_p_left }, p_right{ cst_p_right }, x{ inf }, y{inf} {}
    Node* p_left;
    Node* p_right;
    int x;
    int y;
};

void preorder(Node* node, vector<int>& v, const map<pa, int>& m)
{
    cout << m.at({ node->x, node->y }) << " ";
    v.push_back(m.at({ node->x, node->y }));

    if(node->p_left)
    preorder(node->p_left, v, m);

    if(node->p_right)
    preorder(node->p_right, v, m);
}
void postorder(Node* node, vector<int>& v, const map<pa, int>& m)
{
    if(node->p_left)
    postorder(node->p_left, v, m);

    if(node->p_right)
    postorder(node->p_right, v, m);

    cout << m.at({ node->x, node->y }) << " ";
    v.push_back(m.at({ node->x, node->y }));

    delete node;
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    const int node_cnt = nodeinfo.size();

    // 트리로 재편성
    // [i,0] 가로, [i,1] 세로
    
    // unordered_map에서의 pair을 키로 사용 -> 나만의 해시 정의해야함
    // 그래서 그냥 map씀
    // <좌표, idx>
    map<pa, int> my_map;


    int idx = 0;
    for (const auto& v : nodeinfo)
    {
        const int x = v[0];
        const int y = v[1];
        
        my_map[{ x, y }] = ++idx;
    }
    

    // 높이가 높은 것부터 정렬,
    sort(nodeinfo.begin(), nodeinfo.end(), [](const vector<int>& v1, const vector<int>& v2) 
        {
            if (v1[1] != v2[1])
                return v1[1] > v2[1];

            return v1[0] < v2[0];
        });
    

    Node* root_node = new Node;

    root_node->x = nodeinfo[0][0];
    root_node->y = nodeinfo[0][1];
    //root_node ->idx = my_map[{ nodeinfo[0][0], nodeinfo[0][1] }];

    const int root = 0;
    for (int i = 1; i < node_cnt; i++)
    {
        const int x = nodeinfo[i][0];
        const int y = nodeinfo[i][1];

        // 노드 할당
        Node* new_node = new Node;
        new_node->y = y;
        new_node->x = x;

        Node* p_node = root_node;

        while (1)
        {
            // 전이 방향을 결정한다.
            Node* (p_node_dir) = p_node->x > x ? p_node->p_left : p_node->p_right;

            if (p_node_dir == nullptr)
            {
                p_node_dir = new_node;
                break;
            }
            p_node = p_node_dir;
        }

    }
    vector<vector<int>> answer(2);
    
    preorder(root_node, answer[0], my_map);

    cout << "\n\n";
    postorder(root_node, answer[1], my_map);

    return answer;
}

int main()
{

    solution({ {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} });
}