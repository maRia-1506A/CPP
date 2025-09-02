#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c,int f):ch(c),freq(f),left(NULL),right(NULL){}
};

struct cmp {
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

void printCodes(Node* root,string str){
    if(!root) return;
    if(!root->left && !root->right) cout<<root->ch<<": "<<str<<"\n";
    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}

int main(){
    int n; 
    cout<<"Enter number of chars: ";
    cin>>n;
    vector<char> chars(n);
    vector<int> freq(n);
    cout<<"Enter chars and freq:\n";
    for(int i=0;i<n;i++) cin>>chars[i]>>freq[i];

    priority_queue<Node*,vector<Node*>,cmp> pq;
    for(int i=0;i<n;i++) pq.push(new Node(chars[i],freq[i]));

    while(pq.size()>1){
        Node* left=pq.top(); pq.pop();
        Node* right=pq.top(); pq.pop();
        Node* merged=new Node('$',left->freq+right->freq);
        merged->left=left; merged->right=right;
        pq.push(merged);
    }

    cout<<"Huffman Codes:\n";
    printCodes(pq.top(),"");
}
