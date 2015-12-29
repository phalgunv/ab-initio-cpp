/*A book shop maintains the inventory of books that are being sold at the shop. The list includes details such as author, title, price , publisher and stock position. 
 * - Whenever a customer wants book, the sales person inputs the title and author and the system searches the list and displays whether it is available or not. 
 *   - If it in not, an appropriate message is displayed. If it is, then the system displays the book details and requests for the number of copies required. 
 *   - If the reqested copies are available, the total cost of the requested copies is displayed; otherwise the message "Required copies not in stock" is displayed. 
 *   Design a system using a class called books with suitable member functions and Constructors. Allcate memory dynamically in  constructor to allocate memory space required.*/

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class book
{
	string author;
	string title;
	float price;
	string publisher;
	int instock;
	public:
	book():author(" "), title(" "), price(0), publisher(" "), instock(0)
	{
	}
	void input()
	{
		cout << "Enter the author, title, price, publisher, no of copies "<< endl;
		//cin.ignore();
		cin>> author;
		//cin.ignore();
		cin>> title;
		//cin.ignore();
		cin >> price;
		//cin.ignore();
		cin>> publisher;
		cin >> instock;
	}

	int search(string t, string a)
	{
		if((title.compare(t))&&(author.compare(a)))
		{
			cout << "In if block" << endl;
			return 1;
		}
		else
			return 0;
	}


	void getprice(int n)
	{
		if(instock >= n){cout << "Inside if" << n << endl;
			cout << "The cost for " << n << " copies is " << (n*price) << endl;}
		else{cout << "Inside else " << n << endl;
			cout << "Only " << instock << "copies available..Required copies not in stock" << endl;}
	}

	void getdetails()
	{
		cout << "Title of the book: " << title << endl;
		cout << "Author of the book: " << author << endl;
		cout << " Price of the book: " << price << endl;
		cout << "Publisher of the book: " << publisher << endl;
		cout << "no of copies available: " << instock << endl;
	}

};

int main()
{
	int n, copy;
	cout << "Enter the number of book details to be stored" << endl;
	cin >> n;
	book *obj[n];
	for(int i = 0; i < n; i++)
		obj[i] = new book();	
	for(int i = 0; i < n; i++)
		obj[i]->input();
	for(int i = 0; i < n; i++)
		obj[i]->getdetails();
	cout << "Enter the title and author of the book the customer wants" << endl;
	//cin.ignore();
	string tit, aut;
	cin>> tit;
	//cin.ignore();
	cin>> aut;
	for(int i = 0; i < n; i++)
	{
		int a = obj[i]->search(tit, aut);
		cout << a << endl;
		if(a)
		{
			obj[i]->getdetails();
			cout << "How many copies required" << endl;
			cin >> copy;
			obj[i]->getprice(copy);
		}
		
		else
		cout << "Sorry the book is not available in our inventory" << endl;
	}


	for(int i = 0; i < n; i++)
		delete  obj[i];

}
