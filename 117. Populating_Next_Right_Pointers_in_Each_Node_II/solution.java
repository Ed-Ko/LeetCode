/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    
    public void BFS(Node root){
        
        Queue<Node> q = new LinkedList<Node>();
        
        if(Objects.isNull(root))
            return;
        
        q.add(root);
        int counter = 1;
        
        while(!q.isEmpty()){
            
            int next_size = 0;
            
            for(int i = 0 ; i < counter ; i++){
                Node cur_node = q.remove();
                
                if(i < counter - 1)
                    cur_node.next = q.peek();
                
                if(!Objects.isNull(cur_node.left)){
                    q.add(cur_node.left);
                    next_size++;
                }
                if(!Objects.isNull(cur_node.right)){
                    q.add(cur_node.right);
                    next_size++;
                }
                    
            }
            
            counter = next_size;
            
        }
        
        return;
        
    }
    
    
    public Node connect(Node root) {
        
        BFS(root);
        
        return root;
    }
}