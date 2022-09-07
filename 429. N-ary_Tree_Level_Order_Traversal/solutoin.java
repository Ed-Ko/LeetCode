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
    
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    
    public void traverse(Node root){
        
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        
        int counter = 1;
        while(!q.isEmpty()){
            
            int next_counter = 0;
            List<Integer> cur_vec = new ArrayList<Integer>();
            
            for(int i = 0 ; i < counter ; i++){
                Node cur_node = q.remove();
                
                cur_vec.add(cur_node.val);
                
                for(int j = 0 ; j < cur_node.children.size() ; j++){
                    if(cur_node.children.get(j) != null){
                        q.add(cur_node.children.get(j));
                        next_counter++;
                    }
                }
                
            }
            
            ans.add(cur_vec);
            counter = next_counter;
            
        }
        
        return;
        
    }
    
    public List<List<Integer>> levelOrder(Node root) {
        if(root != null)
            traverse(root);
        return ans;
    }
}