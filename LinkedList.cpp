#include<iostream>

using namespace std;

class Node{
   public:
   	   int data;
   	   Node *next;
   	   
   	   Node(int data){
   	   	this->data = data;
   	   	next= NULL;
		  }
   	
};
class LinkedList{
	
	private:
		Node *header;
		Node *tail;
		int size;
		
	public:
		LinkedList(){
			header = NULL;
			tail= NULL;
			size = 0;
		}
		
		int getSize(){
			return size;
		}
		
		void append(int data){
			
			Node *n = new Node(data);
			
			if(header==NULL){
				header = n;
				tail = n;
				
			}
			else{
				tail->next = n;
				tail = n;
				
			}
			size++;
		}
		void prepend(int data){
			Node *n = new Node(data);
			
			if(header== NULL){
				header = n;
				tail = n;
				
			}else{
				Node *temp = header;
				header = n;
				n->next = temp;
				
				size++;
			}
			
		}
		void toPrint(){
			
			Node *temp = header;
			
			while(temp !=NULL){
				
				cout<< temp->data << " ";
				temp = temp ->next;
			}
			cout<<endl;
		}
		
		void removeFirst(){
			
			if(header !=NULL){
				Node *temp = header;
				header = header->next;
				delete temp;
				size--;
				
			}
			
			
		}
		void removeLast(){
			
			if(header->next ==NULL){
				
			LinkedList::removeFirst();
			}
			else if(header !=NULL){
				Node *current = header;
				Node *prev;
				
				while(current->next !=NULL){
					prev = current;
					current = current->next;
				}
				tail = prev;
				prev->next=NULL;
				delete current;
				size--;
				
						}
			
			}
			
		void remove(int position){
			
			if (position>size || position < 1){
				return;
				
			}
			else if(position==1){
			 LinkedList::removeFirst();
				
			}
			else if(position ==size){
				removeLast();
			}
			else if(header !=NULL){
				Node *prev;
				Node *cur = header;
				for(int i=1; i<position; i++){
					prev = cur;
					cur= cur->next;
					
				}
				prev->next = cur->next;
				delete cur;
				size--;
			}
		}
		
		void insertAt(int position, int data){
			if ( position> size+1 || position<1){
				return;
			}
			else if(position==1){
				prepend(data);
			}
			else if(position==size +1){
                append(data);
      
	  			}
	  			else if(header!=NULL){
	  				Node *n = new Node(data);
	  				Node *prev;
	  				Node *cur = header;
	  				for(int i=1; i<position; i++){
	  					prev = cur;
	  					cur = cur->next;
	  					
	  				
					  }
					  prev->next = n;
					  n->next = cur;
					  size++;
				  }
			
			
		}
		~LinkedList(){
			
			Node *next;
			while(header != NULL){
				next = header->next;
				delete header;
				header = next;
				
			}
		}
		
};
int main(){
	
	LinkedList list;
	list.append(3);
	list.append(7);
	list.append(17);
	list.prepend(11);
	list.append(13);
	list.toPrint();
	list.removeFirst();
	list.toPrint();
	list.removeLast();
	list.append(19);
	list.toPrint();
	list.remove(3);
	list.toPrint();
	list.insertAt(2,29);
	list.toPrint();
	
	return 0;
}
