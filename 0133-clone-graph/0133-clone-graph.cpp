/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<Node*,Node*> mp;

    // void dfs(Node*node, Node* cloneNode){

    //     for(Node* v : node->neighbors){
    //         if(mp.find(v) == mp.end()){
    //             Node* clone = new Node(v->val);
    //             cloneNode->neighbors.push_back(clone);
    //             mp[v] = clone;

    //             dfs(v, clone);
    //         }else{
    //             cloneNode->neighbors.push_back(mp[v]);
    //         }
    //     }

    // }
    Node* cloneGraph(Node* node) {

        if(!node){
            return NULL;
        }
        
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;

        queue<Node*> que;
        que.push(node);

        while(!que.empty()){
            Node* og = que.front();
            Node* curClone = mp[og];
            que.pop();

            for(Node* v : og->neighbors){

                if(mp.find(v) == mp.end()){
                    Node* clone = new Node(v->val);
                    curClone->neighbors.push_back(clone);
                    mp[v] = clone;
                    que.push(v);

                }else{
                    curClone->neighbors.push_back(mp[v]);
                }

            }
        }

        return cloneNode;
    }
};