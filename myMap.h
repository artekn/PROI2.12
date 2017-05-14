#ifndef MYMAP_H
#define MYMAP_H
#include <iostream>
#include <stdlib.h>

template <class Key, class Value> struct node
 {
    Key key;
    Value* val;
    struct node *parent;
    struct node *l_son;
    struct node *r_son;
    public:
    node(Key k, Value* v): key(k), val(v), l_son(NULL), r_son(NULL), parent(NULL){}
    ~node()
    {
        parent=NULL;
        l_son=NULL;
        r_son=NULL;
    }
    node(const node &tmp)
    {
        key=tmp.key;
        val=tmp.val;
        parent=NULL;
        l_son=NULL;
        r_son=NULL;
    }
    node & operator=(const node *tmp)
    {
        key=tmp->key;
        val=tmp->val;
        parent=NULL;
        l_son=NULL;
        r_son=NULL;
    }
 };

template <class Key , class Value> class myMap
{
    public:
    node<Key, Value>* getRoot(){return root;}
    node<Key, Value>* most_left(node<Key, Value> *start)
    {
      if(start->l_son != NULL)
            return most_left(start->l_son);
       else
            return start;
     }
    node<Key, Value>* lookForKey(node<Key, Value>* start, Key key)
    {
       //jezeli wezel ma szukana wartosc to odnalezlismy go
       if (start->key == key) return start;
       //jezeli szukana wartosc jest mniejsza to szukamy w lewym poddrzewie o ile istnieje
       else if (key< start->key && start->l_son != NULL) return lookForKey(start->l_son, key);
       //jezeli szukana wartosc jest wieksza to szukamy w prawym poddrzewie o ile istnieje
       else if (key > start->key && start->r_son != NULL) return lookForKey(start->r_son, key);
       return NULL;
     }

    node<Key, Value>* lookForVal(node<Key, Value>* start, Value val)
    {
       //jezeli wezel ma szukana wartosc to odnalezlismy go
       if (start->val == val) return start;
       //jezeli szukana wartosc jest mniejsza to szukamy w lewym poddrzewie o ile istnieje
       else if (val< start->val&& start->l_son != NULL) return lookForVal(start->l_son, val);
       //jezeli szukana wartosc jest wieksza to szukamy w prawym poddrzewie o ile istnieje
       else if (val > start->val && start->r_son != NULL) return lookForVal(start->r_son, val);
       return NULL;
     }

    int addNode(Key n, Value *m, node<Key, Value>* start)
    {
      //jezeli drzewo jest puste to dodaj korzen
      if (root == NULL)
       {
            root = (node<Key, Value>*)malloc(sizeof *root);
            root->key= n;
            root->val= m;
            root->l_son = NULL;
            root->r_son = NULL;
            root->parent = NULL;
       }
      //jezeli zadana wartosc jest mniejsza od korzenia idz do lewego poddrzewa
      else if(n < start->key)
       {
            //jezeli lewe poddrzewo istnieje wywolaj dla niego ta funkcje rekurencyjnie
            if(start->l_son != NULL)
             {
                addNode(n, m, start->l_son);
             }
            //jezeli lewe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci
             else
             {
                node<Key, Value>* newNode = (node<Key, Value>*)malloc(sizeof *root);
                newNode->key= n;
                newNode->val= m;
                newNode->l_son = NULL;
                newNode->r_son = NULL;
                newNode->parent = start;
                start->l_son=newNode;
             }
        }
       //jezeli zadana wartosc jest wieksza lub rowna korzeniowi idz do prawego poddrzewa
       else
        {
         //jezeli prawe poddrzewo istnieje wywolaj dla niego ta funkcje rekurencyjnie
             if(start->r_son!=NULL)
              {
                    addNode(n, m, start->r_son);
              }
             //jezeli prawe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci
             else
              {
                   node<Key, Value>* newNode = (node<Key, Value>*)malloc(sizeof *root);
                   newNode->key= n;
                   newNode->val= m;
                   newNode->l_son = NULL;
                   newNode->r_son = NULL;
                   newNode->parent = start;
                   start->r_son=newNode;
              }
        }
      return 0;
     }

    void delNode(node<Key, Value>* start)
    {
      if(start==NULL) return;
      if(lookForKey(start, start->key)==NULL)return;
      //jezeli wezel nie ma dzieci
      if(start->l_son==NULL && start->r_son==NULL)
      {
           //jezeli wezel jest korzeniem
           if(start->parent==NULL)
           {
                root=NULL;
           }
           //jezeli wezel jest po lewej stronie rodzica,
           else if(start->parent->l_son==start)
           {
            //usun wezel z lewej strony wezla rodzica
                start->parent->l_son=NULL;
           }
           else
           {
            //usun wezel z prawej strony wezla rodzica
                start->parent->r_son=NULL;
           }
           delete start;
      }
      //jezeli wezel ma tylko jedno dziecko
      else if(start->l_son==NULL || start->r_son==NULL)
      {
           //jezeli po lewej stronie nie ma dziecka
           if(start->l_son==NULL)
           {
            //jezeli wezel jest korzeniem
                if(start->parent==NULL)
                {
                    root=start->r_son;
                    start->r_son->parent=NULL;
                }
            //jezeli wezel jest po lewej stronie rodzica
                else if(start->parent->l_son==start)
                {
                 //przyczep z lewej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
                    start->parent->l_son=start->r_son;
                    start->r_son->parent=start->parent;
                }
                else
                {
                 //przyczep z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
                    start->parent->r_son=start->r_son;
                    start->r_son->parent=start->parent;
                }
           }
           else
           {
                //jezeli wezel jest korzeniem
                if(start->parent==NULL)
                {
                    root=start->l_son;
                    start->l_son->parent=NULL;
                }
                //jezeli wezel jest po lewej stronie rodzica
                else if(start->parent->l_son==start)
                {
                 //przyczep z lewej strony rodzica wezel bedacy po lewej stronie usuwanego wezla
                    start->parent->l_son=start->l_son;
                    start->l_son->parent=start->parent;
                }
                else
                {
                 //przyczep z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
                    start->parent->r_son=start->l_son;
                    start->r_son->parent=start->parent;
                }
           }
           delete start;
      }
      else
      {
           //wstaw w miejsce usuwanego elementu - najmniejsza wartosc z prawego poddrzewa
           node<Key, Value>* temp;
           temp=most_left(start->r_son);
           start->key = temp->key;
           delNode(temp);
      }
    }

    //przeniesc do catalogu
    void in_order_tree_walk(node<Key, Value>* start)
    {
        if(start==NULL) return;
        if(start->l_son != NULL) //jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie
          in_order_tree_walk(start->l_son);
          std::cout<<start->key<<std::endl;
          if(start->r_son != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
          in_order_tree_walk(start->r_son);
     }
    myMap(){}
    ~myMap()
    {
        while(root)
        {
            delNode(most_left(root));
        }
    }
    private:
    node<Key, Value>* root=NULL;
};

template <class Key, class Value> bool isKey(Key k, node<Key, Value>* start)
{
    if(start==NULL) return false;
    if(start->l_son != NULL)//jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie
    if(isKey(k, start->l_son)==true)return true;
    if(start->key==k){return true;}
    if(start->r_son != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
    if(isKey(k, start->r_son)==true)return true;
    return false;
}

#endif // MYMAP_H
