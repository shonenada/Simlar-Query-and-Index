#ifndef MVPLEAFNODE_H
#define MVPLEAFNODE_H

#include "IndexNode.h"

#include <list>

/** @file MVPLeafNode.h
* @classes about index structure
* @author Fuli Lei
* @version 2012-12-09
*/

/**
* @class CMVPLeafNode
* @brief class about leaf nodes in index structure
* @author Fuli Lei
*
* this class packages the basic information of an leaf node of mvp-tree.
*/

class CMVPLeafNode:public CIndexNode
{
public:
    /**constructor with no parameters*/
    CMVPLeafNode();
    /**constructor with four parameters.
    @param pivots a vector contains all the address of pivots
    @param dataobjects address list of all the objects composed in this node
    @param distance contains all the distance values from every pivots to each of the object in the object list of this node.the number of rows in this vector is euqual to the number of pivots in this node while the number of column is equal to the length of dataObjects, which is the second parameter of this function
    @param the height of current node
    */
    CMVPLeafNode(vector<shared_ptr<CIndexObject> > &pivots,vector<shared_ptr<CIndexObject> > &dataObjects,vector<vector<double>> &distance,int height);
    /**destructor*/
    virtual ~CMVPLeafNode();

    /**return the distance value list according to the pivot index in the parameter of this function
    @param pivotIndex the index of pivot in the pivot list
    */
    vector<double>& getDataPointPivotDistance(int pivotIndex);

    /**@return the number of objects in this node*/
    int numChildren();

    /**@return the address of object according the object index in the parameter of this function*/
    shared_ptr<CIndexObject>  getObject(int childIndex);

    /**@return all the address of object in this node trough a vector*/
    vector<shared_ptr<CIndexObject> >& getObjects();

    /**traversal from this internal node to its every child to search out the proper objects base on the parameters
    @param q this object is given by the user according which kind of query does the user want to do later, there is some basic information packaged in the object  like the search radius if the user want do a range query search latter.
    @param metric this object will be use to calculate the distance of two objects
    @return the proper objects address list through a vector
    */
    virtual vector<CIndexObject*>  search(CRangeQuery &q,CMetric &metric);

    virtual void getAlldata(vector<shared_ptr<CIndexObject> > &result);
    virtual void travelSearch(CRangeQuery &q,CMetric &metric,vector<shared_ptr<CIndexObject> > &result);

    virtual int writeExternal(ofstream &out);
    virtual int readExternal(ifstream &in,string &objectType);

    virtual void searchIndex(CRangeQuery &q,long filePointer,ifstream &in,CMetric &metric,vector<shared_ptr<CIndexObject> > &result,string &dataType);
    virtual void searchExternal(CRangeQuery &q,long filePointer,ifstream &in,CMetric &metric,vector<shared_ptr<CIndexObject> > &result,deque<long> &childrenAddress,string &dataType);

private:

    /**all the address of objects that reside in this node is stored in this vector*/
    vector<shared_ptr<CIndexObject> > dataObjects;
    /**contains all the distance values from every pivots to each of the object in the object list of this node.the number of rows in this vector is euqual to the number of pivots in this node while the number of column is equal to the length of dataObjects, which is the second parameter of this function*/
    vector<vector<double>> distance;
};

#endif