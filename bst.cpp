#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

Node* insertBst(Node* root,int val){
	
	if(!root) return new Node(val);
	
	if(val<root->data){
		root->left = insertBst(root->left,val);
	}else{
		root->right = insertBst(root->right,val);
	}
	
	
	return root;
}

void inorder(Node* root){
	
	if(!root) return;
	
	inorder(root->left);
	
	cout<<root->data<<" ";
	
	inorder(root->right);
	
}

Node* searchBst(Node* root,int key){
	if(!root) return root;
	
	if(root->data==key) return root;
	
	if(key<root->data) return searchBst(root->left,key);
	
	return searchBst(root->right,key);
}

Node* inordersucc(Node* root){
	Node* curr = root;
	
	while(curr and curr->left) curr=curr->left;
	
	return curr;
}


Node* deleteBst(Node* root,int key){
	if(!root) return root;
	
	if(key<root->data){
		root->left = deleteBst(root->left,key);
	}
	else if(key>root->data){
		root->right = deleteBst(root->right,key);
	}
	else{
		if(!root->left){
			Node* temp = root->right;
			free(root);
			return temp;
		}
		
		if(!root->right){
			Node* temp = root->left;
			free(root);
			return temp;
		}
		
		Node *temp = inordersucc(root->right);
		root->data = temp->data;
		
		root->right = deleteBst(root->right,temp->data);
	
	}
	
	return root;
}

 Node* util(vector<int>preorder,int &idx,int key,int min,int max,int n){
         if(idx>=n) return nullptr;
        Node *root = nullptr;
        
        if(key>min and key<max){
            
            root = new Node(key);
            
            idx++;
            
            if(idx<n){
                root->left = util(preorder,idx,preorder[idx],min,key,n);
            }
            
            if(idx<n) root->right = util(preorder,idx,preorder[idx],key,max,n);
            
            
        }
       
        
        return root;
        
        
    }
    
    
    
    
    Node* bstFromPreorder(vector<int>& preorder) {
        
        int idx =0;
        int n =preorder.size();
        
        return util(preorder,idx,preorder[0],INT_MIN,INT_MAX,n);
        
    }
   
   bool checkBst(Node* root,Node* min,Node *max){
        
        if(!root) return true;
        
        if(min and root->data<=min->data) return false;
        
        if(max and root->data>=max->data) return false;
        
        bool l = checkBst(root->left,min,root);
        bool r = checkBst(root->right,root,max);
        
        return l and r;
   } 
    
  
    Node* sortedArrayBst(vector<int> nums,int st,int en){
        
        if(st>en) return nullptr;
        
        int mid = (st+en)/2;
        
        Node* root = new Node(nums[mid]);
        
        root->left = sortedArrayBst(nums,st,mid-1);
        
        root->right = sortedArrayBst(nums,mid+1,en);
        
        return root;
         
        
    }
      
    
  vector<vector<int>> zigzagLevelOrder(Node* root) {
        
        vector<vector<int>> res;
        
        if(!root) return res;
        
        stack<Node*> curr,next;
        
        bool lTor = true;
        
        curr.push(root);
        
        vector<int>ans;
        
        while(!curr.empty()){
            
            Node *temp = curr.top();
            curr.pop();
            
            if(temp){
                
                ans.push_back(temp->data);
                
                if(lTor){
                    
                    if(temp->left){
                        next.push(temp->left);
                    }
                    
                    if(temp->right) next.push(temp->right);
                    
                }
                
                else{
                    
                    if(temp->right) next.push(temp->right);
                    
                    if(temp->left) next.push(temp->left);
                    
                    
                }  
                
                                   
             }
            
            if(curr.empty()){
                res.push_back(ans);
                ans.clear();
                lTor = !lTor;
                swap(curr,next);
            }
            
            
        }
        
         
        
        return res;
        
        
        
    }   
 
  bool isSameTree(Node* p, Node* q) {
        
        if(!p and !q) return true;
        
       
        if( p and q and p->data==q->data){
             bool b = isSameTree(p->left,q->left);
        
             bool c = isSameTree(p->right,q->right);
            
            
             if(b and c) return true;
        }    
               
               
        return false;      
              
                
    }  
    
    
    struct Info{
    int min;
    int max;
    int size;
    int ans;
    bool isbst;
};


Info util(Node* root){
    
    if(!root) return {INT_MAX,INT_MIN,0,0,true};
    
    if(!root->left and !root->right) return {root->data,root->data,1,1,true};
    
    Info leftInfo = util(root->left);
    
    Info rightInfo = util(root->right);
    
     Info curr;
        
        curr.size = 1+leftInfo.size + rightInfo.size;
    
    if(leftInfo.isbst and rightInfo.isbst and root->data>leftInfo.max and root->data<rightInfo.min){
        
       curr.min = min(min(leftInfo.min,rightInfo.min),root->data);
       
       curr.max = max(max(rightInfo.max,leftInfo.max),root->data);
       
       curr.ans = curr.size;
        curr.isbst = true;
        
        return curr;
    }
    
    curr.ans  = max(leftInfo.ans,rightInfo.ans);
    curr.isbst = false;
    
    return curr;
    
}



int largestBst(Node *root)
{
	//Your code here
	return util(root).ans;
}

    

int main() {
	// your code goes here
	
	Node *root = nullptr;
	
	root = insertBst(root,5);
	
	insertBst(root,1);//
	insertBst(root,3);
	insertBst(root,4);
	insertBst(root,2);
	insertBst(root,7);
	
	int preorder[5] = {10,2,1,13,11};
 
	return 0;
}