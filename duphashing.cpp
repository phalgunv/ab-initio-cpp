#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cctype>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 26;

class HashNode
{
  public:
    int key;
    int value;
    HashNode* next;
    HashNode(int key, int value)
    {
      this->key = key;
      this->value = value;
      this->next = NULL;
    }
};


class HashMap
{
  private:
    HashNode** htable;
  public:
    HashMap()
    {
      htable = new HashNode*[TABLE_SIZE];
      for (int i = 0; i < TABLE_SIZE; i++)
	htable[i] = NULL;
    }
    ~HashMap()
    {
      for (int i = 0; i < TABLE_SIZE; ++i)
      {
	HashNode* entry = htable[i];
	while (entry != NULL)
	{
	  HashNode* prev = entry;
	  entry = entry->next;
	  delete prev;
	}
      }
      delete[] htable;
    }

    //Hash Function
    int HashFunc(int key)
    {
      return key-65 ;
    }

    //Insert Element at a key
    void Insert(int key, int value)
    {
      int hash_val = HashFunc(key);
      HashNode* prev = NULL;
      HashNode* entry = htable[hash_val];
      while (entry != NULL)
      {
	prev = entry;
	entry = entry->next;
      }
      if (entry == NULL)
      {
	entry = new HashNode(key, value);
	if (prev == NULL)
	{
	  htable[hash_val] = entry;
	}
	else
	{
	  prev->next = entry;
	}
      }
      else
      {
	entry->value = value;
      }
    }

    int Search(int key)
    {
      bool flag = false;
      int hash_val = HashFunc(key);
      HashNode* entry = htable[hash_val];
      while (entry != NULL)
      {
	if (entry->key == key)
	{
	  cout<<entry->value<<" ";
	  flag = true;
	}
	entry = entry->next;
      }
      if (!flag)
	return -1;
    }

    void display() 
    {
      for(int i = 0; i < TABLE_SIZE; i++)
      {
	HashNode* entry = htable[i];
	if(entry!=NULL){
	  while (entry != NULL)
	  {
	    cout <<(char)entry->key << " occured at " << entry->value << "-----> ";
	    entry = entry->next;
	  }
	  cout << "NULL" << endl;
	}
      }		
    }
};



  int main()
{	while(1)
  {
    string str;
    cout << "Enter a string\n";
    getline(cin, str);
    cout << "\n the entered string is : " << str << endl;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    HashMap hash;
    int freq[26]={0};
    for (int i = 0; i < str.length(); i++)
    {
      int j = str[i] - 'A';
      hash.Insert(str[i], i);
      freq[j]++;
    }
    for (int i = 0; i < 26; i++)
    {
      if(freq[i] > 1)
      {
	cout << "\n" << char(i+65) << " occured " << freq[i] << "times \n" ;
      }
    }
    int c;
    cout << endl << "1.to display the positions \n2.Search position of particular alphabet \n3. to exit \n";
    cin >> c;
    switch(c)
    {
      case 1:
	hash.display();break;
      case 2:
	{
	  char k;
	  cout << "Enter any alphabet to know the positions of its occurance" << endl;	
	  cin >> k;
	  k = toupper(k);
	  cout << "values at key " << k << "is: " << endl;
	  if (hash.Search(k) == -1)
	    cout << "No element found at key " << k << endl;
	}
	break;
      case 3:exit(0);
    }

  }	

  return 0;
}
