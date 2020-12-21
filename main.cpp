#include <iostream>
#include "avl.h"
#include <stdio.h>
#include <string.h>
#include <sstream> 
#include <string> 
#include <vector>

using namespace std;
/*
     
    a.insert(10,0);
    a.insert(20,0);
    a.insert(30,0);
    a.insert(40,0);
    a.insert(50,0);
    a.insert(25,0);
    a.search(99,0);
    a.search(50,0);
    a.approx_search(10,0);
    a.approx_search(2000,1);
    a.Delete(9,1);
    a.Delete(10,0);



    cout << "Preorder traversal of the "
            "constructed AVL tree is " << endl; 
    a.preorder();  
    
    cout << "inorder traversal" << endl;
    a.in_order();
      
    */
int main(int argc, char* argv[])
{

    string queryStr = argv[1];
    vector<string> queryVect;
    string delim = ", ";

    int start = 0;
    int end = 0;
    while (start < queryStr.size() )
    {
        end = queryStr.find(delim, start);  
        if (end == string::npos)
        {   
            break;
        }

        queryVect.push_back(queryStr.substr(start, end - start) );  
        start = end + delim.size();
    }

    queryVect.push_back(queryStr.substr(start) );  

    avl t(stoi(queryVect.at(0)) );   

    for (int i = 1; i < queryVect.size(); i++)
    {
        string qry = queryVect.at(i);

        vector<std::string> qryParam;
        stringstream strm(qry);
        string paramStr = "";
        while (std::getline(strm, paramStr, ' ') )
        {
            qryParam.push_back(paramStr);
        }

        

        std::string qryType = qryParam.at(0);

        if (qryType == "search")
        {
            t.search(stoi(qryParam[1]), stoi(qryParam[2]) );
        }

        else if (qryType == "approx_search")
        {
            t.approx_search(stoi(qryParam[1]), stoi(qryParam[2]) );
        }

        else if (qryType == "insert")
        {
            t.insert(stoi(qryParam[1]), stoi(qryParam[2]) );
        }

        else if (qryType == "delete")
        {
            t.Delete(stoi(qryParam[1]), stoi(qryParam[2]) );
        }

        else if (qryType == "in_order")
        {
            t.in_order();
        }

        else if (qryType == "pre_order")
        {
            t.preorder();
        }
    }

    return 0;
}

