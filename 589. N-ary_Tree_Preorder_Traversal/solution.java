/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    
    List<Integer> ans = new ArrayList<Integer>();
    
    public void DFS(Node cur_node){
        
        ans.add(cur_node.val);
        
        for(int i = 0 ; i < cur_node.children.size() ; i++){
            if(cur_node.children.get(i) != null)
                DFS(cur_node.children.get(i));
        }
        
        return;   
    }
    
    public List<Integer> preorder(Node root) {
        if(root == null)
            return ans;
        DFS(root);
        return ans;
    }
}