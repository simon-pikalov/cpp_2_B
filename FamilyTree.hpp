//
// Created by sam on 20/04/2020.
//

#ifndef B_2_FAMILYTREE_HPP
#define B_2_FAMILYTREE_HPP



#include <iostream>
#include <vector>
using namespace std;
namespace family

{

    class Tree {       // The class
    public:             // Access specifier
        string me;        // Attribute (name string)
        Tree* father;            //left Node
        Tree* mother;           // Right Node
        Tree *root;


        Tree(string name);
        ~Tree();

        Tree& addFather(string prsoon, string father);

        Tree& addMother(string prsoon, string mother);

        string relation(string name);

        string find(string relation);

        void remove(string name);

        void display();




    private:
        string relation(Tree * curr, string name , int count,bool male);
        Tree * findNodeRealtion (string relation);
        Tree * findNodeName (string name);
        Tree * findChild (string name);
        bool checkValidFind(  vector<string> splitedRelation);

    };



}
vector<string> split(string txt,string delimeter );

#endif //B_2_FAMILYTREE_HPP
