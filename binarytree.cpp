#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
  Node(int val){
  	data = val;
  	left = nullptr;
  	right = nullptr;
  }
};

int sumAtk(Node *root,int k){
	
	if(!root) return -1;
	
	queue<Node*>q;
	q.push(root);
	q.push(nullptr);
	
	int level=0,sum=0;
	
	while(!q.empty()){
		
		Node* node = q.front();
		q.pop();
		
		if(node){
			
			if(level==k){
				sum+=node->data;
			}
			if(node->left) q.push(node->left);
			
			if(node->right) q.push(node->right);
			
		}
		else if(!q.empty()){
			q.push(nullptr);
			level++;
		}
		
		
	}
	
	return sum;
	
}

int height(Node *root){
	
	if(!root) return 0;
	
	int leftheight = height(root->left);
	int rightheight = height(root->right);
	
	return max(leftheight,rightheight)+1;
	
	
}

int diameter(Node *root){// brute force
	
	if(!root) return 0;
	
	int leftheight = height(root->left);
	int rightheight = height(root->right);
	
	int leftdia = diameter(root->left);
	int rightdia = diameter(root->right);
	
	return max(leftheight+rightheight+1,max(leftdia,rightdia));
}

int dia(Node* root,int &height){ //optimized diameter
	
	if(!root){
		height=0;
		return 0;
	}
	
	int lh=0,rh=0;
	
	int ldia = dia(root->left,lh);
	int rdia = dia(root->right,rh);
	
	int currdia = lh+rh+1;
	
	height = max(lh,rh)+1;
	
	return max(currdia,max(ldia,rdia));
	
}

int countall(Node* root){
	
	if(!root) return 0;
	
	
	
	return countall(root->left)+countall(root->right)+1;
	
	
}

void sumreplacement(Node* root){
	
	if(!root) return;
	
	sumreplacement(root->left);
	sumreplacement(root->right);
	
	if(root->left){
		root->data+= root->left->data;
	}
	
	if(root->right)  root->data+=root->right->data;
}

void preorder(Node *root){
	if(!root) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


int sumall(Node* root){
	
	if(!root) return 0;
	
	
	
	return sumall(root->left)+ sumall(root->right)+root->data;
	
	
}

 vector<int> rightSideView(Node* root) {
        
        vector<int>res;
        
        if(!root) return res;
        
        queue<Node*>q;
        
        q.push(root);
        
        
        while(!q.empty()){
            
            int n = q.size();
            
            for(int i=0;i<n;i++){
                Node* curr = q.front();
                q.pop();
                
                if(i==n-1) res.push_back(curr->data);
                
                if(curr->left) q.push(curr->left);
                
                if(curr->right) q.push(curr->right);
            }
        }
        
        
        
        
        
        return res;
        
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>res;
   
   if(!root) return res;
   
   queue<Node*>q;
   q.push(root);
   
   while(!q.empty()){
       
       int n = q.size();
       
       for(int i=0;i<n;i++){
           
           Node *curr = q.front();
           
           q.pop();
           
           if(i==0) res.push_back(curr->data);
           
           
           if(curr->left) q.push(curr->left);
           
           if(curr->right) q.push(curr->right);
           
       }
       
   }
   
   return res;
   
   
}

 Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        
        
        if(!root) return root;
        
        if(root==p or root==q) return root;
        
        Node *left = lowestCommonAncestor(root->left,p,q);
        
        Node *right = lowestCommonAncestor(root->right,p,q);
        
        if(left and right) return root;
        
        if(left) return left;
        
        return right;
        
    }
    
     Node* Lca(Node* root,int a,int b){
      
      if(!root) return root;
      
      if(root->data==a or root->data==b) return root;
      
      Node* left = Lca(root->left,a,b);
      
      Node* right = Lca(root->right,a,b);
      
      if(left and right) return root;
      
      if(left) return left;
      
      return right;
      
  } 
   
   
   int dist(Node* root,int a,int dis){
       
       if(!root) return -1;
       
       if(root->data==a){
           return dis;
       }
       
       int left = dist(root->left,a,dis+1);
       
       if(left!=-1){
           return left;
       }
       
       return dist(root->right,a,dis+1);
       
   }
   
   
int findDist(Node* root, int a, int b) {
    // Your code here
    if(!root) return 0;
    
    Node* lca = Lca(root,a,b);
    
    int d1 = dist(lca,a,0);
    
    int d2 = dist(lca,b,0);
    
    return d1+d2;
    
    
    
}

void flatten(Node* root) {
        
        if(!root or (!root->right and !root->left)) return;
        
        if(root->left){
            
            flatten(root->left);
            
            Node *temp = root->right;
            
            root->right = root->left;
            
            root->left = nullptr;
            
            Node* t = root->right;
            
            while(t->right) t = t->right;
            
            t->right = temp;
            
        }
        
        
        flatten(root->right);
        
        
        
        
        
    }


 void printSubTreeNodes(Node *root, int k,vector<int> &v1){
      
        
        if(!root or k<0) return ;
        
        if(k==0){
        v1.push_back(root->data);
            return;
        }        
        
        printSubTreeNodes(root->left,k-1,v1);
        
        printSubTreeNodes(root->right,k-1,v1);
        
        
    }
    
    int printNodesAtk(Node *root,Node* target,int k,vector<int> &v2){
        
        if(!root) return -1;
        
        if(root==target){
            printSubTreeNodes(root,k,v2);
            return 0;
        }
        
        int dl = printNodesAtk(root->left,target,k,v2);
        if(dl!=-1){
            if(dl+1==k){
                v2.push_back(root->data);
            }else{
                printSubTreeNodes(root->right,k-dl-2,v2);
            }
            
            return 1+dl;
        }
        
        
        int dr = printNodesAtk(root->right,target,k,v2);
        if(dr!=-1){
            if(dr+1==k){
                v2.push_back(root->data);
            }else{
                printSubTreeNodes(root->left,k-dr-2,v2);
            }
            return 1+dr;
        }
        
       return -1; 
        
    }
    
    
    
    
    vector<int> distanceK(Node* root, Node* target, int k) {
        
        
        vector<int> v1 ;
            printSubTreeNodes(target,k,v1);
        
        
        vector<int> v2;
        
        printNodesAtk(root,target,k,v2); 
        
        
        return v2;        
        
    }
    
    
    int util(Node* root,int &result){
        
        if(!root) return 0;
        
        int left = util(root->left,result);
        
        int right = util(root->right,result);
        
         int ms = max(max(left,right)+root->data,root->data);
        
        int m2 = max(ms,left+right+root->data);
        
        result = max(m2,result);
        
        return ms;
    }
    
    
    
    
    int maxPathSum(Node* root) {
        
        int result = INT_MIN;
        
        util(root,result);
        
        return result;
        
    }


int main() {
	// your code goes here
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right=new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	preorder(root);
	cout<<endl;
	sumreplacement(root);
	preorder(root);
	
	return 0;
}