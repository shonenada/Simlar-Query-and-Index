#include "../../HeaderFiles/metric/RNAMetric.h"

double CRNAMetric::EditDistanceMatrix[RNASYMBOLNUMBER][RNASYMBOLNUMBER] = 
{
    {  0,  1,  1,  1,0.5,  1,0.5,  1,0.5,  1,  1,0.5,0.5,0.5,0.5}, // A Adenine 
    {  1,  0,  1,  1,  1,0.5,0.5,  1,  1,0.5,0.5,  1,0.5,0.5,0.5}, // C Cytosine
    {  1,  1,  0,  1,0.5,  1,  1,0.5,  1,0.5,0.5,0.5,  1,0.5,0.5}, // G Guanine  
    {  1,  1,  1,  0,  1,0.5,  1,0.5,0.5,  1,0.5,0.5,0.5,  1,0.5}, // U Uracil   
    {0.5,  1,0.5,  1,  0,  1,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5}, // R Purine (A or G)  
    {  1,0.5,  1,0.5,  1,  0,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5}, // Y Pyrimidine (C, T, or U)      
    {0.5,0.5,  1,  1,0.5,0.5,  0,  1,0.5,0.5,0.5,0.5,0.5,0.5,0.5}, // M C or A  
    {  1,  1,0.5,0.5,0.5,0.5,  1,  0,0.5,0.5,0.5,0.5,0.5,0.5,0.5}, // K T, U, or G  
    {0.5,  1,  1,0.5,0.5,0.5,0.5,0.5,  0,  1,0.5,0.5,0.5,0.5,0.5}, // W T, U, or A   
    {  1,0.5,0.5,  1,0.5,0.5,0.5,0.5,  1,  0,0.5,0.5,0.5,0.5,0.5}, // S C or G 
    {  1,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,  0,0.5,0.5,0.5,0.5}, // B C, T, U, or G (not A)
    {0.5,  1,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,  0,0.5,0.5,0.5}, // D A, T, U, or G (not C)
    {0.5,0.5,  1,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,  0,0.5,0.5}, // H A, T, U, or C (not G) 
    {0.5,0.5,0.5,  1,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,  0,0.5}, // V A, C, or G (not T, not U)
    {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,  0}  // N Anybase (A,C,G,T,or U) 
};

CRNAMetric::CRNAMetric()
{

}

double CRNAMetric::getDistance(CIndexObject* one, CIndexObject* two)
{
	CRNA* new_one = (CRNA*) one;
	CRNA* new_two = (CRNA*) two;
	return getDistance(new_one, new_two);
}

double CRNAMetric::getDistance(CRNA* one, CRNA* two)
{
	int i;
	int one_size = one->getSize();
	int two_size = two->getSize();
	if(one_size != two_size){
		cerr << "Stop! Two RNA must have the same length.";
		return -1.0;
	}
	double dist = 0.0;
	vector<int> one_byte = one->getBytes();
	vector<int> two_byte = two->getBytes();
	for(i=0;i<one_size;i++){
		dist = dist + CRNAMetric::EditDistanceMatrix[one_byte[i]][two_byte[i]];
	}
	return dist;
}