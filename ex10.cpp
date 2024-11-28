#include<iostream>
using namespace std;

struct book {
    int id; 
    string title; 
    string authur; 
    int year; 
    bool isavailable; 
};


void ajouterLivre(book* books, int& num, int id,
 const std::string& title, const  std::string& authur, int year){
    books[num].id = id;
    books[num].title = title;
    books[num].authur = authur;
    books[num].year = year;
    num++;
}

void afficherLivres(const book* books, int num){
    cout<<"title is : " << books[num].title<<endl
    <<"authur is: "<<books[num].authur<<endl;
}

int main(){
    struct book books[100];


    return 0;
}