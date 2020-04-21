#include "FamilyTree.hpp"

#include <iostream>
#include <vector>

using namespace family;
using namespace std;

class invalidInputExeption: public exception
{
    virtual const char* what() const throw()
    {
        return "Please fix your input it's invalid";
    }
} inputEx;


class placedFillExeprtion: public exception
{
    virtual const char* what() const throw()
    {
        return "your trying to add to a non empty place";
    }
} placeEx;


Tree *  Tree::addFamilyMember(Tree* root, bool father, string name){
    Tree*  newNode = new Tree(name);
    if(father) this->father = newNode;
    else this->mother = newNode;
    newNode->root=root;
}


Tree& Tree::addFather(string to, string name) {

    Tree* curr = this->root->findNodeName(to);
    Tree * newNode = new Tree(name);
    if(curr->father!=NULL) throw placeEx;
    else (curr->father=newNode);
    return *this;
}

Tree &Tree::addMother(string to, string name) {
    Tree* curr = this->root->findNodeName(to);
    Tree * newNode = new Tree(name);
    if(curr->mother!=NULL) throw placeEx;
    else (curr->mother=newNode);
    return *this;
}

void Tree::display() {
    if(this==NULL) return;
    if (this->father != NULL) cout<<me << " father is: " << this->father->me<<endl;
    if (this->mother != NULL)cout << me << " mother is: " << this->mother->me<<endl;
    Tree *father = this->father;
    Tree *mother = this->mother;
    if (father != NULL) father->display();
    if (mother != NULL)mother->display();


}

/**
 *
 * @param txt string to be splited
 * @param delimeter array of chars in a form ostring where ich char representing a delimiter exampel [\n ,.]
 * @return a vector with the splited string
 */
vector<string> split(string txt, string delimeter) {

    int start = 0;
    int end = 0;
    vector<string> ans;

    for (int i = 0; i < txt.length(); i++) {

        for (int j = 0; j < delimeter.length(); j++) {
            if (txt[i] == delimeter[j]) {
                ans.push_back(txt.substr(start, end - start));
                start = end + 1;
            }
        }
        end++;
    }
    ans.push_back(txt.substr(start, end - start));
    return ans;
}


string Tree::relation(string name) {

    string ans = relation(this,  name ,  0 , true);
if(ans=="") return "unrelated";
else return ans;

}


string Tree::relation(Tree * curr , string name , int count,bool male ) {

    if (count <= 2) {
        if (this != NULL && count == 0 && name == this->me) return "me";
        else if (count == 1 && (this->mother != NULL && this->mother->me == name ||
                                this->father != NULL && this->father->me == name)) {
            if (this->mother != NULL && this->mother->me == name) return "mother";
            else if (this->father != NULL && this->father->me == name) return "father";
        } else if (count == 2 &&
                   (this->father != NULL && this->father->father != NULL && this->father->father->me == name ||
                    this->mother != NULL && this->mother->father != NULL && this->mother->father->me == name ||
                    this->father != NULL && this->father->mother != NULL && this->father->mother->me == name ||
                    this->mother != NULL && this->mother->mother != NULL && this->mother->mother->me == name)) {
            if (this->father != NULL && this->father->father != NULL && this->father->father->me == name)
                return "grandfather";
            else if (this->mother != NULL && this->mother->father != NULL && this->mother->father->me == name)
                return "grandfather";
            else if (this->father != NULL && this->father->mother != NULL && this->father->mother->me == name)
                return "grandmother";
            else if (this->mother != NULL && this->mother->mother != NULL && this->mother->mother->me == name)
                return "grandmother";

        } else {
            if (curr->father != NULL) {

                string temp = this->relation(curr->father, name, ++count, true);
           //     if (temp != "unrelated") return temp;
                return  temp;

            }

            if (curr->mother != NULL) {
                string temp = this->relation(curr->father, name, ++count, false);
             //   if (temp != "unrelated") return temp;
                return  temp;
            }
        }


    }

    if (count >= 3) { // case count is bigger  or equal to 3;

        if (curr->me == name) {
            string prefix = "";
            for (int i = 0; i < count - 2; i++) { //generate a prefix
                prefix = prefix + "great-";
            }
            string suffix = (male == true) ? "grandfather" : "grandmother";
            return prefix + suffix;
        } else if (curr->father != NULL || curr->mother != NULL) {

            if (curr->father != NULL) {
                string temp = this->relation(curr->father, name, ++count, true);
                if (temp != "unrelated") return temp;
            }

            if (curr->mother != NULL) {
                string temp = this->relation(curr->father, name, ++count, false);
                if (temp != "unrelated") return temp;
            }


        }
        else return "unrelated";


    }
    return "";
}



string Tree::find(string name) {
  Tree * ans = findNodeRealtion(name);
  if(ans!=NULL) return  ans->me;


}

Tree * Tree::findNodeName(string name) {
    if(this->me==name) return this;
    Tree * fatherCheck = (this->father==NULL)?NULL:this->father->findNodeName(name);
    Tree * motherCheck = (this->mother==NULL)?NULL:this->mother->findNodeName(name);
    if(fatherCheck!=NULL) return fatherCheck;
    else if(motherCheck != NULL )return  motherCheck;
    else return  NULL;
}


void Tree::remove(string name) {

}

Tree *Tree::findNodeRealtion(string relation) {
    vector<string> splitedRelation = split(relation, "-");
    Tree *curr = this;
    for (int i = 0; i < splitedRelation.size(); i++) {
        if (splitedRelation[i] == "father" && curr->father != NULL) {
            curr = curr->father;
        }
        else if (splitedRelation[i] == "mother" && curr->mother != NULL) {
            curr = curr->mother;
        }
        else if (splitedRelation[i] == "grandmother" && curr->father != NULL && curr->father->father != NULL) {
            curr = curr->father->mother;
        }
        else if (splitedRelation[i] == "grandfather" && curr->father != NULL && curr->father->father != NULL) {
          if(i==0)  curr = curr->father->father;
          else curr = curr->father;
        }

        else if (splitedRelation[i] == "great" && curr->father != NULL ) {
            curr = curr->father;
        }

        else{
            cout<<"Wrong input detected :"<<relation<<"  at index :"<<i<<endl;
            throw inputEx;
        }

    }

    return  curr;
}




