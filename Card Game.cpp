#include<bits/stdc++.h>
using namespace std;
// You have a stack of 100 cards, shuffled randomly.
// 4 players ie: A,B,C,D each get one card from the top
// the player with the max numbered card gets to keep all the cards

void displayStack(stack<int> &s);
void maxcard(stack<int> &a,stack<int> &b,stack<int> &c,stack<int> &d);

void fill_abcd_stacks(stack<int> &s,stack<int> &a,stack<int> &b,stack<int> &c,stack<int> &d,int size,string *name){
	system("cls");
	for(int i = 0,j=0 ; i < size ; i++,j++){
		cout<<"\t\tIteration count -> "<<j+1<<" || New cards alloted" <<endl;
		
		a.push(s.top());	s.pop();
			b.push(s.top());	s.pop();
				c.push(s.top());	s.pop();
					d.push(s.top());	s.pop();
					
		cout<<"\n Stack of "<<name[0]<<": " ;displayStack(a);	cout<<endl;	cout<<"\n Stack of "<<name[01]<<": " ;displayStack(b);	cout<<endl;	
		cout<<"\n Stack of "<<name[02]<<": " ;displayStack(c);	cout<<endl;	cout<<"\n Stack of "<<name[03]<<": " ;displayStack(d);		
				
		maxcard(a,b,c,d);			
	}
	//cout<<"Stack of A: ";displaytop(a);		cout<<"Stack of B: ";displaytop(b);			cout<<"Stack of C: ";displaytop(c);		cout<<"Stack of D: ";displaytop(d);
	cout<<"\n\t\tUltimate result of all iterations\n";
	cout<<"\n Stack of "<<name[0]<<": " ;displayStack(a);		cout<<endl<<endl;	cout<<"\n Stack of "<<name[01]<<": " ;displayStack(b);	cout<<endl<<endl;	
	cout<<"\n Stack of "<<name[02]<<": " ;displayStack(c);	    cout<<endl<<endl;	cout<<"\n Stack of "<<name[03]<<": " ;displayStack(d);	cout<<endl<<endl;
	
}
void swap(int* x,int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void shuffle(int *array){	// shuffles the cards randomly
	srand(time(0));
	for(int i = 0 ; i < 100; i++){
		swap(&array[rand()%50],&array[rand()%50+50]);
		swap(&array[rand()%50],&array[rand()%50+50]);
		swap(&array[rand()%50],&array[rand()%50+50]);
	}
}
void fill_array(int* array){	//fills the array with 1-100
	for(int i = 0 ; i < 100 ; i++)
		array[i] = i+1;
}
void displayStack(stack<int> &s){	//utility func to view the stack of cards
	// If stack is empty
    if (s.empty())
        return;
  
// Extract top of the stack
    int x = s.top();
  
    // Pop the top element
    s.pop();
  
    // Print the current top
    // of the stack i.e., x
    cout << endl <<"\t\t" <<  x << ' ' ;
  
    // Proceed to print
// remaining stack
    displayStack(s);
  
    // Push the element back
    s.push(x);
}

void fillstack(stack<int> &s){	//utility func to fill stack of cards with 1-100
	int array[100];
	fill_array(array);
	shuffle(array);
	
	//finally push all the cards to the stack
	for (int i = 0 ; i < 100 ; i++)
		s.push(array[i]);	
}
void maxcard(stack<int> &a,stack<int> &b,stack<int> &c,stack<int> &d){
	int max;
	max = a.top();	int flag = 0;
	if(b.top() > max){
		max = b.top();	flag = 1;
	}
	if(c.top() > max){
		max = c.top();	flag = 2;
	}
	if(d.top() > max){
		max = d.top();	flag = 3;
	}
	
	if(flag == 0){	//A had the highest card
		cout<<endl<<"\n\tA has the highest card -> gets all cards of this turn\n";
		a.push(b.top());	b.pop();
			a.push(c.top());	c.pop();
				a.push(d.top());	d.pop();
	//	cout<<"Stack of A: ";displayStack(a);		
	}
	else if(flag == 1){	//B had the highest card
		cout<<endl<<"\n\tB has the highest card -> gets all cards of this turn\n";
		b.push(a.top());	a.pop();
			b.push(c.top());	c.pop();
				b.push(d.top());	d.pop();
	//	cout<<"Stack of B: ";displayStack(b);		
	}
	else if(flag == 2){	//C had the highest card
		cout<<endl<<"\n\tC has the highest card -> gets all cards of this turn\n";
		c.push(b.top());	b.pop();
			c.push(a.top());	a.pop();
				c.push(d.top());	d.pop();
	//	cout<<"Stack of C: ";displayStack(c);		
	}
	else if(flag == 3){	//D had the highest card
		cout<<endl<<"\n\tD has the highest card -> gets all cards of this turn\n";
		d.push(b.top());	b.pop();
			d.push(c.top());	c.pop();
				d.push(a.top());	a.pop();
	//	cout<<"Stack of D: ";displayStack(d);		
	}
}
void results(stack<int> &a,stack<int> &b,stack<int> &c,stack<int> &d,string *name){
	if(a.size() > b.size() && a.size() > c.size() && a.size() > d.size() )
	cout<<"\n\tPlayer 1 wins the game with most cards in pile";
	else if(b.size() > a.size() && b.size() > c.size() && b.size() > d.size())
	cout<<"\n\tPlayer 2 wins the game with most cards in pile";
	else if(c.size() > b.size() && c.size() > a.size() && c.size() > d.size())	
	cout<<"\n\tPlayer 3 wins the game with most cards in pile";
	else if(d.size() > b.size() && d.size() > c.size() && d.size() > a.size())	
	cout<<"\n\tPlayer 4 wins the game with most cards in pile";	
	else {
	
	if(a.size() == b.size() && b.size() == c.size() && c.size() == d.size()){
		cout<<"\n\tEveryone won equals rounds -> equal cards. "; 	goto end;
	}
	else{
			if(a.size() == b.size() && b.size() == c.size()){
			cout<<"\n\tTie between Player 1,Player 2 and Player 3";	goto end;
			}			
			else if(a.size() == b.size() && b.size() == d.size()){
			cout<<"\n\tTie between Player 1,Player 2 and Player 4";	goto end;
			}				
			else if(a.size() == c.size() && c.size() == d.size()){
			cout<<"\n\tTie between Player 1,Player 3 and Player 4";	goto end;
			}		
			else if(b.size() == c.size() && b.size() == d.size()){
			cout<<"\n\tTie between Player 2,Player 3 and Player 4";	goto end;
			}
			else{
				if(a.size() != 0){
				if(a.size() == b.size() )
				cout<<"\n\tTie between Player 1 and Player 2";	
				else if(a.size() == c.size() )
				cout<<"\n\tTie between Player 1 and Player 3";	
				else if(a.size() == d.size() )
				cout<<"\n\tTie between Player 1 and Player 4";
		}
				if(b.size() != 0){
			 	if(b.size() == c.size() )
				cout<<"\n\tTie between Player 2 and Player 3";	
				else if(b.size() == d.size() )
				cout<<"\n\tTie between Player 2 and Player 4";
		}
				if(c.size() != 0  ){
				if(c.size() == d.size() )
				cout<<"\n\tTie between Player 3 and Player 4";
									}			
				end:	return;
				}		
}
}		
}
int ask_iterations(){ //part of the older version
	int iterations;
		here:	cout<<"How Many iterations:  ";cin>>iterations;
	if(iterations < 0 || iterations > 25)	//at most 25 iterations allowed
	goto here;
	return iterations;
}
void asknames(string *name){
	//Rcin.ignore();
	system("cls");
	for(int i = 0 ; i < 4 ; i++){
		cout<<"\n\tEnter Player "<<i+1<<"'s Name:  ";	
		getline(cin,name[i]);
	
	}
	system("cls");
}

int main(){
	stack<int> s;	1-100
	stack<int> a,b,c,d;
	
	string name[4];
	asknames(name);
	fillstack(s);	

	int choice;
	
L1:	cout<<"\n\tPress 1 to Start/continue Game | 0 to End game.\n\tEnter:  ";	cin>>choice;

	if(choice == 1)
		fill_abcd_stacks(s,a,b,c,d,choice,name);
	else if(choice == 0){
		results(a,b,c,d,name);
		cout<<endl<<endl<<endl;
		return 0;
	}
	else{
		cout<<"\nEnter Valid Instruction\n";	goto L1;
	}	goto L1;
	
	//feedback given by sir
	
	// ---> old logic. no user interaction. 
	//iterations = ask_iterations();	//asks the user how many times he wants to execute the play.
	//fill_abcd_stacks(s,a,b,c,d,choice);
	
}

