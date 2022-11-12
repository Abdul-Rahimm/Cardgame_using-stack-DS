#include<bits/stdc++.h>
using namespace std;

void fill_abcd_stacks(stack<int> &s,stack<int> &a,stack<int> &b,stack<int> &c,stack<int> &d,int size);
void swap(int* x,int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void shuffle(int *array){
	srand(time(0));
	for(int i = 0 ; i < 100; i++){
		swap(&array[rand()%50],&array[rand()%50+50]);
		swap(&array[rand()%50],&array[rand()%50+50]);
		swap(&array[rand()%50],&array[rand()%50+50]);
	}
}
void fill_array(int* array){
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
void fill_abcd_stacks(stack<int> &s,stack<int> &a,stack<int> &b,stack<int> &c,stack<int> &d,int size){
	for(int i = 0,j=0 ; i < size ; i++,j++){
		cout<<"\t\tIteration count -> "<<j+1<<" || New cards alloted" <<endl;
		a.push(s.top());	s.pop();
			b.push(s.top());	s.pop();
				c.push(s.top());	s.pop();
					d.push(s.top());	s.pop();
		cout<<"\nStack of A: ";displayStack(a);	cout<<endl;	cout<<"Stack of B: ";displayStack(b);	cout<<endl;	
		cout<<"Stack of C: ";displayStack(c);	cout<<endl;	cout<<"Stack of D: ";displayStack(d);				
		maxcard(a,b,c,d);			
	}
	//cout<<"Stack of A: ";displaytop(a);		cout<<"Stack of B: ";displaytop(b);			cout<<"Stack of C: ";displaytop(c);		cout<<"Stack of D: ";displaytop(d);
	cout<<"\n\t\tUltimate result of all iterations\n";
	cout<<"Stack of A: ";displayStack(a);	cout<<endl<<endl;	cout<<"Stack of B: ";displayStack(b);	cout<<endl<<endl;	cout<<"Stack of C: ";displayStack(c);	cout<<endl<<endl;	cout<<"Stack of D: ";displayStack(d);	cout<<endl<<endl;
	
}
void results(stack<int> &a,stack<int> &b,stack<int> &c,stack<int> &d){
	if(a.size() > b.size() && a.size() > c.size() && a.size() > d.size() )
	cout<<"\n\tA wins the game with most cards in pile";
	else if(b.size() > a.size() && b.size() > c.size() && b.size() > d.size())
	cout<<"\n\tB wins the game with most cards in pile";
	else if(c.size() > b.size() && c.size() > a.size() && c.size() > d.size())	
	cout<<"\n\tC wins the game with most cards in pile";
	else if(d.size() > b.size() && d.size() > c.size() && d.size() > a.size())	
	cout<<"\n\tD wins the game with most cards in pile";	
	else {
	
	if(a.size() == b.size() && b.size() == c.size() && c.size() == d.size()){
		cout<<"\n\tEveryone won equals rounds -> equal cards. "; 	goto end;
	}
	else{
			if(a.size() == b.size() && b.size() == c.size()){
			cout<<"\n\tTie between A,B and C";	goto end;
			}			
			else if(a.size() == b.size() && b.size() == d.size()){
			cout<<"\n\tTie between A,B and D";	goto end;
			}				
			else if(a.size() == c.size() && c.size() == d.size()){
			cout<<"\n\tTie between A,C and D";	goto end;
			}		
			else if(b.size() == c.size() && b.size() == d.size()){
			cout<<"\n\tTie between B,C and D";	goto end;
			}
			else{
				if(a.size() != 0){
				if(a.size() == b.size() )
				cout<<"\n\tTie between A and B";	
				else if(a.size() == c.size() )
				cout<<"\n\tTie between A and C";	
				else if(a.size() == d.size() )
				cout<<"\n\tTie between A and D";
		}
				if(b.size() != 0){
			 	if(b.size() == c.size() )
				cout<<"\n\tTie between B and C";	
				else if(b.size() == d.size() )
				cout<<"\n\tTie between B and D";
		}
				if(c.size() != 0  ){
				if(c.size() == d.size() )
				cout<<"\n\tTie between C and D";
									}			
				end:	return;
				}		
}
}		
}
int ask_iterations(){
	int iterations;
		here:	cout<<"How Many iterations:  ";cin>>iterations;
	if(iterations < 0 || iterations > 25)	//at most 25 iterations allowed
	goto here;
	return iterations;
}


int main(){
	stack<int> s;	
	stack<int> a,b,c,d;
	
	fillstack(s);	
//	displayStack(s);

	int iterations;
	iterations = ask_iterations();	//asks the user how many times he wants to execute the play.
	fill_abcd_stacks(s,a,b,c,d,iterations);
	
	results(a,b,c,d);
	
}

