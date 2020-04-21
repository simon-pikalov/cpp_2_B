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


        Tree(string name) {
                this->me = name;
                this->root=this;
                this->father = NULL;
                this->mother=NULL;

        }

        Tree(string name,Tree* father, Tree* mother) {
        }

        Tree& addFather(string prsoon, string father);

        Tree& addMother(string prsoon, string mother);

        string relation(string name);

        string find(string relation);

        void remove(string name);

        Tree * findNodeName (string name);

        Tree * findNodeRealtion (string relation);

        void display();

        string relation(Tree * curr, string name , int count,bool male);

    private:
        Tree * addFamilyMember(Tree* root, bool, string name);
    };



}
vector<string> split(string txt,string delimeter );

#endif //B_2_FAMILYTREE_HPP
