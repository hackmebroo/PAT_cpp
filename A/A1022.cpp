#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

void find(map<string, set<int>>& mp, string & str){
    if(mp.find(str) == mp.end()) printf("Not Found\n");
    else{
        for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++)
            printf("%07d\n", *it);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    map<string, set<int>> book_title_set, author_set, key_words_set, publisher_set, year_set;
    string book_title, author, key_words, publisher, year;
    int id;
    for(int i = 0; i < n; i++){
        scanf("%d", &id);
        getchar();
        getline(cin, book_title);
        book_title_set[book_title].insert(id);
        getline(cin, author);
        author_set[author].insert(id);
        while(cin >> key_words){
            key_words_set[key_words].insert(id);
            char c = getchar();
            if(c == '\n') break;
        }
        getline(cin, publisher);
        publisher_set[publisher].insert(id);
        getline(cin, year);
        year_set[year].insert(id);
    }
    string temp;
    int m, query;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d: ", &query);
        getline(cin, temp);
        cout << query << ": " << temp << endl;
        if(query == 1) find(book_title_set, temp);
        else if(query == 2) find(author_set, temp);
        else if(query == 3) find(key_words_set, temp);
        else if(query == 4) find(publisher_set, temp);
        else if(query == 5) find(year_set, temp);
    }
    return 0;
}