#include<iostream>

using namespace std;

class Node{
	public:
   	   int data;
   	   Node *next;
   	   Node *prev;
   	   
   	   Node(int data){
   	   	this->data = data;
   	   	next= NULL;
   	   	prev=NULL;
		  }
	
	
};

class DoubleLinkedList{
	private:
		Node *header;
		Node *tail;
		int size;
	
	public:
		DoubleLinkedList(){
			header = NULL;
			tail= NULL;
			size = 0;
		}
		
		int getSize(){
			return size;
		}
		
	    void prepend(int data){
	    	Node *n = new Node(data);
	    	if(header==NULL){
	    		header = n;
	    		tail = n;
	    		
			}else{
				header->prev = n;
				n->next = header;
				header = n;			
				
				
			}
			size++;
		}
		
		void toPrint(){
			
			Node *temp = header;
			
			while(temp !=NULL){
				
				cout<< temp->data << " ";
				temp = temp ->next;
				
			}
			cout<<endl;
		}
		
		void append(int data){
			Node *n = new Node(data);
			if(header==NULL ){
				header =n;
				tail = n;
				
			}
			else{
				tail->next=n;
				n->prev = tail;
				tail = n;
			}
			size++;
		}
		
	void insert(int position, int data){
		
		if(position< 1 || position > size +1){
			return;
		}
		else if(position==1){
			prepend(data);
			
		}
		else if(position ==size+1){
			append(data);
		}
		else if(header!=NULL){
			Node *n = new Node(data);
			Node *cur = header;
			for( int i= 1; i<position; i++){
				cur = cur->next;
				cur->prev->next = n;
				n->prev = cur->prev;
				n->next = cur;
				cur->prev=n;
				
				size++;
			}
		}
	}	
	
	void reversePrint(){
		
		Node *n = tail;
		while(n!=NULL){
			cout << n->data <<" ";
			n= n->prev;
			
		}
		cout << endl;
	}
	
	void removeFirst(){
		
		if(header->next ==NULL){
			delete header;
			header = NULL;
			tail = NULL;
		}
		else if( header!=NULL){
			header = header->next;
			delete header->prev;
			header->prev=NULL;
			size--;
			
		}
	}
	void removeLast(){
			
			if(header->next ==NULL){
				
			delete header;
			header=NULL;
			tail = NULL;
			size--;
			
			}
			
			else if(header !=NULL){
				tail = tail->prev;
				delete tail->next;
				tail->next = NULL;
				size--;
				
						}
			
			}
	void remove(int position){
		if(position<1 ||position >size){
			return;
			
		}
		else if(position==1){
	       removeFirst();
	}
	else if(position==size){
		removeLast();
	}
	else if(header !=NULL){
		Node *cur = header;
		for(int i= 1; i< position; i++){
			cur = cur->next;
			cur->prev->next = cur->next;
			cur->next->prev= cur->prev;
			delete cur;
			size--;
		}
	}
		}
	
		~DoubleLinkedList(){
			
			Node *next;
			
			
			while(header != NULL){
				next = header->next;
			    
				delete header;
				header = next;
			    
				
			}	
		}
	
		
		
};
int main(){
	DoubleLinkedList list;
	list.prepend(13);
	list.prepend(17);
	list.append(11);
	list.toPrint();
	list.append(5);
	list.toPrint();
	list.insert(2,15);
	list.toPrint();
	list.reversePrint();	
	list.removeFirst();
	list.toPrint();
	list.remove(2);
	list.toPrint();
	list.removeLast();
	list.toPrint();
	
	
	
	
	return 0;
}
