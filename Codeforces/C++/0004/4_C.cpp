// https://codeforces.com/problemset/problem/4/C
#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 26 ;


struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}
	pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main()
{
    int n;string a;
    struct TrieNode *root = getNode();
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(search(root,a))
        {
            int suffix=1;
            while(true)
            {
                vector<string> tempSuffixVector;
                int tempSuffix=suffix;
                string tempName=a;
                while(tempSuffix>0)
                {
                    switch(tempSuffix%10)
                    {
                        case 0: tempSuffixVector.push_back("0");break;
                        case 1: tempSuffixVector.push_back("1");break;
                        case 2: tempSuffixVector.push_back("2");break;
                        case 3: tempSuffixVector.push_back("3");break;
                        case 4: tempSuffixVector.push_back("4");break;
                        case 5: tempSuffixVector.push_back("5");break;
                        case 6: tempSuffixVector.push_back("6");break;
                        case 7: tempSuffixVector.push_back("7");break;
                        case 8: tempSuffixVector.push_back("8");break;
                        case 9: tempSuffixVector.push_back("9");break;
                    }
                    tempSuffix/=10;
                }
                for(int i=tempSuffixVector.size()-1;i>=0;i--) tempName=tempName+tempSuffixVector[i];
                if(search(root,tempName)) suffix++;
                else {insert(root,tempName);cout<<tempName<<endl;break;}
            }
        }
        else {insert(root,a);cout<<"OK\n";}
    }

	return 0;
}