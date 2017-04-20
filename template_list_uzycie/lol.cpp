#include <iostream>
#include <stdexcept>

using namespace std;

template <class DT> class ListNode;

template <typename DT> class List{
	private:
		ListNode<DT>* head;
		ListNode<DT>* cursor;
		int counter;
	public:
		List (){
			head=0;
			cursor=0;
			counter=0;
		}
		
		~List (){
			if(head!=NULL){
				delete head;
			}
		}
		
		void insert (const DT &newDataItem) throw (bad_alloc){
			try{
				if(counter==0){
					ListNode<DT>* newElem=new ListNode<DT>(newDataItem);
					newElem->next=newElem;
					newElem->prior=newElem;
					ListNode<DT>* pom;
					head=newElem;
					cursor=newElem;
					pom=newElem->next;
					counter++;
				}
				else{
					if(counter>0){
						ListNode<DT>* newElem=new ListNode<DT>(newDataItem);
						newElem->next=cursor;
						newElem->prior=cursor->next;
						ListNode<DT>* pom;
						pom=cursor->next;
						pom->prior=newElem;
						cursor->next=newElem;
						cursor=newElem;
						counter++;
					}
				}
			}
			catch (bad_alloc& ba)
			{
				cout<<ba.what()<<endl;
			}
		}
/*		
		void remove () throw (logic_error){
			try{
				ListNode<DT>* pom=new ListNode<DT>(cursor.dataItem);
				pom=cursor->prior;
				pom->next=cursor->next;
				pom=cursor->next;
				pom->prior=cursor->prior;
				cursor=cursor->next;
			}
			catch(logic_error& le){
				cout << le.what()<<endl;
			}
		}
		
		void replace (const DT &newDataItem) throw (logic_error){
			try{
				ListNode<DT>* newElem=new ListNode<DT>(newDataItem,cursor->prior,cursor->next);
				ListNode<DT>* pom=new ListNode<DT>(cursor.dataItem);
				pom=cursor->prior;
				pom->next=newElem;
				pom=cursor->next;
				pom->prior=newElem;
				cursor=newElem;
			}
			catch(logic_error& le){
				cout << le.what()<<endl;
			}
		}
		
		void clear (){
			delete head;
		}
		bool isEmpty () const{
			if(head==NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		bool isFull () const{
			if(head==NULL){
				return false;
			}
			else{
				return true;
			}
		}*/
		
		void gotoBeginning () throw (logic_error){
			try{
				cursor=head;
			}
			catch(logic_error& le){
				cout << le.what()<<endl;
			}
		}
		/*
		void gotoEnd () throw (logic_error){
			try{
				cursor=end;
			}
			catch(logic_error& le){
				cout << le.what()<<endl;
			}
		}*/
		
		bool gotoNext () throw (logic_error){
			try{
				cursor=cursor->next;
			}
			catch(logic_error& le){
				cout << le.what()<<endl;
			}
		}
		/*
		bool gotoPrior () throw (logic_error){
			try{
				cursor=cursor->prior;
			}
			catch(logic_error& le){
				cout << le.what()<<endl;
			}
		}
		*/
		DT getCursor () const throw (logic_error){
			try{
				return cursor->dataItem;
			}
			catch(logic_error& le){
				cout << le.what()<<endl;
			}
		}

		void showStructure () const{
			gotoBeginning ();
			for(int i=0;i<counter;i++){
				getCursor();
				gotoNext();
			}
		}

};

template <class DT> class ListNode{
	friend class List<DT>;
	private:
		ListNode(){
			prior=0;
			next=0;
		}
		ListNode(const DT &data){
			dataItem=data;
			prior=NULL;
			next=NULL;
		}
		ListNode (const DT &data,ListNode<DT> *priorPtr, ListNode<DT> *nextPtr){
			dataItem=data;
			prior=priorPtr;
			next=nextPtr;
		}
		ListNode (const ListNode<DT>& no){
			dataItem=no.dataItem;
			prior=no.prior;
			next=no.next;
		}
		DT dataItem;
		ListNode *prior, *next;
};

int main(){
	//Puzzle puz("ada","ada");
	List<char> s;
	s.insert('k');
	s.insert('n');
	s.insert('p');
	s.showStructure();
}
