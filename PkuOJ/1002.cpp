#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#ifdef DEBUG
#include<string>
using std::string;
using std::freopen;
string input_file_name = __FILE__;
#endif

//here add other file need to included, and declare namespace need to use.
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
//here declare global variables;
char dictionary[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};
char no[50];
char oarray[10];
bool flag;

struct Trie_node
{
    int count;
    Trie_node* next[10];
};

Trie_node root;

Trie_node node_pool[200002];
int index_;

void inline insert(Trie_node* node, char* s)
{
    if(*s == '\0')
    {
        ++node->count;
        return;
    }

    if(node->next[*s - '0'] == NULL)
        node->next[*s - '0'] = &node_pool[index_++];

    insert(node->next[*s - '0'], s + 1);
}

void inline travel(Trie_node* node, int c)
{
    for(int i = 0; i < 10; ++i)
    {

        if(node->next[i] == NULL)
            continue;

        oarray[c] = (char)(i + '0');

        if(c >= 6)
        {
            if(node->next[i]->count > 1)
            {
                flag = true;
                printf("%c%c%c-%c%c%c%c %d\n", oarray[0], oarray[1],
                        oarray[2], oarray[3],
                        oarray[4], oarray[5],
                        oarray[6], node->next[i]->count);
            }
        }
        else
        {
            travel(node->next[i], c + 1);
        }
    }

}


//here add funtions.
void inline format_number(char* no)
{
    //int len = strlen(no);
    //printf("%s\n", no);
    int count = 0;
    int sum = 0;
    for(int i = 0; no[i] != '\0'; ++i)
    {
        ++sum;
        if(no[i] >= 'A' && no[i] <= 'Z')
        {
            no[i] = '0' + dictionary[no[i] - 'A'];
        }
        else if(no[i] == '-')
        {
            ++count;
        }

        if(no[i] != '-')
            no[i - count] = no[i];

    }
    no[sum - count] = '\0';
    //printf("%s\n", no);
}

int getline_(char s[],int lim){
    int c,i;
    i=0;
    while((c=getchar())!=EOF&&c!='\n'&&i<lim-1)
        s[i++]=c;
    s[i]='\0';
    return i;
}

int main(int argc, char* argv[])
{
    #ifdef DEBUG
    if(!freopen((input_file_name.substr(0, input_file_name.size() - 4) + ".in").c_str(), "r", stdin))
        { cout << "input data error, not found input file." << endl; return -1; }
    #endif

    //here add code for solve problem.
    int n = 0;
    //input
    scanf("%d", &n);
    flag = false;
    index_ = 0;
    getchar();
    for(int i = 0; i < n; ++i)
    {
        getline_(no,49);
        //puts(no);
        format_number(no);
        insert(&root, no);
    }

    travel(&root, 0);

    if(!flag)
    {
        printf("No duplicates.\n");
    }

    return 0;
}
