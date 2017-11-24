#include <iostream>
#include <fstream>
using namespace std;
ifstream in;
int count=0;
int count2=0;
char test[100];
char test2[100];
class Tree{
	private:
		struct Node{
			char value;
			char sign;
			Node* left;
			Node* right;
			Node(char a=0, char b=0):sign(b),value(a),left(NULL),right(NULL){
			}
		};
		Node* root;
	public:
		Tree():root(NULL){
		}
		void Build_Tree(Node* &temp, char value){
			if(temp==NULL) temp=new Node(value);
			else{
				if(value>temp->value) Build_Tree(temp->right, value);
				else Build_Tree(temp->left, value);
			}
		}
		void Build_Tree_file(Node* &temp, char sign, char value){
			if(temp==NULL) temp=new Node(value, sign);
			else{
				if(sign>temp->sign) Build_Tree_file(temp->right, sign, value);
				else Build_Tree_file(temp->left, sign, value);
			}
		}
		void build(char value){
			Build_Tree(root, value);
		}
		void build_file(char sign, char value){
			Build_Tree_file(root, sign, value);
		}
		void inorder(Node* temp){
			if(temp!=NULL){
				inorder(temp->left);
				test[count2++]=temp->value;
				inorder(temp->right);
			}
		}
		void preorder(Node* temp){
			if(temp!=NULL){
				cout<<temp->value<<" ";
				test2[count++]=temp->value;
				preorder(temp->left);
				preorder(temp->right);
			}
		}
		void outorder(Node* temp){
			if(temp!=NULL){
				outorder(temp->left);
				outorder(temp->right);
				cout<<temp->value<<" ";
			}
		}
		void store(){
			inorder(root);
		}
		void show(){
			preorder(root);
			cout<<endl;
		}
		void show2(){
			outorder(root);
			cout<<endl;
		}
};
int main(){
	Tree T1;
	for(int i=0; i<6; i++){
		char p=0;
		cin>>p;
		T1.build(p);
	}
	ofstream out;
	out.open("text.txt", ios::out|ios::trunc);
	ofstream out2;
	out2.open("text2.txt", ios::out|ios::trunc);
	T1.store();
	T1.show();
	for(int i=0; i<count; i++){
		out<<test2[i]<<" ";
		for(int j=0; j<count2; j++){
			if(test[j]==test2[i]) out2<<j<<" ";
		}
	}
	out.close();
	out2.close();
	char in1[100];
	char in2[100];
	int count3=0;
	int count4=0;
	ifstream in;
	in.open("text.txt", ios::in);
	ifstream in5;
	in5.open("text2.txt", ios::in);
	while(!in.eof()){
		in>>in1[count3++];
	}
	while(!in5.eof()){
		in5>>in2[count4++];
	}
	for(int i=0; i<count3-1; i++){
		cout<<in1[i]<<" "<<in2[i]<<endl;
	}
	in.close();
	in5.close();
	Tree n;
	for(int i=0; i<count3-1; i++){
		n.build_file(in2[i], in1[i]);
	}
	n.show2();
}
